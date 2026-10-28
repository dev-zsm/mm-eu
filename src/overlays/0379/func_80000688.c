// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80137C58(u8 *, M2C_UNK);                 /* extern */

void func_80000688(u8 *arg0, u8 *arg1) {
    u16 temp_v0;
    u16 temp_v0_2;

    if (M2C_FIELD(arg0, s16 *, 0x1C) == 0) {
        temp_v0 = M2C_FIELD(arg1, u16 *, 0x1F34);
        switch (temp_v0) {                          /* switch 1; irregular */
        case 0x2FA:                                 /* switch 1 */
            func_800B8C4C(arg0, 0x29C0);
            break;
        case 0x31D:                                 /* switch 1 */
            func_800B8C4C(arg0, 0x281B);
            break;
        }
    } else {
        temp_v0_2 = M2C_FIELD(arg1, u16 *, 0x1F34);
        switch (temp_v0_2) {                        /* switch 2; irregular */
        case 0x2FA:                                 /* switch 2 */
            func_800B8C4C(arg0, 0x29C1);
            break;
        case 0x31D:                                 /* switch 2 */
            func_800B8C4C(arg0, 0x2924);
            break;
        }
    }
    if ((M2C_FIELD(arg0, u8 *, 0x261) == 0x35) && (func_80137C58(arg0 + 0x144, 0x41800000) != 0)) {
        func_800B8C4C(arg0, 0x2924);
    }
}
