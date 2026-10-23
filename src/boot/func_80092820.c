// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"
typedef struct { u8 dummy; u8 txsize; u8 rxsize; u8 cmd; u8 typeh; u8 typel; u8 status; u8 dummy1; } Form;
typedef struct { u16 type; u8 status; u8 err; } Dst;
extern u8 D_8009D2E1;
extern u8 D_8009E9A0[];
void __osPfsGetInitData(u8 *pattern, Dst *data) {
    /* declaration order decides the stack layout (matching) */
    s32 i;
    Form fmt;
    u8 *ptr;
    u8 bits;

    bits = 0;
    ptr = D_8009E9A0;
    for (i = 0; i < D_8009D2E1; i++, ptr += sizeof(Form), data++) {
        fmt = *(Form *)ptr;
        data->err = (fmt.rxsize & 0xC0) >> 4;
        if (data->err == 0) {
            data->type = (fmt.typel << 8) | fmt.typeh;
            data->status = fmt.status;
            bits |= 1 << i;
        }
    }
    *pattern = bits;
}
