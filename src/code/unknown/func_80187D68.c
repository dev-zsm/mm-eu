// FLAGS: -g
// COMPILER: ido53
#include "types.h"

extern u8 D_801F48C0[];
extern u32 D_801F48CC;

void func_80088070(void *, void *, s32);
void func_8008F3E0(void *, void *, s32);
void func_80092250(void *, u32, u32 *);
void func_80093D50(void *, u32, u32);
void func_800942F0(void *, u64, u64, void *, void *);
void func_80187D04(void);

s32 func_80187D68(void) {
    u32 sp6C;
    u8 sp48[0x24];
    u8 sp30[0x18];
    u8 sp2C[4];

    func_80093D50(D_801F48C0, D_801F48CC | 0x10000, 0x3C000000);
    func_80093D50(D_801F48C0, D_801F48CC | 0x10000, 0x78000000);
    func_8008F3E0(sp30, sp2C, 1);
    do {
        func_800942F0(sp48, 0xABA95, 0, sp30, sp2C);
        func_80088070(sp30, sp2C, 1);
        func_80092250(D_801F48C0, D_801F48CC, &sp6C);
    } while ((sp6C & 2) == 2);
    func_80092250(D_801F48C0, D_801F48CC, &sp6C);
    func_80187D04();
    if ((sp6C & 0xFF) == 8 || (sp6C & 0xFF) == 0x48 || (sp6C & 8) == 8) {
        return 0;
    } else {
        return -1;
    }
}
