// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
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
    register ViMode *viMode;
    register ViContext *viNext;
    u32 origin;
    u32 hStart;
    u32 vStart;
    u32 sp34;
    u32 field;

    field = 0; // matching: dead initialisation
    viNext = D_800982B4;
    viMode = viNext->modep;
    field = *(u32 *)0xA4400010 & 1;
    origin = osVirtualToPhysical(viNext->framep) + viMode->fldRegs[field].origin;
    if (viNext->state & 2) {
        viNext->x.scale = (viNext->x.scale) | (viMode->xScale & ~0xFFF);
    } else {
        viNext->x.scale = viMode->xScale;
    }
    if (viNext->state & 4) {
        sp34 = viMode->fldRegs[field].yScale; // matching: scratch copy of the Y-scale
        viNext->y.scale = viNext->y.factor * (sp34 & 0xFFF);
        viNext->y.scale |= viMode->fldRegs[field].yScale & ~0xFFF;
    } else {
        viNext->y.scale = viMode->fldRegs[field].yScale;
    }
    vStart = (viMode->fldRegs[field].vStart - (D_800983BC << 16)) + D_800983BC;
    hStart = viMode->hStart;
    if (viNext->state & 0x20) {
        hStart = 0;
    }
    if (viNext->state & 0x40) {
        viNext->y.scale = 0;
        origin = osVirtualToPhysical(viNext->framep);
    }
    if (viNext->state & 0x80) {
        viNext->y.scale = (viNext->y.offset << 16) & 0x3FF0000;
        origin = osVirtualToPhysical(viNext->framep);
    }
    *(u32 *)0xA4400004 = origin;
    *(u32 *)0xA4400008 = viMode->width;
    *(u32 *)0xA4400014 = viMode->burst;
    *(u32 *)0xA4400018 = viMode->vSync;
    *(u32 *)0xA440001C = viMode->hSync;
    *(u32 *)0xA4400020 = viMode->leap;
    *(u32 *)0xA4400024 = hStart;
    *(u32 *)0xA4400028 = vStart;
    *(u32 *)0xA440002C = viMode->fldRegs[field].vBurst;
    *(u32 *)0xA440000C = viMode->fldRegs[field].vIntr;
    *(u32 *)0xA4400030 = viNext->x.scale;
    *(u32 *)0xA4400034 = viNext->y.scale;
    *(u32 *)0xA4400000 = viNext->features;
    D_800982B4 = D_800982B0;
    D_800982B0 = viNext;
    *D_800982B4 = *D_800982B0;
}
