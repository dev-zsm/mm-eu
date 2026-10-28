// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8012C73C(u8 *);                      /* extern */
M2C_UNK func_8012C78C(u8 *);                      /* extern */
s32 func_80134D30(u8 **, s32, s32, M2C_UNK *, s32, u8 *, s32); /* extern */
M2C_UNK func_808A4BD0(u8 *, u8 **);             /* extern */
s32 func_808A50A8(u8 *, u8 **, s32);            /* extern */
s32 func_808A615C(u8 *);                          /* extern */
extern M2C_UNK D_808A6B08;

void func_80002428(u8 *arg0, u8 **arg1) {
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;
    u8 *temp_s0;

    if (!(M2C_FIELD(arg0, u16 *, 0x18C) & 0x20)) {
        temp_s0 = *arg1;
        if (func_808A615C(arg0) != 0) {
            func_8012C78C(*arg1);
            M2C_FIELD(temp_s0, s32 *, 0x2C0) = func_80134D30(arg1, M2C_FIELD(arg0, s32 *, 0x148), M2C_FIELD(arg0, s32 *, 0x164), &D_808A6B08, 0, arg0, M2C_FIELD(temp_s0, s32 *, 0x2C0));
        } else {
            func_8012C73C(*arg1);
            M2C_FIELD(temp_s0, s32 *, 0x2B0) = func_80134D30(arg1, M2C_FIELD(arg0, s32 *, 0x148), M2C_FIELD(arg0, s32 *, 0x164), &D_808A6B08, 0, arg0, M2C_FIELD(temp_s0, s32 *, 0x2B0));
        }
    }
    var_s0 = 0;
    var_s1 = 0;
    do {
        temp_v0 = func_808A50A8(arg0, arg1, var_s0);
        var_s0 += 1;
        var_s1 += temp_v0;
    } while (var_s0 != 0xC);
    if (var_s1 != 0) {
        M2C_FIELD(arg0, s16 *, 0x31A) = (s16) (M2C_FIELD(arg0, s16 *, 0x31A) + 2);
    }
    func_808A4BD0(arg0, arg1);
}
