// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 typel;
    u8 typeh;
    u8 status;
} ReqFmt;

typedef struct {
    u16 type;
    u8 status;
    u8 errno;
} Status;

extern u8 D_8009E9A0[];

void __osPfsGetOneChannelData(s32 channel, Status *data) {
    u8 *ptr = D_8009E9A0;
    ReqFmt requestformat;
    s32 i;

    for (i = 0; i < channel; i++) {
        ptr++;
    }
    requestformat = *(ReqFmt *)ptr;
    data->errno = (requestformat.rxsize & 0xC0) >> 4;
    if (data->errno == 0) {
        data->type = (requestformat.typeh << 8) | requestformat.typel;
        data->status = requestformat.status;
    }
}
