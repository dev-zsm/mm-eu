#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0110.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(u8 *, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
M2C_UNK func_80137828(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
extern M2C_UNK D_6002158;
extern M2C_UNK D_808D088C;
extern f32 D_808D3048;
extern f32 D_808D304C;
extern f32 D_808D3050;

void func_80000A0C(u8 *arg0) {
    s16 temp_v1;
    s16 sp36;

    temp_v1 = M2C_FIELD(arg0, s16 *, 0x190) - M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    if (temp_v1 > 0) {
        sp36 = temp_v1;
        func_80137828(arg0 + 0x144, &D_6002158, 0xC0400000);
    } else {
        sp36 = temp_v1;
        func_80137788(arg0 + 0x144, &D_6002158, 0xBF800000, (f32) func_80134AE8(&D_6002158), 0.0f, 2, -3.0f);
    }
    if (D_808D3048 < M2C_FIELD(arg0, f32 *, 0x58)) {
        M2C_FIELD(arg0, s16 *, 0x190) = (s16) (s32) ((f32) sp36 * D_808D304C);
    } else {
        M2C_FIELD(arg0, f32 *, 0x160) = (f32) (2.0f * M2C_FIELD(arg0, f32 *, 0x160));
        M2C_FIELD(arg0, s16 *, 0x190) = (s16) (s32) ((f32) sp36 * D_808D3050);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808D088C;
}
