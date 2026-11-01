// FLAGS: -O2 -g0 -mips2
// STATUS: size differs: the ROM stores both stick bytes through one lui $at (D_801F4C8C/D_801F4C8D), ours does not
#include "types.h"

typedef struct {
    u16 button;
    u8 pad2[0x12];
    s8 stickX;
    s8 stickY;
    u8 pad16[0x4A];
} InputState;

extern s8 D_801F4C8C;
extern s8 D_801F4C8D;
extern s32 D_801F4C90;
extern s32 D_801F4C98;
extern void PadMgr_GetInput2(InputState *input, s32 arg);

void func_8019BDB0(void) {
    InputState input;
    s32 pad; // keeps the saved value 4 bytes lower, like the ROM's frame
    s32 prev;

    prev = D_801F4C90;
    PadMgr_GetInput2(&input, 0);
    D_801F4C90 = input.button;
    D_801F4C98 = prev;
    D_801F4C8C = input.stickX;
    D_801F4C8D = input.stickY;
}
