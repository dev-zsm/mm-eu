// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern s32 AudioThread_GetEnabledNotesCount();
s8 Audio_GetEnabledNotesCount(void) {
    return AudioThread_GetEnabledNotesCount();
}
