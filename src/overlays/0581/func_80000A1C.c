// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0581.h"

M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80BBDABC;
extern M2C_UNK D_80BBF258;

void func_80000A1C(Actor *thisx) {
    M2C_FIELD(thisx, s16 *, 0x31C) = 0;
    M2C_FIELD(thisx, f32 *, 0x70) = 0.0f;
    func_800BD9E0((u8 *)thisx + 0x190, &D_80BBF258, 3, thisx);
    M2C_FIELD(thisx, M2C_UNK **, 0x1D4) = &D_80BBDABC;
}
