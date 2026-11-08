// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_800E7BB8();
void func_800E2500();

typedef struct {
    u8 pad[0x18884];
    u8 f;
} T0195;

void func_8000113C(u8 *arg0, T0195 *arg1) {
    func_800E7BB8(arg0, arg0 + 0x2F4);
    func_800E2500(arg1, &arg1->f, arg0 + 0x2F4);
}
