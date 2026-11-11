#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0467.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800E1134(s32, s32, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E72F0(u8 *, M2C_UNK, M2C_UNK *);  /* extern */
M2C_UNK func_80B06D2C(u8 *);                      /* extern */
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80B077B0;
extern M2C_UNK D_80B077DC;

void func_80000000(Actor *thisx, PlayState *play) {
    func_800B3B14((u8 *)thisx + 0xBC, 0, &D_800B3F30, 0x42500000);
    func_800E1134(play, (u8 *)thisx + 0x14C, thisx, &D_80B077B0);
    func_800E72F0((u8 *)thisx + 0xA0, 0, &D_80B077DC);
    if (M2C_FIELD(thisx, s16 *, 0x1C) == 1) {
        M2C_FIELD(thisx, f32 *, 0x74) = -1.5f;
    } else {
        M2C_FIELD(thisx, u8 *, 0x15E) = (u8) (M2C_FIELD(thisx, u8 *, 0x15E) & 0xFFFB);
        M2C_FIELD(thisx, f32 *, 0x78) = -100.0f;
        M2C_FIELD(thisx, f32 *, 0x74) = -7.0f;
    }
    func_80B06D2C(thisx);
}
