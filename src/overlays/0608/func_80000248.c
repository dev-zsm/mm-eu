#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0608.h"
void func_80137828(u8 *a, void *b, f32 c);

void func_80000248(u8 *a, void **tbl, s16 idx, f32 spd) {
    func_80137828(a + 0x144, tbl[idx], spd);
    M2C_FIELD(a, s16 *, 0x254) = idx;
}
