#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0396.h"
extern struct { u8 pad0[0xF00]; u8 fF00; } D_801E6EF0;
extern u8 D_80AA4084[];
void func_801A9868(u32 a);

void func_8000165C(u8 *a, s32 b) {
    D_801E6EF0.fF00 &= 0xFE;
    M2C_FIELD(a, void **, 0x188) = D_80AA4084;
    func_801A9868(0x100000FF);
    func_801A9868(0x8041);
}
