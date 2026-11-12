#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801377D0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_60017B8;
extern M2C_UNK D_8089C690;

void func_80002820(u8 *arg0, u8 *arg1) {
    func_801377D0(arg0 + 0x144, &D_60017B8, arg0);
    M2C_FIELD(arg0, u8 *, 0x374) = (u8) (M2C_FIELD(arg0, u8 *, 0x374) & 0xFFFE);
    if (M2C_FIELD(arg1, s16 *, 0xA4) == 0x1B) {
        M2C_FIELD(arg1, u8 *, 0x170C7) = 0xFF;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_8089C690;
}
