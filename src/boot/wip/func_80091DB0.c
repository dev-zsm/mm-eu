// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u16 unk0;
    u16 pad2;
    u32 unk4;
    void *unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    f32 unk24;
    u16 unk28;
    u16 pad2A;
    u32 unk2C;
    u32 unk30;
} BootState;

typedef struct {
    u8 pad0[0x8];
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
} BootDesc;

extern s32 func_8008A6E0(u32, void *);
extern BootState *D_800982B4;
extern void *D_800982B0;
extern s32 D_800983BC;

void func_80091DB0(void) {
    BootState *st;
    BootDesc *d;
    BootDesc *e;
    u32 idx;
    s32 a0;
    u32 a3;
    s32 sp34;
    s32 v3;
    u32 *old;
    u32 *p;
    u32 *q;
    u32 *end;

    st = D_800982B4;
    idx = *(u32 *)0xA4400010 & 1;
    d = st->unk8;
    a0 = func_8008A6E0(st->unk4, d);
    e = (BootDesc *)((u8 *)d + idx * 20);
    a0 = e->unk28 + a0;
    if (st->unk0 & 2) {
        st->unk20 = st->unk20 | (d->unk20 & ~0xFFF);
    } else {
        st->unk20 = d->unk20;
    }
    if (st->unk0 & 4) {
        f32 f;
        s32 t;
        t = e->unk2C & 0xFFF;
        f = (f32)t;
        if (t < 0) {
            f += 4294967296.0f;
        }
        st->unk2C = (u32)(st->unk24 * f);
        st->unk2C = (u32)(st->unk2C | (e->unk2C & ~0xFFF));
    } else {
        st->unk2C = e->unk2C;
    }
    sp34 = (e->unk30 - (D_800983BC << 16)) + D_800983BC;
    a3 = d->unk1C;
    v3 = st->unk0;
    if (v3 & 0x20) {
        a3 = 0;
    }
    if (v3 & 0x40) {
        st->unk2C = 0;
        a0 = func_8008A6E0(st->unk4, d);
    }
    v3 = st->unk0;
    if (v3 & 0x80) {
        st->unk2C = (u32)((st->unk28 << 16) & 0x3FF0000);
        a0 = func_8008A6E0(st->unk4, d);
    }
    *(s32 *)0xA4400004 = a0;
    *(u32 *)0xA4400008 = d->unk8;
    *(u32 *)0xA4400014 = d->unkC;
    *(u32 *)0xA4400018 = d->unk10;
    *(u32 *)0xA440001C = d->unk14;
    *(u32 *)0xA4400020 = d->unk18;
    *(u32 *)0xA4400024 = a3;
    *(s32 *)0xA4400028 = sp34;
    *(u32 *)0xA440002C = e->unk34;
    *(u32 *)0xA440000C = e->unk38;
    *(u32 *)0xA4400030 = st->unk20;
    *(u32 *)0xA4400034 = st->unk2C;
    *(u32 *)0xA4400000 = st->unkC;
    old = (u32 *)D_800982B0;
    D_800982B0 = st;
    D_800982B4 = (BootState *)old;
    p = (u32 *)st;
    q = old;
    end = (u32 *)((u8 *)st + 0x30);
    do {
        q[0] = p[0];
        q[1] = p[1];
        q[2] = p[2];
        p += 3;
        q += 3;
    } while (p != end);
}
