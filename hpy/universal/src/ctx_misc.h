#ifndef HPY_CTX_MISC_H
#define HPY_CTX_MISC_H

#include "hpy.h"
#include "api.h"

HPyAPI_IMPL HPy ctx_FromPyObject(HPyContext *ctx, cpy_PyObject *obj);
HPyAPI_IMPL cpy_PyObject *ctx_AsPyObject(HPyContext *ctx, HPy h);
HPyAPI_IMPL void ctx_Close(HPyContext *ctx, HPy h);
HPyAPI_IMPL HPy ctx_Dup(HPyContext *ctx, HPy h);
HPyAPI_IMPL void ctx_Field_Store(HPyContext *ctx, HPy target_object,
                                 HPyField *target_field, HPy h);
HPyAPI_IMPL HPy ctx_Field_Load(HPyContext *ctx, HPy source_object,
                               HPyField source_field);
HPyAPI_IMPL void ctx_FatalError(HPyContext *ctx, const char *message);

#endif /* HPY_CTX_MISC_H */
