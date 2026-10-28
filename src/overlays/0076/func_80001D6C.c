// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
s32 func_80137070(s32);                             /* extern */
s32 func_8089A088(u8 *);                          /* extern */
M2C_UNK func_8089A0D0(u8 *, s32);                 /* extern */
M2C_UNK func_8089C134(u8 *);                      /* extern */
extern f32 D_8089DB34;

void func_80001D6C(u8 *arg0, s32 arg1) {
    if (func_80137070(arg0 + 0x144) != 0) {
        if ((M2C_FIELD(arg0, s16 *, 0x290) == 1) && (M2C_FIELD(arg0, f32 *, 0x98) < 280.0f) && (func_8089A088(arg0) != 0) && (func_8008704C() < D_8089DB34)) {
            func_8089C134(arg0);
            return;
        }
        func_8089A0D0(arg0, arg1);
    }
}
