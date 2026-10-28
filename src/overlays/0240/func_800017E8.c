// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
extern M2C_UNK D_8097ADEC;
extern M2C_UNK D_8097C070;
extern f32 D_8097C2EC;

void func_800017E8(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x3DE);
    if ((temp_v0 == 9) || (temp_v0 == 0xA)) {
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
        func_800BD9E0(arg0 + 0x144, &D_8097C070, 8);
        M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
        M2C_FIELD(arg0, f32 *, 0x70) = 1.0f;
    } else if (temp_v0 == 0xB) {
        func_800BD9E0(arg0 + 0x144, &D_8097C070, 9);
        M2C_FIELD(arg0, f32 *, 0x70) = (f32) D_8097C2EC;
        M2C_FIELD(arg0, f32 *, 0x68) = 2.0f;
        M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
    } else {
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
        func_800BD9E0(arg0 + 0x144, &D_8097C070, 3);
        if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
            M2C_FIELD(arg0, f32 *, 0x70) = -4.0f;
        }
    }
    func_800B8C4C(arg0, 0x3832);
    M2C_FIELD(arg0, s16 *, 0x3DE) = 6;
    M2C_FIELD(arg0, M2C_UNK **, 0x228) = &D_8097ADEC;
}
