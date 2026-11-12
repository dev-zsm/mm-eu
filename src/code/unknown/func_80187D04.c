// FLAGS: -g
// COMPILER: ido53
#include "types.h"
#include "generated/code_funcs.h"

extern u8 D_801F48C0[];
extern u32 D_801F48CC;

void func_80093D50(void *, u32, u32);

void func_80187D04(void) {
    func_80093D50(D_801F48C0, D_801F48CC | 0x10000, 0xD2000000);
    func_80093D50(D_801F48C0, D_801F48CC, 0);
    return;
}
