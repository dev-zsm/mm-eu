#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0076.h"

M2C_UNK func_80137788(s32, M2C_UNK *, f32, f32, f32, s32, f32); /* extern */
M2C_UNK func_8089A490(u8 *);                      /* extern */
extern M2C_UNK D_600D62C;
extern M2C_UNK D_8089C900;
extern f32 D_8089DB54;

void func_80002A3C(u8 *arg0, s16 arg1) {
    if (arg1 >= 0) {
        M2C_FIELD(arg0, f32 *, 0x70) = -15.0f;
    } else {
        M2C_FIELD(arg0, f32 *, 0x70) = 15.0f;
    }
    func_80137788(arg0 + 0x144, &D_600D62C, M2C_FIELD(arg0, f32 *, 0x70) * D_8089DB54, 0.0f, 0.0f, 0, -4.0f);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) (M2C_FIELD(arg0, s16 *, 0xBE) + 0x4000);
    M2C_FIELD(arg0, s16 *, 0x292) = 0xA;
    M2C_FIELD(arg0, f32 *, 0x2A4) = 0.0f;
    func_8089A490(arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_8089C900;
}
