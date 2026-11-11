#include "types.h"
#include "m2c_compat.h"

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

void func_80001C78(u8 *arg0, u8 *arg1) {
    M2C_FIELD(arg0, f32 *, 0x3C) = (f32) M2C_FIELD(arg0, f32 *, 0x1D0);
    M2C_FIELD(arg0, f32 *, 0x40) = (f32) (M2C_FIELD(arg0, f32 *, 0x54) + M2C_FIELD(arg0, f32 *, 0x1D4));
    M2C_FIELD(arg0, f32 *, 0x44) = (f32) M2C_FIELD(arg0, f32 *, 0x1D8);
    M2C_FIELD(arg0, s16 *, 0x48) = (s16) M2C_FIELD(arg0, s16 *, 0x30);
    M2C_FIELD(arg0, s16 *, 0x4A) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
    M2C_FIELD(arg0, s16 *, 0x4C) = (s16) M2C_FIELD(arg0, s16 *, 0x34);
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, s8 *, 0x206) = 1;
    }
    func_80A93D80(arg0);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, u8 *), 0x1A0)(arg0, arg1);
    func_80A94BB8(arg0, arg1);
    func_80A94F6C(arg0, arg1);
    func_80A9505C(arg0, arg1);
    func_80A94F18(arg0, arg1);
    func_80137070(arg0 + 0x15C);
    func_80A948D4(arg0, arg1);
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) M2C_FIELD(arg0, f32 *, 0x1E4);
    if (M2C_FIELD(arg1, s16 *, 0xA4) == 0x38) {
        if (D_80A96640 < M2C_FIELD(arg0, f32 *, 0x98)) {
            func_800C604C(arg1, arg1 + 0x880, M2C_FIELD(arg0, s32 *, 0x144));
        } else {
            func_800C60A4(arg1, arg1 + 0x880, M2C_FIELD(arg0, s32 *, 0x144));
        }
    }
    if (M2C_FIELD(arg0, u8 *, 0x1FF) != 0) {
        func_80A949FC(arg0, arg1);
        func_800B8398(arg0, arg1, 0x43C80000);
    }
    func_80A9569C(arg0, arg1);
    func_80A95740(arg0, arg1);
}
