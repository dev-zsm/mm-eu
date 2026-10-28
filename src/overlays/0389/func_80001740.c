// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800F1E2C();                                /* extern */
M2C_UNK func_80A97564(u8 *);                      /* extern */
M2C_UNK func_80A97D40(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80A988E0();                            /* extern */
M2C_UNK func_80A989FC(u8 *, u8 *);              /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80A990C4;

void func_80001740(u8 *arg0, u8 *arg1) {
    if ((((s32) M2C_FIELD(&D_801E6EF0, s32 *, 0x18) % 5) == 3) && (M2C_FIELD(arg0, s32 *, 0x16C) < 6) && ((s32) M2C_FIELD(&D_801E6EF0, u16 *, 0xC) < 0x4000)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80A990C4;
        func_80A988E0();
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF00) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF00) | 0x40);
        return;
    }
    if (M2C_FIELD(arg1, u8 *, 0x1F2C) != 0) {
        M2C_FIELD(arg0, s16 *, 0x14) = 1;
        M2C_FIELD(arg0, u16 *, 0x170) = (u16) (M2C_FIELD(arg0, u16 *, 0x170) + 3);
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80A990C4;
    } else {
        if (!(M2C_FIELD(arg1, u8 *, 0x1CA5) & 2) && (((s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0xF000) >> 0xC) == 5) && (func_800F1E2C() == -1)) {
            M2C_FIELD(arg0, M2C_UNK **, 0x13C) = NULL;
        }
        M2C_FIELD(arg0, u16 *, 0x170) = (u16) M2C_FIELD(&D_801E6EF0, u16 *, 0xC);
        if (M2C_FIELD(arg0, s16 *, 0x14) != 0) {
            func_80A97564(arg0);
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
        }
    }
    if ((((s32) M2C_FIELD(&D_801E6EF0, s32 *, 0x18) % 5) != 3) || ((s32) M2C_FIELD(&D_801E6EF0, u16 *, 0xC) >= 0x4000)) {
        func_80A97D40(arg0, 1);
    }
    func_80A989FC(arg0, arg1);
}
