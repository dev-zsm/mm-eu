#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E2318(s32, s32, u8 *);            /* extern */
M2C_UNK func_800E2500(s32, s32, u8 *);            /* extern */
M2C_UNK func_800E26E8(s32, s32, u8 *);            /* extern */
M2C_UNK func_800FF384(s32, s32);                    /* extern */

void func_80000684(u8 *arg0, s32 arg1) {
    s16 temp_v0;
    s16 var_v1;

    func_800FF384(arg0 + 0x1D4, arg0 + 0x24);
    M2C_FIELD(arg0, s16 *, 0x1DA) = (s16) (s32) (M2C_FIELD(arg0, f32 *, 0x1DC) * (f32) M2C_FIELD(arg0, s16 *, 0x1D2));
    if (!(M2C_FIELD(arg0, u16 *, 0x410) & 0x10) && (M2C_FIELD(arg0, u8 *, 0xB7) != 0)) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x458);
        if (temp_v0 == 0) {
            var_v1 = 0;
        } else {
            M2C_FIELD(arg0, s16 *, 0x458) = (s16) (temp_v0 - 1);
            var_v1 = M2C_FIELD(arg0, s16 *, 0x458);
        }
        if (var_v1 < 0xB) {
            func_800E2500(arg1, arg1 + 0x18884, arg0 + 0x18C);
        }
    }
    if (!(M2C_FIELD(arg0, u16 *, 0x410) & 0x10) && (M2C_FIELD(arg0, u8 *, 0xB7) != 0)) {
        func_800E2318(arg1, arg1 + 0x18884, arg0 + 0x18C);
    }
    if (M2C_FIELD(arg0, u16 *, 0x410) & 4) {
        func_800E26E8(arg1, arg1 + 0x18884, arg0 + 0x18C);
    }
}
