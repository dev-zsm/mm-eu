#include "types.h"
extern void Matrix_MtxFToMtx(void *a0, s32 a1);
void Matrix_MtxFToNewMtx(void *a0, void *a1) {
    s32 v = *(s32 *)((u8 *)a1 + 0x2B4) - 0x40;
    *(s32 *)((u8 *)a1 + 0x2B4) = v;
    Matrix_MtxFToMtx(a0, v);
}
