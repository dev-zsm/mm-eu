// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct Obj Obj;
struct Obj {
    u16 flags;
    u8 pad2[0x6];
    Obj *unk8;
    u8 pad10[0xC];
    f32 unk18;
    u8 pad1C[0x4];
    u32 unk20;
    f32 unk24;
};

extern Obj *D_800982B4;

s32 __osDisableInt(void);
void __osRestoreInt(s32);

void osViSetXScale(f32 arg0) {
    s32 s;
    u32 a;

    s = __osDisableInt();
    (*(Obj **)&D_800982B4)->unk18 = arg0;
    (*(Obj **)&D_800982B4)->flags |= 2;
    a = (*(Obj **)&D_800982B4)->unk8->unk20;
    (*(Obj **)&D_800982B4)->unk20 = (u32)((f32)(a & 0xFFF) * (*(Obj **)&D_800982B4)->unk18) & 0xFFF;
    __osRestoreInt(s);
}
