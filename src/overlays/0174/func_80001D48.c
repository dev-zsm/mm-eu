#include "types.h"
#include "m2c_compat.h"

f32 func_800FEB84(s16);                             /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6001ADC;
extern M2C_UNK D_80940E18;

void func_80001D48(u8 *arg0) {
    s16 temp_v1;

    func_80137070(M2C_FIELD(arg0, s32 *, 0x3D4));
    temp_v1 = M2C_FIELD(arg0, s16 *, 0x3EA);
    if (temp_v1 > 0) {
        M2C_FIELD(arg0, s16 *, 0x3EA) = (s16) (temp_v1 - 1);
        M2C_FIELD(arg0, s16 *, 0xC0) = (s16) (s32) (func_800FEB84((s16) (M2C_FIELD(arg0, s16 *, 0x3EA) * 0x333)) * 1000.0f);
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x414) = &D_80940E18;
    M2C_FIELD(arg0, s16 *, 0x3EA) = 6;
    func_80137788(M2C_FIELD(arg0, s32 *, 0x3D4), &D_6001ADC, 0x3F800000, 0, (f32) func_80134AE8(&D_6001ADC), 2, 5.0f);
}
