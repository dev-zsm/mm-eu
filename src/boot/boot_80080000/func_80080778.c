// FLAGS: -O1 -g3 -mips2
#include "types.h"

extern u8 D_80096CC4;
extern s32 D_80096D00;
extern void osViBlack(s32 a);
extern void osViSetYScale(f32 a);

// Pushes the D_80096CC4 flag to osViBlack (1 or 0). If D_80096D00 is mode 2,
// also calls osViSetYScale(1.0f). Mode and flag meanings are not known.
void func_80080778(void) {
    if (*(u8 *)&D_80096CC4 != 0) {
        osViBlack(1);
    } else {
        osViBlack(0);
    }
    if (*(s32 *)&D_80096D00 == 2) {
        osViSetYScale(1.0f);
    }
}
