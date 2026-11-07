#include "types.h"

typedef struct {
    u8 pad0[0x68];
    f32 unk68;
    u8 pad6C[8];
    f32 unk74;
    f32 unk78;
} Ovl0260Actor;

void ObjGrassCarry_UpdateVelY(Ovl0260Actor *a) {
    a->unk68 += a->unk74;
    if (a->unk68 < a->unk78) {
        a->unk68 = a->unk78;
    }
}
