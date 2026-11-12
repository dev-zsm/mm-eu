#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490();                            /* extern */
M2C_UNK func_809F8E34();                            /* extern */
extern s32 D_801E6EF0;
extern M2C_UNK D_809F96E0;

void func_800034CC(u8 *arg0) {
    if ((D_801E6EF0 == 0xD010) || (D_801E6EF0 == 0x1C00)) {
        func_809F8E34();
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_809F96E0;
        return;
    }
    func_800B6490(arg0);
}
