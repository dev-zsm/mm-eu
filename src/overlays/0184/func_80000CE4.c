// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0184.h"

void func_8094D54C();
void func_80147CC4();
extern u8 D_8094E64C;

void func_80000CE4(u8 *arg0, s32 arg1) {
    func_8094D54C(arg0);
    func_80147CC4(arg1);
    M2C_FIELD(arg0, s32 *, 4) &= ~0x100;
    M2C_FIELD(arg0, u8 **, 0x2C4) = &D_8094E64C;
}
