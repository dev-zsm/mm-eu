#include "types.h"

typedef struct {
    u8 pad0[0x74];
    f32 unk74;
    u8 pad78[0x118];
    void *unk190;
    s16 unk194;
    u8 unk196;
} S;

extern u8 D_80AB0B2C[];
extern f32 D_80AB1070;

void func_8000072C(S *s) {
    s->unk74 = D_80AB1070;
    s->unk194 = 0x28;
    s->unk196 = 0x8C;
    s->unk190 = D_80AB0B2C;
}
