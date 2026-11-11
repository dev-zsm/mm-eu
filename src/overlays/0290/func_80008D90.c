#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0290.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FFDD8(u8 *, s16, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
s32 func_80137C58(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_809D99EC(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_809D9A84(u8 *, u8 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_809E285C(u8 *, u8 *);              /* extern */

void func_80008D90(u8 *arg0, u8 *arg1) {
    u8 *sp24;
    s32 temp_v0;

    sp24 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    temp_v0 = M2C_FIELD(arg0, u8 *, 0x14E);
    if ((s32) temp_v0 < 2) {
        func_800B8C4C(arg0, 0x31DC);
    } else if ((temp_v0 == 2) && (func_80137C58(arg0 + 0x190, 0x40A00000) != 0)) {
        func_800B8C4C(arg0, 0x39DD);
    }
    func_80137070(arg0 + 0x190);
    func_809D99EC(arg0, 0x40000000);
    func_800FFDD8(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x92), 5, 0x2000);
    if ((M2C_FIELD(arg0, s16 *, 0x150) == 0) || (M2C_FIELD(sp24, u8 *, 0xD57) == 4) || (M2C_FIELD(arg0, f32 *, 0x98) <= 300.0f)) {
        func_809E285C(arg0, arg1);
        func_800B8C4C(arg0, 0x3A6B);
    }
    func_809D9A84(arg0, arg1, 1, 0);
}
