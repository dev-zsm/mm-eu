#include "types.h"
#include "generated/overlays/0056.h"
void func_8082D500();
void func_80836038();
s32 func_80003918(s32 a, s32 b, s32 c) {
    if (c == 0) {
        func_8082D500(a, b);
        func_80836038(b, a);
        return 1;
    }
    return 0;
}
