// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A733D4();                            /* extern */
extern M2C_UNK D_80A7341C;

void func_800031DC(u8 *arg0) {
    if (M2C_FIELD(arg0, f32 *, 0x164) >= 7.0f) {
        func_80A733D4();
        if (M2C_FIELD(arg0, s16 *, 0x3D8) == 0) {
            M2C_FIELD(arg0, M2C_UNK **, 0x3DC) = &D_80A7341C;
        }
    }
}
