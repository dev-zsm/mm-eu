// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u32 flags;
    u8 pad4[0x5C];
    s32 unk60;
    u8 unk64;
} Obj;

extern s32 __osCheckId(Obj *p);
extern s32 __osPfsRWInode(Obj *p, u16 *buf, s32 zero, u8 i);

s32 osPfsFreeBlocks(Obj *p, s32 *out) {
    u16 buf[0x80]; s32 n; s32 start; s32 j; s32 err; u8 i;

    n = 0;
    if (!(p->flags & 1)) {
        return 5;
    }
    err = __osCheckId(p);
    if (err != 0) {
        return err;
    }
    for (i = 0; i < p->unk64; i++) {
        err = __osPfsRWInode(p, buf, 0, i);
        if (err != 0) {
            return err;
        }
        if (i > 0) { start = 1; } else { start = p->unk60; }
        for (j = start; j < 0x80; j++) {
            if (buf[j] == 3) {
                n++;
            }
        }
    }
    *out = n << 8;
    return 0;
}
