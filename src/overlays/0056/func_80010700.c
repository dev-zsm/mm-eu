// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800C5FD8(s32, u8);                         /* extern */
M2C_UNK func_8082D1C8(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_808360A4(u8 *, s32);                 /* extern */
extern M2C_UNK D_400DE08;
extern u16 *D_80862264;

s32 func_80010700(s32 arg0, u8 *arg1) {
    s32 var_v1;
    u8 temp_a1;

    if ((M2C_FIELD(arg1, u16 *, 0x90) & 0x200) && ((M2C_FIELD(arg1, s32 *, 0xA70) & 0x10) || (~(*D_80862264 | 0xFFFF7FFF) == 0))) {
        temp_a1 = M2C_FIELD(arg1, u8 *, 0x84);
        var_v1 = 0;
        if (temp_a1 != 0x32) {
            var_v1 = func_800C5FD8(arg0 + 0x830, temp_a1);
        }
        if (var_v1 == M2C_FIELD(arg1, s32 *, 0x364)) {
            if (M2C_FIELD(arg1, s32 *, 0xA70) & 0x10) {
                return 1;
            }
            return 0;
        }
        goto block_9;
    }
block_9:
    func_808360A4(arg1, arg0);
    func_8082D1C8(arg0, arg1, &D_400DE08);
    M2C_FIELD(arg1, s32 *, 0xA70) = (s32) (M2C_FIELD(arg1, s32 *, 0xA70) & ~0x10);
    return 1;
}
