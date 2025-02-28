HPy: a better API for Python
==================================

[![Build](https://github.com/hpyproject/hpy/actions/workflows/ci.yml/badge.svg)](https://github.com/hpyproject/hpy/actions/workflows/ci.yml)
[![Documentation](https://readthedocs.org/projects/hpy/badge/)](https://hpy.readthedocs.io/)

**IRC channel** : #hpy on [libera.chat](https://libera.chat)

**Mailing list**: [hpy-dev@python.org](https://mail.python.org/mailman3/lists/hpy-dev.python.org/)

The goal of the project is to design a better API for extending Python
in C. The current API is specific to the current implementation of CPython: it
exposes a lot of internal details which makes it hard:

  - to implement it for other Python implementations (e.g. PyPy, GraalPython,
    Jython, IronPython, etc.)

  - to experiment with new things inside CPython itself: e.g. using a GC
    instead of refcounting, or to remove the GIL

The goal of this project is to improve the situation by designing a new API
which solves some of the current problems.

More specifically, the goals include (but are not necessarily limited to):

  - to be usable on CPython *right now* with no (or almost no) performance
    impact

  - to make the adoption **incremental**: it should be possible to migrate
    existing C extensions piece by piece and to use the old and the new API
    side-by-side during the transition

  - to provide better debugging experience: in debug mode, you could get
    precise notification about which handles are kept open for too long
    or used after being closed.

  - to be more friendly for other implementations: in particular, we do not
    want reference counting to be part of the API: we want a more generic way
    of managing resources which is possible to implement with different
    strategies, including the existing reference counting and/or with a moving
    GC (like the ones used by PyPy or Java, for example)

  - to be smaller and easier to study/use/manage than the existing one

  - to avoid to expose internal details of a specific implementation, so that
    each implementation can experiment with new memory layout of objects, add
    optimizations, etc.

  - to be written in a way which could make it possible in the future to have
    a single binary which is ABI-compatible across multiple Python versions
    and/or multiple implementations

  - internal details might still be available, but in a opt-in way: for
    example, if Cython wants to iterate over a list of integers, it can ask if
    the implementation provides a direct low-level access to the content
    (e.g. in the form of a `int64_t[]` array) and use that. But at the same
    time, be ready to handle the generic fallback case.


More concrete goals
--------------------

  - we will write a small C library which implements the new API on top of the
    existing one: no changes to CPython needed

  - PyPy will implement this natively: extensions using this API will be
    orders of magnitude faster than the ones using the existing old API (see
    [this blog post](https://www.pypy.org/posts/2018/09/inside-cpyext-why-emulating-cpython-c-8083064623681286567.html)
    for details)

  - Cython will adopt this from day one: existing Cython programs will benefit
    from this automatically


Why should I care about this stuff?
------------------------------------

  - the existing C API is becoming a problem for CPython and for the
    evolution of the language itself: this project makes it possible to make
    experiments which might be "officially" adopted in the future

  - for PyPy, it will give obvious speed benefits: for example, data
    scientists will be able to get the benefit of fast C libraries *and* fast
    Python code at the same time, something which is hard to achieve now

  - the current implementation is too tied to CPython and proved to be a
    problem for almost all the other alternative implementations. Having an
    API which is designed to work well on two different implementations will
    make the job much easier for future ones: going from 2 to N is much easier
    than going from 1 to 2

  - arguably, it will be easier to learn and understand than the massive
    CPython C API

See also [Python Performance: Past, Present,
Future](https://github.com/vstinner/talks/raw/main/2019-EuroPython/python_performance.pdf)
by Victor Stinner.


What does `HPy` mean?
-----------------------

The "H" in `HPy` stands for "handle": one of the key idea of the new API is to
use fully opaque handles to represent and pass around Python objects.


Donate to HPy
-------------

Become a financial contributor and help us sustain the HPy community: [Contribute to HPy](https://opencollective.com/hpy/contribute).
