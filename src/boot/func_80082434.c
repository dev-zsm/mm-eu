// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern void func_8008198C();
extern u8 D_800988AC[];
extern u8 D_800988BC[];
extern u8 *D_80096D68[];

void Fault_LogFPCSR(u32 value) {
    s32 i;
    u32 flag = 0x20000;

    func_8008198C(D_800988AC, value);
    for (i = 0; i < 6; i++) {
        if (value & flag) {
            func_8008198C(D_800988BC, D_80096D68[i]);
            break;
        }
        flag >>= 1;
    }
}
