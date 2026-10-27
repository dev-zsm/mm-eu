#include "types.h"

typedef struct {
    u32 unk0;
    u8 pad4[0xE0 - 0x4];
    u8 unkE0[0x1702E - 0xE0];
    s8 unk1702E;
    s8 unk1702F;
    s8 unk17030;
} Play9EC;

void Hilite_DrawXlu(void *, void *, f32 *, u32);

void func_800BC9EC(void *arg0, Play9EC *arg1) {
    f32 v[3];

    v[0] = arg1->unk1702E;
    v[1] = arg1->unk1702F;
    v[2] = arg1->unk17030;
    Hilite_DrawXlu(arg0, arg1->unkE0, v, arg1->unk0);
}
