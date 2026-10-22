// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 *D_80096D80;
extern u8 D_80099308[];
extern u8 D_8009930C[];

void func_8008198C(void *fmt, ...);
void FaultDrawer_SetForeColor(u16 a0);
void FaultDrawer_DrawChar(s32 a0);
void FaultDrawer_FillScreen(void);
void osWritebackDCacheAll(void);

s32 FaultDrawer_FormatStringFunc(s32 a0, u8 *s, s32 n) {
    u8 *ctx;
    u8 d;
    void (*fn)(void);

    for (; n != 0; s++) {
        ctx = D_80096D80;
        if (ctx[0x34] != 0) {
            ctx[0x34] = 0;
            d = *s;
            if (d >= 0x31 && d < 0x3A) {
                FaultDrawer_SetForeColor(*(u16 *)(ctx + (d << 1) - 0x40));
            }
        } else {
            ctx = D_80096D80;
            if (*s == 10) {
                if (ctx[0x35] != 0) {
                    func_8008198C(D_80099308);
                }
                ctx = D_80096D80;
                *(u16 *)(ctx + 0x14) = *(u16 *)(ctx + 0x4);
            } else if (*s == 0x1A) {
                ctx[0x34] = 1;
            } else {
                if (ctx[0x35] != 0) {
                    func_8008198C(D_8009930C);
                }
                FaultDrawer_DrawChar(*s);
                ctx = D_80096D80;
                *(u16 *)(ctx + 0x14) = *(u16 *)(ctx + 0x14) + ctx[0x1C] + *(s8 *)(ctx + 0x1E);
            }
        }
        ctx = D_80096D80;
        if (*(u16 *)(ctx + 0x14) < *(u16 *)(ctx + 0xE) - ctx[0x1C]) {
            n--;
            continue;
        }
        *(u16 *)(ctx + 0x14) = *(u16 *)(ctx + 0xC);
        *(u16 *)(ctx + 0x16) = *(u16 *)(ctx + 0x16) + ctx[0x1D] + *(s8 *)(ctx + 0x1F);
        if (*(u16 *)(ctx + 0x16) < *(u16 *)(ctx + 0xA) - ctx[0x1D]) {
            n--;
            continue;
        }
        fn = *(void (**)(void))(ctx + 0x38);
        if (fn != NULL) {
            fn();
            FaultDrawer_FillScreen();
            ctx = D_80096D80;
        }
        *(u16 *)(ctx + 0x16) = *(u16 *)(ctx + 0x8);
        n--;
    }
    osWritebackDCacheAll();
    return a0;
}
