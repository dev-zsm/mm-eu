// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
typedef struct { u8 pad0[4]; u32 flags; u8 pad8[0x8A]; s16 yaw; f32 f94; } A;
typedef struct { u8 pad0[0x730]; s32 f730; } B;
extern f32 D_801D4B08;
extern f32 D_801D4B0C;
extern f32 D_801D4B10;
f32 Attention_WeightedDistToPlayerSq(A *a, B *b, s16 ang) {
    s16 d;
    s16 ad;
    d = a->yaw - 0x8000 - ang;
    if (d < 0) {
        ad = -d;
    } else {
        ad = d;
    }
    if (b->f730 != 0) {
        if (ad > 0x4000 || (a->flags & 0x08000000)) {
            return D_801D4B08;
        }
        return a->f94 - (a->f94 * D_801D4B0C * ((f32)(0x4000 - ad) * (1.0f / 32768.0f)));
    }
    if (ad >= 0x2AAB) {
        return D_801D4B10;
    }
    return a->f94;
}
