// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_vi.h"

void __osViSwapContext(void) {
    register OSViMode *viMode;
    register OSViContext *viNext;
    u32 origin;
    u32 hStart;
    u32 vStart;
    u32 sp34;
    u32 field;

    field = 0; // matching: dead initialisation
    viNext = D_800982B4;
    viMode = viNext->modep;
    field = IO_READ(VI_CURRENT_REG) & 1;
    origin = osVirtualToPhysical(viNext->framep) + viMode->fldRegs[field].origin;
    if (viNext->state & 2) {
        viNext->x.scale = (viNext->x.scale) | (viMode->comRegs.xScale & ~0xFFF);
    } else {
        viNext->x.scale = viMode->comRegs.xScale;
    }
    if (viNext->state & 4) {
        sp34 = viMode->fldRegs[field].yScale; // matching: scratch copy of the Y-scale
        viNext->y.scale = viNext->y.factor * (sp34 & 0xFFF);
        viNext->y.scale |= viMode->fldRegs[field].yScale & ~0xFFF;
    } else {
        viNext->y.scale = viMode->fldRegs[field].yScale;
    }
    vStart = (viMode->fldRegs[field].vStart - (D_800983BC << 16)) + D_800983BC;
    hStart = viMode->comRegs.hStart;
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
    IO_WRITE(0xA4400004, origin);
    IO_WRITE(0xA4400008, viMode->comRegs.width);
    IO_WRITE(0xA4400014, viMode->comRegs.burst);
    IO_WRITE(0xA4400018, viMode->comRegs.vSync);
    IO_WRITE(0xA440001C, viMode->comRegs.hSync);
    IO_WRITE(0xA4400020, viMode->comRegs.leap);
    IO_WRITE(0xA4400024, hStart);
    IO_WRITE(0xA4400028, vStart);
    IO_WRITE(0xA440002C, viMode->fldRegs[field].vBurst);
    IO_WRITE(0xA440000C, viMode->fldRegs[field].vIntr);
    IO_WRITE(0xA4400030, viNext->x.scale);
    IO_WRITE(0xA4400034, viNext->y.scale);
    IO_WRITE(VI_CONTROL_REG, viNext->control);
    D_800982B4 = D_800982B0;
    D_800982B0 = viNext;
    *D_800982B4 = *D_800982B0;
}
