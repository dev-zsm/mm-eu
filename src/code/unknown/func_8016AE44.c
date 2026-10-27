// FLAGS: -O2 -g3 -mips2
#include "types.h"

s16 func_8016AE44(s16 arg0) {
    if (arg0 == 0x18) {
        return 0x16;
    }
    if (arg0 == 0) {
        return 0x45;
    }
    if (arg0 == 0x5A) {
        return 0x50;
    }
    if (arg0 == 0x48) {
        return 0x4D;
    }
    if (arg0 == 0x5E) {
        return 0x5D;
    }
    if (arg0 == 0x59) {
        return 0x58;
    }
    return arg0;
}
