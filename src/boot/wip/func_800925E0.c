// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[2];
    u8 unk2;
    u8 unk3;
} Struct800925E0;

extern u8 D_8009D2E1;
extern s32 D_8009E9A0;

void __osSiGetAccess(void);
void __osSiRelAccess(void);
void __osPfsRequestData(s32 a0);
s32 __osSiRawStartDma(s32 a0, void *a1);
void osRecvMesg(s32 a0, void *a1, s32 a2);
void __osPfsGetInitData(u8 *a0, Struct800925E0 *a1);

s32 osPfsIsPlug(s32 arg0, u8 *arg1) {
    s32 sp6C;
    u8 sp68[4];
    u8 sp67;
    Struct800925E0 sp54[4];
    Struct800925E0 *p;
    s32 var_s0;
    s32 var_s1;
    u8 var_s5;

    var_s5 = 0;
    var_s1 = 3;
    __osSiGetAccess();
    var_s0 = 0;
    do {
        __osPfsRequestData(0);
        __osSiRawStartDma(1, &D_8009E9A0);
        osRecvMesg(arg0, sp68, 1);
        sp6C = __osSiRawStartDma(0, &D_8009E9A0);
        osRecvMesg(arg0, sp68, 1);
        __osPfsGetInitData(&sp67, sp54);
        p = sp54;
        if (*(u8 *)&D_8009D2E1 > 0) {
            do {
                if (!(p->unk2 & 4)) {
                    var_s1 -= 1;
                    break;
                }
                var_s0 += 1;
                p++;
            } while (var_s0 < *(u8 *)&D_8009D2E1);
        }
        if ((var_s0 ^ *(u8 *)&D_8009D2E1) == 0) {
            var_s1 = 0;
        }
        var_s0 = 0;
    } while (var_s1 > 0);
    p = sp54;
    if (*(u8 *)&D_8009D2E1 > 0) {
        do {
            if (p->unk3 == 0 && (p->unk2 & 1)) {
                var_s5 = (var_s5 | (1 << var_s0)) & 0xFF;
            }
            var_s0 += 1;
            p++;
        } while (var_s0 < *(u8 *)&D_8009D2E1);
    }
    __osSiRelAccess();
    *arg1 = var_s5;
    return sp6C;
}
