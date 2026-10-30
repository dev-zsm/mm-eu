// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_cont.h"

void osContGetReadData(OSContPad *data) {
    register u8 *ptr = (u8 *)&D_8009D2A0;
    __OSContReadFormat readformat;
    register s32 i;

    for (i = 0; i < D_8009D2E1; i++, ptr += sizeof(__OSContReadFormat), data++) {
        readformat = *(__OSContReadFormat *)ptr;
        data->errno = (readformat.rxsize & 0xC0) >> 4;
        if (data->errno == 0) {
            data->button = readformat.button;
            data->stick_x = readformat.stick_x;
            data->stick_y = readformat.stick_y;
        }
    }
}
