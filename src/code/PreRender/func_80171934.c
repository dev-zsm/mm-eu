#include "types.h"
#include "generated/code_funcs.h"
void PreRender_RestoreZBuffer(void *a0, s32 a1) {
    PreRender_RestoreBuffer(a0, a1, *(s32 *)((u8 *)a0 + 0x20), *(s32 *)((u8 *)a0 + 0x1C));
}
