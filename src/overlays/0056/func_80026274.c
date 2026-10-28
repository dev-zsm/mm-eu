// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80136480(u8 *, u8 *);                  /* extern */
M2C_UNK func_8082D1EC(u8 *, u8 *, M2C_UNK *);   /* extern */
s32 func_8082D538(u8 *, M2C_UNK, M2C_UNK);        /* extern */
M2C_UNK func_8082E814(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80836038(u8 *, u8 *);              /* extern */
extern M2C_UNK D_400DE30;

void func_80026274(u8 *arg0, u8 *arg1) {
    M2C_FIELD(arg0, s32 *, 0xA70) = (s32) (M2C_FIELD(arg0, s32 *, 0xA70) | 0x60);
    if (func_80136480(arg1, arg0 + 0x240) != 0) {
        func_8082D1EC(arg1, arg0, &D_400DE30);
    }
    if (M2C_FIELD(arg1, s16 *, 0xA4) != 0x5F) {
        func_8082E814(arg0, 0x10);
    }
    if (func_8082D538(arg0, 0, 0x64) != 0) {
        func_80836038(arg0, arg1);
        M2C_FIELD(arg0, s32 *, 0xA70) = (s32) (M2C_FIELD(arg0, s32 *, 0xA70) & ~0x80);
    }
}
