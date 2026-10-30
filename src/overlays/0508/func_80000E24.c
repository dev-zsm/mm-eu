// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800B68A8(u8 *);                      /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80B5AE40(u8 *);                      /* extern */
M2C_UNK func_80B5AF2C(u8 *, s32);                 /* extern */
M2C_UNK func_80B5B620(u8 *, s32);                 /* extern */
extern u8 D_801E7F00;

void func_80000E24(Actor *thisx, PlayState *play) {
    func_80B5B620(thisx, play);
    func_80137070((u8 *)thisx + 0x148);
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, s32), 0x144)(thisx, play);
    func_80B5AE40(thisx);
    func_800B64E0(thisx, 0x42080000);
    if (!(D_801E7F00 & 1)) {
        func_80B5AF2C(thisx, play);
    }
    func_800B68A8(thisx);
}
