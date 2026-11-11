#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0124.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_808E36EC(s32, u8 *);                 /* extern */
M2C_UNK func_808E3904(u8 *);                      /* extern */
extern f32 D_808E457C;

void func_80000764(u8 *arg0, s32 arg1) {
    s16 temp_a1;

    temp_a1 = M2C_FIELD(arg0, s16 *, 0x24E) + 0x8000;
    func_800FFCBC(arg0 + 0xBE, temp_a1, 1, 0x1F40, 0xA);
    if (temp_a1 == M2C_FIELD(arg0, s16 *, 0xBE)) {
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0x24E);
        if (M2C_FIELD(arg0, f32 *, 0x8C) > 0.0f) {
            M2C_FIELD(arg0, f32 *, 0x68) = 3.0f;
            M2C_FIELD(arg0, f32 *, 0x70) = 5.0f;
            M2C_FIELD(arg0, f32 *, 0x74) = (f32) D_808E457C;
        } else {
            M2C_FIELD(arg0, f32 *, 0x68) = 2.0f;
            M2C_FIELD(arg0, f32 *, 0x70) = 6.0f;
            M2C_FIELD(arg0, f32 *, 0x74) = -2.0f;
        }
        func_808E36EC(arg1, arg0);
        M2C_FIELD(arg0, s16 *, 0x250) = 3;
        func_808E3904(arg0);
    }
}
