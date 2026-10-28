// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013C01C(u8 *, M2C_UNK *, s16, u8 *); /* extern */
extern M2C_UNK D_80B59170;
extern M2C_UNK D_80B5A5A8;

void func_80000D38(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x39E) != 1) {
        M2C_FIELD(arg0, s16 *, 0x39E) = 1;
        M2C_FIELD(arg0, s16 *, 0x3A2) = 0x3E8;
        func_8013C01C(arg0 + 0x198, &D_80B5A5A8, M2C_FIELD(arg0, s16 *, 0x39E), arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x1DC) = &D_80B59170;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x3A2) = 0x3E8;
    M2C_FIELD(arg0, M2C_UNK **, 0x1DC) = &D_80B59170;
}
