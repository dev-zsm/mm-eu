// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BDD44(s32, M2C_UNK *);              /* extern */
M2C_UNK func_8018132C(f32, f32, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK func_80181508(s16, M2C_UNK);                /* extern */
extern M2C_UNK D_6000710;
extern M2C_UNK D_6000958;
extern f32 D_80BD0658;
extern f32 D_80BD065C;

void func_800002D4(u8 *arg0, s32 arg1) {
    func_800BDD44(arg1, &D_6000710);
    func_8018132C(D_80BD0658, D_80BD065C, 0x41100000, 1);
    func_80181508(M2C_FIELD(arg0, s16 *, 0x14), 1);
    func_800BDD44(arg1, &D_6000958);
}
