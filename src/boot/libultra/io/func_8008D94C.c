// FLAGS: -O2 -g0 -mips2
#include "sdk/os_cont.h"

void osContGetQuery(OSContStatus *data) {
    u8 pattern;

    __osContGetInitData(&pattern, data);
}
