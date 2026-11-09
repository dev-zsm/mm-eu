#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x2AE]; s16 unk2AE; } S_arg0;
typedef struct { u8 pad0[0x18875]; s8 unk18875; u8 pad18876[0x4]; s16 unk1887A; u8 pad1887C[0x3]; s8 unk1887F; } S_arg1;

extern M2C_UNK D_801E6EF0;

void func_80000AC4(S_arg0 *arg0, S_arg1 *arg1) {
    s16 temp_v0;

    temp_v0 = arg0->unk2AE;
    if (temp_v0 > 0) {
        arg0->unk2AE = (s16) (temp_v0 - 1);
        return;
    }
    if (M2C_FIELD(&D_801E6EF0, u8 *, 0x3DD4) == 6) {
        arg1->unk1887F = 0x50;
        M2C_FIELD(&D_801E6EF0, s8 *, 0x3F55) = 3;
    } else {
        arg1->unk1887F = 0x40;
        M2C_FIELD(&D_801E6EF0, s8 *, 0x3F55) = 2;
    }
    M2C_FIELD(&D_801E6EF0, s16 *, 0x3F4A) = 0;
    arg1->unk1887A = 0x2810;
    arg1->unk18875 = 0x14;
}
