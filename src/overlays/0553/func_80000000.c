#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0553.h"

M2C_UNK func_800B3B14(u8 *, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_801378E0(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80B9FC24(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_6009CF4;
extern M2C_UNK D_6014DC8;
extern M2C_UNK D_800B3F30;
extern u8 D_801E7E1F;
extern u8 D_801E7E36;
extern M2C_UNK D_80BA0B80;
extern M2C_UNK D_80BA0EEC;
extern M2C_UNK D_80BA0FEC;
extern M2C_UNK D_80BA111C;
extern M2C_UNK D_80BA1490;

void func_80000000(Actor *thisx, PlayState *play) {
    u8 *temp_a1;

    func_800B6564(thisx, 0x3C3C6A7F);
    M2C_FIELD(thisx, M2C_UNK **, 0x2C0) = &D_80BA0B80;
    func_800B3B14((u8 *)thisx + 0xBC, 0.0f, &D_800B3F30, 0x41F00000);
    M2C_FIELD(thisx, u8 *, 0xB6) = 0xFF;
    temp_a1 = (u8 *)thisx + 0x21C;
    func_80136ED0(play, temp_a1, &D_6014DC8, &D_6009CF4, (u8 *)thisx + 0x144, (u8 *)thisx + 0x1B0, 0x12);
    func_801378E0(temp_a1, &D_6009CF4);
    func_800E1134(play, (u8 *)thisx + 0x260, thisx, &D_80BA1490);
    M2C_FIELD(thisx, u16 *, 0x2B6) = 0U;
    M2C_FIELD(thisx, f32 *, 0x78) = -4.0f;
    M2C_FIELD(thisx, f32 *, 0x74) = -4.0f;
    func_80B9FC24(thisx, 0, 2);
    switch ((M2C_FIELD(thisx, s16 *, 0x1C) & 0xF)) {                              /* irregular */
        case 1:
            if (!(D_801E7E1F & 0x80)) {
            func_800B6490(thisx);
            }
            if (D_801E7E36 & 1) {
            M2C_FIELD(thisx, M2C_UNK **, 0x2C0) = &D_80BA0FEC;
            } else {
            M2C_FIELD(thisx, M2C_UNK **, 0x2C0) = &D_80BA0EEC;
            }
            func_80B9FC24(thisx, 0, 2);
            return;
        case 2:
            M2C_FIELD(thisx, M2C_UNK **, 0x2C0) = &D_80BA111C;
            func_80B9FC24(thisx, 7, 2);
            M2C_FIELD(thisx, s16 *, 0x2BC) = -1;
            M2C_FIELD(thisx, u16 *, 0x2B6) = (u16) (M2C_FIELD(thisx, u16 *, 0x2B6) | 0x40);
            return;
        default:
            if (D_801E7E1F & 0x80) {
            func_800B6490(thisx);
            }
            M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) | 0x10);
            return;
    }
}
