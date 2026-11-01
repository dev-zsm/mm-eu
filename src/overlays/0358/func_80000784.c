// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80181508(s16, M2C_UNK);                /* extern */
M2C_UNK func_80181A3C(s16, M2C_UNK);                /* extern */
M2C_UNK func_80181D88(s16, M2C_UNK);                /* extern */
M2C_UNK func_80182B28(M2C_UNK *, u8 *);           /* extern */
extern M2C_UNK D_80A50700;
extern M2C_UNK D_80A5070C;
extern M2C_UNK D_80A50718;

void func_80000784(u8 *arg0) {
    func_80181A3C(M2C_FIELD(arg0, s16 *, 0xBE), 0);
    func_80181508(M2C_FIELD(arg0, s16 *, 0xBC), 1);
    func_80181D88(M2C_FIELD(arg0, s16 *, 0xC0), 1);
    func_80182B28(&D_80A50700, arg0 + 0x310);
    func_80182B28(&D_80A5070C, arg0 + 0x31C);
    func_80182B28(&D_80A50718, arg0 + 0x328);
}
