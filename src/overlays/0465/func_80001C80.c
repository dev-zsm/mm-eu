#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0465.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6000D40;
extern M2C_UNK D_80B00DD4;

void func_80001C80(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_6000D40, 0xC0400000, arg0);
    M2C_FIELD(arg0, u8 *, 0x229) = 0xFF;
    M2C_FIELD(arg0, s16 *, 0x192) = 0x12C;
    M2C_FIELD(arg0, s16 *, 0x194) = 3;
    M2C_FIELD(arg0, u8 *, 0x191) = (u8) (M2C_FIELD(arg0, u8 *, 0x191) | 9);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B00DD4;
}
