// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
extern M2C_UNK D_8097A558;
extern M2C_UNK D_8097C070;
extern f32 D_8097C2D8;
extern f32 D_8097C2DC;

void func_80000F6C(u8 *arg0) {
    s16 temp_v0;

    func_800B8C4C(arg0, 0x3831);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x3DE);
    M2C_FIELD(arg0, s16 *, 0x3DC) = 0;
    M2C_FIELD(arg0, f32 *, 0xCC) = 0.0f;
    if (temp_v0 == 9) {
        func_800BD9E0(arg0 + 0x144, &D_8097C070, 8);
        M2C_FIELD(arg0, f32 *, 0x70) = (f32) D_8097C2D8;
        M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
        M2C_FIELD(arg0, f32 *, 0x68) = 3.0f;
    } else if (temp_v0 == 0xA) {
        func_800BD9E0(arg0 + 0x144, &D_8097C070, 8);
    } else if (temp_v0 == 0xB) {
        func_800BD9E0(arg0 + 0x144, &D_8097C070, 9);
        M2C_FIELD(arg0, f32 *, 0x70) = (f32) D_8097C2DC;
        M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
        M2C_FIELD(arg0, f32 *, 0x68) = 2.0f;
    }
    M2C_FIELD(arg0, s16 *, 0x3DE) = 0xD;
    M2C_FIELD(arg0, M2C_UNK **, 0x228) = &D_8097A558;
}
