// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    f32 factor;
    u16 offset;
    u32 scale;
} ViScale;

typedef struct {
    u16 state;
    u16 retraceCount;
    void *framep;
    struct ViMode *modep;
    u32 features;
    void *mq;
    void *msg;
    ViScale x;
    ViScale y;
} ViContext;

typedef struct {
    u32 origin;
    u32 yScale;
    u32 vStart;
    u32 vBurst;
    u32 vIntr;
} ViFieldRegs;

typedef struct ViMode {
    u8 type;
    u32 ctrl;
    u32 width;
    u32 burst;
    u32 vSync;
    u32 hSync;
    u32 leap;
    u32 hStart;
    u32 xScale;
    u32 vCurrent;
    ViFieldRegs fldRegs[2];
} ViMode;

extern ViContext *D_800982B4;
extern ViContext *D_800982B0;
extern u32 D_800983BC;
extern u32 osVirtualToPhysical(void *);

void __osViSwapContext(void) {
    register ViMode *vm;
    register ViContext *vc;
    u32 origin;
    u32 hStart;
    u32 field;
    u32 vStart;

    vc = D_800982B4;
    vm = vc->modep;
    field = *(u32 *)0xA4400010 & 1;
    origin = osVirtualToPhysical(vc->framep) + vm->fldRegs[field].origin;
    if (vc->state & 2) {
        vc->x.scale |= vm->xScale & ~0xFFF;
    } else {
        vc->x.scale = vm->xScale;
    }
    if (vc->state & 4) {
        vc->y.scale = vc->y.factor * (vm->fldRegs[field].yScale & 0xFFF);
        vc->y.scale |= vm->fldRegs[field].yScale & ~0xFFF;
    } else {
        vc->y.scale = vm->fldRegs[field].yScale;
    }
    vStart = (vm->fldRegs[field].vStart - (D_800983BC << 16)) + D_800983BC;
    hStart = vm->hStart;
    if (vc->state & 0x20) {
        hStart = 0;
    }
    if (vc->state & 0x40) {
        vc->y.scale = 0;
        origin = osVirtualToPhysical(vc->framep);
    }
    if (vc->state & 0x80) {
        vc->y.scale = (vc->y.offset << 16) & 0x3FF0000;
        origin = osVirtualToPhysical(vc->framep);
    }
    *(u32 *)0xA4400004 = origin;
    *(u32 *)0xA4400008 = vm->width;
    *(u32 *)0xA4400014 = vm->burst;
    *(u32 *)0xA4400018 = vm->vSync;
    *(u32 *)0xA440001C = vm->hSync;
    *(u32 *)0xA4400020 = vm->leap;
    *(u32 *)0xA4400024 = hStart;
    *(u32 *)0xA4400028 = vStart;
    *(u32 *)0xA440002C = vm->fldRegs[field].vBurst;
    *(u32 *)0xA440000C = vm->fldRegs[field].vIntr;
    *(u32 *)0xA4400030 = vc->x.scale;
    *(u32 *)0xA4400034 = vc->y.scale;
    *(u32 *)0xA4400000 = vc->features;
    D_800982B4 = D_800982B0;
    D_800982B0 = vc;
    *D_800982B4 = *D_800982B0;
}
