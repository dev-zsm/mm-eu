#include "types.h"
#include "m2c_compat.h"

s32 func_801244EC(M2C_UNK);                         /* extern */
extern s32 D_801E6F08;
extern M2C_UNK D_80BB8B88;
extern M2C_UNK D_80BB8B90;
extern M2C_UNK D_80BB8B98;
extern M2C_UNK D_80BB8BA8;

M2C_UNK *func_80000864(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    if (func_801244EC(arg1) == 2) {
        return &D_80BB8BA8;
    }
    temp_v0 = M2C_FIELD(arg0, u8 *, 0x1DC);
    switch (temp_v0) {                              /* irregular */
        case 1:
            if (D_801E6F08 == 2) {
            return &D_80BB8B90;
            }
            return &D_80BB8B88;
        case 2:
            return &D_80BB8B98;
        default:
            return NULL;
    }
}
