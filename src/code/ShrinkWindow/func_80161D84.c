// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s8 *D_801EE3D4;

s8 ShrinkWindow_Letterbox_GetSizeTarget(void) {
    return *D_801EE3D4;
}
