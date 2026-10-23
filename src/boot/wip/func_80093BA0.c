// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

typedef struct {
    u8 pad0[0x60];
    s32 unk60;
    u8 unk64;
} Ctx;

typedef union {
    struct { u8 a; u8 b; } b;
    u16 h;
} Pair;

s32 __osPfsRWInode(Ctx *a, u8 *b, s32 c, u8 d);

s32 corrupted(Ctx *arg0, Pair p, u8 *arg2) {
    s32 cnt;
    s32 s1;
    s32 idx;
    s32 v0;
    s32 r;
    u8 s2;
    u16 *q;
    s32 v;

    cnt = 0;
    idx = (p.b.b / 4) + ((p.b.a % 8) << 5);
    s2 = 0;
    if (arg0->unk64 > 0) {
        do {
            v0 = s2;
            if (v0 > 0) {
                s1 = 1;
            } else {
                s1 = arg0->unk60;
            }
            if (s2 == p.b.a || ((arg2 + idx)[0x101] & (1 << (v0 % 8)))) {
                if (arg2[0x100] != v0) {
                    r = __osPfsRWInode(arg0, arg2, 0, s2);
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
                            if (p.h == *q) {
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
            s2++;
        } while (s2 < arg0->unk64);
    }
    return cnt;
}
