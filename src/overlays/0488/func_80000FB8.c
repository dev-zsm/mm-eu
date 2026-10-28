// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80147B34(s32);                             /* extern */
M2C_UNK func_80147CC4(s32);                         /* extern */
s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_80B25B48(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B25C18(u8 *, s32);                 /* extern */
M2C_UNK func_80B260F8(u8 *);                      /* extern */
M2C_UNK func_80B2636C(u8 *, s32);                 /* extern */
extern M2C_UNK D_80B266E0;

void func_80000FB8(u8 *arg0, s32 arg1) {
    func_80B2636C(arg0, arg1);
    if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        func_80147CC4(arg1);
        func_80B260F8(arg0);
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~0x100);
        M2C_FIELD(arg0, M2C_UNK **, 0x304) = &D_80B266E0;
        func_80B25B48(arg0, 7);
    }
    func_80B25C18(arg0, arg1);
}
