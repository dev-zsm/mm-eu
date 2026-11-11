#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0540.h"

M2C_UNK func_800B3B14(u8 *, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800E1134(u8 *, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80136ED0(u8 *, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_80B88460(u8 *, u8 *, M2C_UNK);     /* extern */
extern M2C_UNK D_6003AA8;
extern M2C_UNK D_600A978;
extern M2C_UNK D_600C880;
extern M2C_UNK D_800B3F30;
extern u16 D_801E6EFC;
extern M2C_UNK D_80B89D90;
extern M2C_UNK D_80B89DC8;

void func_8000003C(Actor *thisx, PlayState *play) {
    M2C_UNK *var_a3;

    func_800FF8DC(thisx, &D_80B89DC8);
    func_800E1134(play, (u8 *)thisx + 0x264, thisx, &D_80B89D90);
    if ((M2C_FIELD(play, s16 *, 0xA4) == 0x15) && ((s32) D_801E6EFC >= 0x4000) && ((s32) D_801E6EFC < 0xE555)) {
        func_800B6490(thisx);
        return;
    }
    func_800B3B14((u8 *)thisx + 0xBC, 0, &D_800B3F30, 0x41F00000);
    M2C_FIELD(thisx, u16 *, 0x90) = (u16) (M2C_FIELD(thisx, u16 *, 0x90) | 0x400);
    if (M2C_FIELD(play, s16 *, 0xA4) == 0x12) {
        var_a3 = &D_6003AA8;
    } else {
        var_a3 = &D_600C880;
    }
    func_80136ED0(play, (u8 *)thisx + 0x144, &D_600A978, var_a3, (u8 *)thisx + 0x188, (u8 *)thisx + 0x1F4, 0x12);
    func_80B88460(thisx, play, 0);
    M2C_FIELD(thisx, s16 *, 0xBC) = 0;
}
