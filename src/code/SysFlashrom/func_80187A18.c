// FLAGS: -g
// COMPILER: ido53
#include "types.h"

extern u8 D_801F48A8[];
extern u8 D_801F4934[];
extern u32 D_801F48CC;
extern u8 D_801F48C0[];
extern u8 D_801F48C4;
extern u8 D_801F48C5;
extern u8 D_801F48C6;
extern u8 D_801F48C7;
extern u8 D_801F48C8;
extern u8 D_801F48C9;
extern s32 D_801F48D0;
extern s32 D_801F4938;

void func_8008F3E0(void *, void *, s32);
void func_800897D0(void *, s32);
void func_8008AFC0(void *);
void func_80187C00(u32 *, u32 *);

void *func_80187A18(void) {
    u32 sp1C;
    u32 sp18;

    func_8008F3E0(D_801F48A8, D_801F4934, 1);
    if (D_801F48CC == 0xA8000000) {
        return D_801F48C0;
    }
    D_801F48C4 = 8;
    D_801F48CC = 0xA8000000;
    D_801F48C5 = 5;
    D_801F48C8 = 0xC;
    D_801F48C6 = 0xF;
    D_801F48C7 = 2;
    D_801F48C9 = 1;
    D_801F48D0 = 0;
    func_800897D0(D_801F48C0 + 0x14, 0x60);
    func_8008AFC0(D_801F48C0);
    func_80187C00(&sp1C, &sp18);
    if (sp18 == 0xC2001E || sp18 == 0xC20001 || sp18 == 0xC20000) {
        D_801F4938 = 0;
    } else {
        D_801F4938 = 1;
    }
    return D_801F48C0;
}
