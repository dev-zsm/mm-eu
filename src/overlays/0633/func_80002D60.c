// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800AEAC0(s32 *);                       /* extern */
M2C_UNK func_800BE404(s32 *, u8 *, u8 *, M2C_UNK, f32, f32, f32, s32); /* extern */
M2C_UNK func_800FF34C(u8 *, s32);                 /* extern */
M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_801342C8(s32 *, s32, s32, u8, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
M2C_UNK func_80BF80F4(u8 *, s32 *);               /* extern */
extern M2C_UNK D_80BF7E8C;
extern M2C_UNK D_80BF7EFC;

void func_80002D60(Actor *thisx, PlayState *play) {
    func_8012C73C(play->gfxCtx);
    func_801342C8(play, M2C_FIELD(thisx, s32 *, 0x148), M2C_FIELD(thisx, s32 *, 0x164), M2C_FIELD(thisx, u8 *, 0x146), &D_80BF7E8C, &D_80BF7EFC, thisx);
    if ((s32) M2C_FIELD(thisx, u8 *, 0x11C) > 0) {
        func_800AEAC0(play);
    }
    func_80BF80F4(thisx, play);
    func_800BE404(play, thisx, (u8 *)thisx + 0x350, 0xB, M2C_FIELD(thisx, f32 *, 0x3D8), M2C_FIELD(thisx, f32 *, 0x3DC), M2C_FIELD(thisx, f32 *, 0x3D4), (s32) M2C_FIELD(thisx, u8 *, 0x18C));
    func_800FF34C((u8 *)thisx + 0x3C, M2C_FIELD(thisx, s32 *, 0x28C) + 0x70);
}
