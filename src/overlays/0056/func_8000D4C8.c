// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

void func_80830B44();
void func_8082DBC4();
extern u8 D_80849960;
extern s32 D_8085B58C[];

void func_8000D4C8(u8 *arg0, s32 arg1) {
    func_80830B44(arg1, arg0, &D_80849960, 1);
    func_8082DBC4(arg1, arg0, D_8085B58C[M2C_FIELD(arg0, u8 *, 0x14F)]);
}
