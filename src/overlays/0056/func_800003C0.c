// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082D350(s32, s32);                    /* extern */
M2C_UNK func_8082D3DC(s32, s32);                    /* extern */

void func_800003C0(s32 arg0, s32 arg1) {
    func_8082D3DC(arg0, arg1);
    func_8082D350(arg0, arg1);
}
