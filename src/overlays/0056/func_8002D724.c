// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082D184(u8 *);                      /* extern */
M2C_UNK func_8082D1C8(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_8082D500(s32, u8 *);                 /* extern */
M2C_UNK func_8082D63C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80830B44(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_400DE28;
extern M2C_UNK D_808533B4;

void func_8002D724(s32 arg0, u8 *arg1) {
    func_8082D500(arg0, arg1);
    func_80830B44(arg0, arg1, &D_808533B4, 0);
    func_8082D1C8(arg0, arg1, &D_400DE28);
    M2C_FIELD(arg1, s32 *, 0xA70) = (s32) (M2C_FIELD(arg1, s32 *, 0xA70) | 0x80);
    func_8082D184(arg1);
    func_8082D63C(arg1, 0x680D);
}
