#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0110.h"

M2C_UNK func_800FEC70(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_800FEE3C(u8 *, M2C_UNK, f32);        /* extern */
M2C_UNK func_808D0BAC(u8 *, s32);                 /* extern */
M2C_UNK func_808D0E10(u8 *);                      /* extern */
extern f32 D_808D3064;

void func_80000FD0(u8 *arg0, s32 arg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x18E);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x18E) = (s16) (temp_v0 - 1);
    }
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x70);
    func_800FEE3C(arg0 + 0x70, 0x41700000, temp_f0 * temp_f0 * D_808D3064);
    func_800FEC70(arg0 + 0xBC, -0x1680, 0x140);
    temp_f0_2 = M2C_FIELD(arg0, f32 *, 0x28) - M2C_FIELD(arg0, f32 *, 0x88);
    if (temp_f0_2 < 10.0f) {
        M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0x88) + 10.0f);
        M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    }
    if (temp_f0_2 < 12.0f) {
        func_808D0BAC(arg0, arg1);
    }
    if ((M2C_FIELD(arg0, u16 *, 0x90) & 8) || (M2C_FIELD(arg0, s16 *, 0x18E) == 0)) {
        func_808D0E10(arg0);
    }
}
