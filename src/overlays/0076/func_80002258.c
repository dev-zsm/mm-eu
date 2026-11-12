#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0076.h"

M2C_UNK func_800FEE3C(s32, f32, M2C_UNK, u8 *); /* extern */
s32 func_80137070(u8 *);                          /* extern */
M2C_UNK func_8089A0D0(u8 *, s32);                 /* extern */
M2C_UNK func_8089C134(u8 *);                      /* extern */
M2C_UNK func_8089C6CC(u8 *);                      /* extern */
M2C_UNK func_8089CA00(u8 *);                      /* extern */

void func_80002258(u8 *arg0, s32 arg1) {
    func_800FEE3C(arg0 + 0x70, 0, 0x3F000000, arg0);
    if ((func_80137070(arg0 + 0x144) != 0) && (M2C_FIELD(arg0, u16 *, 0x90) & 1)) {
        if (M2C_FIELD(arg0, u8 *, 0xB7) == 0) {
            if (M2C_FIELD(arg0, s8 *, 0x38) == -1) {
                func_8089C6CC(arg0);
                return;
            }
            func_8089CA00(arg0);
            return;
        }
        if (M2C_FIELD(arg0, f32 *, 0x98) < 280.0f) {
            func_8089C134(arg0);
            return;
        }
        M2C_FIELD(arg0, u8 *, 0x375) = (u8) (M2C_FIELD(arg0, u8 *, 0x375) | 1);
        func_8089A0D0(arg0, arg1);
    }
}
