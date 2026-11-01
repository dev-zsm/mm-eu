// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_802006D0;
extern s32 D_802006D4;
extern struct {
    u8 bitPos;
    u8 sawFF;
} D_802006D8;
extern u32 D_802006DC;

u16 JpegDecoder_ReadBits(u8 bits) {
    u8 byte;
    u8 pos = D_802006D8.bitPos;
    u8 n = pos >> 3;

    while (n > 0) {
        pos = D_802006D8.bitPos;
        byte = *(u8 *)(D_802006D4++ + D_802006D0);
        if (D_802006D8.sawFF && byte == 0) {
            byte = *(u8 *)(D_802006D4++ + D_802006D0);
        }
        if (byte == 0xFF) {
            D_802006D8.sawFF = 1;
        } else {
            D_802006D8.sawFF = 0;
        }
        D_802006DC <<= 8;
        D_802006DC |= byte;
        n--;
        pos -= 8;
        D_802006D8.bitPos = pos;
    }
    D_802006D8.bitPos = pos + bits;
    return (D_802006DC << pos) >> -bits;
}
