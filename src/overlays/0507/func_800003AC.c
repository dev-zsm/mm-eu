#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0507.h"

M2C_UNK func_800F1944(s16);                         /* extern */
M2C_UNK func_800F1D6C(s16);                         /* extern */
s32 func_800F1E2C();                                /* extern */
s16 func_800F1E68(s16);                             /* extern */
extern M2C_UNK D_80B58E64;
extern M2C_UNK D_80B58F28;

void func_800003AC(u8 *arg0) {
    u16 temp_t9;

    func_800F1D6C(M2C_FIELD(arg0, s16 *, 0x3C8));
    if (M2C_FIELD(arg0, u8 *, 0x3D0) == 0xA) {
        if (func_800F1E2C() == 0x7C) {
            M2C_FIELD(arg0, M2C_UNK **, 0x1DC) = &D_80B58E64;
        } else {
            M2C_FIELD(arg0, s16 *, 0x3C8) = 0x7C;
        }
    } else {
        M2C_FIELD(arg0, s16 *, 0x3C8) = func_800F1E68(M2C_FIELD(arg0, s16 *, 0x3C8));
        if (func_800F1E2C() == 0x7C) {
            func_800F1D6C(0x7C);
        }
    }
    func_800F1944(M2C_FIELD(arg0, s16 *, 0x3C8));
    M2C_FIELD(arg0, M2C_UNK **, 0x1DC) = &D_80B58F28;
    switch ((M2C_FIELD(arg0, u16 *, 0x3CE))) {
        case 0xDD0:
        case 0xDD2:
        case 0xDD3:
        case 0xDD4:
        case 0xDD6:
            M2C_FIELD(arg0, u16 *, 0x3CC) = (u16) (M2C_FIELD(arg0, u16 *, 0x3CC) | 1);
            return;
        default:
            M2C_FIELD(arg0, u16 *, 0x3CC) = (u16) (M2C_FIELD(arg0, u16 *, 0x3CC) & 0xFFFE);
            return;
    }
}
