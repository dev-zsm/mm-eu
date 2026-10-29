#include "types.h"

extern void func_80136480();
extern void func_8082D8D4();

void func_8002B7C4(void *a0, u8 *a1, void *a2) {
    func_80136480(a0, a1 + 0x240);
    func_8082D8D4(a1, a2);
}
