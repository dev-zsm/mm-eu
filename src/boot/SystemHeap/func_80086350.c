#include "types.h"
extern s32 D_8009D0F0;
void func_8008743C(s32 *p, s32 n);

void SystemHeap_Malloc(s32 arg0) {
    s32 n = arg0;
    if (arg0 == 0) {
        n = 1;
    }
    func_8008743C(&D_8009D0F0, n);
}
