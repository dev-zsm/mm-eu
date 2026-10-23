// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern u8 D_801F4E48[];
void *AudioVoice_GetVoiceMaskPattern(void) { return D_801F4E48; }
