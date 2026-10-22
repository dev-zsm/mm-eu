// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct Obj {
    u16 flags;
    u8 pad2[0x22];
    f32 unk24;
} Obj;

extern Obj *D_800982B4;

s32 __osDisableInt(void);
void __osRestoreInt(s32, void *);

void osViSetYScale(f32 arg0) {
    s32 s;

    s = __osDisableInt();
    (*(Obj **)&D_800982B4)->unk24 = arg0;
    (*(Obj **)&D_800982B4)->flags |= 4;
    __osRestoreInt(s, &D_800982B4);
}
