#include "types.h"

extern void func_8017A38C(void);
extern void func_80089610(s32 a0);
extern u32 D_80000318;

void func_8017A51C(void) {
    if (D_80000318 >= 0x800000) {
        return;
    }
    func_8017A38C();
    func_80089610(0);
    while (1) {
    }
}
