#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0374.h"
extern u8 D_80A7AC68[];
void func_800BE0C0(u8 *a, u8 *b, u8 *c, s32 d);

void func_80001564(u8 *a, s32 b) {
    func_800BE0C0(a + 0x24, a + 8, a + 0x30, 0);
    M2C_FIELD(a, s16 *, 0xBE) = M2C_FIELD(a, s16 *, 0x32);
    M2C_FIELD(a, s16 *, 0x39E) = 0;
    M2C_FIELD(a, void **, 0x144) = D_80A7AC68;
}
