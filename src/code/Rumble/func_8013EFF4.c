#include "types.h"

typedef struct {
    u8 pad0[0x10B];
    u8 unk10B;
    u8 unk10C;
} Rumble;

extern f32 D_801D6920;
extern Rumble D_801EE250;
extern u8 D_801EE35A;
float sqrtf(float);
#pragma intrinsic (sqrtf)

void Rumble_Override(f32 distSq, u8 a1, u8 a2, u8 a3) {
    s32 d;
    s32 t;

    if (distSq > D_801D6920) {
        d = 1000;
    } else {
        d = sqrtf(distSq);
    }
    if (d < 1000 && a1 != 0 && a3 != 0) {
        t = a1 - (d * 255) / 1000;
        if (t > 0) {
            D_801EE35A = t;
            D_801EE250.unk10B = a2;
            D_801EE250.unk10C = a3;
        }
    }
}
