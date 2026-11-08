// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0611.h"

s32 func_800B8254(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_800B8398(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80BE0784(M2C_UNK, u8 *, M2C_UNK);    /* extern */
M2C_UNK func_80BE07F0(u8 *, M2C_UNK);             /* extern */
s32 func_80BE08E4(u8 *);                          /* extern */
s32 func_80BE0A18(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_80BE0AF4(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BE0B9C(M2C_UNK);                     /* extern */
M2C_UNK func_80BE164C(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80BE14C8;

void func_80001478(Actor *thisx, s32 arg1) {
    s32 temp_v0;

    func_80BE0AF4(thisx, arg1);
    M2C_FIELD(thisx, f32 *, 0x70) = 1.5f;
    temp_v0 = func_80BE08E4(thisx);
    if (temp_v0 != 1) {
        if (temp_v0 == 2) {
            func_80BE07F0(thisx, arg1);
            func_80BE164C(thisx, arg1);
        }
    } else {
        func_80BE164C(thisx, arg1);
    }
    if (func_800B8254(thisx, arg1) != 0) {
        M2C_FIELD(thisx, M2C_UNK **, 0x430) = &D_80BE14C8;
        func_80BE0784(arg1, thisx, 0);
        M2C_FIELD(thisx, f32 *, 0x70) = 0.0f;
        func_80BE0B9C(arg1);
        return;
    }
    if (func_80BE0A18(thisx, arg1) != 0) {
        func_800B8398(thisx, arg1, 0x42F00000);
    }
}
