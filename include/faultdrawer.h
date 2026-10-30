#ifndef FAULTDRAWER_H
#define FAULTDRAWER_H

#include "types.h"
#include "printf.h"

/* Text console of the fault screen, drawn straight into a 16-bit frame buffer. */

#define FAULTDRAWER_NUM_PRINT_COLORS 10

/* RGBA 5551 */
#define FAULT_COLOR_WHITE 0xFFFF
#define FAULT_COLOR_BLACK 0x0001
#define FAULT_COLOR_RED 0xF801
#define FAULT_COLOR_DARK_RED 0xF001

typedef void (*FaultDrawerCallback)(void);

typedef struct {
    /* 0x00 */ u16 *fb;
    /* 0x04 */ u16 w;
    /* 0x06 */ u16 h;
    /* 0x08 */ u16 yStart;
    /* 0x0A */ u16 yEnd;
    /* 0x0C */ u16 xStart;
    /* 0x0E */ u16 xEnd;
    /* 0x10 */ u16 foreColor;
    /* 0x12 */ u16 backColor;
    /* 0x14 */ u16 cursorX;
    /* 0x16 */ u16 cursorY;
    /* 0x18 */ const u32 *font;     /* one word per 8 pixels of a row, 4 bits per pixel */
    /* 0x1C */ u8 charW;
    /* 0x1D */ u8 charH;
    /* 0x1E */ s8 charWPad;
    /* 0x1F */ s8 charHPad;
    /* 0x20 */ u16 printColors[FAULTDRAWER_NUM_PRINT_COLORS]; /* selected by the escape sequence 0x1A '1'..'9' */
    /* 0x34 */ u8 escCode;          /* the previous character was 0x1A */
    /* 0x35 */ u8 osSyncPrintfEnabled;
    /* 0x38 */ FaultDrawerCallback inputCallback;
} FaultDrawer;

extern FaultDrawer *D_80096D80;   /* the drawer in use */
extern FaultDrawer D_80096D84;    /* initial state, copied by FaultDrawer_Init */
extern FaultDrawer D_8009D0A0;    /* the drawer */

void FaultDrawer_SetOsSyncPrintfEnabled(s32 enabled);
void FaultDrawer_DrawRecImpl(s32 xStart, s32 yStart, s32 xEnd, s32 yEnd, u16 color);
void FaultDrawer_DrawChar(char c);
s32 FaultDrawer_ColorToPrintColor(u16 color);
void FaultDrawer_UpdatePrintColor(void);
void FaultDrawer_SetForeColor(u16 color);
void FaultDrawer_SetBackColor(u16 color);
void FaultDrawer_SetFontColor(u16 color);
void FaultDrawer_SetCharPad(s8 padW, s8 padH);
void FaultDrawer_SetCursor(s32 x, s32 y);
void FaultDrawer_FillScreen(void);
void *FaultDrawer_FormatStringFunc(void *arg, const char *str, u32 count);
void FaultDrawer_VPrintf(const char *fmt, va_list args);
void FaultDrawer_Printf(const char *fmt, ...);
void FaultDrawer_DrawText(s32 x, s32 y, const char *fmt, ...);
void FaultDrawer_SetDrawerFrameBuffer(void *fb, u16 w, u16 h);
void FaultDrawer_SetInputCallback(FaultDrawerCallback callback);
void FaultDrawer_Init(void);

#endif
