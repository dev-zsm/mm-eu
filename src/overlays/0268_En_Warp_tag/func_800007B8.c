// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0268.h"

void EnWarptag_Update(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK (**)(), 0x160)();
}
