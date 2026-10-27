// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80091460(s32, s32 *, M2C_UNK);         /* extern */
M2C_UNK func_80162B08(s32, M2C_UNK *);              /* extern */
s32 func_8016B2F0();                                /* extern */
extern M2C_UNK D_801EC5C8;

s32 CutsceneCmd_UpdateCamSpline(s32 arg0, s32 arg1) {
    s32 sp1C;

    sp1C = 0;
    func_80091460(arg1, &sp1C, 4);
    arg1 += 4;
    if (func_8016B2F0() == 0) {
        func_80162B08(arg1, &D_801EC5C8);
    }
    return sp1C + 4;
}
