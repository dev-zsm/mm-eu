// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_8012C78C(s32);                         /* extern */
M2C_UNK func_80134760(s32 *, s32, s32, u8, s32, s32, M2C_UNK *, u8 *); /* extern */
M2C_UNK func_809FDAD0(u8 *, s32 *);               /* extern */
extern M2C_UNK D_809FD2CC;

void func_80001CC8(Actor *thisx, PlayState *play) {
    func_8012C73C(play->gfxCtx);
    func_8012C78C(play->gfxCtx);
    func_80134760(play, M2C_FIELD(thisx, s32 *, 0x160), M2C_FIELD(thisx, s32 *, 0x17C), M2C_FIELD(thisx, u8 *, 0x15E), 0, 0, &D_809FD2CC, thisx);
    if (M2C_FIELD(thisx, s16 *, 0x3C6) == 4) {
        func_809FDAD0(thisx, play);
    }
}
