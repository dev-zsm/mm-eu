#include "types.h"
#include "generated/code_funcs.h"


void Environment_LerpAmbientColor(u8 *play, s32 a1, f32 t) {
    Environment_LerpRGB8(play + 0x170C8, a1, t, play + 0x17090);
}
