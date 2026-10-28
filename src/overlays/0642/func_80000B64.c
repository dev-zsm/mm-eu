// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6580(s32, u8 *);                 /* extern */
s32 func_8012FA08(s32, s32);                        /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_801378E0(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_6013928;
extern M2C_UNK D_6016588;
extern M2C_UNK D_80BFE854;

void func_80000B64(u8 *arg0, s32 arg1) {
    u8 *sp34;
    u8 *temp_a1;

    if (func_8012FA08(arg1 + 0x17D88, M2C_FIELD(arg0, s32 *, 0x160)) != 0) {
        M2C_FIELD(arg0, s8 *, 0x1E) = (s8) M2C_FIELD(arg0, s32 *, 0x160);
        func_800B6580(arg1, arg0);
        M2C_FIELD(arg0, s32 *, 0x164) = (s32) (M2C_FIELD(arg0, s32 *, 0x164) | 1);
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80BFE854;
        temp_a1 = arg0 + 0x170;
        sp34 = temp_a1;
        func_80136ED0(arg1, temp_a1, &D_6013928, &D_6016588, arg0 + 0x1B4, arg0 + 0x23E, 0x17);
        func_801378E0(sp34, &D_6016588);
    }
}
