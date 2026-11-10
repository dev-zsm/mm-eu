#include "types.h"
typedef struct { u8 p[0xA70]; u32 f; } Pl;
typedef struct { u8 p[0x1CCC]; Pl *pl; } P;
typedef struct { u8 p[0x356]; s16 a; } T;
s32 func_8013E684();
void func_80B41A24(T *, P *);
void func_800019C0(T *this, P *play) {
    if (func_8013E684(this, this->a, 0x7C, 1) != 0) {
        play->pl->f |= 0x20000000;
        func_80B41A24(this, play);
    }
}
