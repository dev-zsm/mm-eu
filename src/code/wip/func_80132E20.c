// STATUS: 18 instructions differ: the ROM keeps the script pointer in v1 and the constant return value in v0 from the start
#include "types.h"

typedef struct {
    u8 pad0[0xA4];
    s16 sceneId;
} PlayState;

s32 Schedule_CheckNotInSceneL(PlayState *play, u8 **script, s32 unused) {
    u8 *cmd = *script;

    if ((s16)((cmd[1] << 8) | cmd[2]) != play->sceneId) {
        *script = cmd + (s16)((cmd[3] << 8) | cmd[4]);
    }
    return 0;
}
