
/*
   DO NOT EDIT THIS FILE!

   This file is automatically generated by hpy.tools.autogen.trampolines.universal_autogen_ctx_impl_h
   See also hpy.tools.autogen and hpy/tools/public_api.h

   Run this to regenerate:
       make autogen

*/

HPyAPI_IMPL HPy ctx_Long_FromLong(HPyContext *ctx, long value)
{
    return _py2h(PyLong_FromLong(value));
}

HPyAPI_IMPL HPy ctx_Long_FromUnsignedLong(HPyContext *ctx, unsigned long value)
{
    return _py2h(PyLong_FromUnsignedLong(value));
}

HPyAPI_IMPL HPy ctx_Long_FromLongLong(HPyContext *ctx, long long v)
{
    return _py2h(PyLong_FromLongLong(v));
}

HPyAPI_IMPL HPy ctx_Long_FromUnsignedLongLong(HPyContext *ctx, unsigned long long v)
{
    return _py2h(PyLong_FromUnsignedLongLong(v));
}

HPyAPI_IMPL HPy ctx_Long_FromSize_t(HPyContext *ctx, size_t value)
{
    return _py2h(PyLong_FromSize_t(value));
}

HPyAPI_IMPL HPy ctx_Long_FromSsize_t(HPyContext *ctx, HPy_ssize_t value)
{
    return _py2h(PyLong_FromSsize_t(value));
}

HPyAPI_IMPL long ctx_Long_AsLong(HPyContext *ctx, HPy h)
{
    return PyLong_AsLong(_h2py(h));
}

HPyAPI_IMPL unsigned long ctx_Long_AsUnsignedLong(HPyContext *ctx, HPy h)
{
    return PyLong_AsUnsignedLong(_h2py(h));
}

HPyAPI_IMPL unsigned long ctx_Long_AsUnsignedLongMask(HPyContext *ctx, HPy h)
{
    return PyLong_AsUnsignedLongMask(_h2py(h));
}

HPyAPI_IMPL long long ctx_Long_AsLongLong(HPyContext *ctx, HPy h)
{
    return PyLong_AsLongLong(_h2py(h));
}

HPyAPI_IMPL unsigned long long ctx_Long_AsUnsignedLongLong(HPyContext *ctx, HPy h)
{
    return PyLong_AsUnsignedLongLong(_h2py(h));
}

HPyAPI_IMPL unsigned long long ctx_Long_AsUnsignedLongLongMask(HPyContext *ctx, HPy h)
{
    return PyLong_AsUnsignedLongLongMask(_h2py(h));
}

HPyAPI_IMPL size_t ctx_Long_AsSize_t(HPyContext *ctx, HPy h)
{
    return PyLong_AsSize_t(_h2py(h));
}

HPyAPI_IMPL HPy_ssize_t ctx_Long_AsSsize_t(HPyContext *ctx, HPy h)
{
    return PyLong_AsSsize_t(_h2py(h));
}

HPyAPI_IMPL HPy ctx_Float_FromDouble(HPyContext *ctx, double v)
{
    return _py2h(PyFloat_FromDouble(v));
}

HPyAPI_IMPL double ctx_Float_AsDouble(HPyContext *ctx, HPy h)
{
    return PyFloat_AsDouble(_h2py(h));
}

HPyAPI_IMPL HPy ctx_Bool_FromLong(HPyContext *ctx, long v)
{
    return _py2h(PyBool_FromLong(v));
}

HPyAPI_IMPL HPy_ssize_t ctx_Length(HPyContext *ctx, HPy h)
{
    return PyObject_Length(_h2py(h));
}

HPyAPI_IMPL int ctx_Number_Check(HPyContext *ctx, HPy h)
{
    return PyNumber_Check(_h2py(h));
}

