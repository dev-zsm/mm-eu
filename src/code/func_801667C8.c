#include "types.h"
extern u8 *D_801EB7E0;
void Play_SetMotionBlurAlpha(s32 a) { *(s16 *)(D_801EB7E0 + 0x188) = a; }
