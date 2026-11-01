#include "types.h"

typedef struct {
    u8 pad0[0xA4];
    s16 unkA4;
} Struct_80132DDC;

s32 Schedule_CheckNotInSceneS(Struct_80132DDC *arg0, u8 **arg1, s16 arg2) {
    u8 *cmd = *arg1;

    arg2 = (cmd[1] << 8) | cmd[2];
    if (arg2 != arg0->unkA4) {
        *arg1 = cmd + (s8)cmd[3];
    }
    return 0;
}
