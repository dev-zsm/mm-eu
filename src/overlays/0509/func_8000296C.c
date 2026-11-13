#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0509.h"

M2C_UNK func_80B5DB5C(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80B5FEA8(u8 *, s32, M2C_UNK);        /* extern */
extern u16 D_801E6EFC;
extern M2C_UNK D_80B5ED9C;

void func_8000296C(u8 *arg0, s32 arg1) {
    func_80B5FEA8(arg0, arg1, 2);
    if ((M2C_FIELD(arg0, u16 *, 0x4C8) - D_801E6EFC)) {
        func_80B5FEA8(arg0, arg1, 0);
        func_80B5DB5C(arg0, &D_80B5ED9C);
    }
}
