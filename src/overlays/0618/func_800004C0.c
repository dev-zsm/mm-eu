// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BDD44(s32, M2C_UNK *);              /* extern */
M2C_UNK func_80BEAFA8(u8 *, s32);                 /* extern */
extern M2C_UNK D_6000A00;
extern M2C_UNK D_6000D78;

void func_800004C0(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x14A) != 1) {
        func_800BDD44(arg1, &D_6000A00);
        func_800BDD44(arg1, &D_6000D78);
    }
    func_80BEAFA8(arg0, arg1);
}
