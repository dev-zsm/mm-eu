// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_8013DD78(M2C_UNK, u8 *, u8 *, M2C_UNK); /* extern */
M2C_UNK func_80B9652C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B96A2C(u8 *);                      /* extern */
M2C_UNK func_80B96AA4(u8 *);                      /* extern */
M2C_UNK func_80B96D6C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B96E28(u8 *, M2C_UNK);             /* extern */

void func_80001FD0(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, M2C_UNK), 0x188)(thisx, play);
    func_80B96D6C(thisx, play);
    func_80B96E28(thisx, play);
    func_80B96A2C(thisx);
    func_8013DD78(play, (u8 *)thisx + 0x238, (u8 *)thisx + 0x232, 3);
    func_80B96AA4(thisx);
    func_80B9652C(thisx, play);
}
