// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0144.h"

void func_800F1944(s8, u8 *);
void func_800BE288();
extern u8 D_8090FB88;

void func_8000172C(u8 *arg0, u8 *arg1) {
    func_800F1944(M2C_FIELD(arg0, s8 *, 0x38), arg1);
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    if (M2C_FIELD(arg0, u8 *, 0xB7) != 0) {
        func_800BE288(arg0, arg0 + 0x3AC);
    }
    M2C_FIELD(arg0, u8 **, 0x2F0) = &D_8090FB88;
}
