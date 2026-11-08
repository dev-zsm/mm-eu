// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0092.h"

M2C_UNK func_808B0E78(u8 *);                      /* extern */
extern M2C_UNK D_808B3488;

void func_80002A44(Actor *thisx) {
    func_808B0E78(thisx);
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_808B3488;
}
