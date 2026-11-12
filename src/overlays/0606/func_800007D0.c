#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80BD655C;
extern M2C_UNK D_80BD80F4;
extern M2C_UNK D_80BD80FC;
extern M2C_UNK D_80BD8180;
extern M2C_UNK D_80BD8188;
extern M2C_UNK D_80BD8190;

M2C_UNK *func_800007D0(u8 *arg0, M2C_UNK arg1) {
    switch ((M2C_FIELD(arg0, u8 *, 0x298))) {
        case 3:
            M2C_FIELD(arg0, M2C_UNK **, 0x3F8) = &D_80BD655C;
            return &D_80BD80FC;
        case 4:
            return &D_80BD8190;
        case 2:
        case 11:
        case 14:
            return &D_80BD8180;
        case 10:
        case 12:
            return &D_80BD80F4;
        case 13:
            return &D_80BD8188;
        default:
            return NULL;
    }
}
