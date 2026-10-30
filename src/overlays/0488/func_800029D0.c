// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_801342C8(s32 *, s32, s32, u8, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
M2C_UNK func_80B27DA4(u8 *, s32 *);               /* extern */
extern M2C_UNK D_80B27CD0;
extern M2C_UNK D_80B27D38;

void func_800029D0(Actor *thisx, PlayState *play) {
    func_8012C73C(play->gfxCtx);
    if (M2C_FIELD(thisx, u16 *, 0x29C) & 1) {
        func_80B27DA4(thisx, play);
    }
    func_801342C8(play, M2C_FIELD(thisx, s32 *, 0x148), M2C_FIELD(thisx, s32 *, 0x164), M2C_FIELD(thisx, u8 *, 0x146), &D_80B27CD0, &D_80B27D38, thisx);
}
