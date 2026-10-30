// FLAGS: -O2 -g0
#include "os_internal.h"

s32 func_800851D4(u16 *ptr, u16 value) {
    return (*ptr ^ value) == 0;
}
