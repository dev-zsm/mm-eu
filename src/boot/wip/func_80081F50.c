// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"
extern u8 *D_8009C220;
extern void func_80081E8C(s32 a);
extern void func_80081F04(void);
extern void func_80083F10(s32 a);
s32 func_80081F50(void) {
    u16 * volatile ptr;
    s32 timeout;
    s32 btn;
    ptr = (u16 *)(D_8009C220 + 0x7E4);
    timeout = 0x258;
    for (;;) {
        func_80081E8C(0x10);
        func_80081F04();
        btn = ptr[6];
        if (0x20 == btn) {
            D_8009C220[0x7CF] = (D_8009C220[0x7CF] == 0);
        }
        if (D_8009C220[0x7CF] != 0) {
            if (timeout-- < 1) return 0;
            continue;
        }
        if (0x8000 == btn || 0x100 == btn) return 0;
        if (0x200 == btn) return 1;
        if (0x800 == btn) func_80083F10(1);
        if (0x400 == btn) func_80083F10(0);
    }
}
