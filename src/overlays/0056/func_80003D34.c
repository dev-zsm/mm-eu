#include "types.h"
typedef struct { u8 pad0[0x124]; s32 a124; u8 pad1[0x224]; s32 a34C; } A;
s32 func_80124578();
void func_800B6490();
void func_80003D34(A *thisx) {
    A *this = thisx;
    if (func_80124578(this) != 0) {
        if (this->a34C != 0) {
            func_800B6490(this->a34C);
            this->a124 = 0;
            this->a34C = 0;
        }
    }
}
