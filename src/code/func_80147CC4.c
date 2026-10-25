#include "types.h"

typedef struct {
    u8 pad0[0x11F26];
    u8 unk11F26;
    u8 pad11F27[0x12024 - 0x11F27];
    u8 unk12024;
    u8 pad12025[0x12027 - 0x12025];
    u8 unk12027;
} SubState;

typedef struct {
    u8 pad0[0x4908];
    SubState sub;
    u8 pad_after[0x1681C - 0x4908 - sizeof(SubState)];
    s32 unk1681C;
} PlayState;

extern void Audio_PlaySfx(s32 a, PlayState *play);

void func_80147CC4(PlayState *play) {
    SubState *sub = &play->sub;

    if (play->unk1681C != 0) {
        sub->unk12027 = 2;
        sub->unk11F26 = 0x43;
        sub->unk12024 = 0;
        Audio_PlaySfx(0, play);
    }
}
