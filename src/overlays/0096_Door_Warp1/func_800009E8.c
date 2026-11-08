// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0096.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_801017FC(u8 *, s16, s16, s16, s32, s32, s32, s32); /* extern */
M2C_UNK func_808B7B70(u8 *, M2C_UNK *);           /* extern */
extern u8 D_801E7E3E;
extern M2C_UNK D_808B8774;
extern M2C_UNK D_808B88FC;
extern M2C_UNK D_808B8D80;

void func_800009E8(DoorWarp1 *this, PlayState *play) {
    func_800B6564(this, 0x3DCCCCCD);
    func_801017FC((u8 *)this + 0x1E0, (s16) (s32) M2C_FIELD(this, f32 *, 0x24), (s16) (s32) M2C_FIELD(this, f32 *, 0x28), (s16) (s32) M2C_FIELD(this, f32 *, 0x2C), 0xC8, 0xFF, 0xFF, 0);
    func_801017FC((u8 *)this + 0x1F4, (s16) (s32) M2C_FIELD(this, f32 *, 0x24), (s16) (s32) M2C_FIELD(this, f32 *, 0x28), (s16) (s32) M2C_FIELD(this, f32 *, 0x2C), 0xC8, 0xFF, 0xFF, 0);
    func_800B6564(this, 0x40400000);
    M2C_FIELD(this, s8 *, 0x1D4) = 1;
    M2C_FIELD(this, s16 *, 0x1D0) = 0;
    M2C_FIELD(this, f32 *, 0x1A8) = 0.0f;
    M2C_FIELD(this, f32 *, 0x1AC) = 0.0f;
    M2C_FIELD(this, f32 *, 0x1A4) = 700.0f;
    if (M2C_FIELD(play, s16 *, 0xA4) == 0x16) {
        func_808B7B70(this, &D_808B8D80);
        return;
    }
    if (D_801E7E3E & 0x80) {
        M2C_FIELD(this, s8 *, 0x1D4) = 0;
        func_808B7B70(this, &D_808B88FC);
        return;
    }
    func_808B7B70(this, &D_808B8774);
}
