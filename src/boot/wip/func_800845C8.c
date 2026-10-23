// FLAGS: -O2 -g3 -mips2 -trapuv
// best attempt: 6 instr differ (switch var in a0 ok; esc-branch temp is v1 instead of a1, beq vs beql at first case)
#include "types.h"

typedef struct {
    void *fb;
    u16 w;
    u16 h;
    u16 yStart;
    u16 yEnd;
    u16 xStart;
    u16 xEnd;
    u16 foreColor;
    u16 backColor;
    u16 cursorX;
    u16 cursorY;
    void *font;
    u8 charW;
    u8 charH;
    s8 charWPad;
    s8 charHPad;
    u16 printColors[10];
    u8 escCode;
    u8 osSyncPrintfEnabled;
    u8 pad36[2];
    void (*inputCallback)(void);
} FaultDrawer;

extern FaultDrawer *D_80096D80;
extern u8 D_80099308[];
extern u8 D_8009930C[];

void func_8008198C(void *fmt, ...);
void FaultDrawer_SetForeColor(u16 color);
void FaultDrawer_DrawChar(u8 c);
void FaultDrawer_FillScreen(void);
void osWritebackDCacheAll(void);

s32 FaultDrawer_FormatStringFunc(s32 arg, u8 *str, s32 count) {
    for (; count != 0; count--, str++) {
        if (D_80096D80->escCode) {
            D_80096D80->escCode = 0;
            if (*str >= '1' && *str <= '9') {
                FaultDrawer_SetForeColor(D_80096D80->printColors[*str - '0']);
            }
        } else {
            switch (*str) {
                case '\n':
                    if (D_80096D80->osSyncPrintfEnabled) {
                        func_8008198C(D_80099308);
                    }
                    D_80096D80->cursorX = D_80096D80->w;
                    break;
                case 0x1A:
                    D_80096D80->escCode = 1;
                    break;
                default:
                    if (D_80096D80->osSyncPrintfEnabled) {
                        func_8008198C(D_8009930C);
                    }
                    FaultDrawer_DrawChar(*str);
                    D_80096D80->cursorX += D_80096D80->charW + D_80096D80->charWPad;
                    break;
            }
        }
        if (D_80096D80->cursorX >= (D_80096D80->xEnd - D_80096D80->charW)) {
            D_80096D80->cursorX = D_80096D80->xStart;
            D_80096D80->cursorY += D_80096D80->charH + D_80096D80->charHPad;
            if (D_80096D80->cursorY >= (D_80096D80->yEnd - D_80096D80->charH)) {
                if (D_80096D80->inputCallback != NULL) {
                    D_80096D80->inputCallback();
                    FaultDrawer_FillScreen();
                }
                D_80096D80->cursorY = D_80096D80->yStart;
            }
        }
    }
    osWritebackDCacheAll();
    return arg;
}
