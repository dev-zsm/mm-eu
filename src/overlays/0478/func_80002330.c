#include "types.h"
#include "m2c_compat.h"
void func_80B17EF8(u8 *a, s32 b);
void func_80B18548(u8 *a, s32 b);

void func_80002330(u8 *a, s32 b) {
    if (M2C_FIELD(a, u8 *, 0x1ED) > 0) {
        func_80B17EF8(a, b);
    }
    if (M2C_FIELD(a, u8 *, 0x1ED) != 0xFF) {
        func_80B18548(a, b);
    }
}
