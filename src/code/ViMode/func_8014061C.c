// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_vimode.h"

void ViMode_Configure(OSViMode* viMode, s32 type, s32 tvType, s32 loRes, s32 antialiasOff, s32 modeN, s32 fb16Bit,
                      s32 width, s32 height, s32 leftAdjust, s32 rightAdjust, s32 upperAdjust, s32 lowerAdjust) {
    s32 hiRes;
    s32 antialiasOn;
    s32 modeF;
    s32 fb32Bit;
    s32 hiResDeflicker; 
    s32 hiResInterlaced;
    s32 loResDeinterlaced;
    s32 loResInterlaced;
    s32 modeLAN1; 
    s32 modeLPN2; 
    s32 modeHPN2; 
    s32 yScaleLo;
    s32 yScaleHiEvenField;
    s32 yScaleHiOddField;

    hiRes = !loRes;
    antialiasOn = !antialiasOff;
    modeF = !modeN;
    fb32Bit = !fb16Bit;

    hiResDeflicker = hiRes && modeF;
    hiResInterlaced = hiRes && modeN;
    loResDeinterlaced = loRes && modeN;
    loResInterlaced = loRes && modeF;

    modeLAN1 = loRes && antialiasOn && modeN && fb16Bit;
    modeLPN2 = loRes && antialiasOff && modeN && fb32Bit;
    modeHPN2 = hiRes && antialiasOff && modeN && fb32Bit;

    upperAdjust &= ~1;
    lowerAdjust &= ~1;

    yScaleLo = (hiResDeflicker ? 2 : 1) * (((SCREEN_HEIGHT << 11) / SCREEN_HEIGHT) / (loRes ? 1 : 2));

    yScaleHiEvenField = modeF ? (loResInterlaced ? 0x1000000 : 0x2000000) : 0;
    yScaleHiOddField = modeF ? (loResInterlaced ? 0x3000000 : 0x2000000) : 0;

    viMode->type = type;
    viMode->comRegs.ctrl = VI_CTRL_PIXEL_ADV_3 | VI_CTRL_GAMMA_ON | VI_CTRL_GAMMA_DITHER_ON |
                           (!loResDeinterlaced ? VI_CTRL_SERRATE_ON : 0) | (antialiasOn ? VI_CTRL_DIVOT_ON : 0) |
                           (fb32Bit ? VI_CTRL_TYPE_32 : VI_CTRL_TYPE_16);

    if (modeLAN1) {
        
        viMode->comRegs.ctrl |= 0x100;
    } else if (modeLPN2 | modeHPN2) {
        
        viMode->comRegs.ctrl |= 0x300;
    } else {
        if (antialiasOff) {
            
            viMode->comRegs.ctrl |= 0x200;
        } else {
            
            viMode->comRegs.ctrl |= 0;
        }
    }

    viMode->comRegs.width = width * (hiResInterlaced ? 2 : 1);

    if (tvType < 3) {
        static const ViModeStruct ref_D_801DF0C0[] = {
            {
                
                BURST(58, 35, 4, 64),
                VSYNC(624),
                HSYNC(3177, 21),
                LEAP(3183, 3182),
                HSTART(128, 768),
                START(95, 569),
                BURST(107, 2, 9, 0),
            },
            {
                
                BURST(57, 34, 5, 62),
                VSYNC(524),
                HSYNC(3093, 0),
                LEAP(3093, 3093),
                HSTART(108, 748),
                START(37, 511),
                BURST(4, 2, 14, 0),
            },
            {
                
                BURST(57, 30, 5, 70),
                VSYNC(524),
                HSYNC(3088, 0),
                LEAP(3100, 3100),
                HSTART(108, 748),
                START(37, 511),
                BURST(4, 2, 14, 0),
            },
        };
        const ViModeStruct* ptr = &ref_D_801DF0C0[tvType];

        viMode->comRegs.burst = ptr->burst;
        viMode->comRegs.vSync = ptr->vSync;
        viMode->comRegs.hSync = ptr->hSync;
        viMode->comRegs.leap = ptr->leap;
        viMode->comRegs.hStart = ptr->hStart;
        viMode->fldRegs[0].vStart = ptr->vStart;
        viMode->fldRegs[1].vStart = ptr->vStart;
        viMode->fldRegs[0].vBurst = ptr->vBurst;
        viMode->fldRegs[1].vBurst = ptr->vBurst;
    } else {
        _dbg_hungup("../z_vimode.c", 276);
    }

    viMode->comRegs.hStart += (leftAdjust << 16) + (s16)rightAdjust;
    viMode->fldRegs[0].vStart += (upperAdjust << 16) + (s16)lowerAdjust;
    viMode->fldRegs[1].vStart += (upperAdjust << 16) + (s16)lowerAdjust;

    if (loResDeinterlaced) {
        viMode->comRegs.vSync++;
        if (tvType == OS_TV_MPAL) {
            viMode->comRegs.hSync += HSYNC(1, 4);
            viMode->comRegs.leap += LEAP(-4, -2);
        }
    } else {
        viMode->fldRegs[0].vStart += START(-3, -2);
        if (tvType == OS_TV_MPAL) {
            viMode->fldRegs[0].vBurst += BURST(-2, -1, 12, -1);
        } else if (tvType == OS_TV_PAL) {
            viMode->fldRegs[1].vBurst += BURST(-2, -1, 2, 0);
        }
    }

    viMode->comRegs.xScale = (SCREEN_WIDTH << 10) / SCREEN_WIDTH;
    viMode->comRegs.vCurrent = 0;

    viMode->fldRegs[0].origin = ORIGIN(width * 2 * (fb16Bit ? 1 : 2));
    viMode->fldRegs[1].origin = ORIGIN(width * 2 * (fb16Bit ? 1 : 2) * (loRes ? 1 : 2));

    viMode->fldRegs[0].yScale = yScaleLo | yScaleHiEvenField;
    viMode->fldRegs[1].yScale = yScaleLo | yScaleHiOddField;

    viMode->fldRegs[0].vIntr = 2;
    viMode->fldRegs[1].vIntr = 2;
}
