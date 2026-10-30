#ifndef GFXPRINT_H
#define GFXPRINT_H

#include "types.h"
#include "printf.h"

/* Display list command words of the RDP/RSP (two 32-bit words). */
typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef union {
    struct {
        u8 r;
        u8 g;
        u8 b;
        u8 a;
    } c;
    u32 rgba;
} ColorRGBA8;

#define GFXPRINT_FLAG_1 0x01
#define GFXPRINT_FLAG_2 0x02
#define GFXPRINT_FLAG_4 0x04
#define GFXPRINT_FLAG_8 0x08
#define GFXPRINT_FLAG_OPEN 0x80  /* set by GfxPrint_Open, cleared by GfxPrint_Close */

typedef struct {
    /* 0x00 */ PrintfCallback callback;
    /* 0x04 */ Gfx *dList;  /* next free display list slot */
    /* 0x08 */ u16 posX;    /* in 1/4 pixel */
    /* 0x0A */ u16 posY;
    /* 0x0C */ u16 baseX;
    /* 0x0E */ u8 baseY;
    /* 0x0F */ u8 flags;
    /* 0x10 */ ColorRGBA8 color;
} GfxPrint;

void GfxPrint_SetColor(GfxPrint *this, u32 r, u32 g, u32 b, u32 a);
void GfxPrint_SetPosPx(GfxPrint *this, s32 x, s32 y);
void GfxPrint_SetPos(GfxPrint *this, s32 x, s32 y);
void GfxPrint_SetBasePosPx(GfxPrint *this, s32 x, s32 y);
void GfxPrint_Setup(GfxPrint *this);
void GfxPrint_PrintCharImpl(GfxPrint *this, u8 c);
void GfxPrint_PrintChar(GfxPrint *this, u8 c);
void GfxPrint_PrintStringWithSize(GfxPrint *this, const char *str, size_t size, size_t count);
void GfxPrint_PrintString(GfxPrint *this, const char *str);
void *GfxPrint_Callback(void *arg, const char *str, size_t size);
void GfxPrint_Init(GfxPrint *this);
void GfxPrint_Destroy(GfxPrint *this);
void GfxPrint_Open(GfxPrint *this, Gfx *dList);
Gfx *GfxPrint_Close(GfxPrint *this);
s32 GfxPrint_VPrintf(GfxPrint *this, const char *fmt, va_list args);
s32 GfxPrint_Printf(GfxPrint *this, const char *fmt, ...);

#endif
