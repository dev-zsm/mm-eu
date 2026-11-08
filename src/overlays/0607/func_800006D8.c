// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0607.h"

M2C_UNK func_80137070(u8 *, u8 *);              /* extern */

void func_800006D8(Actor *thisx) {
    M2C_FIELD(thisx, f32 *, 0x160) = (f32) M2C_FIELD(thisx, f32 *, 0x314);
    func_80137070((u8 *)thisx + 0x144, thisx);
}
