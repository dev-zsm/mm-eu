// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 func_8016AE44(s16 a0);
extern s32 D_801C00D0;

typedef struct {
    u8 pad0[0xA4];
    s16 unkA4;
} Dungeon;

s32 Map_GetDungeonSceneIndexForDungeon(Dungeon *arg0) {
    s32 *var_s1;
    s32 var_s0;

    var_s1 = &D_801C00D0;
    var_s0 = 0;
    do {
        if (func_8016AE44(arg0->unkA4) == *var_s1) {
            return var_s0;
        }
        var_s0 += 1;
        var_s1 += 1;
    } while (var_s0 != 5);
    return -1;
}
