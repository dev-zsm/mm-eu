#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6000924;
extern M2C_UNK D_80B472CC;
extern M2C_UNK D_80B47650;

void func_80000F14(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_6000924, 0xC0A00000, arg0);
    if (&D_80B47650 == M2C_FIELD(arg0, M2C_UNK **, 0x200)) {
        M2C_FIELD(arg0, s16 *, 0x206) = 0x50;
    } else {
        M2C_FIELD(arg0, s16 *, 0x206) = 0;
    }
    M2C_FIELD(arg0, s16 *, 0x212) = 0x28;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x218) = (f32) M2C_FIELD(arg0, f32 *, 0x28);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, u8 *, 0x2BD) = (u8) (M2C_FIELD(arg0, u8 *, 0x2BD) | 1);
    M2C_FIELD(arg0, u8 *, 0x2BE) = (u8) (M2C_FIELD(arg0, u8 *, 0x2BE) | 1);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x200) = &D_80B472CC;
}
