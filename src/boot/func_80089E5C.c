// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

extern u8 D_8009D2E1;
extern u8 D_8009D2A0[];

typedef struct {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 typeh;
    u8 typel;
    u8 status;
    u8 dummy1;
} Req;

typedef struct {
    u16 type;
    u8 status;
    u8 errno;
} Status;

void __osContGetInitData(u8 *pattern, Status *data) {
    u8 *ptr;
    Req header;
    s32 i;
    u8 bits;

    bits = 0;
    ptr = D_8009D2A0;
    for (i = 0; i < D_8009D2E1; i++, ptr += sizeof(header), data++) {
        header = *(Req *)ptr;
        data->errno = (header.rxsize & 0xC0) >> 4;
        if (data->errno == 0) {
            data->type = header.typel << 8 | header.typeh;
            data->status = header.status;
            bits |= 1 << i;
        }
    }
    *pattern = bits;
}
