#include "types.h"

typedef struct {
    u32 segment;
    u8 pad4[0x40];
} ObjectEntry; // size = 0x44

typedef struct {
    u8 pad0[0x17D98];
    ObjectEntry entries[1];
} PlayState;

typedef struct {
    /* 0x000 */ u8 pad0[0x13C];
    /* 0x13C */ void *unk13C;
    /* 0x140 */ u8 pad140[0xC];
    /* 0x14C */ u8 skelAnime[0x193 - 0x14C];
    /* 0x193 */ s8 objectIndex;
} EnHy;

extern u32 D_801EFA18;

s32 SkelAnime_Update(void *skelAnime, PlayState *play);

s32 EnHy_UpdateSkelAnime(EnHy *this, PlayState *play) {
    s32 updated = 0;

    if (this->unk13C != NULL) {
        D_801EFA18 = play->entries[this->objectIndex].segment + 0x80000000;
        SkelAnime_Update(this->skelAnime, play);
        updated = 1;
    }
    return updated;
}
