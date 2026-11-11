#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEC70(s32, s16, M2C_UNK, u8 *);   /* extern */
extern f32 D_8086225C;

void func_8000EDF4(u8 *arg0) {
    func_800FEC70(arg0 + 0xAB2, (s16) (s32) (D_8086225C * -500.0f), 0x384, arg0);
    M2C_FIELD(arg0, s16 *, 0xAAC) = (s16) (s32) (-(f32) M2C_FIELD(arg0, s16 *, 0xAB2) * 0.5f);
    M2C_FIELD(arg0, u16 *, 0xAA6) = (u16) (M2C_FIELD(arg0, u16 *, 0xAA6) | 0x48);
}
