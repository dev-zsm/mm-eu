#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0125.h"

M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_60039C4;
extern M2C_UNK D_808E9990;

void func_80005294(u8 *arg0) {
    func_801378E0(arg0 + 0x144, &D_60039C4, arg0);
    M2C_FIELD(arg0, s16 *, 0x2BA) = 0x64;
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0x2D0);
    M2C_FIELD(arg0, f32 *, 0x70) = 8.0f;
    M2C_FIELD(arg0, s16 *, 0x2B6) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) + 0x8000);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808E9990;
}
