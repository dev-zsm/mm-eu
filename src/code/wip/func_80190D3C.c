// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[0x10];
} Entry; /* size 0x14 */

extern struct {
    /* 0x0000 */ u8 pad0[0x2868];
    /* 0x2868 */ Entry *unk2868;
    /* 0x286C */ u8 pad286C[0x4398 - 0x286C];
    /* 0x4398 */ u8 unk4398[1];
} D_801F84B0;

s32 AudioLoad_TrySyncLoadSampleBank(s32, void *, s32, s32);
s32 AudioLoad_SyncLoad(s32, s32, s32 *);
s32 AudioLoad_GetRealTableIndex(s32, s32);
void AudioLoad_RelocateFontAndPreloadSamples(s32, s32, s32 *, s32);

s32 AudioLoad_SyncLoadFont(s32 arg0) {
    s32 sp44;
    s32 sp3C;
    s32 sp38;
    u8 sp34[4];
    u8 sp30[4];
    s32 sp2C;
    s32 sp28;
    s32 sp1C;
    s32 sp20[2];
    s32 temp_v0;
    s32 var_a1;
    u8 temp_a0;
    u8 var_a3;
    Entry *temp_v1;

    temp_v0 = AudioLoad_GetRealTableIndex(1, arg0);
    sp1C = temp_v0;
    if (D_801F84B0.unk4398[temp_v0] == 1) {
        return 0;
    }
    temp_v1 = D_801F84B0.unk2868 + temp_v0;
    temp_a0 = temp_v1->unk2;
    var_a3 = temp_v1->unk3;
    sp20[0] = temp_a0;
    sp20[1] = var_a3;
    if (temp_a0 != 0xFF) {
        sp3C = var_a3;
        temp_v0 = AudioLoad_TrySyncLoadSampleBank(temp_a0, sp30, 0, var_a3);
        var_a3 = sp3C;
        sp28 = temp_v0;
    } else {
        sp28 = 0;
    }
    if (var_a3 != 0xFF) {
        sp2C = AudioLoad_TrySyncLoadSampleBank(var_a3, sp34, 0, var_a3);
    } else {
        sp2C = 0;
    }
    temp_v0 = AudioLoad_SyncLoad(1, arg0, &sp38);
    var_a1 = temp_v0;
    if (temp_v0 == 0) {
        return 0;
    }
    if (sp38 == 1) {
        sp44 = var_a1;
        AudioLoad_RelocateFontAndPreloadSamples(sp1C, var_a1, sp20, 0);
        var_a1 = sp44;
    }
    return var_a1;
}
