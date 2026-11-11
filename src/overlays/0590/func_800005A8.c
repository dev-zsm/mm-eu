#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */

void func_800005A8(s32 arg0) {
    s16 var_s0;
    u8 *temp_a0;

    var_s0 = 0;
    do {
        temp_a0 = M2C_FIELD(((u8 *)((s32)arg0 + (var_s0 * 4))), u8 **, 0x144);
        if ((temp_a0 != NULL) && (M2C_FIELD(temp_a0, s16 *, 0x152) == 0)) {
            func_800B6490(temp_a0);
        }
        var_s0 += 1;
    } while (var_s0 < 0x14);
}
