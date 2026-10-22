#ifndef M2C_COMPAT_H
#define M2C_COMPAT_H

/* Verified drafts only: unknown type and raw field access at a byte offset. Each use is a field whose struct is not
   known yet; replace it by a real struct member when the type is understood. */
typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

#endif
