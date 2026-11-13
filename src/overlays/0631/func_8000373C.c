#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0631.h"

M2C_UNK func_800B5B64(s32, s16);                    /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800EDCC4(u8 *, s32, s32);            /* extern */
s32 func_800EDFA0(s32, M2C_UNK);                    /* extern */
s32 func_800EE03C(s32, M2C_UNK);                    /* extern */
M2C_UNK func_80BF0030(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BF2F18(u8 *);                      /* extern */
extern M2C_UNK D_801E6EF0;

s32 func_8000373C(u8 *arg0, s32 arg1) {
    u32 sp24;
    u32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    u16 temp_t9;

    if (func_800EE03C(arg1, 0x214) != 0) {
        temp_v0 = func_800EDFA0(arg1, 0x214);
        sp24 = temp_v0;
        if (M2C_FIELD(arg0, s16 *, 0x296) != *M2C_FIELD((arg1 + (temp_v0 * 4)), u16 **, 0x1F4C)) {
            if (M2C_FIELD(arg0, s16 *, 0x2B4) != 0xE) {
                func_80BF2F18(arg0);
            }
            switch ((*M2C_FIELD((arg1 + (sp24 * 4)), u16 **, 0x1F4C))) {
                case 1:
                    func_80BF0030(arg0, 0xD);
                    break;
                case 2:
                    temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x2D8);
                    if ((temp_v0_2 != 0xE) && (temp_v0_2 != 0xF)) {
                    func_80BF0030(arg0, 0xE);
                    }
                    break;
                case 3:
                    temp_v0_3 = M2C_FIELD(arg0, s32 *, 0x2D8);
                    if ((temp_v0_3 != 0x10) && (temp_v0_3 != 0x11)) {
                    func_80BF0030(arg0, 0x10);
                    }
                    break;
                case 4:
                    temp_v0_4 = M2C_FIELD(arg0, s32 *, 0x2D8);
                    if ((temp_v0_4 != 0x12) && (temp_v0_4 != 0x13)) {
                    func_80BF0030(arg0, 0x12);
                    }
                    break;
                case 5:
                    M2C_FIELD(&D_801E6EF0, u8 *, 0xF0F) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF0F) | 4);
                    func_800B8C4C(arg0, 0x3AA9);
                    break;
                case 6:
                    func_800B5B64(arg1, M2C_FIELD(arg0, s16 *, 0x2BA));
                    func_800B8C4C(arg0, 0x4823);
                    break;
            }
        }
        M2C_FIELD(arg0, s16 *, 0x296) = (s16) *M2C_FIELD((arg1 + (sp24 * 4)), u16 **, 0x1F4C);
        func_800EDCC4(arg0, arg1, sp24);
        return 1;
    }
    return 0;
}
