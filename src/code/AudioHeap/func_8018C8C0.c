// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 AudioHeap_Alloc(M2C_UNK *, s32);                  /* extern */
M2C_UNK AudioHeap_InitPool(M2C_UNK *, s32, s32);         /* extern */
extern M2C_UNK D_801F84B0;
extern M2C_UNK D_801FAED0;
extern M2C_UNK D_801FAEE0;
extern M2C_UNK D_801FAEF0;

void AudioHeap_InitCachePool(void *arg0) {
    M2C_FIELD(&D_801F84B0, s32 *, 0x2A24) = (s32) M2C_FIELD(&D_801F84B0, s32 *, 0x2A20);
    AudioHeap_InitPool(&D_801FAEE0, AudioHeap_Alloc(&D_801FAED0, M2C_FIELD(arg0, s32 *, 0)), M2C_FIELD(arg0, s32 *, 0));
    AudioHeap_InitPool(&D_801FAEF0, AudioHeap_Alloc(&D_801FAED0, M2C_FIELD(arg0, s32 *, 4)), M2C_FIELD(arg0, s32 *, 4));
}
