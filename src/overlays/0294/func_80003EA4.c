#include "types.h"

typedef struct {
    /* 0x000 */ u8 pad0[0x38];
    /* 0x038 */ s8 unk38;
    /* 0x039 */ u8 pad39[0x14F];
    /* 0x188 */ void *unk188;
} Ovl0294Actor;

extern u8 D_809F9BE0[];
extern s32 func_809F8224();

void func_80003EA4(Ovl0294Actor *this, s32 play) {
    if (func_809F8224(this, this->unk38) != 0) {
        this->unk188 = D_809F9BE0;
    }
}
