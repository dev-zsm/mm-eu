// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8019FFD8(M2C_UNK, u8 *);             /* extern */
extern M2C_UNK D_80BBF96C;
extern M2C_UNK D_80BBFCC4;
extern f32 D_80BBFD30;

void func_8000013C(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80BBFCC4;
    M2C_FIELD(arg0, s16 *, 0x164) = 0;
    M2C_FIELD(arg0, s16 *, 0x166) = 0;
    M2C_FIELD(arg0, f32 *, 0x168) = (f32) D_80BBFD30;
    func_8019FFD8(0x3A86, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80BBF96C;
}
