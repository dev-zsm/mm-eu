// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_8093FC48(u8 *);                      /* extern */
M2C_UNK func_80941D3C(u8 *, M2C_UNK *, M2C_UNK *, u8 *, M2C_UNK *, f32); /* extern */
extern M2C_UNK D_6001ADC;
extern M2C_UNK D_80940A68;
extern M2C_UNK D_80940E18;

void func_80001B8C(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, f32 *, 0x1A8) > 10.0f) {
        func_800FFCBC(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x3EC), 2, 0x400, 0x40);
        M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
    }
    if (M2C_FIELD(arg0, f32 *, 0x1A8) > 45.0f) {
        M2C_FIELD(arg0, f32 *, 0x68) = 2.0f;
        M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x70) = 8.0f;
    } else if (M2C_FIELD(arg0, f32 *, 0x1A8) > 17.0f) {
        M2C_FIELD(arg0, f32 *, 0x68) = 6.0f;
        M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x70) = 4.0f;
    }
    if (M2C_FIELD(arg0, u16 *, 0x3E8) & 1) {
        func_80941D3C(arg0, &D_80940A68, &D_80940E18, arg0 + 0x190, &D_6001ADC, 0.0f);
        M2C_FIELD(arg0, s16 *, 0x3EA) = 6;
        M2C_FIELD(arg0, s16 *, 0x3EC) = (s16) (M2C_FIELD(arg0, s16 *, 0x3EC) + 0x2000);
    }
    func_8093FC48(arg0);
}
