#include "types.h"

typedef struct {
    u8 pad0[0xBE];
    s16 unkBE;
    u8 padC0[0xADB - 0xC0];
    s8 unkADB;
} P;
typedef struct {
    u8 pad0[0x92];
    s16 unk92;
    u8 pad94[4];
    f32 unk98;
} A;
typedef struct {
    u8 pad0[0x1CCC];
    P *unk1CCC;
} G;
s32 func_800BDF08(G *arg0, A *arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5) {
    P *p;
    s16 a;
    s16 b;
    s32 t;
    p = arg0->unk1CCC;
    a = (s16) (((((((((((((arg1->unk92 + 0x8000) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) - p->unkBE);
    b = (s16) (arg1->unk92 - arg5);
    if ((arg1->unk98 <= arg2) && (p->unkADB != 0)) {
        if (a < 0) {
            t = -a;
        } else {
            t = a;
        }
        if (arg4 >= t) {
            if (b < 0) {
                t = -b;
            } else {
                t = b;
            }
            if (arg3 >= t) {
                return 1;
            }
        }
    }
    return 0;
}