HPyAPI_IMPL HPy ctx_Add(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_Add(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_Subtract(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_Subtract(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_Multiply(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_Multiply(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_MatrixMultiply(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_MatrixMultiply(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_FloorDivide(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_FloorDivide(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_TrueDivide(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_TrueDivide(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_Remainder(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_Remainder(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_Divmod(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_Divmod(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_Power(HPyContext *ctx, HPy h1, HPy h2, HPy h3)
{
    return _py2h(PyNumber_Power(_h2py(h1), _h2py(h2), _h2py(h3)));
}

HPyAPI_IMPL HPy ctx_Negative(HPyContext *ctx, HPy h1)
{
    return _py2h(PyNumber_Negative(_h2py(h1)));
}

HPyAPI_IMPL HPy ctx_Positive(HPyContext *ctx, HPy h1)
{
    return _py2h(PyNumber_Positive(_h2py(h1)));
}

HPyAPI_IMPL HPy ctx_Absolute(HPyContext *ctx, HPy h1)
{
    return _py2h(PyNumber_Absolute(_h2py(h1)));
}

HPyAPI_IMPL HPy ctx_Invert(HPyContext *ctx, HPy h1)
{
    return _py2h(PyNumber_Invert(_h2py(h1)));
}

HPyAPI_IMPL HPy ctx_Lshift(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_Lshift(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_Rshift(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_Rshift(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_And(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_And(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_Xor(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_Xor(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_Or(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_Or(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_Index(HPyContext *ctx, HPy h1)
{
    return _py2h(PyNumber_Index(_h2py(h1)));
}

HPyAPI_IMPL HPy ctx_Long(HPyContext *ctx, HPy h1)
{
    return _py2h(PyNumber_Long(_h2py(h1)));
}

HPyAPI_IMPL HPy ctx_Float(HPyContext *ctx, HPy h1)
{
    return _py2h(PyNumber_Float(_h2py(h1)));
}

HPyAPI_IMPL HPy ctx_InPlaceAdd(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_InPlaceAdd(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_InPlaceSubtract(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_InPlaceSubtract(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_InPlaceMultiply(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_InPlaceMultiply(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_InPlaceMatrixMultiply(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_InPlaceMatrixMultiply(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_InPlaceFloorDivide(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_InPlaceFloorDivide(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_InPlaceTrueDivide(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_InPlaceTrueDivide(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_InPlaceRemainder(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_InPlaceRemainder(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_InPlacePower(HPyContext *ctx, HPy h1, HPy h2, HPy h3)
{
    return _py2h(PyNumber_InPlacePower(_h2py(h1), _h2py(h2), _h2py(h3)));
}

HPyAPI_IMPL HPy ctx_InPlaceLshift(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_InPlaceLshift(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_InPlaceRshift(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_InPlaceRshift(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_InPlaceAnd(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_InPlaceAnd(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_InPlaceXor(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_InPlaceXor(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL HPy ctx_InPlaceOr(HPyContext *ctx, HPy h1, HPy h2)
{
    return _py2h(PyNumber_InPlaceOr(_h2py(h1), _h2py(h2)));
}

HPyAPI_IMPL int ctx_Callable_Check(HPyContext *ctx, HPy h)
{
    return PyCallable_Check(_h2py(h));
}

HPyAPI_IMPL void ctx_Err_SetString(HPyContext *ctx, HPy h_type, const char *message)
{
    PyErr_SetString(_h2py(h_type), message);
}

HPyAPI_IMPL void ctx_Err_SetObject(HPyContext *ctx, HPy h_type, HPy h_value)
{
    PyErr_SetObject(_h2py(h_type), _h2py(h_value));
}

HPyAPI_IMPL HPy ctx_Err_SetFromErrno(HPyContext *ctx, HPy h_type)
{
    return _py2h(PyErr_SetFromErrno(_h2py(h_type)));
}

HPyAPI_IMPL HPy ctx_Err_NoMemory(HPyContext *ctx)
{
    return _py2h(PyErr_NoMemory());
}

HPyAPI_IMPL void ctx_Err_Clear(HPyContext *ctx)
{
    PyErr_Clear();
}

HPyAPI_IMPL HPy ctx_Err_NewException(HPyContext *ctx, const char *name, HPy base, HPy dict)
{
    return _py2h(PyErr_NewException(name, _h2py(base), _h2py(dict)));
}

HPyAPI_IMPL HPy ctx_Err_NewExceptionWithDoc(HPyContext *ctx, const char *name, const char *doc, HPy base, HPy dict)
{
    return _py2h(PyErr_NewExceptionWithDoc(name, doc, _h2py(base), _h2py(dict)));
}

HPyAPI_IMPL int ctx_IsTrue(HPyContext *ctx, HPy h)
{
    return PyObject_IsTrue(_h2py(h));
}

HPyAPI_IMPL HPy ctx_GetAttr(HPyContext *ctx, HPy obj, HPy name)
{
    return _py2h(PyObject_GetAttr(_h2py(obj), _h2py(name)));
}

HPyAPI_IMPL HPy ctx_GetAttr_s(HPyContext *ctx, HPy obj, const char *name)
{
    return _py2h(PyObject_GetAttrString(_h2py(obj), name));
}

HPyAPI_IMPL int ctx_HasAttr(HPyContext *ctx, HPy obj, HPy name)
{
    return PyObject_HasAttr(_h2py(obj), _h2py(name));
}

HPyAPI_IMPL int ctx_HasAttr_s(HPyContext *ctx, HPy obj, const char *name)
{
    return PyObject_HasAttrString(_h2py(obj), name);
}

HPyAPI_IMPL int ctx_SetAttr(HPyContext *ctx, HPy obj, HPy name, HPy value)
{
    return PyObject_SetAttr(_h2py(obj), _h2py(name), _h2py(value));
}

HPyAPI_IMPL int ctx_SetAttr_s(HPyContext *ctx, HPy obj, const char *name, HPy value)
{
    return PyObject_SetAttrString(_h2py(obj), name, _h2py(value));
}

HPyAPI_IMPL HPy ctx_GetItem(HPyContext *ctx, HPy obj, HPy key)
{
    return _py2h(PyObject_GetItem(_h2py(obj), _h2py(key)));
}

HPyAPI_IMPL int ctx_SetItem(HPyContext *ctx, HPy obj, HPy key, HPy value)
{
    return PyObject_SetItem(_h2py(obj), _h2py(key), _h2py(value));
}

HPyAPI_IMPL HPy ctx_Type(HPyContext *ctx, HPy obj)
{
    return _py2h(PyObject_Type(_h2py(obj)));
}

HPyAPI_IMPL HPy ctx_Repr(HPyContext *ctx, HPy obj)
{
    return _py2h(PyObject_Repr(_h2py(obj)));
}

HPyAPI_IMPL HPy ctx_Str(HPyContext *ctx, HPy obj)
{
    return _py2h(PyObject_Str(_h2py(obj)));
}

HPyAPI_IMPL HPy ctx_ASCII(HPyContext *ctx, HPy obj)
{
    return _py2h(PyObject_ASCII(_h2py(obj)));
}

HPyAPI_IMPL HPy ctx_Bytes(HPyContext *ctx, HPy obj)
{
    return _py2h(PyObject_Bytes(_h2py(obj)));
}

HPyAPI_IMPL HPy ctx_RichCompare(HPyContext *ctx, HPy v, HPy w, int op)
{
    return _py2h(PyObject_RichCompare(_h2py(v), _h2py(w), op));
}

HPyAPI_IMPL int ctx_RichCompareBool(HPyContext *ctx, HPy v, HPy w, int op)
{
    return PyObject_RichCompareBool(_h2py(v), _h2py(w), op);
}

HPyAPI_IMPL HPy_hash_t ctx_Hash(HPyContext *ctx, HPy obj)
{
    return PyObject_Hash(_h2py(obj));
}

HPyAPI_IMPL int ctx_Bytes_Check(HPyContext *ctx, HPy h)
{
    return PyBytes_Check(_h2py(h));
}

HPyAPI_IMPL HPy_ssize_t ctx_Bytes_Size(HPyContext *ctx, HPy h)
{
    return PyBytes_Size(_h2py(h));
}

HPyAPI_IMPL HPy_ssize_t ctx_Bytes_GET_SIZE(HPyContext *ctx, HPy h)
{
    return PyBytes_GET_SIZE(_h2py(h));
}

HPyAPI_IMPL char *ctx_Bytes_AsString(HPyContext *ctx, HPy h)
{
    return PyBytes_AsString(_h2py(h));
}

HPyAPI_IMPL char *ctx_Bytes_AS_STRING(HPyContext *ctx, HPy h)
{
    return PyBytes_AS_STRING(_h2py(h));
}

HPyAPI_IMPL HPy ctx_Bytes_FromString(HPyContext *ctx, const char *v)
{
    return _py2h(PyBytes_FromString(v));
}

HPyAPI_IMPL HPy ctx_Unicode_FromString(HPyContext *ctx, const char *utf8)
{
    return _py2h(PyUnicode_FromString(utf8));
}

HPyAPI_IMPL int ctx_Unicode_Check(HPyContext *ctx, HPy h)
{
    return PyUnicode_Check(_h2py(h));
}

HPyAPI_IMPL HPy ctx_Unicode_AsUTF8String(HPyContext *ctx, HPy h)
{
    return _py2h(PyUnicode_AsUTF8String(_h2py(h)));
}

HPyAPI_IMPL const char *ctx_Unicode_AsUTF8AndSize(HPyContext *ctx, HPy h, HPy_ssize_t *size)
{
    return PyUnicode_AsUTF8AndSize(_h2py(h), size);
}

HPyAPI_IMPL HPy ctx_Unicode_FromWideChar(HPyContext *ctx, const wchar_t *w, HPy_ssize_t size)
{
    return _py2h(PyUnicode_FromWideChar(w, size));
}

HPyAPI_IMPL HPy ctx_Unicode_DecodeFSDefault(HPyContext *ctx, const char *v)
{
    return _py2h(PyUnicode_DecodeFSDefault(v));
}

HPyAPI_IMPL int ctx_List_Check(HPyContext *ctx, HPy h)
{
    return PyList_Check(_h2py(h));
}

HPyAPI_IMPL HPy ctx_List_New(HPyContext *ctx, HPy_ssize_t len)
{
    return _py2h(PyList_New(len));
}

HPyAPI_IMPL int ctx_List_Append(HPyContext *ctx, HPy h_list, HPy h_item)
{
    return PyList_Append(_h2py(h_list), _h2py(h_item));
}

HPyAPI_IMPL int ctx_Dict_Check(HPyContext *ctx, HPy h)
{
    return PyDict_Check(_h2py(h));
}

HPyAPI_IMPL HPy ctx_Dict_New(HPyContext *ctx)
{
    return _py2h(PyDict_New());
}

HPyAPI_IMPL int ctx_Tuple_Check(HPyContext *ctx, HPy h)
{
    return PyTuple_Check(_h2py(h));
}

HPyAPI_IMPL HPy ctx_Import_ImportModule(HPyContext *ctx, const char *name)
{
    return _py2h(PyImport_ImportModule(name));
}

