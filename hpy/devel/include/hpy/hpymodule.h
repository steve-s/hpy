#ifndef HPY_UNIVERSAL_HPYMODULE_H
#define HPY_UNIVERSAL_HPYMODULE_H
// Copied from Python's exports.h
#ifndef Py_EXPORTED_SYMBOL
    #if defined(_WIN32) || defined(__CYGWIN__)
        #define Py_EXPORTED_SYMBOL __declspec(dllexport)
    #else
        #define Py_EXPORTED_SYMBOL __attribute__ ((visibility ("default")))
    #endif
#endif


// this is defined by HPy_MODINIT
extern HPyContext *_ctx_for_trampolines;

typedef struct {
    const char* name;
    const char* doc;
    HPy_ssize_t size;
    cpy_PyMethodDef *legacy_methods;
    HPyDef **defines;   /* points to an array of 'HPyDef *' */
    /* array with pointers to statically allocated HPyGlobal,
     * with NULL at the end as a sentinel. */
    HPyGlobal **globals;
} HPyModuleDef;


#if defined(__cplusplus)
#  define HPyMODINIT_FUNC extern "C" Py_EXPORTED_SYMBOL HPy
#else /* __cplusplus */
#  define HPyMODINIT_FUNC Py_EXPORTED_SYMBOL HPy
#endif /* __cplusplus */



#ifdef HPY_UNIVERSAL_ABI

// module initialization in the universal case
#define HPy_MODINIT(modname)                                    \
    _HPy_HIDDEN HPyContext *_ctx_for_trampolines;              \
    static HPy init_##modname##_impl(HPyContext *ctx);         \
    HPyMODINIT_FUNC                                            \
    HPyInit_##modname(HPyContext *ctx)                         \
    {                                                          \
        _ctx_for_trampolines = ctx;                            \
        return init_##modname##_impl(ctx);                     \
    }

#else // HPY_UNIVERSAL_ABI

#define GET_MACRO(exec_or_create_name, exec_name, NAME, ...) NAME
#define HPy_MODINIT(modname, moddef, ...) GET_MACRO(__VA_ARGS__, HPy_MODINIT_CREATE_EXEC, HPy_MODINIT_EXEC)(modname, moddef, __VA_ARGS__)

// module initialization in the CPython case
// Note: create_module_def is an internal helper from ctx_module.c

#define HPy_MODINIT_CREATE_EXEC(modname, moddef, create_name, exec_name)         \
    PyModuleDef *create_module_def(HPyModuleDef *hpydef,                         \
                                   void *create_func, void *exec_func);          \
    static HPy create_name(HPyContext *ctx, HPy spec, HPyModuleDef *def);        \
    static int exec_name(HPyContext *ctx, HPy module);                           \
    static PyObject* _hpy_py_##modname##_create_func(PyObject *s, PyModuleDef *d)\
    {                                                                            \
        return _h2py(create_name(_HPyGetContext(), _py2h(s), &moddef));          \
    }                                                                            \
    static int _hpy_py_##modname##_exec_func(PyObject *mod)                      \
    {                                                                            \
        return exec_name(_HPyGetContext(), _py2h(mod));                          \
    }                                                                            \
    PyMODINIT_FUNC                                                               \
    PyInit_##modname(void)                                                       \
    {                                                                            \
        return PyModuleDef_Init(create_module_def(&moddef,                       \
                      _hpy_py_##modname##_create_func,                           \
                      _hpy_py_##modname##_exec_func));                           \
    }

#define HPy_MODINIT_EXEC(modname, moddef, exec_name)                    \
    PyModuleDef *create_module_def(HPyModuleDef *hpydef,                \
                                   void *create_func, void *exec_func); \
    static int exec_name(HPyContext *ctx, HPy module);                  \
    static int _hpy_py_##modname##_exec_func(PyObject *mod)             \
    {                                                                   \
        return exec_name(_HPyGetContext(), _py2h(mod));                 \
    }                                                                   \
    PyMODINIT_FUNC                                                      \
    PyInit_##modname(void)                                              \
    {                                                                   \
        return PyModuleDef_Init(create_module_def(&moddef, NULL,        \
                  _hpy_py_##modname##_exec_func));                      \
    }

#endif // HPY_UNIVERSAL_ABI

#endif // HPY_UNIVERSAL_HPYMODULE_H
