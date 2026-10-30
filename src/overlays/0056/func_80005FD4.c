#include "types.h"
void func_8082DED0();
typedef struct { u16 x[3]; } B6;
typedef struct { u8 pad[0x260]; B6 *p; u8 pad2[0x14]; B6 a; } S;
void func_80005FD4(S *a0) {
    a0->a = *a0->p;
    func_8082DED0(a0, 3);
}
