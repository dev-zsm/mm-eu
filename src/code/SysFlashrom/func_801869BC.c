// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8008A780(s32, s32);                    /* extern */
s32 SysFlashrom_IsInit();                                /* extern */
s32 SysFlashrom_EraseSector(M2C_UNK);                         /* extern */
s32 SysFlashrom_ExecWrite(s32, M2C_UNK, s32);               /* extern */

s32 SysFlashrom_AttemptWrite(s32 arg0, M2C_UNK arg1, s32 arg2) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;

    if (SysFlashrom_IsInit() == 0) {
        return -1;
    }
    func_8008A780(arg0, arg2 << 7);
    var_s0 = 0;
loop_3:
    temp_v0_2 = SysFlashrom_EraseSector(arg1);
    if (temp_v0_2 != 0) {
        if (var_s0 < 3) {
            var_s0 += 1;
            goto loop_3;
        }
        return temp_v0_2;
    }
    temp_v0 = SysFlashrom_ExecWrite(arg0, arg1, arg2);
    if (temp_v0 != 0) {
        if (var_s0 < 3) {
            var_s0 += 1;
            goto loop_3;
        }
        return temp_v0;
    }
    return 0;
}
