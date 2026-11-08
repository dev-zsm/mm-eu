#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0581.h"
extern u8 D_80BBF258[];
extern u8 D_80BBEF68[];
void func_80BBE16C(u8 *a, s32 b, s32 c);
void func_800BD9E0(u8 *a, u8 *b, s32 c);

void func_80001EC0(Actor *thisx) {
    M2C_FIELD(thisx, s16 *, 0x31E) = 1;
    func_80BBE16C(thisx, 0, 1);
    func_800BD9E0((u8 *)thisx + 0x190, D_80BBF258, 9);
    M2C_FIELD(thisx, void **, 0x1D8) = D_80BBEF68;
}
