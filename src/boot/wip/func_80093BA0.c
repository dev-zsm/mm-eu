// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x60];
    s32 unk60;
    u8 unk64;
} Ctx;

s32 func_8008D184(Ctx *a, u8 *b, s32 c, s32 d);

s32 func_80093BA0(Ctx *arg0, s32 arg1, u8 *arg2) {
    u8 *pb;
    s32 cnt;
    s32 s1;
    s32 idx;
    s32 v0;
    s32 r;
    u8 s2;
    u16 *q;
    s32 v;

    pb = (u8 *)&arg1;
    cnt = 0;
    s2 = 0;
    idx = ((s32)pb[1] / 4) + (((s32)pb[0] % 8) << 5);
    if ((s32)arg0->unk64 > 0) {
        v0 = 0;
        do {
            if (v0 > 0) {
                s1 = 1;
            } else {
                s1 = arg0->unk60;
            }
            if (pb[0] == v0 || (arg2[idx + 0x101] & (1 << (v0 % 8)))) {
                if (arg2[0x100] != v0) {
                    r = func_8008D184(arg0, arg2, 0, s2);
                    if (r != 0 && r != 3) {
                        return r;
                    }
                    arg2[0x100] = s2;
                }
                if (cnt < 2) {
                    if (s1 < 0x80) {
                        v = s1 * 2;
                        q = (u16 *)(arg2 + v);
                        do {
                            v += 2;
                            if (*(u16 *)pb == *q) {
                                cnt++;
                            }
                            q++;
                        } while (cnt < 2 && v < 0x100);
                    }
                }
                if (cnt >= 2) {
                    return 2;
                }
            }
            s2 = (u8)(s2 + 1);
            v0 = s2;
        } while (v0 < (s32)arg0->unk64);
    }
    return cnt;
}
