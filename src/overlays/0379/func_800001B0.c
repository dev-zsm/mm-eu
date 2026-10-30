#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ s16 params;
} Ovl0379Actor;

typedef struct {
    /* 0x0000 */ u8 pad0[0x1F34];
    /* 0x1F34 */ u16 unk1F34;
} Ovl0379Play;

extern void func_800B8C4C();

void func_800001B0(Ovl0379Actor *this, Ovl0379Play *play) {
    if (this->params == 0 && play->unk1F34 == 0x1F9) {
        func_800B8C4C(this, 0x2927);
    }
}
