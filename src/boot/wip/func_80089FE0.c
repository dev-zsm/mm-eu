// FLAGS: -O1 -g3 -mips2
#include "types.h"

extern u8 D_800895C0[];
extern void *D_8009800C;

void *func_80091C00(void);
void func_80091C70(void *a0);

typedef struct {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u16 unk10;
    u16 unk12;
    u32 unk14;
    u32 unk18;
    u8 pad1C[0x1C];
    s64 unk38;
    u8 pad40[0xB0];
    s64 unkF0;
    u8 padF8[0x8];
    s64 unk100;
    u8 pad108[0x10];
    u32 unk118;
    u32 unk11C;
    u32 unk120;
    u32 unk124;
    u32 unk128;
    u32 unk12C;
} Obj;

void func_80089FE0(Obj *p, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    void *s0;
    u32 local;

    local = 0x3FFF01;
    p->unk14 = a1;
    p->unk04 = a5;
    p->unk00 = 0;
    p->unk08 = 0;
    p->unk11C = a2;
    p->unk38 = (s64)a3;
    p->unkF0 = (s64)a4 - 0x10;
    p->unk100 = (s64)(s32)D_800895C0;
    p->unk118 = 0xFF03;
    p->unk128 = (local & 0x3F0000) >> 16;
    p->unk12C = 0x1000800;
    p->unk18 = 0;
    p->unk10 = 1;
    p->unk12 = 0;
    s0 = func_80091C00();
    p->unk0C = (u32)D_8009800C;
    D_8009800C = p;
    func_80091C70(s0);
}
