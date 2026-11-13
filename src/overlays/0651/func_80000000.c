#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0651.h"

M2C_UNK func_800B3B14(u8 *, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800B763C(s32, u8 *, f32, f32, f32, s32); /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_80C03864(u8 *);                      /* extern */
extern M2C_UNK D_60005FC;
extern M2C_UNK D_600A6D0;
extern M2C_UNK D_800B3F30;
extern f32 D_80C04080;

void func_80000000(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, s8 *, 0x1F) = 1;
    M2C_FIELD(thisx, f32 *, 0xFC) = (f32) D_80C04080;
    func_800B6564(thisx, 0x3CA3D70A);
    func_800B3B14((u8 *)thisx + 0xBC, 0, &D_800B3F30, 0x42100000);
    func_80136ED0(play, (u8 *)thisx + 0x144, &D_600A6D0, &D_60005FC, (u8 *)thisx + 0x19C, (u8 *)thisx + 0x262, 0x21);
    func_800B763C(play, thisx, 0.0f, 0.0f, 0.0f, 4);
    M2C_FIELD(thisx, s16 *, 0x334) = 0x3C;
    M2C_FIELD(thisx, s32 *, 0x198) = 0;
    M2C_FIELD(thisx, s16 *, 0x336) = 0;
    func_80C03864(thisx);
}
