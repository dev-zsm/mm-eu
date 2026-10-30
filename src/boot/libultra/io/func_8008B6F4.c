// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_pfs.h"

void __osPfsGetOneChannelData(s32 channel, OSContStatus *data) {
    u8 *ptr = (u8 *)&D_8009E9A0;
    __OSContRequestFormatShort requestformat;
    s32 i;

    for (i = 0; i < channel; i++) {
        ptr++;
    }
    requestformat = *(__OSContRequestFormatShort *)ptr;
    data->errno = (requestformat.rxsize & 0xC0) >> 4;
    if (data->errno == 0) {
        data->type = (requestformat.typeh << 8) | requestformat.typel;
        data->status = requestformat.status;
    }
}
