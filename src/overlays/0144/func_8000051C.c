// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0144.h"

s32 func_8090E770();
s32 func_8090E7F4();
void func_8090EAB8();
void func_8090EC14();

void func_8000051C(u8 *arg0) {
    if (func_8090E770(arg0) == 0 && func_8090E7F4(arg0) == 0) {
        if (M2C_FIELD(arg0, u8 *, 0x2F4) != 0) {
            func_8090EC14(arg0);
            return;
        }
        func_8090EAB8(arg0);
    }
}
