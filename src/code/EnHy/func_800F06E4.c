#include "types.h"

typedef struct {
    u32 segment;
    u8 pad4[0x40];
} ObjectEntry;

typedef struct {
    u8 pad0[0x17D98];
    ObjectEntry entries[1];
} ObjectContext;

typedef struct {
    u8 pad0[0x14C];
    u8 skelAnime[1];
    u8 pad14D[0x193 - 0x14D];
    s8 objectIndex;
} EnHy;

extern u32 D_801EFA18;
extern void EnHy_ChangeAnim(void *skelAnime, s16 animIndex, s16 arg2, void *this);

void EnHy_ChangeObjectAndAnim(EnHy *this, ObjectContext *objCtx, s16 animIndex) {
    D_801EFA18 = objCtx->entries[this->objectIndex].segment + 0x80000000;
    EnHy_ChangeAnim(this->skelAnime, animIndex, animIndex, this);
}
