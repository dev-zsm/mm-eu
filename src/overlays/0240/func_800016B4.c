#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80979AE8();                            /* extern */
M2C_UNK func_8097A018();                            /* extern */
M2C_UNK func_8097A128();                            /* extern */
M2C_UNK func_8097AF24();                            /* extern */
extern M2C_UNK D_8097A2AC;
extern f32 D_8097C2E8;

void func_800016B4(u8 *arg0) {
    f32 temp_f0;
    s16 temp_v0_2;
    s32 temp_v0;

    if (M2C_FIELD(arg0, u16 *, 0x90) & 2) {
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    }
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        temp_f0 = M2C_FIELD(arg0, f32 *, 0x70);
        if (temp_f0 < 0.0f) {
            M2C_FIELD(arg0, f32 *, 0x70) = (f32) (temp_f0 + D_8097C2E8);
        }
    }
    temp_v0 = M2C_FIELD(arg0, u8 *, 0x11C);
    if ((temp_v0 == 0) && (M2C_FIELD(arg0, u16 *, 0x90) & 1)) {
        if (M2C_FIELD(arg0, s16 *, 0x3DC) == 0) {
            if (M2C_FIELD(arg0, u8 *, 0xB7) == 0) {
                func_8097AF24();
                return;
            }
            func_80979AE8();
            return;
        }
        temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x3D6);
        switch (temp_v0_2) {                        /* irregular */
            case 2:
                func_8097A018();
                return;
            case 3:
                func_8097A128();
                return;
        }
    } else if ((temp_v0 == 0) && (M2C_FIELD(arg0, s16 *, 0x3DC) == 1) && (M2C_FIELD(arg0, s16 *, 0x3D6) == 4)) {
        M2C_FIELD(arg0, s16 *, 0x3DE) = 0xB;
        M2C_FIELD(arg0, M2C_UNK **, 0x228) = &D_8097A2AC;
    }
}
