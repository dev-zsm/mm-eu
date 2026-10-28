// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8400(u8 *, s32);                     /* extern */
M2C_UNK func_801A9868(M2C_UNK);                     /* extern */
M2C_UNK func_8093F5C0(u8 *, s32);                 /* extern */
M2C_UNK func_8093F698(u8 *);                      /* extern */
extern M2C_UNK D_8093F60C;

void func_80000740(u8 *arg0, s32 arg1) {
    if (func_800B8400(arg0, arg1) != 0) {
        func_801A9868(0x110000FF);
        if (!(M2C_FIELD(arg0, s16 *, 0x3DA) & 0x3F)) {
            func_8093F5C0(arg0, arg1);
        } else {
            M2C_FIELD(arg0, u16 *, 0x3E8) = (u16) (M2C_FIELD(arg0, u16 *, 0x3E8) & 0xFFFD);
            func_8093F698(arg0);
            M2C_FIELD(arg0, M2C_UNK **, 0x410) = &D_8093F60C;
        }
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & 0xFFFEFFFF);
    }
}
