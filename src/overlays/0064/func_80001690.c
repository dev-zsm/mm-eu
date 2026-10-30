#include "types.h"
extern void func_8086D810();
extern void func_8086E5AC();
typedef struct { u8 pad0[0x18E]; s16 t; } A;
void func_80001690(A *a) {
    if (a->t != 0) {
        a->t--;
    }
    if (a->t == 0) {
        func_8086D810(a);
        func_8086E5AC(a);
    }
}
