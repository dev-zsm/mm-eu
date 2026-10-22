// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Actor {
    u8 pad0[0xA4];
    s16 unkA4;
} Actor;

extern s32 func_8016AE44(s16);
extern s32 D_801C00AC[];

s32 Map_GetDungeonSceneIndex(Actor *actor) {
    s32 *p = D_801C00AC;
    s32 i = 0;

    do {
        if (func_8016AE44(actor->unkA4) == *p) {
            return i;
        }
        i++;
        p++;
    } while (i != 9);
    return -1;
}
