// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 AudioHeap_Alloc(M2C_UNK *, s32);                  /* extern */
M2C_UNK AudioHeap_InitPool(M2C_UNK *, s32, s32);         /* extern */
extern M2C_UNK D_801F84B0;
extern M2C_UNK D_801FAE70;
extern M2C_UNK D_801FAEA0;
extern M2C_UNK D_801FAED0;

void AudioHeap_InitSessionPool(void *arg0) {
    M2C_FIELD(&D_801F84B0, s32 *, 0x29C4) = (s32) M2C_FIELD(&D_801F84B0, s32 *, 0x29C0);
    AudioHeap_InitPool(&D_801FAEA0, AudioHeap_Alloc(&D_801FAE70, M2C_FIELD(arg0, s32 *, 0)), M2C_FIELD(arg0, s32 *, 0));
    AudioHeap_InitPool(&D_801FAED0, AudioHeap_Alloc(&D_801FAE70, M2C_FIELD(arg0, s32 *, 0xC)), M2C_FIELD(arg0, s32 *, 0xC));
}
