#include "types.h"
typedef struct { u8 p[0x1F34]; u16 v; } P;
void func_800B8C4C(void *, s32);
void func_80000374(void *thisx, P *play) {
    switch (play->v) {
        case 0x4E:
        case 0x59:
        case 0x64:
        case 0x6F:
        case 0x7A:
        case 0x85:
        case 0x90:
        case 0x9B:
        case 0xA6:
        case 0xB1:
        case 0xBC:
        case 0xC7:
        case 0xD2:
        case 0xDD:
        case 0xE8:
        case 0xF3:
        case 0xFE:
            func_800B8C4C(thisx, 0x3916);
            break;
        case 0xAD:
            func_800B8C4C(thisx, 0x3A77);
            break;
    }
}
