#include "types.h"
extern u8 *D_801EB7E0;
extern s32 D_801EE5A0;
void func_8012D3BC(s32, s32, s32, u8, u8, u8);
void func_8012D824(s32 a0, u8 a1, u8 a2, u8 a3) {
    if (*(s16 *)(D_801EB7E0 + 0x190) < 2 && D_801EE5A0 < 2) {
        func_8012D3BC(a0, 1, 1, a1, a2, a3);
        return;
    }
    func_8012D3BC(a0, 0, 0, a1, a2, a3);
}
