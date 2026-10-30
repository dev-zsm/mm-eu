// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_pfs.h"

void __osPfsGetInitData(u8 *pattern, OSContStatus *data) {
    /* declaration order decides the stack layout (matching) */
    s32 i;
    __OSContRequestFormat requestformat;
    u8 *ptr;
    u8 bits;

    bits = 0;
    ptr = (u8 *)&D_8009E9A0;
    for (i = 0; i < D_8009D2E1; i++, ptr += sizeof(requestformat), data++) {
        requestformat = *(__OSContRequestFormat *)ptr;
        data->errno = (requestformat.rxsize & 0xC0) >> 4;
        if (data->errno == 0) {
            data->type = (requestformat.typel << 8) | requestformat.typeh;
            data->status = requestformat.status;
            bits |= 1 << i;
        }
    }
    *pattern = bits;
}
