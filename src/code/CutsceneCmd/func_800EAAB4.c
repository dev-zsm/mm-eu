#include "types.h"
#include "code_funcs.h"
void CutsceneCmd_StartAmbience(u8 *a0, u8 *a1, u8 *a2) {
    if (*(u16 *)(a2 + 2) == *(u16 *)(a1 + 0x10)) {
        Audio_PlayAmbience(a0[0x815]);
    }
}
