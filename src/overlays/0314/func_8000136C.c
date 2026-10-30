#include "types.h"

typedef struct {
    /* 0x000 */ u8 pad0[0x2];
    /* 0x002 */ s16 unk2;
} Ovl0314Rot;

typedef struct {
    /* 0x000 */ u8 pad0[0x214];
    /* 0x214 */ s16 unk214;
} Ovl0314Actor;

s32 func_8000136C(s32 a0, s32 limb, s32 a2, s32 a3, Ovl0314Rot *rot, Ovl0314Actor *this) {
    if (limb == 2) {
        rot->unk2 += this->unk214;
    }
    return 0;
}
