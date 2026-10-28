// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800F1944(M2C_UNK);                     /* extern */
s32 func_800F1984(M2C_UNK);                         /* extern */
M2C_UNK func_800F1B24(M2C_UNK, u8 *);             /* extern */
extern M2C_UNK D_80A8676C;

void func_80001CC4(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v1;

    if (func_800F1984(0xA) != 0) {
        func_800B8C4C(arg0, 0x3921);
        func_800F1B24(0xA, arg0);
        M2C_FIELD(arg0, s16 *, 0xBC) = 0;
        temp_v1 = M2C_FIELD(arg0, s16 *, 0xBC);
        M2C_FIELD(arg0, M2C_UNK **, 0x290) = &D_80A8676C;
        M2C_FIELD(arg0, s16 *, 0x30) = temp_v1;
        M2C_FIELD(arg0, s16 *, 0xBE) = temp_v1;
        M2C_FIELD(arg0, s16 *, 0x32) = temp_v1;
        return;
    }
    func_800F1944(0xA);
}
