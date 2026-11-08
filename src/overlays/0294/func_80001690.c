// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

typedef struct {
    u8 pad[0x18884];
    u8 f;
} T0294;

void func_800FF384();
void func_800E26E8();

void func_80001690(u8 *arg0, T0294 *arg1) {
    func_800FF384(arg0 + 0x1DA, arg0 + 0x24);
    M2C_FIELD(arg0, s16 *, 0x1D4) = 0x18;
    M2C_FIELD(arg0, s16 *, 0x1D6) = 0x3E;
    func_800E26E8(arg1, &arg1->f, arg0 + 0x194);
}
