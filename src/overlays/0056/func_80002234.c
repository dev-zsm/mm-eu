#include "types.h"
#include "generated/overlays/0056.h"
s32 func_8082EBD4();
s32 func_80002234(s32 a, s32 b, s32 c) {
    if (b < 0xFD && func_8082EBD4(a) == c) {
        return 1;
    }
    return 0;
}
