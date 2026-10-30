// FLAGS: -O2 -g0 -mips2
#include "ultra64.h"

OSMesgQueue *osPiGetCmdQueue(void) {
    if (D_80098060.active == 0) {
        return NULL;
    }
    return D_80098060.cmdQueue;
}
