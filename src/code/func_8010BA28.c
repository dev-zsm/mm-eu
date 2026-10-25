#include "types.h"

extern u8 D_801C2D38[];

void func_8011489C(s16 arg0, u8 arg1);

s32 MsgEvent_DeleteItem(s32 arg0, s32 arg1, u8 **cmdp, s32 arg3) {
    u8 *cmd = *cmdp;
    s16 id = cmd[2] | (cmd[1] << 8);

    func_8011489C(id, D_801C2D38[id]);
    return 0;
}
