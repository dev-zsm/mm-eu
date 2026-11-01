// FLAGS: -O2 -g0 -mips2
#include "types.h"


void AudioThread_QueueCmdS8(s32, s8);                     /* extern */
void AudioSeq_QueueSeqCmd(s32);                         /* extern */
extern f32 *D_801CF024;
extern f32 D_801CF028;
extern f32 D_801D8680;
extern f32 D_801D8684;
extern f32 D_801D8688;

void func_801A1884(f32 *arg0, f32 arg1) {
    f32 *var_v0;
    f32 temp_f2;
    f32 var_f22;
    s32 var_s0;
    s32 var_v0_2;
    s8 var_s4;

    var_v0 = D_801CF024;
    if (var_v0 == NULL) {
        D_801CF028 = arg1;
        D_801CF024 = arg0;
        var_v0 = arg0;
    } else if (arg0 != var_v0) {
        if (arg1 < D_801CF028) {
            D_801CF028 = arg1;
            D_801CF024 = arg0;
            var_v0 = arg0;
        }
    } else {
        D_801CF028 = arg1;
    }
    temp_f2 = *var_v0;
    var_v0_2 = 0;
    var_s0 = 0;
    if (temp_f2 > 100.0f) {
        var_s4 = 0x7F;
    } else if (temp_f2 < -100.0f) {
        var_s4 = 0;
    } else {
        var_s4 = (s8) (s32) (((temp_f2 / 100.0f) * 64.0f) + 64.0f);
    }
    if (D_801CF028 > 400.0f) {
        var_f22 = D_801D8680;
    } else if (D_801CF028 < 120.0f) {
        var_f22 = 1.0f;
    } else {
        var_f22 = ((1.0f - ((D_801CF028 - 120.0f) / 280.0f)) * D_801D8684) + D_801D8688;
    }
    do {
        if (var_v0_2 != 9) {
            AudioSeq_QueueSeqCmd((var_s0 << 8) | 0x60020000 | ((u32) (127.0f * var_f22) & 0xFF));
            AudioThread_QueueCmdS8(((var_s0 & 0xFF) << 8) | 0x03000000, var_s4);
        }
        var_s0 = (var_s0 + 1) & 0xFF;
        var_v0_2 = var_s0;
    } while (var_s0 < 0x10);
}
