// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

void Fault_WalkStack(u32 *arg0, u32 *arg1, u32 *arg2) {
    u32 v0 = *arg0;
    u32 v1 = *arg1;
    u32 a3 = *arg2;
    u32 t0 = 0;
    u32 t2;
    u32 t6;
    u32 t4;
    u32 jr = 0x03E00008;
    u32 two = 2;
    u32 addiu_sp = 0x27BD;
    u32 eret = 0x42000018;
    s16 imm;

    if ((v0 & 3) || v0 < 0x80000000 || v0 >= 0xC0000000 || (a3 & 3) || a3 < 0x80000000 || a3 >= 0xC0000000) {
        *arg0 = 0;
        *arg1 = 0;
        *arg2 = 0;
        return;
    }
    if ((v1 & 3) || v1 < 0x80000000 || v1 >= 0xC0000000) {
        *arg1 = a3;
        return;
    }
    for (;;) {
        t2 = *(u32 *)v1;
        t6 = t0 >> 26;
        t4 = (t2 >> 16) & 0xFFFF;
        imm = (s16)t2;
        if (t4 == 0x8FBF) {
            a3 = *(u32 *)(v0 + imm);
        } else if (t4 == addiu_sp) {
            v0 += imm;
        } else if (t2 == eret) {
            v0 = 0;
            v1 = 0;
            a3 = 0;
            break;
        }
        if (t0 == jr) {
            v1 = a3;
            break;
        }
        if (t6 == two) {
            v1 = ((v1 >> 28) << 28) | ((t0 << 6) >> 4);
            break;
        }
        t0 = t2;
        v1 += 4;
    }
    *arg0 = v0;
    *arg1 = v1;
    *arg2 = a3;
}
