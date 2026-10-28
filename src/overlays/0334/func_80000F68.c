// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490();                            /* extern */
extern s32 D_80A30F20;

void func_80000F68(u8 *arg0, M2C_UNK arg1) {
    u8 *temp_v0;

    if (M2C_FIELD(arg0, s16 *, 0x16A) == 0) {
        M2C_FIELD(arg0, s16 *, 0x16A) = 2;
        M2C_FIELD(arg0, s16 *, 0x16E) = (s16) (M2C_FIELD(arg0, s16 *, 0x16E) + 1);
        if (M2C_FIELD(arg0, s16 *, 0x16E) >= 6) {
            temp_v0 = M2C_FIELD(arg0, u8 **, 0x120);
            if ((temp_v0 != NULL) && (M2C_FIELD(arg0, s16 *, 0x162) == 0) && (M2C_FIELD(temp_v0, s16 *, 0) == 0x15D)) {
                D_80A30F20 = 0;
                if (M2C_FIELD(temp_v0, s32 *, 0x138) != 0) {
                    M2C_FIELD(temp_v0, s16 *, 0x3BA) = 0;
                }
            }
            func_800B6490();
        }
    }
}
