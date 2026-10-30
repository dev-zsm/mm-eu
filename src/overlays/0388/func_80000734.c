// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80A96F98(u8 *, u8 *);              /* extern */
M2C_UNK func_80A971EC(u8 *, u8 *);              /* extern */

void func_80000734(Actor *thisx, PlayState *play) {
    func_80137070((u8 *)thisx + 0x144);
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, u8 *), 0x200)(thisx, play);
    func_80A96F98(thisx, play);
    func_80A971EC(thisx, play);
    if ((M2C_FIELD(play, u8 *, 0x1F2C) != 0) && (M2C_FIELD(thisx, u8 *, 0x22E) != 0) && (M2C_FIELD(thisx, s16 *, 0x1C) & 0x100)) {
        func_800B8C4C(thisx, 0x304A);
    }
}
