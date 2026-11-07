#include "types.h"
#include "m2c_compat.h"
extern u8 D_801C2D7B;
extern u8 D_801E6F60[];
void func_801520F8(u8 *a, s32 b);

void func_800001FC(u8 *a) {
    if (D_801E6F60[D_801C2D7B] == 0x43) {
        func_801520F8(a, 0x34);
    }
    func_801520F8(a, 0xF);
}
