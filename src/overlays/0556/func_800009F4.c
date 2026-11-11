#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0556.h"

s32 func_8010BD58(u8 *, s32, s32, s32, u8 *);   /* extern */
M2C_UNK func_8013B284(u8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_80BA7014(u8 *, s32);                     /* extern */
extern M2C_UNK D_80BA6F48;

void func_800009F4(u8 *arg0, s32 arg1) {
    if (func_8010BD58(arg0, arg1, func_80BA7014(arg0, arg1), M2C_FIELD(arg0, s32 *, 0x368), arg0 + 0x1DC) != 0) {
        M2C_FIELD(arg0, u16 *, 0x340) = (u16) (M2C_FIELD(arg0, u16 *, 0x340) & 0xFFF7);
        func_8013B284(arg0 + 0x340, 3, 7);
        M2C_FIELD(arg0, s32 *, 0x1DC) = 0;
        M2C_FIELD(arg0, u16 *, 0x340) = (u16) (M2C_FIELD(arg0, u16 *, 0x340) | 0x10);
        M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80BA6F48;
    }
}
