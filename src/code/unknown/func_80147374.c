// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 THA_AllocTailAlign16(s32, M2C_UNK, void *, s32);       /* extern */
extern u8 D_801EAE2F;

void func_80147374(s32 arg0, void *arg1) {
    if (D_801EAE2F != 0) {
        M2C_FIELD(arg1, s32 *, 4) = THA_AllocTailAlign16(arg0 + 0x74, 0x4000, arg1, arg0);
        M2C_FIELD(arg1, s16 *, 0xC) = 0;
    }
}
