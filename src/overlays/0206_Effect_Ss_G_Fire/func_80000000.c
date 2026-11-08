// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0206.h"

M2C_UNK func_800FF30C(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_4032270;
extern M2C_UNK D_801C9EE0;
extern M2C_UNK D_8095F288;
extern M2C_UNK D_8095F330;

u32 EffectSsGFire_Init(PlayState *play, u32 index, void *this, void *initParamsx) {
    func_800FF30C((u8 *)this + 0xC, &D_801C9EE0);
    func_800FF30C((u8 *)this + 0x18, &D_801C9EE0);
    func_800FF30C(this, initParamsx);
    M2C_FIELD(this, M2C_UNK **, 0x28) = &D_8095F288;
    M2C_FIELD(this, M2C_UNK **, 0x24) = &D_8095F330;
    M2C_FIELD(this, M2C_UNK **, 0x38) = &D_4032270;
    M2C_FIELD(this, s16 *, 0x5C) = 8;
    M2C_FIELD(this, s16 *, 0x5A) = 0;
    M2C_FIELD(this, s16 *, 0x42) = 0xC8;
    M2C_FIELD(this, s16 *, 0x40) = 0;
    M2C_FIELD(this, s16 *, 0x44) = 0x32;
    M2C_FIELD(this, s16 *, 0x46) = 0xFF;
    M2C_FIELD(this, s16 *, 0x48) = 0xDC;
    M2C_FIELD(this, s16 *, 0x4A) = 0x50;
    M2C_FIELD(this, s16 *, 0x4C) = 0xFF;
    M2C_FIELD(this, s16 *, 0x4E) = 0x82;
    M2C_FIELD(this, s16 *, 0x50) = 0x1E;
    M2C_FIELD(this, s16 *, 0x52) = 0;
    M2C_FIELD(this, s16 *, 0x54) = 0;
    return 1;
}
