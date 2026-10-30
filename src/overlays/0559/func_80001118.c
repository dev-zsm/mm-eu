// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
s32 func_80BAA78C(u8 *, s32);                     /* extern */
M2C_UNK func_80BAAB8C(u8 *);                      /* extern */
M2C_UNK func_80BAAD88(u8 *, s32);                 /* extern */

void func_80001118(Actor *thisx, PlayState *play) {
    func_80BAAB8C(thisx);
    func_80137070((u8 *)thisx + 0x1F0);
    func_800B64E0(thisx, 0x42280000);
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, s32), 0x234)(thisx, play);
    if (func_80BAA78C(thisx, play) == 0) {
        func_80BAAD88(thisx, play);
    }
}
