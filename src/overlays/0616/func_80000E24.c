// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0616.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK D_80BE9168;

void func_80000E24(Actor *thisx, s32 arg1) {
    func_800FFCBC((u8 *)thisx + 0x288, M2C_FIELD(thisx, s16 *, 0x28E), 1, 0x3E8, 0);
    if (func_800B8254(thisx, arg1) != 0) {
        M2C_FIELD(thisx, s16 *, 0x28E) = 0;
        M2C_FIELD(thisx, M2C_UNK **, 0x284) = &D_80BE9168;
        return;
    }
    func_800B8398(thisx, arg1, 0x428C0000);
}
