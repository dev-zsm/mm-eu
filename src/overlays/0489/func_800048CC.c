#include "types.h"
#include "m2c_compat.h"
extern s32 D_80B35120;
void func_800B6490(u8 *a);
void func_80137070(u8 *a);

void func_800048CC(u8 *a, s32 b) {
    if (D_80B35120 == 0 || M2C_FIELD(a, s32 *, 0x120) == 0) {
        func_800B6490(a);
    } else {
        func_80137070(a + 0x144);
    }
}
