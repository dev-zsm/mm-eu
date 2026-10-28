// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801A3D04(M2C_UNK, u8 *);             /* extern */
extern M2C_UNK D_80B46DB4;

void func_80000A54(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x206) = 0xF;
    if (M2C_FIELD(arg0, u8 *, 0x204) == 0) {
        func_801A3D04(0x38, arg0);
        M2C_FIELD(arg0, u8 *, 0x204) = 1U;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x200) = &D_80B46DB4;
}
