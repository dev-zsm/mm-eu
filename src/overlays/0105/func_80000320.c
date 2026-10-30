// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B02EC(M2C_UNK, s32);                /* extern */
M2C_UNK func_800E0FAC(M2C_UNK, s32);                /* extern */
M2C_UNK func_800E1574(M2C_UNK, s32);                /* extern */
M2C_UNK func_800E1C28(M2C_UNK, s32);                /* extern */
M2C_UNK func_800E1F64(M2C_UNK, s32);                /* extern */
M2C_UNK func_801A818C(s32);                         /* extern */

void func_80000320(Actor *thisx, PlayState *play) {
    func_800E1F64(play, (u8 *)thisx + 0x808);
    func_800E0FAC(play, (u8 *)thisx + 0x73C);
    func_800E1C28(play, (u8 *)thisx + 0x788);
    func_800E1574(play, (u8 *)thisx + 0x860);
    func_801A818C((u8 *)thisx + 0x338);
    func_800B02EC(play, M2C_FIELD(thisx, s32 *, 0x300));
}
