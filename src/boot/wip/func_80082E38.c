// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

typedef struct {
    u16 unk0;
    u8 pad2[0xA];
    u16 unkC;
} Pad;

extern u8 *D_8009C220;
extern u32 D_80098C08;

extern void Fault_Sleep();
extern void Fault_UpdatePadImpl();
extern void Fault_DrawMemDumpContents();

void Fault_DrawMemDump(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    s32 var_s0;
    s32 var_v1;
    u16 temp_a0;
    u16 temp_v0;
    u32 var_s3;
    Pad *temp_s1;

    var_s3 = arg0;
    temp_s1 = (Pad *)(D_8009C220 + 0x7E4);
loop_1:
    if (var_s3 < 0x80000000U) {
        var_s3 = 0x80000000;
    }
    if (var_s3 >= 0x807FFF01U) {
        var_s3 = 0x807FFF00;
    }
    var_s3 &= ~0xF;
    Fault_DrawMemDumpContents(&D_80098C08, var_s3, 0);
    var_s0 = 0x258;
    if (D_8009C220[0x7CF] != 0) {
loop_6:
        if (var_s0 != 0) {
            var_s0--;
            Fault_Sleep(0x10);
            Fault_UpdatePadImpl();
            if (~(temp_s1->unkC | ~0x20) == 0) {
                D_8009C220[0x7CF] = 0;
            }
            if (D_8009C220[0x7CF] == 0) {
                goto loop_10;
            }
            goto loop_6;
        }
    } else {
        do {
loop_10:
            Fault_Sleep(0x10);
            Fault_UpdatePadImpl();
            temp_v0 = temp_s1->unkC;
        } while (temp_v0 == 0);
        if (~(temp_v0 | ~0x1000) != 0) {
            temp_a0 = temp_s1->unk0;
            var_v1 = 0x10;
            if (~(temp_a0 | 0xFFFF7FFF) == 0) {
                var_v1 = 0x100;
            }
            if (~(temp_a0 | ~0x4000) == 0) {
                var_v1 <<= 8;
            }
            if (~(temp_v0 | ~0x800) == 0) {
                var_s3 -= var_v1;
            }
            if (~(temp_v0 | ~0x400) == 0) {
                var_s3 += var_v1;
            }
            if (~(temp_v0 | ~8) == 0) {
                var_s3 = arg0;
            }
            if (~(temp_v0 | ~4) == 0) {
                var_s3 = arg1;
            }
            if (~(temp_v0 | ~2) == 0) {
                var_s3 = arg2;
            }
            if (~(temp_v0 | ~1) == 0) {
                var_s3 = arg3;
            }
            if (~(temp_v0 | ~0x20) == 0) {
                D_8009C220[0x7CF] = 1;
            } else {
                goto loop_1;
            }
        }
    }
}
