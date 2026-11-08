// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0476.h"

M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_60015B0;
extern M2C_UNK D_80B1241C;

void func_80000FA4(Actor *thisx) {
    func_801378E0((u8 *)thisx + 0x144, &D_60015B0, thisx);
    M2C_FIELD(thisx, s16 *, 0x192) = (s16) (M2C_FIELD(thisx, s16 *, 0x32) + 0x8000);
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_80B1241C;
    M2C_FIELD(thisx, f32 *, 0x70) = 0.0f;
}
