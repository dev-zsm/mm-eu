// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_808360A4();
void func_8082D2E8();
s32 func_80124664();
void func_8082DAE8();
extern s32 D_8085C658[];

void func_80013410(u8 *arg0, s32 arg1) {
    func_808360A4(arg0, arg1);
    func_8082D2E8(arg0);
    func_8082DAE8(arg1, arg0, D_8085C658[func_80124664(arg0)]);
    M2C_FIELD(arg0, s16 *, 0xAD4) = M2C_FIELD(arg0, s16 *, 0xBE);
}
