// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

typedef struct {
    u16 unk0;
    u8 pad2[0xA];
    u16 unkC;
} Hw;

extern void func_8008431C(s32);
extern void func_80084368(s32);
extern void func_80081E8C(s32);
extern void func_80081F04(void);
extern u8 *D_8009C220;

void func_80082C30(void) {
    Hw *s0;

    s0 = (Hw *)(D_8009C220 + 0x7E4);
    func_8008431C(0xFFFF);
    func_80084368(1);
    do {
loop:
        func_80081E8C(0x10);
        func_80081F04();
        if (~(s0->unkC | -0x81) != 0) {
            goto loop;
        }
    } while (~(s0->unk0 | -0x232) != 0);
}
