#include "types.h"

extern u8 D_801E6F72;
extern u8 D_801E6F73;
extern u8 D_801E6EF0[];

s32 func_80114E28(u8 v) {
    u8 w = v;
    u8 *p;
    s32 i = 0x14;

    if (D_801E6F72 == v) {
        return 1;
    }
    if (D_801E6F73 == w) {
        return 1;
    }
    p = (u8 *)(i + (s32)D_801E6EF0);
    if (p[0x70] == w) {
        return 1;
    }
    if (p[0x71] == w) {
        return 1;
    }
    if (p[0x72] == w) {
        return 1;
    }
    if (p[0x73] == w) {
        return 1;
    }
    return 0;
}
