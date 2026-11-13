#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0665.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_80136ED0(s32, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
M2C_UNK func_80C0AAE0(u8 *);                      /* extern */
extern M2C_UNK D_6009120;
extern M2C_UNK D_6009220;
extern M2C_UNK D_800B3F30;

void func_80000054(Actor *thisx, PlayState *play) {
    func_800B3B14((u8 *)thisx + 0xBC, 0, &D_800B3F30, 0x41A00000);
    func_80136ED0(play, (u8 *)thisx + 0x190, &D_6009220, &D_6009120, 0, 0, 0);
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & ~1);
    func_80C0AAE0(thisx);
}
