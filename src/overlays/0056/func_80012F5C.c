#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

M2C_UNK func_800B8BDC(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_8082D63C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_8083007C(s32, u8 *, u8 *);         /* extern */
s32 func_80830A58(s32, u8 *, u8 *);             /* extern */

void func_80012F5C(s32 arg0, u8 *arg1, f32 arg2, f32 arg3) {
    u8 *temp_a2;

    temp_a2 = M2C_FIELD(arg1, u8 **, 0x34C);
    if (func_80830A58(arg0, arg1, temp_a2) == 0) {
        M2C_FIELD(temp_a2, s16 *, 0x32) = (s16) M2C_FIELD(arg1, s16 *, 0xBE);
        M2C_FIELD(temp_a2, f32 *, 0x70) = arg2;
        M2C_FIELD(temp_a2, f32 *, 0x68) = arg3;
        func_8083007C(arg0, arg1, temp_a2);
        func_800B8BDC(arg1, 0x83A);
        func_8082D63C(arg1, 0x6800);
    }
}
