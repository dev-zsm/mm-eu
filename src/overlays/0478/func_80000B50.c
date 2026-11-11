#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B5B64(M2C_UNK, s32);                /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_800B8254(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_800B8398(u8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_800B877C(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_800B87A0(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_80151DF4(M2C_UNK, M2C_UNK, u8 *);    /* extern */
M2C_UNK func_80B16970(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80B16DC4;

void func_80000B50(u8 *arg0, M2C_UNK arg1) {
    if (func_800B877C(arg0, arg1) != 0) {
        func_800B5B64(arg1, (s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0xFE00) >> 9);
        func_800B6490(arg0);
    } else if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x1F8) = &D_80B16DC4;
        func_80151DF4(arg1, 0x24B, arg0);
    } else {
        func_800B87A0(arg0, arg1, 0xBA, 0x42A00000, 60.0f);
        if (M2C_FIELD(arg0, u8 *, 0x114) != 0) {
            func_800B8398(arg0, arg1, 0x42DC0000);
        }
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 9);
    M2C_FIELD(arg0, s8 *, 0x1F) = 3;
    func_80B16970(arg0, arg1);
}
