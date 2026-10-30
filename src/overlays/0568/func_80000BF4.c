// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B763C(M2C_UNK, u8 *, M2C_UNK, M2C_UNK, f32, s32); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80BB4518(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BB4578(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BB49AC(u8 *, M2C_UNK);             /* extern */

void func_80000BF4(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, M2C_UNK), 0x1D4)(thisx, play);
    func_80137070((u8 *)thisx + 0x190);
    func_80BB4578(thisx, play);
    func_80BB49AC(thisx, play);
    func_800B763C(play, thisx, 0x41F00000, 0x41C80000, 0.0f, 5);
    func_80BB4518(thisx, play);
}
