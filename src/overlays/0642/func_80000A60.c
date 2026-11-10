#include "types.h"
typedef struct { u8 p[0x120]; s32 a; u8 q[0x170 - 0x124]; u8 b[1]; } T;
void func_800B6490(void *);
void func_80137070(void *);
void func_80000A60(T *thisx, s32 play) {
    T *this = thisx;
    if (this->a == 0) {
        func_800B6490(this);
    } else {
        func_80137070(this->b);
    }
}
