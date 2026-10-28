// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"
typedef struct { u8 dummy; u8 txsize; u8 rxsize; u8 cmd; u16 button; s8 stick_x; s8 stick_y; } Fmt;
typedef struct { u16 button; s8 stick_x; s8 stick_y; u8 errno; } Pad;
extern u8 D_8009D2A0[];
extern u8 D_8009D2E1;

void osContGetReadData(Pad *data) {
    register u8 *ptr = D_8009D2A0;
    Fmt readformat;
    register s32 i;

    for (i = 0; i < D_8009D2E1; i++, ptr += sizeof(Fmt), data++) {
        readformat = *(Fmt *)ptr;
        data->errno = (readformat.rxsize & 0xC0) >> 4;
        if (data->errno == 0) {
            data->button = readformat.button;
            data->stick_x = readformat.stick_x;
            data->stick_y = readformat.stick_y;
        }
    }
}
