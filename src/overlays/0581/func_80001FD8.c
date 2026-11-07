#include "types.h"
#include "m2c_compat.h"
extern u8 D_80BBF258[];
extern u8 D_80BBF080[];
void func_80BBE16C(u8 *a, s32 b, s32 c);
void func_800BD9E0(u8 *a, u8 *b, s32 c);

void func_80001FD8(u8 *a) {
    M2C_FIELD(a, s16 *, 0x31E) = 1;
    func_80BBE16C(a, 0, 0);
    func_800BD9E0(a + 0x190, D_80BBF258, 0xB);
    M2C_FIELD(a, void **, 0x1D8) = D_80BBF080;
}
