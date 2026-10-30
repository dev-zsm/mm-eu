#include "types.h"

typedef struct {
    /* 0x0000 */ u8 pad0[0x1F34];
    /* 0x1F34 */ u16 unk1F34;
} Ovl0378Play;

extern void func_800B8C4C();

void func_800008A8(s32 a0, Ovl0378Play *play) {
    if (play->unk1F34 >= 0x282 && play->unk1F34 < 0x34D) {
        func_800B8C4C(a0, 0x328E);
    }
}
