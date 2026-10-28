// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_600A280;
extern M2C_UNK D_80BF5074;

void func_800002C0(u8 *arg0) {
    func_80137828(arg0 + 0x144, &D_600A280, 0xC0800000);
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_80BF5074;
}
