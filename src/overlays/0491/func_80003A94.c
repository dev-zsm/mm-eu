#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0491.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80137C58(u8 *, M2C_UNK);                 /* extern */
s32 func_80B3ABFC(u8 *);                          /* extern */
s32 func_80B3ACBC(M2C_UNK);                         /* extern */

s32 func_80003A94(u8 *arg0, M2C_UNK arg1) {
    switch ((M2C_FIELD(arg0, u8 *, 0x200))) {
        case 23:
            if ((func_80B3ACBC(arg1) != 0) && (func_80B3ABFC(arg0) != 0)) {
            M2C_FIELD(arg0, u16 *, 0x360) = (u16) (M2C_FIELD(arg0, u16 *, 0x360) | 0x20);
            } else {
            M2C_FIELD(arg0, u16 *, 0x360) = (u16) (M2C_FIELD(arg0, u16 *, 0x360) & 0xFFDF);
            }
            break;
        case 1:
            if (func_80B3ABFC(arg0) != 0) {
            M2C_FIELD(arg0, u16 *, 0x360) = (u16) (M2C_FIELD(arg0, u16 *, 0x360) | 0x20);
            } else {
            M2C_FIELD(arg0, u16 *, 0x360) = (u16) (M2C_FIELD(arg0, u16 *, 0x360) & 0xFFDF);
            }
            break;
        case 18:
        case 19:
            if (func_80B3ABFC(arg0) != 0) {
            M2C_FIELD(arg0, u16 *, 0x360) = (u16) (M2C_FIELD(arg0, u16 *, 0x360) | 0x20);
            } else {
            M2C_FIELD(arg0, u16 *, 0x360) = (u16) (M2C_FIELD(arg0, u16 *, 0x360) & 0xFFDF);
            }
            break;
        case 22:
            if ((func_80137C58(arg0 + 0x144, 0x40C00000) != 0) && (M2C_FIELD(arg0, s32 *, 0x39C) == 0x17)) {
            func_800B8C4C(arg0, 0x2899);
            }
            break;
    }
    return 0;
}
