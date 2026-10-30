#include "types.h"
typedef struct { u8 pad[0x170]; u16 t; } A;
extern u8 D_80957584;
extern void func_809573C0();
void func_80000278(A *a, s32 b) {
    if (a->t > 0) {
        a->t -= 1;
        return;
    }
    func_809573C0(a, &D_80957584);
}
