#include "types.h"
extern u8 D_801F4BF0;
void Audio_UpdatePauseState(void) {
    u8 v = *(u8 *)&D_801F4BF0;
    if (v != 0 && v != 2) {
        *(u8 *)&D_801F4BF0 = v - 1;
    }
}
