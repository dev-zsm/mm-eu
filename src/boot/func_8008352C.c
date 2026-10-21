// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern void func_80095AA0(f32 a0);
extern void func_8008B7F0(void *a0);
extern void func_800922A0(s32 a0);
extern void func_8008B010(s32 a0);
extern s32 func_8008ABB0(void);
extern void func_80090000(s32 a0);
extern void func_800848CC(s32 a0, s32 a1, s32 a2);
extern u8 D_800981B0[];
extern void *D_8009C220;
extern s32 D_80000318;
void func_8008352C(void) {
    s32 a;
    s32 v;
    func_80095AA0(1.0f);
    func_8008B7F0(D_800981B0);
    func_800922A0(0x42);
    func_8008B010(0);
    v = *(s32 *)((u8 *)D_8009C220 + 0x844);
    if (v != 0) {
        a = v;
    } else {
        v = func_8008ABB0();
        a = v;
        if (v == 0x80000000) {
            a = (D_80000318 | 0x80000000) + 0xFFFDA800;
        }
    }
    func_80090000(a);
    func_800848CC(a, 0x140, 0xF0);
}
