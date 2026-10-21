// FLAGS: -O1 -g0 -mips2
#include "types.h"

s32 func_8008FBA0(void);
void func_80095420(s32 arg0);

void func_80088994(s32 arg0) {
    if (func_8008FBA0() != 0) {
        do {
        } while (func_8008FBA0() != 0);
    }
    func_80095420(0x125);
}
