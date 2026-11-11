#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x18875]; s8 unk18875; u8 pad18876[0x4]; s16 unk1887A; u8 pad1887C[0x3]; s8 unk1887F; } S_arg1;

M2C_UNK func_800B701C(u8 *, s32, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_801E6EF0;

s32 func_80000000(s32 arg0, S_arg1 *arg1) {
    func_800B701C(arg1, arg0, 7, arg1);
    arg1->unk1887A = M2C_FIELD(&D_801E6EF0, u8 *, 0x100F) & 0x20 ? 0xC60 : 0x8460;
    M2C_FIELD(&D_801E6EF0, s16 *, 0x3F4A) = 0;
    arg1->unk18875 = 0x14;
    arg1->unk1887F = 3;
    M2C_FIELD(&D_801E6EF0, s8 *, 0x3F55) = 7;
    M2C_FIELD(&D_801E6EF0, u8 *, 0xF52) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF52) & 0xBF);
    M2C_FIELD(&D_801E6EF0, u8 *, 0x1011) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0x1011) & 0xFE);
    return 1;
}
