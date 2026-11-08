// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0184.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
s32 func_8094D8C0(u8 *, s32);                     /* extern */
M2C_UNK func_8094EB70(u8 *, s32);                 /* extern */
extern M2C_UNK D_8094E894;

void func_80001954(Actor *thisx, s32 arg1) {
    func_80137070((u8 *)thisx + 0x144);
    if (func_800B8254(thisx, arg1) != 0) {
        M2C_FIELD(thisx, M2C_UNK **, 0x2C4) = &D_8094E894;
        func_8094EB70(thisx, arg1);
        return;
    }
    if (func_8094D8C0(thisx, arg1) != 0) {
        func_800B8398(thisx, arg1, 0x42F00000);
    }
}
