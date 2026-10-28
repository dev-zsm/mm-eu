// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800BC370(s32, u8 *);                     /* extern */
M2C_UNK func_800FEC70(s32, s16, M2C_UNK);           /* extern */
s32 func_80137070(u8 *);                          /* extern */
M2C_UNK func_80975F40(u8 *);                      /* extern */
M2C_UNK func_80976944(u8 *);                      /* extern */

void func_80002474(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    func_800FEC70(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 0x9C4);
    if ((func_80137070(arg0 + 0x144) != 0) && (M2C_FIELD(arg0, u16 *, 0x90) & 3)) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x92);
        M2C_FIELD(arg0, s16 *, 0xBC) = 0;
        M2C_FIELD(arg0, s16 *, 0x32) = temp_v0;
        M2C_FIELD(arg0, s16 *, 0xBE) = temp_v0;
        M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x28) = (f32) M2C_FIELD(arg0, f32 *, 0x88);
        if (func_800BC370(arg1, arg0) == 0) {
            func_80976944(arg0);
            return;
        }
        func_80975F40(arg0);
    }
}
