// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0476.h"

M2C_UNK func_801377D0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_6000A60;
extern M2C_UNK D_80B12358;

void func_80000EEC(Actor *thisx) {
    func_801377D0((u8 *)thisx + 0x144, &D_6000A60, thisx);
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_80B12358;
    M2C_FIELD(thisx, f32 *, 0x70) = -5.0f;
}
