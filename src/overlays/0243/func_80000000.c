// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B3B14(u8 *, M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800E0CD4(s32, u8 *, u8 *, M2C_UNK *, u8 *); /* extern */
M2C_UNK func_800E72F0(u8 *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_8097F998(u8 *);                      /* extern */
extern M2C_UNK D_60000F0;
extern M2C_UNK D_60010C0;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80980DD4;
extern u8 *D_80980DE0;
extern M2C_UNK D_80980DE4;
extern M2C_UNK D_80980DEC;
extern s32 D_80980E0C;
extern M2C_UNK D_80980E10;

void func_80000000(Actor *thisx, PlayState *play) {
    func_800FF8DC(thisx, &D_80980E10);
    func_80136ED0(play, (u8 *)thisx + 0x144, &D_60010C0, &D_60000F0, (u8 *)thisx + 0x194, (u8 *)thisx + 0x1CA, 9);
    func_800E0CD4(play, (u8 *)thisx + 0x200, thisx, &D_80980DD4, (u8 *)thisx + 0x220);
    M2C_FIELD(M2C_FIELD(thisx, u8 **, 0x21C), s16 *, 0x36) = (s16) M2C_FIELD(D_80980DE0, s16 *, 0x20);
    func_800E72F0((u8 *)thisx + 0xA0, &D_80980DEC, &D_80980DE4);
    func_800B3B14((u8 *)thisx + 0xBC, 0x44FA0000, &D_800B3F30, 0x41A00000);
    D_80980E0C = 0;
    if (M2C_FIELD(thisx, s32 *, 0x120) != 0) {
        M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & ~1);
    }
    func_8097F998(thisx);
}
