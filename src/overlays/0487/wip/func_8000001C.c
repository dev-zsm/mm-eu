#include "types.h"

extern u8 D_80B24E30[];

typedef struct {
    u8 pad0[0x38];
    s8 unk38;
    u8 pad39[0x123];
    u8 *unk15C;
    u8 pad160[4];
    f32 unk164;
    u8 pad168[0x14];
    s16 unk17C;
    s16 unk17E;
} Actor487;

void func_8000001C(Actor487 *a) {
    a->unk17E = 0;
    a->unk17C = a->unk38;
    a->unk15C = D_80B24E30;
    a->unk164 = 20.0f;
}
