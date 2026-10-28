// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800BE350(u8 *, s32, s32);            /* extern */
M2C_UNK func_801377D0(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_600D21C;
extern M2C_UNK D_8089C058;

void func_8000219C(u8 *arg0, s32 arg1) {
    func_801377D0(arg0 + 0x144, &D_600D21C);
    func_800BE350(arg0, arg0 + 0x364, arg1);
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (M2C_FIELD(arg0, s16 *, 0x32) + 0x8000);
    M2C_FIELD(arg0, f32 *, 0x70) = 10.0f;
    if (M2C_FIELD(arg0, f32 *, 0x68) > 0.0f) {
        M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    }
    M2C_FIELD(arg0, s16 *, 0x28E) = 0;
    func_800B8C4C(arg0, 0x382B);
    M2C_FIELD(arg0, u8 *, 0x375) = (u8) (M2C_FIELD(arg0, u8 *, 0x375) & 0xFFFE);
    func_800BC8F4(arg0, 0x4000, 0xFF, 0, 0x12);
    M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_8089C058;
}
