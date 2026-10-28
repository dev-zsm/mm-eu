// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800C9874(s32, s32, u8, u8 *);            /* extern */
M2C_UNK func_8082D63C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_8083D9E8(u8 *, s32);                 /* extern */
extern s32 D_8086222C;
extern u8 *D_80862264;

s32 func_80010908(u8 *arg0, s32 arg1) {
    if ((~(M2C_FIELD(D_80862264, u16 *, 0xC) | 0xFFFF7FFF) != 0) && (M2C_FIELD(arg0, u16 *, 0x90) & 0x200) && ((D_8086222C & 8) || (D_8086222C & 2) || (func_800C9874(arg1 + 0x830, M2C_FIELD(arg0, s32 *, 0x7C), M2C_FIELD(arg0, u8 *, 0x84), arg0) != 0))) {
        return 0;
    }
    func_8083D9E8(arg0, arg1);
    func_8082D63C(arg0, 0x6814);
    return 1;
}
