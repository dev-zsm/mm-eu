// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 unk0_0 : 4;
    u8 unk0_4 : 2;
    u8 unk0_6 : 2;
    u8 pad1[3];
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Entry2054;

typedef struct {
    u8 unk0;
    u8 unk1;
    u16 unk2;
    u8 pad4[0xC];
    s32 unk10;
    u8 pad14[0xC];
    Entry2054 unk20;
} Obj2054;

Entry2054 *func_80191FBC(u8, u16, Obj2054 *);

void func_80192054(Obj2054 *arg0) {
    Entry2054 *e;

    if (arg0->unk20.unk4 != 0) {
        e = func_80191FBC(arg0->unk1, arg0->unk2, arg0);
        if (e != NULL) {
            arg0->unk20 = *e;
            e->unk4 = arg0->unk10;
            e->unk0_4 = 0;
        }
    }
}
