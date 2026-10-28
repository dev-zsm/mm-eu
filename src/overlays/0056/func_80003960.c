// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801369F0(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_8082EAEC(s32, u8 *, M2C_UNK *);      /* extern */
s32 func_80830A58(s32, u8 *, s32);                /* extern */
extern M2C_UNK D_400DB30;
extern M2C_UNK D_808487A8;

void func_80003960(u8 *arg0, s32 arg1) {
    if (func_80830A58(arg1, arg0, M2C_FIELD(arg0, s32 *, 0x34C)) == 0) {
        func_8082EAEC(arg1, arg0, &D_808487A8);
        func_801369F0(arg1, arg0 + 0x284, &D_400DB30);
    }
}
