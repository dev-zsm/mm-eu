// FLAGS: -O1 -g3 -mips2 -trapuv
#include "types.h"

extern void func_8008198C();
extern u8 D_800988AC[];
extern u8 D_800988BC[];
extern s32 D_80096D68[];

void Fault_LogFPCSR(u32 arg0) {
    u32 bit;
    s32 i;

    func_8008198C(D_800988AC, arg0);
    bit = 0x20000;
    for (i = 0; i != 6; i++) {
        if (arg0 & bit) {
            func_8008198C(D_800988BC, D_80096D68[i]);
            return;
        }
        bit >>= 1;
    }
}
