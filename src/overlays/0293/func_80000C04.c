#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0293.h"

M2C_UNK func_809F15DC(s32, M2C_UNK *);                   /* extern */
extern M2C_UNK D_809F2A70;
extern f32 D_809F5808;

void func_80000C04(s32 arg0, u8 *arg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    temp_f0 = M2C_FIELD(temp_v0, f32 *, 0x24);
    if ((temp_f0 >= 0.0f) && (temp_f0 <= 390.0f)) {
        temp_f0_2 = M2C_FIELD(temp_v0, f32 *, 0x2C);
        if ((temp_f0_2 >= 72.0f) && (temp_f0_2 <= D_809F5808)) {
            func_809F15DC(arg0, &D_809F2A70);
        }
    }
}
