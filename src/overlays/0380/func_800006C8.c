#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(s32, M2C_UNK);                /* extern */
s32 func_800EDFA0(u8 *, M2C_UNK);                 /* extern */
s32 func_800EE03C(u8 *, M2C_UNK);                 /* extern */
extern s16 D_80A8FB54;

void func_800006C8(s32 arg0, u8 *arg1) {
    if (func_800EE03C(arg1, 0x87) != 0) {
        if (M2C_FIELD(arg1, u16 *, 0x1F34) == M2C_FIELD(((u8 **)(arg1 + 0x1F4C))[func_800EDFA0(arg1, 0x87)], u16 *, 2)) {
            D_80A8FB54 = 1;
            func_800B8C4C(arg0, 0x2964);
        }
    } else {
        D_80A8FB54 = 0;
    }
}
