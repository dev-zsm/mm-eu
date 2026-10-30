#include "types.h"

typedef struct {
    /* 0x000 */ u8 pad0[0x147];
    /* 0x147 */ s8 unk147;
} Ovl0056Player;

extern void func_80831040();

s32 func_80000384(s32 play, Ovl0056Player *player) {
    if (player->unk147 >= 2) {
        func_80831040(play, player, 0xFF);
        return 1;
    }
    return 0;
}
