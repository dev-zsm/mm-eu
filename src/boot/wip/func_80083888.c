// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 *D_8009C220;
extern u8 D_80098DF8[];
extern u8 D_80098DDC[];
extern u8 D_80098DB8[];
extern u8 D_80098D18[];
extern u8 D_80098D50[];
extern u8 D_80098D84[];
extern u8 D_80098E14[];
extern u8 D_80098E30[];
extern u8 D_80098E4C[];

void func_8008D7E0(s32 a0, u8 *a1, s32 a2);
void func_80088070(u8 *a0, s32 *a1, s32 a2);
void func_8008198C(void *a0, ...);
void func_80083844(void);
s32 func_80095790(void);
s32 func_80082B18(void);
s32 func_80092E90(void);
void func_80092E80(s32 a0);
void func_80081E8C(s32 a0);
void func_8008352C(void);
void func_80082BA0(void);
void func_800821E0(s32 a0);
void func_80082C30(void);
void func_8008431C(s32 a0);
void func_80084368(s32 a0);
void func_800824CC(u8 *a0);
void func_8008281C(u8 *a0);
void func_8008209C(void);
void func_800831A4(u8 *a0, s32 a1);
void func_80083334(u8 *a0, s32 a1);
void func_800835EC(void);
void func_80082E38(s32 a0, s32 a1, s32 a2, s32 a3);
void func_8008218C(void);
void func_8008487C(s32 a0, s32 a1, void *a2, ...);
void func_800834B0(u8 *a0);

void func_80083888(s32 a0) {
    u8 **s1;
    u8 *s0;
    s32 sp54;

    s1 = &D_8009C220;
    func_8008D7E0(0xA, *s1 + 0x7B0, 1);
    func_8008D7E0(0xC, *s1 + 0x7B0, 2);
    do {
        do {
            func_80088070(*s1 + 0x7B0, &sp54, 1);
            if (sp54 == 3) {
                s0 = NULL;
                func_80083844();
            } else {
                if (sp54 == 1) {
                    (*s1)[0x7CD] = 1;
                    func_8008198C(D_80098D18);
                } else if (sp54 == 2) {
                    (*s1)[0x7CD] = 2;
                    func_8008198C(D_80098D50);
                } else {
                    (*s1)[0x7CD] = 3;
                    func_8008198C(D_80098D84);
                }
                s0 = (u8 *)func_80095790();
                func_8008198C(D_80098DB8, s0);
                if (s0 == NULL) {
                    s0 = (u8 *)func_80082B18();
                    func_8008198C(D_80098DDC, s0);
                }
            }
        } while (s0 == NULL);
        func_80092E80(func_80092E90() & ~0xF80);
        *(s32 *)(*s1 + 0x7D0) = (s32)s0;
        while ((*s1)[0x7CE] == 0) {
            func_80081E8C(0x3E8);
        }
        func_80081E8C(0x1F4);
        func_8008352C();
        if ((*s1)[0x7CF] != 0) {
            func_80082BA0();
        } else {
            func_800821E0(0xF801);
            func_80082C30();
        }
        (*s1)[0x7CF] = 1;
        func_8008431C(0xFFFF);
        func_80084368(0);
        do {
            func_800824CC(s0);
            func_8008281C(s0);
            func_8008209C();
            func_800831A4(s0, 0);
            func_80083334(s0, 0);
            func_8008209C();
            func_800835EC();
            func_80082E38(*(s32 *)(s0 + 0x11C) - 0x100, *(s32 *)(s0 + 0xF4), 0, 0);
            func_800831A4(s0, 1);
            func_80083334(s0, 1);
            func_8008209C();
            func_8008218C();
            func_8008487C(0x40, 0x50, D_80098DF8);
            func_8008487C(0x40, 0x5A, D_80098E14);
            func_8008487C(0x40, 0x64, D_80098E30);
            func_8008487C(0x40, 0x6E, D_80098E4C);
            func_8008209C();
        } while ((*s1)[0x7CC] == 0);
        func_800834B0(s0);
    } while (1);
}
