// FLAGS: -O2 -g3 -mips2
#include "types.h"
void Audio_PlaySfx(u16);
void func_800FFEA4(u16 arg0) {
    Audio_PlaySfx(arg0);
}
