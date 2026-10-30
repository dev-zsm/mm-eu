#ifndef OS_VI_H
#define OS_VI_H

#include "ultra64.h"

#define VI_CONTROL_REG 0xA4400000
#define VI_CURRENT_REG 0xA4400010

/* Bits of OSViContext.state. */
#define VI_STATE_BLACK 0x20
#define VI_STATE_SWAP_FRAMEBUFFER 0x10
#define VI_STATE_FEATURES 0x08
#define VI_STATE_Y_SCALE 0x04
#define VI_STATE_X_SCALE 0x02

typedef struct {
    /* 0x00 */ u32 ctrl;
    /* 0x04 */ u32 width;
    /* 0x08 */ u32 burst;
    /* 0x0C */ u32 vSync;
    /* 0x10 */ u32 hSync;
    /* 0x14 */ u32 leap;
    /* 0x18 */ u32 hStart;
    /* 0x1C */ u32 xScale;
    /* 0x20 */ u32 vCurrent;
} OSViCommonRegs;

typedef struct {
    /* 0x00 */ u32 origin;
    /* 0x04 */ u32 yScale;
    /* 0x08 */ u32 vStart;
    /* 0x0C */ u32 vBurst;
    /* 0x10 */ u32 vIntr;
} OSViFieldRegs;

typedef struct {
    /* 0x00 */ u32 type;
    /* 0x04 */ OSViCommonRegs comRegs;
    /* 0x28 */ OSViFieldRegs fldRegs[2];
} OSViMode;

typedef struct {
    /* 0x00 */ f32 factor;
    /* 0x04 */ u16 offset;
    /* 0x08 */ u32 scale;
} __OSViScale;

typedef struct {
    /* 0x00 */ u16 state;
    /* 0x02 */ u16 retraceCount;
    /* 0x04 */ void *framep;
    /* 0x08 */ OSViMode *modep;
    /* 0x0C */ u32 control;
    /* 0x10 */ OSMesgQueue *msgq;
    /* 0x14 */ OSMesg msg;
    /* 0x18 */ __OSViScale x;
    /* 0x24 */ __OSViScale y;
} OSViContext;

extern OSViContext D_80098250;
extern OSViContext D_80098280;
extern OSViContext *D_800982B0; /* context the VI registers currently hold */
extern OSViContext *D_800982B4; /* context being prepared for the next retrace */
extern s32 D_800983BC;
extern OSViMode D_80097780;
extern OSViMode D_800981B0;
extern OSViMode D_80098200;
extern s32 D_80098048[];
extern u32 D_80000300;

void __osViInit(void);
void __osViSwapContext(void);
void osViExtendVStart(s32 value);
void osViBlack(u8 active);
void osViSetMode(OSViMode *mode);
void osViSwapBuffer(void *frameBuf);
void osViSetSpecialFeatures(u32 func);
void osViSetEvent(OSMesgQueue *mq, OSMesg msg, u32 retraceCount);
void osViSetYScale(f32 value);
void osViSetXScale(f32 value);
void *osViGetCurrentFramebuffer(void);
s32 osAiSetFrequency(u32 frequency);
u32 osAiGetLength(void);

#endif
