// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/overlays/0129.h"

s32 func_80182AD0();
void func_800BDDC0();
void func_800BDD44();
extern u8 D_6003030;
extern u8 D_60030C0;

s32 func_800001D0(s32 arg0, s32 *arg1) {
    if (func_80182AD0(*arg1) == 0) {
        return 1;
    }
    func_800BDDC0(arg1, &D_6003030);
    func_800BDD44(arg1, &D_60030C0);
    return 1;
}
