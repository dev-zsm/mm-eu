#include "types.h"

extern u8 D_80A0B01C[];
extern f32 D_80A0BDB4;

typedef struct {
    u8 pad0[0x68];
    f32 unk68;
    u8 pad6C[0x13C];
    u8 *unk1A8;
    u8 pad1AC[0xF4];
    s16 unk2A0;
} Actor305;

void func_8000322C(Actor305 *a) {
    a->unk1A8 = D_80A0B01C;
    a->unk68 = a->unk68 * D_80A0BDB4;
    a->unk2A0 = -1;
}
