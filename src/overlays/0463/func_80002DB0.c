#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x146]; u8 unk146; u8 pad147[0x1]; s32 unk148; u8 pad14C[0x18]; s32 unk164; u8 pad168[0x123]; u8 unk28B; u8 pad28C[0x8]; f32 unk294; u8 pad298[0x8]; f32 unk2A0; f32 unk2A4; } S_arg0;

M2C_UNK func_800BE404(s32 *, u8 *, u8 *, M2C_UNK, f32, f32, f32, s32); /* extern */
M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_801342C8(s32 *, s32, s32, u8, s32, M2C_UNK *, u8 *); /* extern */
extern M2C_UNK D_80AFE448;

void func_80002DB0(S_arg0 *arg0, s32 *arg1) {
    func_8012C73C(*arg1);
    func_801342C8(arg1, arg0->unk148, arg0->unk164, arg0->unk146, 0, &D_80AFE448, arg0);
    func_800BE404(arg1, arg0, (u8 *)arg0 + 0x2C0, 9, arg0->unk2A4 * arg0->unk294, 0.0f, arg0->unk2A0, (s32) arg0->unk28B);
}
