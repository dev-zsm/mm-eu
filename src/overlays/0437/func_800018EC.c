#include "types.h"
#include "m2c_compat.h"
void func_800F1D6C(s16 a);
void func_80147CC4(u8 *a);
void func_800B6490(u8 *a);

void func_800018EC(u8 *a, u8 *play) {
    M2C_FIELD(a, s16 *, 0x2E8) -= 1;
    if (M2C_FIELD(a, s16 *, 0x2E8) <= 0) {
        func_800F1D6C(M2C_FIELD(a, s16 *, 0x314));
        func_80147CC4(play);
        func_800B6490(a);
    }
}
