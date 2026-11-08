// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0581.h"

M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
M2C_UNK func_80BBE16C(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_80BBEE30;
extern M2C_UNK D_80BBF258;

void func_80001D88(Actor *thisx) {
    func_80BBE16C(thisx, 0, 1);
    func_800BD9E0((u8 *)thisx + 0x190, &D_80BBF258, 7);
    M2C_FIELD(thisx, s16 *, 0x31E) = 0;
    M2C_FIELD(thisx, M2C_UNK **, 0x1D8) = &D_80BBEE30;
}
