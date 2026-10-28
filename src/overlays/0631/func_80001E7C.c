// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BF550(s32, u8 *, u8 *, M2C_UNK, s32, f32, f32); /* extern */
M2C_UNK func_80BF00BC(s32, u8 *, u8 *);         /* extern */
M2C_UNK func_80BF160C(u8 *);                      /* extern */
M2C_UNK func_80BF17C8(u8 *, s32);                 /* extern */
extern f32 D_80BF48A4;
extern f32 D_80BF48A8;

void func_80001E7C(u8 *arg0, s32 arg1) {
    f32 sp34;
    s16 temp_v0;

    sp34 = M2C_FIELD(arg0, f32 *, 0x15C);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x324);
    if (((temp_v0 == 0xB) || (temp_v0 == 0xA)) && (M2C_FIELD(arg0, s16 *, 0x322) != 0)) {
        func_800BF550(arg1, arg0, arg0 + 0x330, 0x11, 2, M2C_FIELD(arg0, f32 *, 0x32C), D_80BF48A4);
        M2C_FIELD(arg0, s16 *, 0x322) = 0;
        M2C_FIELD(arg0, s16 *, 0x324) = 0;
    }
    func_80BF00BC(arg1, arg0, arg0 + 0x304);
    func_80BF00BC(arg1, arg0, arg0 + 0x2F8);
    if (M2C_FIELD(arg0, f32 *, 0x2C4) <= sp34) {
        if ((D_80BF48A8 < M2C_FIELD(arg0, f32 *, 0x2C)) || ((s32) M2C_FIELD(arg0, u8 *, 0xB7) < 0xA)) {
            func_80BF17C8(arg0, arg1);
            return;
        }
        func_80BF160C(arg0);
    }
}
