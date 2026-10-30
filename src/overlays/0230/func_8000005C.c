// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80115F80(u8 *);                      /* extern */

void func_8000005C(Actor *thisx, PlayState *play) {
    func_80115F80(play);
    M2C_FIELD(play, s8 *, 0x169BC) = 0;
}
