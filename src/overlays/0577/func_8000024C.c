// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF3BC(u8 *, M2C_UNK *, u8 *);   /* extern */
M2C_UNK func_80181508(s16, M2C_UNK);                /* extern */
M2C_UNK func_80181A3C(s16, M2C_UNK);                /* extern */
M2C_UNK func_80181D88(s16, M2C_UNK);                /* extern */
M2C_UNK func_80182B28(M2C_UNK *, M2C_UNK *);        /* extern */
extern M2C_UNK D_80BBB644;

void func_8000024C(u8 *arg0) {
    s32 pad[4];
    M2C_UNK sp24;

    M2C_FIELD(arg0, M2C_UNK (**)(u8 *), 0x15C)(arg0);
    func_80181A3C(M2C_FIELD(arg0, s16 *, 0x32), 0);
    func_80181508(M2C_FIELD(arg0, s16 *, 0x30), 1);
    func_80181D88(M2C_FIELD(arg0, s16 *, 0x34), 1);
    func_80182B28(&D_80BBB644, &sp24);
    func_800FF3BC(arg0 + 0x24, &sp24, arg0 + 0x3C);
}
