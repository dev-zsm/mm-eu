#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BBB30(u8 *, u8 *, u8 *, f32, s32, f32, s32, s32, s32); /* extern */
M2C_UNK func_800FFBF8(u8 *, f32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80954540(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80956778(u8 *);                      /* extern */

void func_8000235C(u8 *arg0, u8 *arg1) {
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (M2C_FIELD(arg0, s16 *, 0xBE) + 0x3000);
    if (M2C_FIELD(arg0, s32 *, 0x1A0) != 1) {
        func_80954540(arg0, 1);
    }
    if (M2C_FIELD(arg0, f32 *, 0xC4) < -10.0f) {
        if (!(M2C_FIELD(arg1, s32 *, 0x18840) & 7)) {
            func_800BBB30(arg1, arg0, arg0 + 0x24, M2C_FIELD(arg0, f32 *, 0xCC) - 20.0f, 0xA, 8.0f, 0x1F4, 0xA, 1);
            func_800B8C4C(arg0, 0x3987);
        }
        func_800FFBF8(arg0 + 0xC4, 0, 0x3F000000, 0x43480000);
        return;
    }
    func_80956778(arg0);
}
