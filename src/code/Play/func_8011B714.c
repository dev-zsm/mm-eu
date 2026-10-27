// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_8011B714(u8 *arg0, s16 arg1) {
    s16 i;
    u8 *p;

    p = arg0 + 0x169E8;
    *(s16 *)(arg0 + 0x16C6E) = 1;
    *(s16 *)(arg0 + 0x16C70) = arg1;
    *(s16 *)(arg0 + 0x16CE4) = 0xFF;
    *(s16 *)(arg0 + 0x16CE6) = 0xA5;
    *(s16 *)(arg0 + 0x16CE8) = 0x37;
    *(s16 *)(arg0 + 0x16CEA) = 0xFF;
    *(s16 *)(arg0 + 0x16CF2) = 0x14;
    *(s16 *)(arg0 + 0x16CF0) = 0;
    *(s16 *)(arg0 + 0x16CEC) = 1;
    *(s16 *)(arg0 + 0x16CF4) = 0;
    i = 0;
    do {
        u8 *q = (u8 *)((s32)p + i * 2);
        *(s16 *)(q + 0x2AA) = 0;
        *(s16 *)(q + 0x29A) = 0;
        *(s16 *)(q + 0x28A) = *(s16 *)(q + 0x2AA);
        if (*(s16 *)(p + 0x288) == 1) {
            q = (u8 *)((s32)p + i * 4);
            *(f32 *)(q + 0x2BC) = 140.0f;
            *(f32 *)(q + 0x2DC) = 100.0f;
        } else {
            q = (u8 *)((s32)p + i * 4);
            *(f32 *)(q + 0x2DC) = 200.0f;
            *(f32 *)(q + 0x2BC) = 200.0f;
        }
        i += 1;
    } while (i < 8);
    *(s16 *)(p + 0x28A) = 1;
}
