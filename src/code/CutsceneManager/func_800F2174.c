// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "code_funcs.h"

extern s16 D_801BE3F4;

void CutsceneManager_SetReturnCamera(s16 arg0) {
    D_801BE3F4 = arg0;
}
