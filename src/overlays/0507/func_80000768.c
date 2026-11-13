#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E00C8(s32, u8 *);                 /* extern */
M2C_UNK func_800F1944(s16);                         /* extern */
s32 func_800F1984(s16);                             /* extern */
M2C_UNK func_800F1B24(s16, u8 *);                 /* extern */
M2C_UNK func_800F1D6C(M2C_UNK);                     /* extern */
s32 func_800F1E2C();                                /* extern */
u8 *func_80B587C0(u8 *, u8);                    /* extern */
extern M2C_UNK D_80B58E64;

void func_80000768(u8 *arg0, u8 *arg1) {
    u16 temp_t6;
    u8 *temp_v0;

    if (func_800F1984(M2C_FIELD(arg0, s16 *, 0x3C8)) != 0) {
        switch ((M2C_FIELD(arg0, u16 *, 0x3CE))) {
            case 0xDD0:
            case 0xDD2:
            case 0xDD3:
            case 0xDD4:
            case 0xDD6:
                temp_v0 = func_80B587C0(arg1, M2C_FIELD(arg0, u8 *, 0x3D0));
                M2C_FIELD(arg0, u8 **, 0x144) = temp_v0;
                func_800F1B24(M2C_FIELD(arg0, s16 *, 0x3C8), temp_v0);
                func_800E00C8(M2C_FIELD(arg1, s32 *, 0x800), M2C_FIELD(arg0, u8 **, 0x144));
                break;
            default:
                func_800F1B24(M2C_FIELD(arg0, s16 *, 0x3C8), arg0);
                func_800E00C8(M2C_FIELD(arg1, s32 *, 0x800), M2C_FIELD(arg0, u8 **, 0x144));
                break;
        }
        M2C_FIELD(arg0, M2C_UNK **, 0x1DC) = &D_80B58E64;
        return;
    }
    if (func_800F1E2C() == 0x7C) {
        if (M2C_FIELD(arg0, u8 *, 0x3D0) == 0xA) {
            M2C_FIELD(arg0, M2C_UNK **, 0x1DC) = &D_80B58E64;
        } else {
            func_800F1D6C(0x7C);
        }
    }
    func_800F1944(M2C_FIELD(arg0, s16 *, 0x3C8));
}
