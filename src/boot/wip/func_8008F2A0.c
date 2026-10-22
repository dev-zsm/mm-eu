// FLAGS: -O2 -g0 -mips2
#include "types.h"

u8 __osVoiceContDataCrc(u8 *p, u32 n) {
    u32 crc = 0;
    u32 mask;
    u32 s;
    u8 byte;

    if (n != 0) {
        do {
            byte = *p;
            mask = 0x80;
            do {
                s = crc << 1;
                crc = s;
                if (byte & mask) {
                    if (s & 0x100) {
                        crc = s ^ 0x84;
                    } else {
                        crc = s + 1;
                    }
                } else if (s & 0x100) {
                    crc = s ^ 0x85;
                }
                mask >>= 1;
            } while (mask != 0);
            p++;
            n--;
        } while (n != 0);
    }
    do {
        s = crc << 1;
        crc = s;
        if (s & 0x100) {
            crc = s ^ 0x85;
        }
        n++;
    } while (n < 8);
    return crc;
}
