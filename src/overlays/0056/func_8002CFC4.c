#include "types.h"
#include "generated/overlays/0056.h"
s32 func_80136480();
s32 func_800F1E2C();
void func_800F1D6C();
void func_8002CFC4(s32 a, u8 *p, s32 c) {
    if (func_80136480(a, p + 0x240) != 0 && func_800F1E2C() == 0x7D) {
        func_800F1D6C(0x7D);
    }
}
