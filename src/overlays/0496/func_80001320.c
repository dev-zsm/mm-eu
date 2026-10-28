#include "types.h"
extern u8 D_80B47650[];
void func_80001320(u8 *a) { a[0x2BC] &= ~1; *(void **)(a + 0x200) = D_80B47650; }
