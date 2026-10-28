// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80136480(s32, s32);                    /* extern */
M2C_UNK func_8013692C(s32, s32, M2C_UNK *);         /* extern */
M2C_UNK func_8082EAEC(s32, s32, M2C_UNK *);         /* extern */
M2C_UNK func_808306C0(s32, s32);                    /* extern */
extern M2C_UNK D_400E398;
extern M2C_UNK D_80848A30;
extern s32 D_8086226C;

s32 func_8001B878(s32 arg0, s32 arg1) {
    s32 sp1C;
    s32 temp_a1;

    temp_a1 = arg0 + 0x284;
    sp1C = temp_a1;
    func_80136480(arg1, temp_a1);
    func_808306C0(arg0, arg1);
    if (D_8086226C == 0) {
        func_8082EAEC(arg1, arg0, &D_80848A30);
        func_8013692C(arg1, sp1C, &D_400E398);
    }
    return 1;
}
