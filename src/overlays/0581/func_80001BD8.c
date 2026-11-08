// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0581.h"

M2C_UNK func_800BD9E0(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80BBEC70;
extern M2C_UNK D_80BBF258;

void func_80001BD8(Actor *thisx) {
    func_800BD9E0((u8 *)thisx + 0x190, &D_80BBF258, 0, thisx);
    M2C_FIELD(thisx, s16 *, 0x31E) = 0;
    M2C_FIELD(thisx, M2C_UNK **, 0x1D8) = &D_80BBEC70;
}
