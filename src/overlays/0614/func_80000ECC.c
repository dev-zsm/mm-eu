#include "types.h"
#include "m2c_compat.h"

s16 func_800DFA9C(s32);                             /* extern */
M2C_UNK func_800F1944(s16);                         /* extern */
s32 func_800F1984(s16);                             /* extern */
M2C_UNK func_800F1A08(s16, u8 *);                 /* extern */
M2C_UNK func_800F1D6C(M2C_UNK);                     /* extern */
s32 func_800F1E2C();                                /* extern */
M2C_UNK func_80BE3EC0(u8 *);                      /* extern */
extern M2C_UNK D_801E6EF0;

void func_80000ECC(u8 *arg0, u8 *arg1) {
    u8 *sp24;

    sp24 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    if (func_800F1E2C() == 0x7C) {
        func_800F1D6C(0x7C);
        func_800F1944(M2C_FIELD(arg0, s16 *, 0x2D4));
        return;
    }
    if (func_800F1984(M2C_FIELD(arg0, s16 *, 0x2D4)) == 0) {
        func_800F1944(M2C_FIELD(arg0, s16 *, 0x2D4));
        return;
    }
    M2C_FIELD(sp24, s32 *, 0xA6C) = (s32) (M2C_FIELD(sp24, s32 *, 0xA6C) & ~0x20);
    M2C_FIELD(&D_801E6EF0, u8 *, 0xF4B) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF4B) & 0xFB);
    M2C_FIELD(arg0, s16 *, 0x32) = func_800DFA9C(((s32 *)(arg1 + 0x800))[M2C_FIELD(arg1, s16 *, 0x810)]);
    M2C_FIELD(arg0, s16 *, 0x2DC) = func_800DFA9C(((s32 *)(arg1 + 0x800))[M2C_FIELD(arg1, s16 *, 0x810)]);
    func_800F1A08(M2C_FIELD(arg0, s16 *, 0x2D4), arg0);
    func_80BE3EC0(arg0);
}
