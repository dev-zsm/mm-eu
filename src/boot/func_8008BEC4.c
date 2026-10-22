// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x60];
    s32 unk60;
} Obj;

s32 __osPfsDeclearPage(Obj *obj, u16 *tbl, s32 n, s32 *cnt, u8 i, s32 *p1, s32 *p2) {
    s32 v;
    s32 idx;
    s32 found;
    s32 last;
    u8 *bytes;

    if (i > 0) {
        v = 1;
    } else {
        v = obj->unk60;
    }
    idx = v;
    while (idx < 0x80) {
        if (tbl[idx] == 3) {
            break;
        }
        idx++;
    }
    if (idx == 0x80) {
        *cnt = -1;
        return 0;
    }
    found = idx;
    *p1 = 1;
    last = found;
    idx = found + 1;
    bytes = (u8 *)tbl;
    if (n >= 2 && idx < 0x80) {
        do {
            if (tbl[idx] == 3) {
                bytes[last * 2] = i;
                bytes[last * 2 + 1] = idx;
                (*p1)++;
                last = idx;
            }
            idx++;
        } while (*p1 < n && idx < 0x80);
    }
    *cnt = found;
    if (idx == 0x80 && *p1 < n) {
        *p2 = last;
    } else {
        tbl[last] = 1;
        *p2 = 0;
    }
    return 0;
}
