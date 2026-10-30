#include "types.h"

typedef struct {
    /* 0x000 */ u8 pad0[0x192];
    /* 0x192 */ s16 unk192;
} Ovl0110Actor;

typedef struct {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
} Ovl0110Vec;

s32 func_80002E08(s32 a0, s32 limb, s32 a2, Ovl0110Vec *pos, s32 a4, Ovl0110Actor *this) {
    if (limb == 1) {
        pos->z += this->unk192;
    }
    return 0;
}
