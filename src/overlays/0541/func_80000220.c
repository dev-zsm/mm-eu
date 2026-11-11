#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0541.h"

M2C_UNK func_800B3B14(u8 *, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800E0F5C(M2C_UNK, u8 *);             /* extern */
M2C_UNK func_800E10CC(M2C_UNK, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E731C(u8 *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80136ED0(M2C_UNK, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_80B8A1A0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B8A548(u8 *);                      /* extern */
M2C_UNK func_80B8C90C(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_60053E8;
extern M2C_UNK D_600ABE0;
extern M2C_UNK D_800B3F30;
extern u16 D_801E6EFC;
extern u8 D_801E7DF6;
extern M2C_UNK D_80B8D040;
extern M2C_UNK D_80B8D06C;
extern M2C_UNK D_80B8D08C;
extern M2C_UNK D_80B8D09C;

void func_80000220(Actor *thisx, PlayState *play) {
    u8 *sp34;
    u8 *temp_a1;

    func_800FF8DC(thisx, &D_80B8D09C);
    M2C_FIELD(thisx, s8 *, 0x1F) = 0;
    M2C_FIELD(thisx, s8 *, 0x11F) = 0x2D;
    M2C_FIELD(thisx, s16 *, 0x116) = 0;
    if (M2C_FIELD(thisx, s16 *, 0x1C) & 0x80) {
        func_80B8C90C(thisx, play);
        return;
    }
    func_80B8A1A0(thisx, play);
    M2C_FIELD(thisx, s16 *, 0x3F2) = 0;
    M2C_FIELD(thisx, u16 *, 0x402) = (u16) D_801E6EFC;
    M2C_FIELD(thisx, s8 *, 0x404) = 0;
    M2C_FIELD(thisx, s16 *, 0x3F8) = 0;
    M2C_FIELD(thisx, s16 *, 0x400) = 0;
    M2C_FIELD(thisx, s16 *, 0x3FA) = 0;
    if (M2C_FIELD(thisx, s32 *, 0x120) == 0) {
        M2C_FIELD(thisx, s16 *, 0x3EC) = 1;
        M2C_FIELD(thisx, s16 *, 0x3EE) = 1;
    }
    func_800B3B14((u8 *)thisx + 0xBC, 0, &D_800B3F30, 0x41E00000);
    func_80136ED0(play, (u8 *)thisx + 0x190, &D_60053E8, &D_600ABE0, (u8 *)thisx + 0x2A8, (u8 *)thisx + 0x344, 0x1A);
    temp_a1 = (u8 *)thisx + 0x144;
    sp34 = temp_a1;
    func_800E0F5C(play, temp_a1);
    func_800E10CC(play, temp_a1, thisx, &D_80B8D040);
    func_800E731C((u8 *)thisx + 0xA0, &D_80B8D06C, &D_80B8D08C);
    if (D_801E7DF6 & 4) {
        func_800B6490(thisx);
    }
    func_80B8A548(thisx);
}
