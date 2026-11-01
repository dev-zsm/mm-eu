#include "types.h"
extern u8 D_801F48C0[];
extern u32 D_801F48CC;
void func_80093D50(void *a, u32 b, u32 c);
void func_80092250(void *a, u32 b, u32 *c);
void func_80187B4C(u8 *out) {
    u32 v;
    u32 t;
    t = D_801F48CC | 0x10000;
    func_80093D50(D_801F48C0, t, 0xD2000000);
    func_80092250(D_801F48C0, D_801F48CC, &v);
    t = D_801F48CC | 0x10000;
    func_80093D50(D_801F48C0, t, 0xD2000000);
    func_80092250(D_801F48C0, D_801F48CC, &v);
    *out = v;
}
