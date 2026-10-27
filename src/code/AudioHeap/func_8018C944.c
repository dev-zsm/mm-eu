// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 AudioHeap_Alloc(M2C_UNK *, s32);                  /* extern */
M2C_UNK AudioHeap_InitPool(M2C_UNK *, s32, s32);         /* extern */
M2C_UNK AudioHeap_InitPersistentCache(M2C_UNK *);                   /* extern */
extern M2C_UNK D_801F84B0;
extern M2C_UNK D_801FAEE0;
extern M2C_UNK D_801FAF00;
extern M2C_UNK D_801FAF04;
extern M2C_UNK D_801FB010;
extern M2C_UNK D_801FB014;
extern M2C_UNK D_801FB120;
extern M2C_UNK D_801FB124;

void AudioHeap_InitPersistentPoolsAndCaches(void *arg0) {
    M2C_FIELD(&D_801F84B0, s32 *, 0x2A34) = (s32) M2C_FIELD(&D_801F84B0, s32 *, 0x2A30);
    AudioHeap_InitPool(&D_801FAF04, AudioHeap_Alloc(&D_801FAEE0, M2C_FIELD(arg0, s32 *, 0)), M2C_FIELD(arg0, s32 *, 0));
    AudioHeap_InitPool(&D_801FB014, AudioHeap_Alloc(&D_801FAEE0, M2C_FIELD(arg0, s32 *, 4)), M2C_FIELD(arg0, s32 *, 4));
    AudioHeap_InitPool(&D_801FB124, AudioHeap_Alloc(&D_801FAEE0, M2C_FIELD(arg0, s32 *, 8)), M2C_FIELD(arg0, s32 *, 8));
    AudioHeap_InitPersistentCache(&D_801FAF00);
    AudioHeap_InitPersistentCache(&D_801FB010);
    AudioHeap_InitPersistentCache(&D_801FB120);
}
