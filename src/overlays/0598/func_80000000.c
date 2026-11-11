#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0598.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_80136ED0(s32, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
M2C_UNK func_80BCE4AC(u8 *);                      /* extern */
extern M2C_UNK D_6003BFC;
extern M2C_UNK D_600D640;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80BCE7F0;

void func_80000000(Actor *thisx, PlayState *play) {
    func_800B3B14((u8 *)thisx + 0xBC, 0, &D_800B3F30, 0x41C80000);
    func_80136ED0(play, (u8 *)thisx + 0x144, &D_600D640, &D_6003BFC, (u8 *)thisx + 0x188, (u8 *)thisx + 0x1EE, 0x11);
    M2C_FIELD(thisx, u8 *, 0xB6) = 0xFF;
    M2C_FIELD(thisx, s8 *, 0x1F) = 6;
    M2C_FIELD(thisx, f32 *, 0x74) = -3.0f;
    func_800E1134(play, (u8 *)thisx + 0x274, thisx, &D_80BCE7F0);
    func_80BCE4AC(thisx);
}
