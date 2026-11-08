// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0546.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
s32 func_8012FA08(s32, s32);                        /* extern */
M2C_UNK func_80B969BC(u8 *);                      /* extern */
M2C_UNK func_80B96DC0(u8 *, s32);                 /* extern */
extern M2C_UNK D_80B96FBC;

void func_80000AAC(Actor *thisx, s32 arg1) {
    if (func_8012FA08(arg1 + 0x17D88, M2C_FIELD(thisx, s32 *, 0x248)) != 0) {
        M2C_FIELD(thisx, s32 *, 0x4AC) = 5;
        func_80B96DC0(thisx, arg1);
        func_800B6564(thisx, 0x3C23D70A);
        M2C_FIELD(thisx, s16 *, 0x230) = 0;
        M2C_FIELD(thisx, f32 *, 0xCC) = 20.0f;
        M2C_FIELD(thisx, f32 *, 0x74) = -1.0f;
        func_80B969BC(thisx);
        M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_80B96FBC;
        M2C_FIELD(thisx, s8 *, 0x1F) = 3;
    }
}
