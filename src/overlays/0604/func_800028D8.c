#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0604.h"

s32 func_800B8254();                                /* extern */
M2C_UNK func_800B8364(u8 *, s32, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_80BD3D48;

void func_800028D8(u8 *arg0, s32 arg1) {
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x2DC)(arg0, arg1);
        M2C_FIELD(arg0, M2C_UNK **, 0x2D8) = &D_80BD3D48;
        return;
    }
    func_800B8364(arg0, arg1, 0x43C80000, -1);
}
