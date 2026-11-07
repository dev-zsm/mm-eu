#include "types.h"

typedef struct {
    u8 pad0[0x1C];
    f32 unk1C;
    u8 pad20[0x40 - 0x20];
    s16 unk40;
} A;

extern f32 D_80963854[];

s32 func_80000810(A *a, s32 b, s32 c) {
    s32 i = (a->unk40 >> 2) & 7;

    if (i != 0) {
        a->unk1C += D_80963854[i];
    }
    return 1;
}
