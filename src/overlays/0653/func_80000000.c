#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0653.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800E090C(s32, s32);                    /* extern */
M2C_UNK func_800E0C20(s32, s32, u8 *, M2C_UNK *, s32); /* extern */
M2C_UNK func_800E731C(u8 *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80136E1C(s32, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
M2C_UNK func_80C04BAC(u8 *);                      /* extern */
extern M2C_UNK D_6005EF8;
extern M2C_UNK D_600697C;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80C06A68;
extern M2C_UNK D_80C06A78;
extern M2C_UNK D_80C06A84;
extern M2C_UNK D_80C06BDC;

void func_80000000(Actor *thisx, PlayState *play) {
    s32 sp34;
    s32 temp_a1;

    func_800B3B14((u8 *)thisx + 0xBC, 0, &D_800B3F30, 0x42100000);
    func_80136E1C(play, (u8 *)thisx + 0x1E4, &D_6005EF8, &D_600697C, (u8 *)thisx + 0x2E0, (u8 *)thisx + 0x358, 0x14);
    temp_a1 = (u8 *)thisx + 0x144;
    sp34 = temp_a1;
    func_800E090C(play, temp_a1);
    func_800E0C20(play, temp_a1, thisx, &D_80C06A68, (u8 *)thisx + 0x164);
    func_800E731C((u8 *)thisx + 0xA0, &D_80C06A84, &D_80C06A78);
    func_800FF8DC(thisx, &D_80C06BDC);
    M2C_FIELD(thisx, s8 *, 0x11F) = 0x55;
    M2C_FIELD(thisx, s16 *, 0x3E4) = 0;
    M2C_FIELD(thisx, s16 *, 0x3DE) = 0;
    M2C_FIELD(thisx, s16 *, 0x3E0) = 0;
    M2C_FIELD(thisx, s16 *, 0x3DC) = 0;
    M2C_FIELD(thisx, s8 *, 0x3E9) = 0;
    func_80C04BAC(thisx);
}
