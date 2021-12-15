HPy API
=======

.. warning::
   HPy is still in the early stages of development and the API may change.


Handles
-------

The "H" in HPy stands for **handle**, which is a central concept: handles are
used to hold a C reference to Python objects, and they are represented by the
C ``HPy`` type.  They play the same role as ``PyObject *`` in the Python/C
API, albeit with some important differences which are detailed below.

When they are no longer needed, handles must be closed by calling
``HPy_Close``, which plays more or less the same role as ``Py_DECREF``.
Similarly, if you need a new handle for an existing object, you can duplicate
it by calling ``HPy_Dup``, which plays more or less the same role as
``Py_INCREF``.

The concept of handles is certainly not unique to HPy. Other examples include
Unix file descriptors, where you have ``dup()`` and ``close()``, and Windows'
``HANDLE``, where you have ``DuplicateHandle()`` and ``CloseHandle()``.


Handles vs ``PyObject *``
~~~~~~~~~~~~~~~~~~~~~~~~~

.. XXX I don't like this sentence, but I can't come up with anything better
   right now. Please rephrase/rewrite :)

In the old Python/C API, multiple ``PyObject *`` references to the same object
are completely equivalent to each other. Therefore they can be passed to Python/C
API functions interchangeably. As a result, ``Py_INCREF`` an ``Py_DECREF`` can
be called with any reference to an object as long as the total number of calls
of `incref` is equal to the number of calls of `decref` at the end of the object
lifetime.

Whereas using HPy API, each handle must be closed independently.

Thus, the following perfectly valid piece of Python/C code::

  void foo(void)
  {
      PyObject *x = PyLong_FromLong(42);  // implicit INCREF on x
      PyObject *y = x;
      Py_INCREF(y);                       // INCREF on y
      /* ... */
      Py_DECREF(x);
      Py_DECREF(x);                       // two DECREF on x
  }

Becomes using HPy API:

.. literalinclude:: examples/snippets/snippets.c
  :start-after: // BEGIN: foo
  :end-before: // END: foo

Calling any HPy function on a closed handle is an error. Calling
``HPy_Close()`` on the same handle twice is an error. Forgetting to call
``HPy_Close()`` on a handle results in a memory leak. When running in
:ref:`debug mode`, HPy actively checks that you that you don't close a handle
twice and that you don't forget to close any.


.. note::
  The debug mode is a good example of how powerful it is to decouple the
  lifetime of handles and the lifetime of an objects.  If you find a memory
  leak on CPython, you know that you are missing a ``Py_DECREF`` somewhere but
  the only way to find the corresponding ``Py_INCREF`` is to manually and
  carefully study the source code.  On the other hand, if you forget to call
  ``HPy_Close()``, the HPy debug mode is able to tell the precise code
  location which created the unclosed handle.  Similarly, if you try to
  operate on a closed handle, it will tell you the precise code locations
  which created and closed it.


The other important difference is that Python/C guarantees that multiple
references to the same object results in the very same ``PyObject *`` pointer.
Thus, it is possible to compare C pointers by equality to check whether they
point to the same object::

    int is_same_object(PyObject *x, PyObject *y)
    {
        return x == y;
    }

On the other hand, in HPy, each handle is independent and it is common to have
two different handles which point to the same underlying object, so comparing
two handles directly is ill-defined.  To prevent this kind of common error
(especially when porting existing code to HPy), the ``HPy`` C type is opaque
and the C compiler actively forbids comparisons between them.  To check for
identity, you can use ``HPy_Is()``:

.. literalinclude:: examples/snippets/snippets.c
  :start-after: // BEGIN: is_same_object
  :end-before: // END: is_same_object

.. note::
   The main benefit of the semantics of handles is that it allows
   implementations to use very different models of memory management.  On
   CPython, implementing handles is trivial because ``HPy`` is basically
   ``PyObject *`` in disguise, and ``HPy_Dup()`` and ``HPy_Close()`` are just
   aliases for ``Py_INCREF`` and ``Py_DECREF``.

   Unlike CPython, PyPy does not use reference counting for memory
   management: instead, it uses a *moving GC*, which means that the address of
   an object might change during its lifetime, and this makes it hard to implement
   semantics like ``PyObject *``'s where the address is directly exposed to
   the user.  HPy solves this problem: on PyPy, handles are integers which
   represent indices into a list, which is itself managed by the GC. When an
   object moves, the GC fixes the address in the list, without having to touch
   all the handles which have been passed to C.


HPyContext
-----------

All HPy function calls take an ``HPyContext`` as a first argument, which
represents the Python interpreter all the handles belong to.  Strictly
speaking, it would be possible to design the HPy API without using
``HPyContext``: after all, all HPy function calls are ultimately mapped to
Python/C function call, where there is no notion of context.

One of the reasons to include ``HPyContext`` from the day one is to be
future-proof: it is conceivable to use it to hold the interpreter or the
thread state in the future, in particular when there will be support for
sub-interpreters.  Another possible usage could be to embed different versions
or implementations of Python inside the same process.

Moreover, ``HPyContext`` is used by the :term:`HPy Universal ABI` to contain a
sort of virtual function table which is used by the C extensions to call back
into the Python interpreter.


A simple example
-----------------

