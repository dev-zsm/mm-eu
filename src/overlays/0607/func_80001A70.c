// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B763C(M2C_UNK, u8 *, M2C_UNK, M2C_UNK, f32, s32); /* extern */
M2C_UNK func_800FF30C(u8 *, u8 *);              /* extern */
s32 func_8016A23C(M2C_UNK);                         /* extern */
M2C_UNK func_80BD8A04(u8 *);                      /* extern */
M2C_UNK func_80BD8C74(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BD8CB4(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BD8D98(u8 *);                      /* extern */
M2C_UNK func_80BD8DC4(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BD8E94(u8 *);                      /* extern */

void func_80001A70(u8 *arg0, M2C_UNK arg1) {
    func_80BD8CB4(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, M2C_UNK), 0x188)(arg0, arg1);
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
    if (!(M2C_FIELD(arg0, u16 *, 0x310) & 0x10)) {
        func_80BD8E94(arg0);
        func_80BD8D98(arg0);
        func_80BD8DC4(arg0, arg1);
    }
    func_800B763C(arg1, arg0, 0x41F00000, 0x41A00000, 0.0f, 0x1D);
    if (M2C_FIELD(arg0, f32 *, 0x88) <= -32000.0f) {
        func_800FF30C(arg0 + 0x24, arg0 + 0x108);
    }
    func_80BD8C74(arg0, arg1);
    if (func_8016A23C(arg1) == 0) {
        func_80BD8A04(arg0);
    }
}
