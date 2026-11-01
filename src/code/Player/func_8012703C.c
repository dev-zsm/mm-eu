// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80126B4C(s32, s32, s32, M2C_UNK *);    /* extern */
M2C_UNK func_80126F64(s32, s32 *);                  /* extern */
extern M2C_UNK D_801C1630;

void func_8012703C(s32 arg0, s32 arg1) {
    s32 sp1C;

    func_80126F64(arg1, &sp1C);
    func_80126B4C(arg0, arg1, sp1C, &D_801C1630);
}
