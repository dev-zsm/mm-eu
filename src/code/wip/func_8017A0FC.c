// FLAGS: -O2 -g3 -mips2
// STATUS: automatic draft, 12/43 instructions differ
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800807E0(s32, u32 *, M2C_UNK);         /* extern */
s32 func_800809A0();                                /* extern */
M2C_UNK func_8017A02C(s32, u32, s32, M2C_UNK);      /* extern */
extern s32 D_8009BDE0;
extern u32 D_801F3460;

void CmpDma_LoadAllFiles(s32 arg1, M2C_UNK arg2) {
    s32 temp_v0;
    s32 var_s1;
    u32 temp_s3;
    u32 var_s0;

    temp_v0 = func_800809A0();
    func_800807E0(temp_v0, &D_801F3460, 4);
    var_s1 = arg1;
    temp_s3 = ((u32) D_801F3460 >> 2) - 1;
    var_s0 = 0;
    if (temp_s3 != 0) {
        do {
            func_8017A02C(temp_v0, var_s0, var_s1, 0);
            var_s0 += 1;
            var_s1 = D_8009BDE0;
        } while (var_s0 < temp_s3);
    }
}
