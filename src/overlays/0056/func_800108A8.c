// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80833150();                            /* extern */
extern f32 D_8085DB80;
extern f32 D_8085DB84;

void func_800108A8(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0xA6C) = (s32) (M2C_FIELD(arg0, s32 *, 0xA6C) & 0xF7DFFFFF);
    func_80833150();
    if (M2C_FIELD(arg0, u8 *, 0x14B) == 3) {
        M2C_FIELD(arg0, f32 *, 0xAD0) = (f32) D_8085DB80;
        return;
    }
    M2C_FIELD(arg0, f32 *, 0xAD0) = (f32) D_8085DB84;
}
