// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    u8 pad4;
    u8 unk5;
    u8 pad6[0xF];
    u8 unk15;
    u8 pad16[0x6A];
} Ovl0056Ent;

typedef struct {
    u8 pad0[0x57C];
    Ovl0056Ent ent[1];
} Ovl0056Obj;

void func_80005C98(Ovl0056Obj *a, s32 i, s32 c, s32 d) {
    a->ent[i].unk0 = c;
    a->ent[i].unk5 = d;
    if (c == 2) {
        a->ent[i].unk15 = 0x15;
    } else {
        a->ent[i].unk15 = 5;
    }
}
