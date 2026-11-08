// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_800E7BB8();
void func_800E26E8();

typedef struct {
    u8 pad[0x18884];
    u8 f;
} T0146;

void func_8000013C(u8 *arg0, T0146 *arg1) {
    func_800E7BB8(arg0, arg0 + 0x18C);
    func_800E26E8(arg1, &arg1->f, arg0 + 0x18C);
}
