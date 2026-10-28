// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF32C(u8 *, u8 *);              /* extern */
M2C_UNK func_800FF3BC(u8 *, M2C_UNK *, u8 *);   /* extern */
M2C_UNK func_80181A3C(s16, M2C_UNK);                /* extern */
M2C_UNK func_80182B28(M2C_UNK *, M2C_UNK *);        /* extern */
extern M2C_UNK D_80A4AFD8;
extern M2C_UNK D_80A4B25C;

void func_80000088(u8 *arg0, M2C_UNK arg1) {
    s32 pad[2];
    M2C_UNK sp24;

    M2C_FIELD(arg0, s16 *, 0x116) = 0;
    func_80181A3C(M2C_FIELD(arg0, s16 *, 0xBE), 0);
    func_80182B28(&D_80A4B25C, &sp24);
    func_800FF3BC(arg0 + 0x24, &sp24, arg0 + 0x3C);
    func_800FF32C(arg0 + 0x48, arg0 + 0xBC);
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80A4AFD8;
}
