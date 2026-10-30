// FLAGS: -O2 -g0 -mips2
#include "os_cont.h"

void osContGetQuery(OSContStatus *data) {
    u8 pattern;

    __osContGetInitData(&pattern, data);
}
