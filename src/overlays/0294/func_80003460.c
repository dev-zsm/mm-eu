#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0294.h"

M2C_UNK func_800B6490();                            /* extern */
M2C_UNK func_809F8D48();                            /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_809F96E0;

void func_80003460(u8 *arg0) {
    if (((M2C_FIELD(&D_801E6EF0, s32 *, 0) == 0xD000) || (M2C_FIELD(&D_801E6EF0, s32 *, 0) == 0xD020)) && (M2C_FIELD(&D_801E6EF0, u8 *, 0xF19) & 0x80)) {
        func_809F8D48();
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_809F96E0;
        return;
    }
    func_800B6490(arg0);
}
