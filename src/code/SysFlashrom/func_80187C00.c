// FLAGS: -g
// COMPILER: ido53
#include "types.h"
#include "generated/code_funcs.h"

extern u8 D_801F4880[];
extern u8 D_801F4890[];
extern s8 D_801F4892;
extern u8 *D_801F4894;
extern u8 *D_801F4898;
extern s32 D_801F489C;
extern s32 D_801F48A0;
extern u8 D_801F48A8[];
extern u8 D_801F48C0[];
extern u32 D_801F48CC;

void func_80088070(void *, s32, s32);
void func_8008EFD0(void *, void *, s32);
void func_8008F490(void *, s32);
void func_80093D50(void *, u32, u32);

void func_80187C00(u32 *arg0, u32 *arg1) {
    u8 sp1F;

    func_80187B4C(&sp1F);
    func_80093D50(D_801F48C0, D_801F48CC | 0x10000, 0xE1000000);
    D_801F4892 = 0;
    D_801F4894 = D_801F48A8;
    D_801F4898 = D_801F4880;
    D_801F489C = 0;
    D_801F48A0 = 8;
    func_8008F490(D_801F4880, 0x10);
    func_8008EFD0(D_801F48C0, D_801F4890, 0);
    func_80088070(D_801F48A8, 0, 1);
    *arg0 = ((u32 *)D_801F4880)[0];
    *arg1 = ((u32 *)D_801F4880)[1];
    return;
}
