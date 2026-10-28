// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
M2C_UNK func_8093FC48(u8 *);                      /* extern */
M2C_UNK func_8093FF70(u8 *, s32);                 /* extern */
extern M2C_UNK D_600CB94;
extern M2C_UNK D_80940140;
extern M2C_UNK D_80940F74;

void func_800011B8(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, u16 *, 0x3E8) & 1) {
        func_80137788(M2C_FIELD(arg0, s32 *, 0x3D4), &D_600CB94, 0xBF800000, (f32) func_80134AE8(&D_600CB94), 0.0f, 2, 0.0f);
        M2C_FIELD(arg0, M2C_UNK **, 0x414) = &D_80940F74;
        M2C_FIELD(arg0, M2C_UNK **, 0x410) = &D_80940140;
    }
    func_8093FC48(arg0);
    func_8093FF70(arg0, arg1);
}
