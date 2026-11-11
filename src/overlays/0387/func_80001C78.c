#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0387.h"

s32 func_800B8254(u8 *, u8 *);                  /* extern */
M2C_UNK func_800B8398(u8 *, u8 *, M2C_UNK);     /* extern */
M2C_UNK func_800C604C(u8 *, u8 *, s32);         /* extern */
M2C_UNK func_800C60A4(u8 *, u8 *, s32);         /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80A93D80(u8 *);                      /* extern */
M2C_UNK func_80A948D4(u8 *, u8 *);              /* extern */
M2C_UNK func_80A949FC(u8 *, u8 *);              /* extern */
M2C_UNK func_80A94BB8(u8 *, u8 *);              /* extern */
M2C_UNK func_80A94F18(u8 *, u8 *);              /* extern */
M2C_UNK func_80A94F6C(u8 *, u8 *);              /* extern */
M2C_UNK func_80A9505C(u8 *, u8 *);              /* extern */
M2C_UNK func_80A9569C(u8 *, u8 *);              /* extern */
M2C_UNK func_80A95740(u8 *, u8 *);              /* extern */
extern f32 D_80A96640;

void func_80001C78(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, f32 *, 0x3C) = (f32) M2C_FIELD(thisx, f32 *, 0x1D0);
    M2C_FIELD(thisx, f32 *, 0x40) = (f32) (M2C_FIELD(thisx, f32 *, 0x54) + M2C_FIELD(thisx, f32 *, 0x1D4));
    M2C_FIELD(thisx, f32 *, 0x44) = (f32) M2C_FIELD(thisx, f32 *, 0x1D8);
    M2C_FIELD(thisx, s16 *, 0x48) = (s16) M2C_FIELD(thisx, s16 *, 0x30);
    M2C_FIELD(thisx, s16 *, 0x4A) = (s16) M2C_FIELD(thisx, s16 *, 0x32);
    M2C_FIELD(thisx, s16 *, 0x4C) = (s16) M2C_FIELD(thisx, s16 *, 0x34);
    if (func_800B8254(thisx, play) != 0) {
        M2C_FIELD(thisx, s8 *, 0x206) = 1;
    }
    func_80A93D80(thisx);
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, u8 *), 0x1A0)(thisx, play);
    func_80A94BB8(thisx, play);
    func_80A94F6C(thisx, play);
    func_80A9505C(thisx, play);
    func_80A94F18(thisx, play);
    func_80137070((u8 *)thisx + 0x15C);
    func_80A948D4(thisx, play);
    M2C_FIELD(thisx, f32 *, 0x28) = (f32) M2C_FIELD(thisx, f32 *, 0x1E4);
    if (M2C_FIELD(play, s16 *, 0xA4) == 0x38) {
        if (D_80A96640 < M2C_FIELD(thisx, f32 *, 0x98)) {
            func_800C604C(play, (u8 *)play + 0x880, M2C_FIELD(thisx, s32 *, 0x144));
        } else {
            func_800C60A4(play, (u8 *)play + 0x880, M2C_FIELD(thisx, s32 *, 0x144));
        }
    }
    if (M2C_FIELD(thisx, u8 *, 0x1FF) != 0) {
        func_80A949FC(thisx, play);
        func_800B8398(thisx, play, 0x43C80000);
    }
    func_80A9569C(thisx, play);
    func_80A95740(thisx, play);
}
