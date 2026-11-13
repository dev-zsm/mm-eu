#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

s32 func_80124664(u8 *);                          /* extern */
s32 func_80134AE8(s32);                             /* extern */
M2C_UNK func_801367B4(s32, u8 *, s32, M2C_UNK, f32, f32, s32, f32); /* extern */
M2C_UNK func_8082D2E8(u8 *);                      /* extern */
M2C_UNK func_80832950(s32, u8 *, M2C_UNK, M2C_UNK); /* extern */
extern u32 D_8085C640[];
extern u32 D_8085C648[];

void func_80005A44(s32 arg0, u8 *arg1) {
    s32 var_a2;
    s32 sp34;
    s8 temp_v0;

    temp_v0 = M2C_FIELD(arg1, s8 *, 0xADA);
    if ((temp_v0 >= 4) && (temp_v0 < 8)) {
        var_a2 = D_8085C648[func_80124664(arg1)];
    } else {
        var_a2 = D_8085C640[func_80124664(arg1)];
    }
    sp34 = var_a2;
    func_8082D2E8(arg1);
    func_801367B4(arg0, arg1 + 0x240, var_a2, 0x3F800000, 8.0f, (f32) func_80134AE8(sp34), 2, -9.0f);
    func_80832950(arg0, arg1, 0x200, 0);
}
