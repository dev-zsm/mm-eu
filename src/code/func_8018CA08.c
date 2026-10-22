// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 AudioHeap_Alloc(M2C_UNK *, s32);                  /* extern */
M2C_UNK AudioHeap_InitPool(M2C_UNK *, s32, s32);         /* extern */
M2C_UNK AudioHeap_InitTemporaryCache(M2C_UNK *);                   /* extern */
extern M2C_UNK D_801F84B0;
extern M2C_UNK D_801FAEF0;
extern M2C_UNK D_801FAFD4;
extern M2C_UNK D_801FAFD8;
extern M2C_UNK D_801FB0E4;
extern M2C_UNK D_801FB0E8;
extern M2C_UNK D_801FB1F4;
extern M2C_UNK D_801FB1F8;

void AudioHeap_InitTemporaryPoolsAndCaches(void *arg0) {
    M2C_FIELD(&D_801F84B0, s32 *, 0x2A44) = (s32) M2C_FIELD(&D_801F84B0, s32 *, 0x2A40);
    AudioHeap_InitPool(&D_801FAFD8, AudioHeap_Alloc(&D_801FAEF0, M2C_FIELD(arg0, s32 *, 0)), M2C_FIELD(arg0, s32 *, 0));
    AudioHeap_InitPool(&D_801FB0E8, AudioHeap_Alloc(&D_801FAEF0, M2C_FIELD(arg0, s32 *, 4)), M2C_FIELD(arg0, s32 *, 4));
    AudioHeap_InitPool(&D_801FB1F8, AudioHeap_Alloc(&D_801FAEF0, M2C_FIELD(arg0, s32 *, 8)), M2C_FIELD(arg0, s32 *, 8));
    AudioHeap_InitTemporaryCache(&D_801FAFD4);
    AudioHeap_InitTemporaryCache(&D_801FB0E4);
    AudioHeap_InitTemporaryCache(&D_801FB1F4);
}
