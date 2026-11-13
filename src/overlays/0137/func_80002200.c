#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490();                            /* extern */
M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_80902218(u8 *);                      /* extern */
M2C_UNK func_809022B4(u8 *);                      /* extern */
extern M2C_UNK D_80904494;
extern f32 D_809046A4;

void func_80002200(u8 *arg0) {
    M2C_UNK (*temp_v0_2)();
    f32 temp_f0;
    s16 temp_v0_3;
    u8 *temp_v0;

    if (M2C_FIELD(arg0, s16 *, 0x1C) == 1) {
        func_800B6490();
        return;
    }
    temp_v0 = M2C_FIELD(arg0, u8 **, 0x124);
    if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s32 *, 0x138) == 0) && (arg0 != temp_v0)) {
        M2C_FIELD(arg0, u8 **, 0x124) = NULL;
    }
    temp_v0_2 = M2C_FIELD(arg0, M2C_UNK (**)(), 0x23C);
    if ((temp_v0_2 == NULL) || (temp_v0_2(), (M2C_FIELD(arg0, s32 *, 0x138) != 0))) {
        func_809022B4(arg0);
        func_800B680C(arg0);
        temp_v0_3 = M2C_FIELD(arg0, s16 *, 0x242);
        if (temp_v0_3 == 0x14) {
            M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80904494;
            return;
        }
        if (temp_v0_3 == 0) {
            M2C_FIELD(arg0, f32 *, 0x25C) = (f32) M2C_FIELD(arg0, f32 *, 0x260);
            func_80902218(arg0);
            return;
        }
        if (temp_v0_3 < 0x14) {
            M2C_FIELD(arg0, f32 *, 0x25C) = (f32) ((D_809046A4 * M2C_FIELD(arg0, f32 *, 0x260)) + M2C_FIELD(arg0, f32 *, 0x25C));
            if (M2C_FIELD(arg0, f32 *, 0x260) < M2C_FIELD(arg0, f32 *, 0x25C)) {
                M2C_FIELD(arg0, f32 *, 0x25C) = M2C_FIELD(arg0, f32 *, 0x260);
            }
            func_80902218(arg0);
        }
    }
}
