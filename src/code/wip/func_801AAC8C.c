#include "types.h"
typedef struct { u8 pad[0x50]; u8 *unk50; } H;
typedef char chk[sizeof(H) == 0x54 ? 1 : -1];
extern s32 JpegUtils_ProcessHuffmanTableImpl(u8 *, H *, s32, s32, s32);
s32 JpegUtils_ProcessHuffmanTable(u8 *arg0, H *arg1, s32 arg2, s32 arg3, u8 arg4) {
    u8 i;
    s32 ret;
    for (i = 0; i < arg4; i++) {
        ret = JpegUtils_ProcessHuffmanTableImpl(arg0 + 1, &arg1[i], arg2, arg3, *arg0 >> 4);
        arg0 += 0x11;
        if (ret == 0) {
            return 1;
        }
        arg1[i].unk50 = arg0;
        arg0 += ret;
    }
    return 0;
}
