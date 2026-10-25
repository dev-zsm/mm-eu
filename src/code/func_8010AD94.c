#include "types.h"

extern u8 D_801E6EF0[];
s32 MsgEvent_SetWeekEventReg(void *arg0, void *arg1, u8 **script, s32 arg3) {
    short new_var2;
    u8 *cmd = *script;
    u16 flag = cmd[2] | (cmd[1] << 8);
    u16 new_var;
    new_var2 = flag;
    new_var = new_var2;
    D_801E6EF0[0xEF8 + (flag >> 8)] |= new_var;
    return 0;
}
