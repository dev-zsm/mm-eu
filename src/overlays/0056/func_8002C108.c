#include "types.h"
typedef struct { u8 pad0[0x14A]; s8 a14A; } P;
extern u8 D_400DDB0[];
void func_808583BC();
s32 func_80123E10();
void func_80123F54();
void func_8002C108(s32 a, P *p, s32 c) {
    func_808583BC(a, p, D_400DDB0);
    p->a14A = 0x14;
    func_80123F54(p, func_80123E10(p, p->a14A));
}
