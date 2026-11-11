#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0064.h"

M2C_UNK func_801377D0(u8 *, M2C_UNK *, u8 *);   /* extern */
M2C_UNK func_8086D888(u8 *, s32);                 /* extern */
extern M2C_UNK D_600466C;
extern M2C_UNK D_8086DD78;
extern M2C_UNK D_8086FE00;

void func_800007C8(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_8086FE00;
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
    func_801377D0(arg0 + 0x144, &D_600466C, arg0);
    func_8086D888(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_8086DD78;
}
