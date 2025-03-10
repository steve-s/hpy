#include "hpy.h"

/* a HPy style function */
HPyDef_METH(add_ints, "add_ints", add_ints_impl, HPyFunc_VARARGS)
static HPy add_ints_impl(HPyContext *ctx, HPy self, HPy *args, HPy_ssize_t nargs)
{
    long a, b;
    if (!HPyArg_Parse(ctx, NULL, args, nargs, "ll", &a, &b))
        return HPy_NULL;
    return HPyLong_FromLong(ctx, a+b);
}


/* Add an old-style function */
static PyObject *
add_ints2(PyObject *self, PyObject *args)
{

    long a, b, ret;
    if (!PyArg_ParseTuple(args, "ll", &a, &b))
        return NULL;
    ret = a + b;
    return PyLong_FromLong(ret);
}

static HPyDef *hpy_defines[] = {
    &add_ints,
    NULL
};

static PyMethodDef py_defines[] = {
    {"add_ints_legacy", add_ints2, METH_VARARGS, "add two ints"},
    {NULL, NULL, 0, NULL}    /* Sentinel */
};

static HPyModuleDef moduledef = {
    HPyModuleDef_HEAD_INIT,
    .m_name = "simple",
    .m_doc = "HPy Example",
    .m_size = -1,
    .defines = hpy_defines,
    .legacy_methods = py_defines
};


HPy_MODINIT(simple)
static HPy init_simple_impl(HPyContext *ctx)
{
    HPy m;
    m = HPyModule_Create(ctx, &moduledef);
    if (HPy_IsNull(m))
        return HPy_NULL;
    return m;
}
