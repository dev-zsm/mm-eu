#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_6007790;
extern M2C_UNK D_808E68CC;

void func_80002194(u8 *arg0) {
    func_801378E0(arg0 + 0x144, &D_6007790, arg0);
    M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 20.0f;
    if (M2C_FIELD(arg0, s16 *, 0x2C6) != 0) {
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        M2C_FIELD(arg0, s16 *, 0x2BA) = 0x14;
    } else {
        M2C_FIELD(arg0, s16 *, 0x2BA) = 0x140;
        M2C_FIELD(arg0, f32 *, 0x70) = 5.0f;
    }
    M2C_FIELD(arg0, s16 *, 0x2BC) = 0;
    M2C_FIELD(arg0, u8 *, 0x689) = (u8) (M2C_FIELD(arg0, u8 *, 0x689) | 1);
    M2C_FIELD(arg0, u8 *, 0xB6) = 0xFF;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~0x200);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808E68CC;
}
