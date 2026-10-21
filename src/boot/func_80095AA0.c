// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct Obj {
    u16 flags;
    u8 pad2[0x22];
    f32 unk24;
} Obj;

extern Obj *D_800982B4;

s32 func_80091C00(void);
void func_80091C70(s32, void *);

void func_80095AA0(f32 arg0) {
    s32 s;

    s = func_80091C00();
    (*(Obj **)&D_800982B4)->unk24 = arg0;
    (*(Obj **)&D_800982B4)->flags |= 4;
    func_80091C70(s, &D_800982B4);
}
