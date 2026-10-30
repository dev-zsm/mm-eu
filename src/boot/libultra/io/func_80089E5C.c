// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_cont.h"

void __osContGetInitData(u8 *pattern, OSContStatus *data) {
    u8 *ptr;
    __OSContRequestFormat requestHeader;
    s32 i;
    u8 bits;

    bits = 0;
    ptr = (u8 *)&D_8009D2A0;
    for (i = 0; i < D_8009D2E1; i++, ptr += sizeof(requestHeader), data++) {
        requestHeader = *(__OSContRequestFormat *)ptr;
        data->errno = (requestHeader.rxsize & 0xC0) >> 4;
        if (data->errno == 0) {
            data->type = requestHeader.typel << 8 | requestHeader.typeh;
            data->status = requestHeader.status;
            bits |= 1 << i;
        }
    }
    *pattern = bits;
}
