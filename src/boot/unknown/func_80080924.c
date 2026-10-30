// FLAGS: -O2 -g0 -mips2
#include "os_internal.h"

/* Thin wrapper around osEPiStartDma. */
s32 func_80080924(OSPiHandle *handle, OSIoMesg *mb, s32 direction) {
    return osEPiStartDma(handle, mb, direction);
}
