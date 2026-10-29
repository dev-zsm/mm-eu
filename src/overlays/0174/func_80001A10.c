#include "types.h"

extern void func_8093F4EC();
extern void *D_8093F6E0[];

void func_80001A10(u8 *a0, void *a1) {
    func_8093F4EC(a0, a1, 0x7D0);
    *(void **)(a0 + 0x410) = D_8093F6E0;
}
