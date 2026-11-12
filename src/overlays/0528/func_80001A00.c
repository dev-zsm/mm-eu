#include "types.h"
#include "m2c_compat.h"

s32 func_800B70A4(u8 *, M2C_UNK, s32);            /* extern */
s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80B7B90C(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80B7C918(u8 *, s32);                 /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80B7CB2C;
extern M2C_UNK D_80B7CB6C;

void func_80001A00(u8 *arg0, s32 arg1) {
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x16), 2, 0x800, 0x100);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x2F8) = &D_80B7CB6C;
        func_80B7C918(arg0, arg1);
        return;
    }
    if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF1E) & 8) {
        if ((M2C_FIELD(arg0, f32 *, 0x98) < 120.0f) && (M2C_FIELD(&D_801E6EF0, u8 *, 0x20) == 2)) {
            M2C_FIELD(arg0, u16 *, 0x2F2) = (u16) (M2C_FIELD(arg0, u16 *, 0x2F2) | 4);
            M2C_FIELD(arg0, M2C_UNK **, 0x2F8) = &D_80B7CB2C;
            func_80B7B90C(arg0, 6, 2);
        }
    } else if ((func_800B70A4(arg0, 0x3000, arg1) != 0) && (M2C_FIELD(arg0, f32 *, 0x98) < 100.0f)) {
        func_800B8398(arg0, arg1, 0x42F00000);
    }
}
