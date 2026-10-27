// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s16 D_801BE6EC;
extern f32 D_801D5B0C;

void Environment_SetTimeJump(f32 arg0) {
    D_801BE6EC = (s16) (u32) (arg0 * D_801D5B0C);
}
