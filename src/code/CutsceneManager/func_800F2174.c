// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern s16 D_801BE3F4;

void CutsceneManager_SetReturnCamera(s16 camId) {
    D_801BE3F4 = camId;
}
