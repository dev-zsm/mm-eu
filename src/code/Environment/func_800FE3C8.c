// FLAGS: -O2 -g3 -mips2
#include "types.h"
s32 Entrance_GetSceneId(s32);
extern s32 D_801E6EF0;
u8 func_800FE3C8(s32 arg0) {
    u8 v = 0;
    s32 t = D_801E6EF0;
    if (Entrance_GetSceneId(t & 0xFFFF) < 0) {
        v = 1;
    }
    return v;
}
