#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0125.h"

M2C_UNK func_800FF30C(s32, s32, u8 *, u8 *);    /* extern */
extern f32 D_808EFBE8;
extern f32 D_808EFBEC;

void func_80001B48(u8 *arg0, u8 *arg1) {
    M2C_FIELD(arg1, s8 *, 0x170C7) = 3;
    func_800FF30C(arg0 + 0x2EC, arg0 + 0x24, arg0, arg1);
    M2C_FIELD(arg0, f32 *, 0x2F0) = (f32) D_808EFBE8;
    M2C_FIELD(arg0, u8 *, 0x2B4) = 0xEB;
    M2C_FIELD(arg0, f32 *, 0x628) = (f32) D_808EFBEC;
}
