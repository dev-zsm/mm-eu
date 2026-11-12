#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFDD8(u8 *, s16, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80BD71A0(u8 *);                      /* extern */
M2C_UNK func_80BD7210(u8 *);                      /* extern */
M2C_UNK func_80BD7388(u8 *);                      /* extern */
M2C_UNK func_80BD7630(u8 *);                      /* extern */
M2C_UNK func_80BD76DC(u8 *);                      /* extern */

void func_80001900(u8 *arg0) {
    switch ((M2C_FIELD(arg0, u8 *, 0x298))) {
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
            func_80BD7388(arg0);
            break;
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            func_80BD7210(arg0);
            break;
        case 2:
            func_80BD76DC(arg0);
            break;
        case 3:
            func_80BD71A0(arg0);
            break;
        case 4:
            func_80BD7630(arg0);
            break;
    }
    func_800FFDD8(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x32), 3, 0x2AA8);
}
