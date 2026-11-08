// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0612.h"

void EnScopecoin_Update(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK (**)(), 0x144)();
}
