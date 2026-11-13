#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0608.h"

M2C_UNK func_800B3B14(u8 *, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_801378E0(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_60000B8;
extern M2C_UNK D_60038F0;
extern M2C_UNK D_60063C8;
extern M2C_UNK D_6007708;
extern M2C_UNK D_6009AC0;
extern M2C_UNK D_600B050;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80BDAD00;
extern M2C_UNK D_80BDAF8C;
extern M2C_UNK D_80BDB30C;
extern M2C_UNK D_80BDB7C0;

void func_80000000(Actor *thisx, PlayState *play) {
    s32 temp_v0;
    u8 *temp_s1;
    u8 *temp_s1_2;
    u8 *temp_s1_3;

    func_800B6564(thisx, 0x3C54FDF4);
    func_800B3B14((u8 *)thisx + 0xBC, 0, &D_800B3F30, 0x41200000);
    temp_v0 = M2C_FIELD(thisx, s16 *, 0x1C) & 0xF;
    M2C_FIELD(thisx, M2C_UNK **, 0x260) = &D_80BDAD00;
    M2C_FIELD(thisx, s16 *, 0x254) = -1;
    M2C_FIELD(thisx, s16 *, 0x256) = -1;
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & ~1);
    switch (temp_v0) {                              /* irregular */
        case 1:
            temp_s1 = (u8 *)thisx + 0x144;
            func_80136ED0(play, temp_s1, &D_6007708, &D_60063C8, (u8 *)thisx + 0x188, (u8 *)thisx + 0x1EE, 7);
            func_801378E0(temp_s1, &D_60063C8);
            M2C_FIELD(thisx, M2C_UNK **, 0x260) = &D_80BDB30C;
            M2C_FIELD(thisx, s16 *, 0x258) = 0x210;
            return;
        case 2:
            temp_s1_2 = (u8 *)thisx + 0x144;
            func_80136ED0(play, temp_s1_2, &D_600B050, &D_6009AC0, (u8 *)thisx + 0x188, (u8 *)thisx + 0x1EE, 7);
            func_801378E0(temp_s1_2, &D_60063C8);
            M2C_FIELD(thisx, M2C_UNK **, 0x260) = &D_80BDB7C0;
            M2C_FIELD(thisx, s16 *, 0x258) = 0x211;
            return;
        default:
            func_800B6564(thisx, 0x3C8B4396);
            temp_s1_3 = (u8 *)thisx + 0x144;
            func_80136ED0(play, temp_s1_3, &D_60038F0, &D_60000B8, (u8 *)thisx + 0x188, (u8 *)thisx + 0x1EE, 0x11);
            func_801378E0(temp_s1_3, &D_60000B8);
            M2C_FIELD(thisx, M2C_UNK **, 0x260) = &D_80BDAF8C;
            M2C_FIELD(thisx, s16 *, 0x258) = 0x212;
            M2C_FIELD(thisx, s16 *, 0x18) = 0;
            M2C_FIELD(thisx, f32 *, 0x25C) = 0.0f;
            return;
    }
}
