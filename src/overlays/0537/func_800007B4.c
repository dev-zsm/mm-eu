#include "types.h"
#include "m2c_compat.h"

s32 func_800EDFA0(s32, M2C_UNK);                    /* extern */
s32 func_800EE03C(s32, M2C_UNK);                    /* extern */
M2C_UNK func_80B84584(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80B8460C(u8 *);                      /* extern */

void func_800007B4(u8 *arg0, s32 arg1) {
    s16 temp_v1;

    func_80B8460C(arg0);
    if ((func_800EE03C(arg1, 0x1F4) != 0) && (M2C_FIELD(arg0, s16 *, 0x30E) = -1, temp_v1 = *((s16 **)(arg1 + 0x1F4C))[func_800EDFA0(arg1, 0x1F4)], (temp_v1 != M2C_FIELD(arg0, s16 *, 0x310)))) {
        M2C_FIELD(arg0, s16 *, 0x310) = temp_v1;
        switch (temp_v1) {                          /* irregular */
            case 1:
                func_80B84584(arg0, 8, 0);
                return;
            case 2:
                func_80B84584(arg0, 7, 0);
                break;
        }
    }
}
