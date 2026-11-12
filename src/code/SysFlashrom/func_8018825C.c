// FLAGS: -g
// COMPILER: ido53
#include "types.h"
#include "generated/code_funcs.h"

extern u8 D_801F48C0[];
extern u32 D_801F48CC;
extern s32 D_801F4938;

void func_80088070(void *, void *, s32);
void func_8008F3E0(void *, void *, s32);
void func_80092250(void *, u32, u32 *);
void func_80093D50(void *, u32, u32);
void func_800942F0(void *, u64, u64, void *, void *);

s32 func_8018825C(u32 arg0) {
    u32 sp6C;
    u8 sp48[0x24];
    u8 sp30[0x18];
    u8 sp2C[4];

    if (D_801F4938 == 1) {
        func_80093D50(D_801F48C0, D_801F48CC | 0x10000, 0xB4000000);
    }
    func_80093D50(D_801F48C0, D_801F48CC | 0x10000, arg0 | 0xA5000000);
    func_8008F3E0(sp30, sp2C, 1);
    do {
        func_800942F0(sp48, 0x249F, 0, sp30, sp2C);
        func_80088070(sp30, sp2C, 1);
        func_80092250(D_801F48C0, D_801F48CC, &sp6C);
    } while ((sp6C & 1) == 1);
    func_80092250(D_801F48C0, D_801F48CC, &sp6C);
    func_80187D04();
    if ((sp6C & 0xFF) == 4 || (sp6C & 0xFF) == 0x44 || (sp6C & 4) == 4) {
        return 0;
    } else {
        return -1;
    }
}
