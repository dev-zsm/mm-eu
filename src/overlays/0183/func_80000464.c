// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0183.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_8094C810(u8 *, s32, M2C_UNK);        /* extern */
extern M2C_UNK D_8094C8BC;

void func_80000464(Actor *thisx, s32 arg1) {
    func_80137070((u8 *)thisx + 0x1DC);
    if (func_800B8254(thisx, arg1) != 0) {
        M2C_FIELD(thisx, M2C_UNK **, 0x2FC) = &D_8094C8BC;
        return;
    }
    func_8094C810(thisx, arg1, 0x6DE);
}
