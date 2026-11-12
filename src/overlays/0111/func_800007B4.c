#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0111.h"

f32 func_8008704C();                                /* extern */
M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_601216C;
extern M2C_UNK D_808D3D30;

void func_800007B4(u8 *arg0) {
    f32 temp_f6;

    func_80137934(arg0 + 0x144, &D_601216C, 0xC0C00000, arg0);
    M2C_FIELD(arg0, s8 *, 0x3EF) = 0xE;
    temp_f6 = func_8008704C() * 10.0f;
    M2C_FIELD(arg0, s16 *, 0x3D6) = (s16) (s32) (temp_f6 + 5.0f);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, s16 *, 0x3E4) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808D3D30;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
