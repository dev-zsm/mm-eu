#include "types.h"

typedef struct {
    u8 pad0[0x1CA5];
    u8 flags;
} PlayState;
extern u8 D_801C2D44;
extern s8 D_801E6F90[];
s32 MsgEvent_CheckHasPowderKeg(s32 arg0, PlayState *play, u8 **script, s32 arg3) {
    s16 offset;
    unsigned int new_var2;
    u8 new_var;
    new_var2 = (*script)[2];
    new_var = new_var2;
    offset = ((*script)[1] << 8) | new_var;
    if ((D_801E6F90[D_801C2D44] != 0) || (play->flags & 1)) {
        *script += offset;
    }
    return 0;
}
