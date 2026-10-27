// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad0[0xA74]; s32 unkA74; } Inner;
typedef struct { u8 pad0[0x1CCC]; Inner *unk1CCC; } Outer;
typedef struct { u8 pad0[0x114]; u8 unk114; } Actor;

s32 Actor_IsTargeted(Outer *arg0, Actor *arg1) {
    Inner *p = arg0->unk1CCC;
    if (p->unkA74 & 0x80000000) {
        if (arg1->unk114 != 0) {
            return 1;
        }
    }
    return 0;
}
