// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80BFD978(u8 *);                      /* extern */

void func_80000304(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK (**)(), 0x188)();
    func_80137070((u8 *)thisx + 0x144);
    func_80BFD978(thisx);
}
