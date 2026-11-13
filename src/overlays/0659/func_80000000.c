#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0659.h"

M2C_UNK func_800B3B14(u8 *, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_80C08720(u8 *);                      /* extern */
extern M2C_UNK D_6002FA0;
extern M2C_UNK D_600A850;
extern M2C_UNK D_800B3F30;

void func_80000000(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, u8 *, 0xB6) = 0xFF;
    func_800B6564(thisx, 0x3C23D70A);
    M2C_FIELD(thisx, s8 *, 0x1F) = 6;
    M2C_FIELD(thisx, f32 *, 0x74) = -3.0f;
    func_80136ED0(play, (u8 *)thisx + 0x144, &D_600A850, &D_6002FA0, (u8 *)thisx + 0x188, (u8 *)thisx + 0x1EE, 0x11);
    func_800B3B14((u8 *)thisx + 0xBC, 0, &D_800B3F30, 0x41C80000);
    M2C_FIELD(thisx, s32 *, 0x25C) = (s32) M2C_FIELD(thisx, s16 *, 0x1C);
    func_80C08720(thisx);
}
