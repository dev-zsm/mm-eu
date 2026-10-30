#include "types.h"
typedef struct {
    u8 pad0[0x70]; f32 unk70;
    u8 pad74[0x1C]; s16 unk90; s16 unk92;
    u8 pad94[0x28]; s16 unkBC; s16 unkBE;
    u8 padC0[0xA0]; f32 unk160;
    u8 pad164[0x24]; void *unk188;
    u8 pad18C[4]; s16 unk190;
} A;
extern u8 D_8087A13C[];
void func_800012F0(A *a) {
    a->unk160 = 3.0f;
    a->unkBC = 0x1554;
    a->unkBE = a->unk92;
    a->unk190 = 0x32;
    a->unk70 = 3.0f;
    a->unk188 = D_8087A13C;
}
