#include "types.h"
#include "m2c_compat.h"

s16 func_800B6AB0(u8 *, M2C_UNK *);               /* extern */
s16 func_800B6B2C(u8 *, M2C_UNK *);               /* extern */
f32 func_800FEB84(s16);                             /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80BF6260(u8 *);                      /* extern */
M2C_UNK func_80BF62D8(u8 *);                      /* extern */
M2C_UNK func_80BF71CC(u8 *);                      /* extern */
M2C_UNK func_80BF74E4(u8 *);                      /* extern */
extern f32 D_80BF8474;
extern M2C_UNK D_80BF86C0;

void func_800019EC(u8 *arg0) {
    f32 sp2C;
    s16 temp_v1;
    s16 temp_v1_2;

    if (M2C_FIELD(arg0, s16 *, 0x18E) != 0) {
        temp_v1 = M2C_FIELD(arg0, s16 *, 0x18E);
        M2C_FIELD(arg0, s16 *, 0x18E) = (s16) (temp_v1 - 1);
    }
    if (M2C_FIELD(arg0, u8 *, 0x18C) == 0xA) {
        if (M2C_FIELD(arg0, s16 *, 0x18E) < 0x26) {
            func_80BF6260(arg0);
            M2C_FIELD(arg0, f32 *, 0x70) = 4.0f;
            goto block_5;
        }
    } else {
        block_5:
        func_80137070(arg0 + 0x144);
        if (M2C_FIELD(arg0, u16 *, 0x90) & 8) {
            M2C_FIELD(arg0, s16 *, 0x192) = (s16) M2C_FIELD(arg0, s16 *, 0x86);
        } else if (M2C_FIELD(arg0, s32 *, 0x3E8) == 0) {
            M2C_FIELD(arg0, s16 *, 0x192) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) + 0x8000);
        } else {
            M2C_FIELD(arg0, s16 *, 0x192) = func_800B6AB0(arg0, &D_80BF86C0);
            M2C_FIELD(arg0, s16 *, 0x190) = func_800B6B2C(arg0, &D_80BF86C0);
        }
        func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x192), 6, 0x1000, 0x100);
        func_800FFCBC(arg0 + 0xBC, M2C_FIELD(arg0, s16 *, 0x190), 5, 0x100, 0x10);
        temp_v1_2 = M2C_FIELD(arg0, s16 *, 0x18E);
        sp2C = ((f32) temp_v1_2 * D_80BF8474) + 2048.0f;
        M2C_FIELD(arg0, s16 *, 0xC0) = (s16) (s32) (func_800FEB84((s16) (temp_v1_2 * 0x1999)) * sp2C);
        if (M2C_FIELD(arg0, s16 *, 0x18E) == 0) {
            if (M2C_FIELD(arg0, s32 *, 0x3E8) != 0) {
                func_80BF71CC(arg0);
                return;
            }
            if (M2C_FIELD(arg0, s32 *, 0x3EC) != 0) {
                func_80BF74E4(arg0);
                return;
            }
            func_80BF62D8(arg0);
        }
    }
}
