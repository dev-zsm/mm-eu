// FLAGS: -g
// COMPILER: ido53
#include "types.h"

extern u8 D_801F48C0[];
extern u32 D_801F48CC;

void func_80093D50(void *, u32, u32);
void func_80092250(void *, u32, u32 *);

void func_80187B4C(u8 *arg0) {
    u32 sp1C;

    func_80093D50(D_801F48C0, D_801F48CC | 0x10000, 0xD2000000);
    func_80092250(D_801F48C0, D_801F48CC, &sp1C);
    func_80093D50(D_801F48C0, D_801F48CC | 0x10000, 0xD2000000);
    func_80092250(D_801F48C0, D_801F48CC, &sp1C);
    *arg0 = sp1C & 0xFF;
    return;
}
