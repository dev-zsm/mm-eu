// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(s32);                         /* extern */
M2C_UNK func_8094FB90(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_8094FBF4;

void func_8000001C(s32 arg0, u8 *arg1) {
    if (M2C_FIELD(arg1, u8 *, 0x170F7) != 0) {
        func_800B6490(arg0);
    }
    func_8094FB90(arg0, &D_8094FBF4);
}
