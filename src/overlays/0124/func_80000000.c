#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0124.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E0F5C(s32, u8 *);                 /* extern */
M2C_UNK func_800E1064(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_808E379C(u8 *);                      /* extern */
extern M2C_UNK D_6000194;
extern M2C_UNK D_6002BF0;
extern M2C_UNK D_808E44E0;
extern M2C_UNK D_808E450C;
extern M2C_UNK D_808E452C;
extern f32 D_808E4570;

void func_80000000(Actor *thisx, PlayState *play) {
    u8 *temp_a1;

    func_800FF8DC(thisx, &D_808E452C);
    M2C_FIELD(thisx, M2C_UNK **, 0xA0) = &D_808E450C;
    M2C_FIELD(thisx, s8 *, 0xB6) = 0xA;
    M2C_FIELD(thisx, s8 *, 0xB7) = 2;
    func_80136ED0(play, (u8 *)thisx + 0x144, &D_6002BF0, &D_6000194, (u8 *)thisx + 0x188, (u8 *)thisx + 0x1BE, 9);
    temp_a1 = (u8 *)thisx + 0x1F8;
    func_800E0F5C(play, temp_a1);
    func_800E1064(play, temp_a1, thisx, &D_808E44E0);
    M2C_FIELD(thisx, s16 *, 0x248) = 0;
    M2C_FIELD(thisx, s8 *, 0xB6) = 0x5A;
    M2C_FIELD(thisx, s16 *, 0xBE) = 0;
    M2C_FIELD(thisx, f32 *, 0x70) = 0.0f;
    M2C_FIELD(thisx, f32 *, 0x74) = (f32) D_808E4570;
    M2C_FIELD(thisx, s16 *, 0x244) = 0;
    M2C_FIELD(thisx, s8 *, 0x252) = 0;
    M2C_FIELD(thisx, f32 *, 0x68) = -1.0f;
    func_800B6564(thisx, 0x3BC49BA6);
    func_808E379C(thisx);
}
