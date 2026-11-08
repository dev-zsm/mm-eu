// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0493.h"

M2C_UNK func_8013E578(s32, M2C_UNK *, M2C_UNK, s32); /* extern */
M2C_UNK func_8013E768(u8 *, s32, M2C_UNK);        /* extern */
extern M2C_UNK D_80B40B34;
extern M2C_UNK D_80B430FC;

void func_80000AC8(Actor *thisx, s32 arg1) {
    func_8013E578((u8 *)thisx + 0x148, &D_80B430FC, 1, (u8 *)thisx + 0x2BC);
    func_8013E768(thisx, (u8 *)thisx + 0x356, 4);
    M2C_FIELD(thisx, M2C_UNK **, 0x144) = &D_80B40B34;
}
