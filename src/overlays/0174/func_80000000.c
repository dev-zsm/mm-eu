#include "types.h"
typedef struct { u8 pad0[0x1C]; s16 params; u8 pad1[0x3D6]; void* a3F4; s32 a3F8; s32 a3FC; } A;
typedef struct { u8 pad0[0x18864]; u8* a18864; } P;
void func_80000000(A *this, P *play) {
    this->a3FC = (this->params & 0xF000) >> 12;
    if (this->a3FC == 0xF) {
        this->a3FC = -1;
        this->a3F4 = NULL;
        return;
    }
    this->a3F8 = 0;
    this->a3F4 = play->a18864 + this->a3FC * 8;
}
