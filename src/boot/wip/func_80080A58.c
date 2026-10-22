// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { u32 unk0; u32 unk4; u32 unk8; } Arg;
typedef struct { u32 unk0; u32 unk4; u32 unk8; u32 unkC; } Entry;
extern u16 D_8009B68C;
extern Entry D_8009FC80[];
extern u8 D_80098454[];
extern u8 D_80098464[];
extern u8 D_80098474[];
extern u8 D_80098484[];
s32 DmaMgr_FindDmaIndex(u32 start, Arg *arg);
void func_800807E0(u32 a, u32 b, u32 c, u32 d);
void DmaMgr_ProcessRequest(Arg *arg) {
    s32 idx;
    u32 start;
    u32 size;
    Entry *e;
    u32 len;
    u32 base;

    start = arg->unk0;
    size = arg->unk8;
    idx = DmaMgr_FindDmaIndex(start, arg);
    if (idx >= 0 && idx < (s32)D_8009B68C) {
        e = &D_8009FC80[idx];
        if (e->unkC == 0) {
            if (e->unk4 < start + size) {
                Fault_AddHungupAndCrash(D_80098454, 0x1F3);
            }
            e = &D_8009FC80[idx];
            func_800807E0(e->unk8 + start - e->unk0, arg->unk4, size, start);
            return;
        }
        base = e->unk8;
        len = e->unkC - base;
        if (start != e->unk0) {
            Fault_AddHungupAndCrash(D_80098464, 0x206);
        }
        e = &D_8009FC80[idx];
        if (size != e->unk4 - e->unk0) {
            Fault_AddHungupAndCrash(D_80098474, 0x20D);
        }
        osSetThreadPri(0, 0xA);
        Yaz0_Decompress(base, arg->unk4, len);
        osSetThreadPri(0, 0x11);
        return;
    }
    Fault_AddHungupAndCrash(D_80098484, 0x22E);
}
