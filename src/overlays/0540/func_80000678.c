// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B899AC();                            /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80B89E28;
extern M2C_UNK D_80B89E5C;

void func_80000678(u8 *arg0, u8 *arg1) {
    M2C_FIELD(arg0, s8 *, 0x2B2) = (s8) M2C_FIELD(arg0, s8 *, 0x38);
    if ((M2C_FIELD(&D_801E6EF0, u8 *, 0xF2A) & 1) || (M2C_FIELD(&D_801E6EF0, u8 *, 0xF2B) & 0x80)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x2B8) = &D_80B89E5C;
    } else {
        M2C_FIELD(arg0, M2C_UNK **, 0x2B8) = &D_80B89E28;
    }
    func_80B899AC();
    M2C_FIELD(arg1, u8 *, 0x1CA5) = (u8) (M2C_FIELD(arg1, u8 *, 0x1CA5) | 0x20);
    M2C_FIELD(arg0, s16 *, 0x260) = 0;
}
