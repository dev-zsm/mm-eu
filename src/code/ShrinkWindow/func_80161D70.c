#include "types.h"
#include "generated/code_funcs.h"

extern u8 *D_801EE3D4;

void ShrinkWindow_Letterbox_SetSizeTarget(s32 arg0) {
    *D_801EE3D4 = arg0;
}
