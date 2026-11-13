#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BA9E4(u8 *, u8 *, M2C_UNK, f32, f32, f32, s32, s32, s32, s32); /* extern */
M2C_UNK func_800BB80C(u8 *, u8 *);              /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80AA77AC(u8 *, u8 *);              /* extern */
M2C_UNK func_80AA8190(u8 *);                      /* extern */
s32 func_80AA8660(u8 *, u8 *);                  /* extern */
extern M2C_UNK D_6000A74;
extern f32 D_80AA9360;
extern f32 D_80AA9364;
extern f32 D_80AA9368;

void func_800012B0(u8 *arg0, u8 *arg1) {
    s16 temp_v0;
    s32 temp_v0_2;
    if ((M2C_FIELD(arg0, u8 *, 0x3BD) & 1) && ((M2C_FIELD(arg0, u8 *, 0x3BD) & 2) || (((temp_v0 = M2C_FIELD(arg1, s16 *, 0xA4), (temp_v0 == 0x45)) || (temp_v0 == 0)) && (func_80AA8660(arg0, arg1) != 0)))) {
        func_800BB80C(arg1, arg0);
        if (M2C_FIELD(arg0, u8 *, 0x3BD) & 2) {
            temp_v0_2 = *M2C_FIELD(arg0, s32 **, 0x3E8);
            if (temp_v0_2 & 0x1000) {
                M2C_FIELD(arg0, s8 *, 0x190) = 0xA;
                M2C_FIELD(arg0, f32 *, 0x28C) = (f32) D_80AA9360;
                M2C_FIELD(arg0, f32 *, 0x290) = (f32) D_80AA9364;
                M2C_FIELD(arg0, f32 *, 0x288) = 1.0f;
            } else if (temp_v0_2 & 0x2000) {
                M2C_FIELD(arg0, s8 *, 0x190) = 0x14;
                M2C_FIELD(arg0, f32 *, 0x28C) = (f32) D_80AA9368;
                M2C_FIELD(arg0, f32 *, 0x288) = 4.0f;
                func_800BA9E4(arg1 + 0x1CA0, arg1, 0xA2, (f32) M2C_FIELD(arg0, s16 *, 0x3D2), (f32) M2C_FIELD(arg0, s16 *, 0x3D4), (f32) M2C_FIELD(arg0, s16 *, 0x3D6), 0, 0, 0, 4);
            }
        }
        M2C_FIELD(arg0, u8 *, 0x3BD) = (u8) (M2C_FIELD(arg0, u8 *, 0x3BD) & 0xFFFD);
        func_800BC8F4(arg0, 0x4000, 0xFF, 0, func_80134AE8(&D_6000A74));
        func_80AA77AC(arg0, arg1);
        func_80AA8190(arg0);
    }
}
