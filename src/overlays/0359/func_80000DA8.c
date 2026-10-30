#include "types.h"

typedef struct {
    /* 0x0000 */ u8 pad0[0xA4];
    /* 0x00A4 */ s16 unkA4;
    /* 0x00A6 */ u8 padA6[0x1E86];
    /* 0x1F2C */ u8 unk1F2C;
} Ovl0359Play;

extern void func_800B8D94();

void func_80000DA8(s32 a0, Ovl0359Play *play) {
    if (play->unk1F2C != 0 && play->unkA4 == 0x19) {
        func_800B8D94(a0, 0x2129);
    }
}
