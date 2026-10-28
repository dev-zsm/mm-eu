// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8017B8A8(f32, f32);                        /* extern */
M2C_UNK func_809740A4(u8 *, s32);                 /* extern */
M2C_UNK func_80974178(u8 *, s32);                 /* extern */
M2C_UNK func_80974310(u8 *);                      /* extern */
extern f32 D_809744A4;

void func_80000640(u8 *arg0, s32 arg1) {
    func_80974178(arg0, arg1);
    if (D_809744A4 <= func_8017B8A8(M2C_FIELD(arg0, f32 *, 0xEC), M2C_FIELD(arg0, f32 *, 0xF4))) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~0x10);
        func_809740A4(arg0, arg1);
        func_80974310(arg0);
    }
}
