#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0476.h"

M2C_UNK func_800B3B14(u8 *, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800E0CD4(s32, u8 *, u8 *, M2C_UNK *, u8 *); /* extern */
M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E72F0(u8 *, M2C_UNK *, M2C_UNK *); /* extern */
s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80101860(u8 *, s16, s16, s16, s32, s32, s32, s32); /* extern */
s32 func_80102424(s32, s32, u8 *);                /* extern */
M2C_UNK func_80136E1C(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_80B11E18(u8 *);                      /* extern */
extern M2C_UNK D_6000A60;
extern M2C_UNK D_60050D0;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80B143B0;
extern M2C_UNK D_80B14400;
extern M2C_UNK D_80B14410;
extern M2C_UNK D_80B14430;
extern M2C_UNK D_80B14438;

void func_80000000(Actor *thisx, PlayState *play) {
    u8 *sp34;
    u8 *temp_a2;

    func_800FF8DC(thisx, &D_80B14438);
    func_800B3B14((u8 *)thisx + 0xBC, 0, &D_800B3F30, 0x41F00000);
    func_800E0CD4(play, (u8 *)thisx + 0x378, thisx, &D_80B14400, (u8 *)thisx + 0x398);
    M2C_FIELD(M2C_FIELD(thisx, u8 **, 0x394), s16 *, 0x36) = 0;
    M2C_FIELD(M2C_FIELD(thisx, u8 **, 0x394), s16 *, 0x30) = (s16) (s32) M2C_FIELD(thisx, f32 *, 0x24);
    M2C_FIELD(M2C_FIELD(thisx, u8 **, 0x394), s16 *, 0x32) = (s16) (s32) M2C_FIELD(thisx, f32 *, 0x28);
    M2C_FIELD(M2C_FIELD(thisx, u8 **, 0x394), s16 *, 0x34) = (s16) (s32) M2C_FIELD(thisx, f32 *, 0x2C);
    func_800E1134(play, (u8 *)thisx + 0x32C, thisx, &D_80B143B0);
    func_800E72F0((u8 *)thisx + 0xA0, &D_80B14410, &D_80B14430);
    M2C_FIELD(thisx, s8 *, 0x18D) = 0x20;
    M2C_FIELD(thisx, s16 *, 0x190) = func_800FF250(0x2BC, 0x12C);
    temp_a2 = (u8 *)thisx + 0x31C;
    sp34 = temp_a2;
    M2C_FIELD(thisx, s32 *, 0x318) = func_80102424(play, (u8 *)play + 0x818, temp_a2);
    func_80101860(sp34, (s16) (s32) M2C_FIELD(thisx, f32 *, 8), (s16) (s32) M2C_FIELD(thisx, f32 *, 0xC), (s16) (s32) M2C_FIELD(thisx, f32 *, 0x10), 0xFF, 0xFF, 0xFF, 0);
    func_80136E1C(play, (u8 *)thisx + 0x144, &D_60050D0, &D_6000A60, (u8 *)thisx + 0x19C, (u8 *)thisx + 0x21A, 0x15);
    M2C_FIELD(thisx, u16 *, 0x90) = (u16) (M2C_FIELD(thisx, u16 *, 0x90) | 0x400);
    func_80B11E18(thisx);
}
