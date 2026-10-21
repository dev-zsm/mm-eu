// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

typedef struct {
    u8 pad0[0xF4];
    s32 unkF4;
    u8 pad1[0x104 - 0xF8];
    s32 unk104;
    u8 pad2[0x11C - 0x108];
    s32 unk11C;
} Obj80083334;

extern void func_8008198C(void *a0, ...);
extern s32 func_80081DFC(s32 a0);
extern void func_80083030(void *a0, void *a1, void *a2);
extern u8 D_80098C5C[];
extern u8 D_80098C68[];
extern u8 D_80098C84[];
extern u8 D_80098C90[];
extern u8 D_80098C9C[];
extern u8 D_80098CAC[];
extern u8 D_800895C0[];

void func_80083334(Obj80083334 *arg0, s32 arg1) {
    s32 sp50;
    s32 sp58;
    s32 sp54;
    s32 s0;
    s32 s1;

    sp58 = arg0->unkF4;
    sp54 = arg0->unk104;
    sp50 = arg0->unk11C;
    func_8008198C(D_80098C5C);
    func_8008198C(D_80098C68);
    s0 = 1;
    if (sp54 != 0 || sp58 != 0) {
        if (sp50 != (s32)D_800895C0) {
            s1 = arg1 & 1;
            do {
                func_8008198C(D_80098C84, sp58);
                if (s1 != 0) {
                    s32 v = func_80081DFC(sp50);
                    if (v != 0) {
                        func_8008198C(D_80098C90, v);
                    }
                } else {
                    func_8008198C(D_80098C9C);
                }
                func_8008198C(D_80098CAC);
                func_80083030(&sp58, &sp50, &sp54);
                s0++;
                if (s0 >= 0x16) {
                    break;
                }
                if (sp54 == 0 && sp58 == 0) {
                    break;
                }
            } while (sp50 != (s32)D_800895C0);
        }
    }
}
