#include "types.h"
#include "m2c_compat.h"
extern u8 D_80B6F978[];
extern u8 D_80B6F97C[];
extern u8 D_80B6F980[];
extern u8 D_80B6F98C[];
void func_800B1BD8(u8 *a, u8 *b, u8 *c, u8 *d, u8 *e, u8 *f);

void func_80002768(u8 *a, u8 *b) {
    func_800B1BD8(a, b, D_80B6F980, D_80B6F98C, D_80B6F978, D_80B6F97C);
}
