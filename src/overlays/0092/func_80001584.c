#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0092.h"

M2C_UNK func_800FEC70(u8 *, M2C_UNK, M2C_UNK);    /* extern */
s16 func_800FF860(u8 *, s32);                     /* extern */
M2C_UNK func_800FFCBC(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800FFDD8(u8 *, s16, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_808B0C98(u8 *);                      /* extern */
M2C_UNK func_808B2060(u8 *);                      /* extern */

void func_80001584(u8 *arg0, u8 *arg1) {
    s32 temp_v1;
    s32 sp2C;
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x18E);
    temp_v1 = M2C_FIELD(arg1, s32 *, 0x1CCC);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x18E) = (s16) (temp_v0 - 1);
    }
    sp2C = temp_v1;
    func_800FFCBC(arg0 + 0xBC, 0x1800, 2, 0xE38, 0x71C);
    func_800FFDD8(arg0 + 0xBE, func_800FF860(arg0 + 8, temp_v1 + 0x24), 2, 0xE38);
    func_800FEC70(arg0 + 0x192, 0xAAA, 0x444);
    func_800FEC70(arg0 + 0x194, -0x4718, 0x888);
    func_800FEC70(arg0 + 0x196, -0x6AA4, 0x888);
    if (M2C_FIELD(arg0, s16 *, 0x18E) == 0) {
        func_808B2060(arg0);
    }
    func_808B0C98(arg0);
}
