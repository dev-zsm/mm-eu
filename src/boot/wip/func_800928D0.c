// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 b[6];
} Hdr;

extern u8 D_8009D2A0[];
extern u8 D_8009D2E0;
extern void func_80089C90(void);
extern void func_80089CD4(void);
extern void func_8008AF10(s32 a, u8 *b);
extern void func_80088070(s32 a, s32 b, s32 c);

s32 func_800928D0(s32 arg0, s32 arg1, u8 *arg2) {
    u8 *s0;
    u8 *s3;
    u8 *s7;
    s32 s2;
    s32 mode;
    s32 v0;
    s32 i;
    s32 s2old;
    Hdr hdr;

    s3 = D_8009D2A0;
    s0 = s3;
    s7 = s3 + arg1;
    s2 = 2;
    mode = 0;
    func_80089C90();
    for (;;) {
        if (mode == 4) {
            goto post;
        }
        v0 = 0;
        *(s32 *)(s3 + 0x3C) = 1;
        if (arg1 > 0) {
            i = arg1 & 3;
            if (i != 0) {
                do {
                    v0++;
                    *s0++ = 0;
                } while (v0 != i);
                if (v0 == arg1) {
                    goto header;
                }
            }
            do {
                v0 += 4;
                s0[0] = 0;
                s0[1] = 0;
                s0[2] = 0;
                s0[3] = 0;
                s0 += 4;
            } while (v0 != arg1);
        }
    header:
        s0[0] = 1;
        s0[1] = 3;
        s0[2] = 0;
        s0[6] = 0xFE;
        D_8009D2E0 = 0xFE;
        s0 += 6;
        func_8008AF10(1, s3);
        func_80088070(arg0, 0, 1);
    post:
        s0 = s7;
        func_8008AF10(0, s3);
        func_80088070(arg0, 0, 1);
        *(Hdr *)&hdr = *(Hdr *)s7;
        *arg2 = hdr.b[5];
        if (((hdr.b[1] & 0xC0) >> 4) != 0) {
            mode = (hdr.b[1] & 0x80) ? 1 : 4;
        } else {
            mode = 0;
            if (hdr.b[3] == 0 && hdr.b[4] == 1) {
                mode = (hdr.b[5] & 4) ? 4 : 0;
            } else {
                mode = 0xB;
            }
        }
        if (mode == 4) {
            s2old = s2;
            s2--;
            if (s2old >= 0) {
                continue;
            }
        }
        break;
    }
    func_80089CD4();
    return mode;
}
