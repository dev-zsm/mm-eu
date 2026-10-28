// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082DCE4(s32, s32, M2C_UNK *);         /* extern */
M2C_UNK func_80830B44(s32, s32, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_400DFD0;
extern M2C_UNK D_80850C7C;

void func_8001A5FC(s32 arg0, s32 arg1) {
    func_80830B44(arg0, arg1, &D_80850C7C, 0);
    func_8082DCE4(arg0, arg1, &D_400DFD0);
}
