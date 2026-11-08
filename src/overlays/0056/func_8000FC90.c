// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80830B44();
void func_8082D1C8();
extern u8 D_8084DD50;
extern s32 D_8085B814[];

void func_8000FC90(u8 *arg0, s32 arg1) {
    func_80830B44(arg1, arg0, &D_8084DD50, 1);
    func_8082D1C8(arg1, arg0, D_8085B814[M2C_FIELD(arg0, u8 *, 0x14F)]);
}
