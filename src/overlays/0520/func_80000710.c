// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B75928(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B75C10(u8 *);                      /* extern */
extern M2C_UNK D_80B739CC;

void func_80000710(u8 *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x16) == M2C_FIELD(arg0, s16 *, 0xBE)) {
        M2C_FIELD(arg0, s16 *, 0x314) = 0xB;
        func_80B75928(arg0, 0xB);
    } else {
        M2C_FIELD(arg0, s16 *, 0x314) = 1;
        func_80B75928(arg0, 1);
    }
    func_80B75C10(arg0);
    M2C_FIELD(arg0, s16 *, 0x31E) = 2;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B739CC;
}
