// FLAGS: -O2 -g0
#include "types.h"

u8 *func_80080F20(u32);

extern s32 D_8009BDE0;
extern s32 D_8009C1F0;
extern u32 D_8009C1F4;

s32 func_80081040(u8 *arg0, u8 *arg1) {
    u8 *cur;
    u8 *dst;
    u8 *end;
    u8 *back;
    s32 count;
    u8 code;
    s32 len;
    s32 dist;
    u8 b1;
    u8 t5;
    u8 t6;

    if (*(u32 *)arg0 != 0x59617A30) {
        return -1;
    }
    count = 0;
    code = 0;
    cur = arg0 + 0x10;
    dst = arg1;
    end = dst + *(u32 *)(arg0 + 4);
    do {
        if (count == 0) {
            if (D_8009C1F4 < (u32)cur && D_8009C1F0 != 0) {
                cur = func_80080F20((u32)cur);
            }
            code = *cur;
            cur++;
            count = 8;
        }
        if (code & 0x80) {
            *dst = *cur;
            dst++;
            cur++;
        } else {
            b1 = cur[0];
            dist = ((b1 & 0xF) << 8) | cur[1];
            cur += 2;
            len = b1 >> 4;
            back = dst - dist;
            if (len == 0) {
                len = *cur + 0x12;
                cur++;
            } else {
                len += 2;
            }
            if ((len & 3) != 0) {
                do {
                    *dst = back[-1];
                    dst++;
                    back++;
                    len--;
                } while ((len & 3) != 0);
            }
            if (len != 0) {
                do {
                    t5 = back[-1];
                    len -= 4;
                    dst += 4;
                    dst[-4] = t5;
                    t6 = back[0];
                    back += 4;
                    dst[-3] = t6;
                    dst[-2] = back[-3];
                    dst[-1] = back[-2];
                } while (len != 0);
            }
        }
        code <<= 1;
        count--;
    } while (dst != end);
    D_8009BDE0 = (s32)end;
    return 0;
}
