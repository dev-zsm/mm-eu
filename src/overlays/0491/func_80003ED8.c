#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0491.h"

M2C_UNK func_800FFDD8(u8 *, s16, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80B3BB74(u8 *);                      /* extern */
M2C_UNK func_80B3BBE4(u8 *);                      /* extern */
M2C_UNK func_80B3BD5C(u8 *);                      /* extern */
M2C_UNK func_80B3C004(u8 *);                      /* extern */
M2C_UNK func_80B3C124(u8 *);                      /* extern */
M2C_UNK func_80B3C2EC(u8 *);                      /* extern */
M2C_UNK func_80B3C3A4(u8 *);                      /* extern */

void func_80003ED8(u8 *arg0) {
    switch ((M2C_FIELD(arg0, u8 *, 0x200))) {
        case 0x10:
        case 0x11:
        case 0x15:
            func_80B3BB74(arg0);
            break;
        case 0x3:
            func_80B3C124(arg0);
            break;
        case 0x1:
            func_80B3C2EC(arg0);
            break;
        case 0x19:
            func_80B3C3A4(arg0);
            break;
        case 0xC:
        case 0xE:
        case 0x12:
        case 0x13:
        case 0x16:
        case 0x18:
            func_80B3C004(arg0);
            break;
        case 0x17:
            func_80B3C004(arg0);
            break;
        case 0x1A:
        case 0x1B:
        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0x1F:
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x24:
        case 0x25:
        case 0x26:
        case 0x27:
            func_80B3BBE4(arg0);
            break;
        case 0x28:
        case 0x2A:
        case 0x2B:
        case 0x2C:
        case 0x2D:
        case 0x2E:
        case 0x2F:
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3A:
        case 0x3B:
        case 0x3C:
        case 0x3D:
        case 0x3E:
        case 0x3F:
            func_80B3BD5C(arg0);
            break;
    }
    func_800FFDD8(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x32), 3, 0x2AA8);
}
