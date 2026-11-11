#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFDD8(u8 *, s16, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80ADEA34(u8 *);                      /* extern */
M2C_UNK func_80ADEBAC(u8 *);                      /* extern */
M2C_UNK func_80ADEEA0(u8 *);                      /* extern */
M2C_UNK func_80ADF064(u8 *);                      /* extern */

void func_800028F8(u8 *arg0) {
    switch ((M2C_FIELD(arg0, u8 *, 0x258))) {
        case 0x3:
        case 0x4:
        case 0x5:
        case 0x6:
        case 0x7:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x1C:
            func_80ADEEA0(arg0);
            break;
        case 0x1:
        case 0x2:
        case 0xA:
        case 0xB:
        case 0xC:
        case 0xD:
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x24:
        case 0x25:
            func_80ADEA34(arg0);
            break;
        case 0x9:
        case 0xE:
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1B:
        case 0x1D:
            func_80ADF064(arg0);
            break;
        case 0x26:
        case 0x27:
        case 0x28:
        case 0x29:
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
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
        case 0x4A:
        case 0x4B:
        case 0x4C:
        case 0x4D:
        case 0x4E:
        case 0x4F:
        case 0x50:
        case 0x51:
        case 0x52:
        case 0x53:
        case 0x54:
        case 0x55:
        case 0x56:
        case 0x57:
        case 0x58:
        case 0x59:
        case 0x5A:
        case 0x5B:
            func_80ADEBAC(arg0);
            break;
    }
    func_800FFDD8(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x32), 3, 0x2AA8);
}
