// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0283.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_809B4578(s32, M2C_UNK, M2C_UNK, u8 *); /* extern */
extern u8 D_801E7EFD;

void func_80000A48(Actor *thisx, s32 arg1) {
    s16 temp_v0;
    s16 var_v1;

    temp_v0 = M2C_FIELD(thisx, s16 *, 0x15A);
    if (temp_v0 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(thisx, s16 *, 0x15A) = (s16) (temp_v0 - 1);
        var_v1 = M2C_FIELD(thisx, s16 *, 0x15A);
    }
    if (var_v1 == 0) {
        if (D_801E7EFD & 2) {
            func_809B4578(arg1, 3, 3, thisx);
        } else {
            func_809B4578(arg1, 2, 2, thisx);
        }
        func_800B6490(thisx);
    }
}
