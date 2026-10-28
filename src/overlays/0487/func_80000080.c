// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s16, u8 *);                 /* extern */
s32 func_800F1984(s16, u8 *);                     /* extern */
M2C_UNK func_800F1A08(s16, u8 *);                 /* extern */
extern M2C_UNK D_80B24E90;

void func_80000080(u8 *arg0, M2C_UNK arg1) {
    if (func_800F1984(M2C_FIELD(arg0, s16 *, 0x17C), arg0) != 0) {
        func_800F1A08(M2C_FIELD(arg0, s16 *, 0x17C), arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80B24E90;
        return;
    }
    func_800F1944(M2C_FIELD(arg0, s16 *, 0x17C), arg0);
}
