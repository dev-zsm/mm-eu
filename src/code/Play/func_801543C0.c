#include "types.h"
void func_8014B214(void);
void func_8015A62C(u8 *, s32, s32);
void func_8015F95C(void);
extern u8 D_801EAE32;
void func_801543C0(u8 *a0, s32 a1) {
    if ((D_801EAE32 == 0) && (*(s16 *)(a0 + 0x1699C) == 0)) {
        func_8014B214();
        return;
    }
    if (*(s16 *)(a0 + 0x1699C) != 0) {
        func_8015F95C();
        return;
    }
    func_8015A62C(a0, a1, 0);
}