In this section, we will see how to write a simple C extension using HPy. It
is assumed that you are already familiar with the existing Python/C API, so we
will underline the similarities and the differences with it.

We want to create a function named ``myabs`` which takes a single argument and
computes its absolute value:

.. literalinclude:: examples/simple-example/simple.c
  :start-after: // BEGIN: myabs
  :end-before: // END: myabs

There are a couple of points which are worth noting:

  * We use the macro ``HPyDef_METH`` to declare we are going to define a
    HPy function called ``myabs``.

  * The function will be available under the name ``"myabs"`` in our Python
    module.

  * The actual C function which implements ``myabs`` is called ``myabs_impl``.

  * It uses the ``HPyFunc_O`` calling convention. Like ``METH_O`` in Python/C API,
    ``HPyFunc_O`` means that the function receives a single argument on top of
    ``self``.

  * ``myabs_impl`` takes two arguments of type ``HPy``: handles for ``self``
    and the argument, which are guaranteed to be valid. They are automatically
    closed by the caller, so there is no need to call ``HPy_Close`` on them.

  * ``myabs_impl`` returns a handle, which has to be closed by the caller.

  * ``HPy_Absolute`` is the equivalent of ``PyNumber_Absolute`` and
    computes the absolute value of the given argument.

  * We also do not call ``HPy_Close`` on the result returned to the caller.
    We must return a valid handle.

.. note::
   Among other things,
   the ``HPyDef_METH`` macro is needed to maintain compatibility with CPython.
   In CPython, C functions and methods have a C signature that is different to
   the one used by HPy: they don't receive an ``HPyContext`` and their arguments
   have the type ``PyObject *`` instead of ``HPy``.  The macro automatically
   generates a trampoline function whose signature is appropriate for CPython and
   which calls the ``myabs_impl``. This trampoline is then used from both the
   CPython ABI and the CPython implementation of the universal ABI, but other
   implementations of the universal ABI will usually call directly the HPy
   function itself.

Now, we can define our module:

.. literalinclude:: examples/simple-example/simple.c
  :start-after: // BEGIN: methodsdef
  :end-before: // END: methodsdef

This part is very similar to the one you would write in Python/C.  Note that
we specify ``myabs`` (and **not** ``myabs_impl``) in the method table. There
is also the ``.legacy_methods`` field, which allows to add methods that use the
Python/C API, i.e., the value should be an array of ``PyMethodDef``. This
feature enables support for hybrid extensions in which some of the methods
are still written using the Python/C API.

.. This would be perhaps good place to add a link to the porting tutorial
   once it's merged

Finally, ``HPyModuleDef`` is basically the same as the old ``PyModuleDef``:

.. literalinclude:: examples/simple-example/simple.c
  :start-after: // BEGIN: moduledef
  :end-before: // END: moduledef

Building the module
~~~~~~~~~~~~~~~~~~~~

Let's write a ``setup.py`` to build our extension:

.. literalinclude:: examples/simple-example/setup.py
    :language: python

We can now build the extension by running ``python setup.py build_ext -i``. On
CPython, it will target the :term:`CPython ABI` by default, so you will end up with
a file named e.g. ``simple.cpython-37m-x86_64-linux-gnu.so`` which can be
imported directly on CPython with no dependency on HPy.

To target the :term:`HPy Universal ABI` instead, it is possible to pass the
option ``--hpy-abi=universal`` to ``setup.py``. The following command will
produce a file called ``simple.hpy.so`` (note that you need to specify
``--hpy-abi`` **before** ``build_ext``, since it is a global option)::

  python setup.py --hpy-abi=universal build_ext -i

.. note::
   This command will also produce a Python file named ``simple.py``, which
   loads the HPy module using the ``universal.load`` function from
   the ``hpy`` Python package.

VARARGS calling convention
~~~~~~~~~~~~~~~~~~~~~~~~~~~

If we want to receive more than a single arguments, we need the
``HPy_METH_VARARGS`` calling convention. Let's add a function ``add_ints``
which adds two integers:

.. literalinclude:: examples/snippets/hpyvarargs.c
  :start-after: // BEGIN: add_ints
  :end-before: // END: add_ints

There are a few things to note:

  * The C signature is different than the corresponding Python/C
    ``METH_VARARGS``: in particular, instead of taking a ``PyObject *args``,
    we take an array of ``HPy`` and its size.  This allows e.g. PyPy to do a
    call more efficiently, because you don't need to create a tuple just to
    pass the arguments.

  * We call ``HPyArg_Parse`` to parse the arguments. Contrarily to almost all
    the other HPy functions, this is **not** a thin wrapper around
    ``PyArg_ParseTuple`` because as stated above we don't have a tuple to pass
    to it, although the idea is to mimic its behavior as closely as
    possible. The parsing logic is implemented from scratch inside HPy, and as
    such there might be missing functionality during the early stages of HPy
    development.

  * If an error occurs, we return ``HPy_NULL``: we cannot simply ``return NULL``
    because ``HPy`` is not a pointer type.

Once we have written our function, we can add it to the ``SimpleMethods[]``
table, which now becomes:

.. literalinclude:: examples/snippets/hpyvarargs.c
  :start-after: // BEGIN: methodsdef
  :end-before: // END: methodsdef
