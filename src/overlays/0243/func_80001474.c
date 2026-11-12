#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x58]; f32 unk58; u8 pad5C[0xEA]; u8 unk146; u8 pad147[0x1]; s32 unk148; u8 pad14C[0x18]; s32 unk164; u8 pad168[0x24]; u8 unk18C; u8 pad18D[0x103]; f32 unk290; f32 unk294; f32 unk298; } S_arg0;

M2C_UNK func_800BE404(s32 *, u8 *, u8 *, M2C_UNK, f32, f32, f32, s32); /* extern */
M2C_UNK func_8012C73C();                         /* extern */
M2C_UNK func_801342C8(); /* extern */
extern M2C_UNK D_80980B88;
extern M2C_UNK D_80980C60;

void func_80001474(S_arg0 *arg0, s32 *arg1) {
    func_8012C73C(*arg1);
    func_801342C8(arg1, arg0->unk148, arg0->unk164, arg0->unk146, &D_80980B88, &D_80980C60, arg0);
    func_800BE404(arg1, arg0, (u8 *)arg0 + 0x260, 4, arg0->unk58 * 100.0f * arg0->unk294, arg0->unk298, arg0->unk290, (s32) arg0->unk18C);
}
