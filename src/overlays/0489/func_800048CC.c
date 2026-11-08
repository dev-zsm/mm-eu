#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"
extern s32 D_80B35120;
void func_800B6490(u8 *a);
void func_80137070(u8 *a);

void func_800048CC(Actor *thisx, s32 b) {
    if (D_80B35120 == 0 || M2C_FIELD(thisx, s32 *, 0x120) == 0) {
        func_800B6490(thisx);
    } else {
        func_80137070((u8 *)thisx + 0x144);
    }
}
