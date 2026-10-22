// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 *D_801ED0C0;

s32 Nmi_GetPrenmiHasStarted(void) {
    return *D_801ED0C0;
}
