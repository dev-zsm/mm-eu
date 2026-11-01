#include "types.h"

extern u8 D_801F48C0[];
extern u32 D_801F48CC;

void func_80093D50(void *arg0, u32 arg1, u32 arg2);

void func_80187D04(void) {
    u32 a;
    u32 b;

    a = D_801F48CC | 0x10000;
    func_80093D50(D_801F48C0, a, 0xD2000000);
    func_80093D50(D_801F48C0, D_801F48CC, 0);
    if (a) {
        return;
    }
    return;
}
