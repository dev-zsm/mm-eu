#include "types.h"

typedef struct {
    u8 pad0[0x24];
    f32 unk24, unk28, unk2C;
    u8 pad30[0x18C];
    f32 unk1BC, unk1C0, unk1C4;
    u8 pad1C8[4];
    f32 unk1CC, unk1D0;
} S;

void func_80000548(S *s) {
    s->unk24 = s->unk1BC + s->unk1CC;
    s->unk28 = s->unk1C0;
    s->unk2C = s->unk1C4 + s->unk1D0;
}
