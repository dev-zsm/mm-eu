#include "types.h"
typedef struct { u8 p[0x294]; u8 c[1]; } T;
typedef struct { u8 p[0x18884]; u8 d[1]; } P;
void func_800E7BB8();
void func_800E2500();
void func_800E26E8();
void func_80002940(T *this, P *play) {
    u8 *b;
    func_800E7BB8(this, this->c);
    b = play->d;
    func_800E2500(play, b, this->c);
    func_800E26E8(play, b, this->c);
}
