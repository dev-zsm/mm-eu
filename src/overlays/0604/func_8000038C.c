#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0604.h"
u8 *func_80100304(s32 a);
void func_800FF34C(u8 *a, u8 *b);
void func_800FF860(u8 *a, u8 *b);

void func_8000038C(u8 *a) {
    u8 *p;
    u8 sp28[12];
    u8 sp1C[12];

    p = func_80100304(M2C_FIELD(a, s32 *, 4));
    func_800FF34C(sp28, p);
    func_800FF34C(sp1C, p + 6);
    func_800FF860(sp28, sp1C);
}
