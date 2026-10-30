// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800AEAC0(s32);                         /* extern */
M2C_UNK func_800BDD44(s32, M2C_UNK *);              /* extern */
M2C_UNK func_800BE404(s32, u8 *, u8 *, M2C_UNK, f32, f32, f32, s32); /* extern */
M2C_UNK func_80133EDC(s32, s32, s32, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
M2C_UNK func_8018142C(f32, f32, s32, M2C_UNK);      /* extern */
M2C_UNK func_801826E0(f32, f32, s32, u8 *);       /* extern */
extern M2C_UNK D_6001E50;
extern M2C_UNK D_808BE2B0;
extern M2C_UNK D_808BE410;

void func_80001C58(Actor *thisx, PlayState *play) {
    func_80133EDC(play, M2C_FIELD(thisx, s32 *, 0x148), M2C_FIELD(thisx, s32 *, 0x164), &D_808BE2B0, &D_808BE410, thisx);
    func_801826E0(M2C_FIELD(thisx, f32 *, 8), M2C_FIELD(thisx, f32 *, 0xC), M2C_FIELD(thisx, s32 *, 0x10), (u8 *)thisx + 0x14);
    func_8018142C(M2C_FIELD(thisx, f32 *, 0x58), M2C_FIELD(thisx, f32 *, 0x5C), M2C_FIELD(thisx, s32 *, 0x60), 1);
    if (M2C_FIELD(thisx, u8 *, 0x11C) != 0) {
        func_800AEAC0(play);
    }
    func_800BDD44(play, &D_6001E50);
    func_800BE404(play, thisx, (u8 *)thisx + 0x21C, 8, M2C_FIELD(thisx, f32 *, 0x214), M2C_FIELD(thisx, f32 *, 0x218), M2C_FIELD(thisx, f32 *, 0x210), (s32) M2C_FIELD(thisx, u8 *, 0x18E));
}
