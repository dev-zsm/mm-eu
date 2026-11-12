#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

M2C_UNK func_8082D1C8(s32, u8 *, s32);            /* extern */
M2C_UNK func_80830B44(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_808496D4;
extern u32 D_8085B7E4[];
extern s32 D_8085B7FC[];

void func_8000D738(u8 *arg0, s32 arg1) {
    s32 var_a2;

    func_80830B44(arg1, arg0, &D_808496D4, 1);
    if (M2C_FIELD(arg0, f32 *, 0xB40) < 0.5f) {
        var_a2 = D_8085B7FC[M2C_FIELD(arg0, u8 *, 0x14F)];
    } else {
        var_a2 = D_8085B7E4[M2C_FIELD(arg0, u8 *, 0x14F)];
    }
    func_8082D1C8(arg1, arg0, var_a2);
    M2C_FIELD(arg0, s16 *, 0xAD4) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
}
