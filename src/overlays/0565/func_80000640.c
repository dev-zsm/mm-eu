#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0565.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B68A8(u8 *);                      /* extern */
f32 func_800FEB84(s16);                             /* extern */
M2C_UNK func_800FFBF8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80BB1F4C(s16);                             /* extern */
M2C_UNK func_80BB205C(u8 *, s32);                 /* extern */
s32 func_80BB20D4(u8 *, u8 *, s32);               /* extern */
M2C_UNK func_80BB2270(u8 *, s32, u8 *, s16 *);    /* extern */

void func_80000640(u8 *arg0, s32 arg1) {
    s32 temp_v0;
    s16 sp32;
    s16 sp30;
    u8 *temp_t6;

    temp_t6 = M2C_FIELD(arg0, u8 **, 0x1F8);
    if (temp_t6 != NULL) {
        func_80BB2270(temp_t6, M2C_FIELD(arg0, s32 *, 0x1FC), arg0 + 0x24, &sp30);
        if (M2C_FIELD(arg0, u16 *, 0x90) & 8) {
            sp32 = M2C_FIELD(arg0, s16 *, 0x86);
        }
        func_800FFCBC(arg0 + 0x32, sp32, 4, 0x3E8, 1);
        M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
        func_800FFCBC(arg0 + 0x30, (s16) (sp30 * -1), 4, 0x3E8, 1);
        if (func_80BB20D4(arg0, M2C_FIELD(arg0, u8 **, 0x1F8), M2C_FIELD(arg0, s32 *, 0x1FC)) != 0) {
            if ((M2C_FIELD(arg0, s16 *, 0x262) == M2C_FIELD(arg0, s32 *, 0x1FC)) && (func_80BB1F4C(M2C_FIELD(arg0, s16 *, 0x260)) != 0)) {
                func_80BB205C(arg0, arg1);
            }
            temp_v0 = M2C_FIELD(arg0, s32 *, 0x1FC);
            if (temp_v0 >= (*M2C_FIELD(arg0, u8 **, 0x1F8) - 1)) {
                func_800B6490(arg0);
            } else {
                M2C_FIELD(arg0, s32 *, 0x1FC) = (s32) (temp_v0 + 1);
            }
        }
    }
    func_800FFBF8(arg0 + 0x70, 0x40C00000, 0x3E4CCCCD, 0x3F800000);
    func_800B68A8(arg0);
    M2C_FIELD(arg0, s16 *, 0x264) = (s16) (M2C_FIELD(arg0, s16 *, 0x264) + 0x1000);
    M2C_FIELD(arg0, f32 *, 0xC4) = (f32) (func_800FEB84(M2C_FIELD(arg0, s16 *, 0x264)) * 500.0f);
}
