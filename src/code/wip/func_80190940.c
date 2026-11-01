// FLAGS: -O2 -g0 -mips2
// STATUS: automatic draft, 6/28 instructions differ
#include "types.h"
#include "m2c_compat.h"

s32 AudioLoad_GetLoadTable();                                /* extern */

void func_80190940(s32 arg1, s32 arg2, s32 arg3) {
    u8 *temp_v1;

    temp_v1 = AudioLoad_GetLoadTable() + (arg1 * 0x10);
    if (M2C_FIELD(temp_v1, s8 *, 0x18) == 5) {
        switch (arg2) {                             /* irregular */
        case 0:
            M2C_FIELD(temp_v1, s32 *, 0x10) = arg3;
            return;
        case 1:
            M2C_FIELD(temp_v1, s32 *, 0x14) = arg3;
            break;
        }
    }
}
