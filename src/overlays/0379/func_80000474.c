#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C();             /* extern */

void func_80000474(u8 *arg0, u8 *arg1) {
    u16 temp_v0;

    if (M2C_FIELD(arg0, s16 *, 0x1C) == 0) {
        temp_v0 = M2C_FIELD(arg1, u16 *, 0x1F34);
        switch (temp_v0) {                          /* irregular */
            case 0x7D:
                func_800B8C4C(arg0, (u8 *)0x281B);
                return;
            case 0x728:
                func_800B8C4C(arg0, (u8 *)0x281B);
                func_800B8C4C(arg0, 0x4832);
                return;
        }
    } else if (M2C_FIELD(arg1, u16 *, 0x1F34) == 0x7D) {
        func_800B8C4C(arg0, (u8 *)0x2924);
    }
}
