#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082D1C8(s32, u8 *, s32);            /* extern */
s32 func_80830A58(s32, u8 *, s32);                /* extern */
M2C_UNK func_80830B44(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_8083CDD0(u8 *, s32);                 /* extern */
s32 func_8083CE2C(u8 *, s32);                     /* extern */
extern M2C_UNK D_8084DC80;
extern u32 D_8085B82C[];
extern u8 *D_80862264;

s32 func_8000FD40(u8 *arg0, s32 arg1) {
    s32 temp_a2;
    s32 var_v0;

    var_v0 = 0;
    if (M2C_FIELD(arg0, s32 *, 0xA6C) & 0x800) {
        temp_a2 = M2C_FIELD(arg0, s32 *, 0x34C);
        if ((temp_a2 != 0) && (M2C_FIELD(D_80862264, u16 *, 0xC) & 0xC007)) {
            if (func_80830A58(arg1, arg0, temp_a2) == 0) {
                if (func_8083CE2C(arg0, M2C_FIELD(arg0, s32 *, 0x34C)) == 0) {
                    func_80830B44(arg1, arg0, &D_8084DC80, 1);
                    func_8082D1C8(arg1, arg0, D_8085B82C[M2C_FIELD(arg0, u8 *, 0x14F)]);
                    return 1;
                }
                func_8083CDD0(arg0, arg1);
                goto block_7;
            }
            block_7:
            var_v0 = 1;
            /* Duplicate return node #8. Try simplifying control flow for better match */
            return var_v0;
        }
    }
    return var_v0;
}
