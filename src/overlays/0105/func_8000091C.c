#include "types.h"
#include "m2c_compat.h"

s16 func_800B6A58(u8 *, u8 *);                  /* extern */
M2C_UNK func_800B6FD0(u8 *, u8 *, M2C_UNK);     /* extern */
f32 func_800FEB44(s16);                             /* extern */
f32 func_800FEB84(s16);                             /* extern */
M2C_UNK func_808C4D3C(u8 *);                      /* extern */
M2C_UNK func_808C504C(u8 *, u8 *);              /* extern */
extern f32 D_808C9248;
extern f32 D_808C924C;

void func_8000091C(u8 *arg0, u8 *arg1) {
    u8 *temp_s1;

    temp_s1 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    M2C_FIELD(temp_s1, f32 *, 0x24) = (f32) (M2C_FIELD(arg0, f32 *, 0x24) + (func_800FEB84((s16) (M2C_FIELD(arg0, s16 *, 0x16) - 0x370)) * D_808C9248));
    M2C_FIELD(temp_s1, f32 *, 0x2C) = (f32) (M2C_FIELD(arg0, f32 *, 0x2C) + (func_800FEB44((s16) (M2C_FIELD(arg0, s16 *, 0x16) - 0x370)) * D_808C924C));
    M2C_FIELD(temp_s1, s16 *, 0xBE) = func_800B6A58(temp_s1, arg0);
    if (M2C_FIELD(arg0, s16 *, 0x2EE) == 0x19) {
        func_800B6FD0(arg1, arg0, 0x51);
    }
    if (M2C_FIELD(arg0, s16 *, 0x2EE) > 0) {
        M2C_FIELD(arg0, s16 *, 0x2EE) = (s16) (M2C_FIELD(arg0, s16 *, 0x2EE) - 1);
    } else {
        func_808C504C(arg0, arg1);
    }
    func_808C4D3C(arg0);
}
