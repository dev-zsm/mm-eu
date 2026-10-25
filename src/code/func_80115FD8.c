#include "types.h"

typedef struct {
    u8 pad0[0x39];
    s8 level;
    u8 pad3A[6];
    u8 enabled;
    u8 pad41[0xEC5];
    u8 flagsF06;
    u8 padF07[0x3021];
    s16 state;
    u8 pad3F2A[4];
    s16 unk3F2E;
    u8 pad3F30[2];
    s16 unk3F32;
} MenuState;

typedef struct {
    u8 pad0[0x1CA3];
    u8 unk1CA3;
    u8 pad1CA4[0x14F9C];
    s16 unk16C40;
} MenuContext;

extern MenuState D_801E6EF0;
extern u8 *D_801EB7E0;

extern void Audio_PlaySfx(s32 sfxId);

s32 func_80115FD8(MenuContext *ctx, s16 arg1, s16 arg2) {
    s32 ret;
    s16 state;

    if (D_801E6EF0.enabled == 0) {
        return 0;
    }
    if (D_801E6EF0.level - arg1 < 0) {
        if (D_801E6EF0.unk3F2E != 0) {
            Audio_PlaySfx(0x4806);
        }
        return 0;
    }
    switch (arg2) {
        case 0:
        case 2:
            state = D_801E6EF0.state;
            if (state == 0 || state == 7) {
                if (state == 7) {
                    ctx->unk1CA3 = 0;
                }
                ret = 1;
                if (D_801E6EF0.flagsF06 & 8) {
                    arg1 = 0;
                }
                D_801E6EF0.unk3F32 = arg1;
                D_801E6EF0.state = 1;
                return ret;
            }
            Audio_PlaySfx(0x4806);
            return 0;
        case 1:
            state = D_801E6EF0.state;
            if (state == 0 || state == 7) {
                if (state == 7) {
                    ctx->unk1CA3 = 0;
                }
                ret = 1;
                if (D_801E6EF0.flagsF06 & 8) {
                    arg1 = 0;
                }
                D_801E6EF0.unk3F32 = arg1;
                D_801E6EF0.state = 6;
                return ret;
            }
            Audio_PlaySfx(0x4806);
            return 0;
        case 3:
            state = D_801E6EF0.state;
            if (state == 0) {
                if (D_801E6EF0.level != 0) {
                    ctx->unk16C40 = 0x50;
                    D_801E6EF0.state = 7;
                    return 1;
                }
                return 0;
            }
            if (state == 7) {
                return 1;
            }
            return 0;
        case 4:
            state = D_801E6EF0.state;
            if (state == 0 || state == 7) {
                if (state == 7) {
                    ctx->unk1CA3 = 0;
                }
                D_801E6EF0.unk3F32 = arg1;
                D_801E6EF0.state = 4;
                return 1;
            }
            Audio_PlaySfx(0x4806);
            return 0;
        case 5:
            if (D_801E6EF0.level != 0) {
                ctx->unk16C40 = 0xA;
                D_801E6EF0.state = 0xA;
                return 1;
            }
            return 0;
        case 6:
            state = D_801E6EF0.state;
            if (state == 0) {
                if (D_801E6EF0.level != 0) {
                    ctx->unk16C40 = *(s16 *)(D_801EB7E0 + 0xAE6);
                    D_801E6EF0.state = 0xC;
                    return 1;
                }
                return 0;
            }
            if (state == 0xC) {
                return 1;
            }
            return 0;
        case 7:
            state = D_801E6EF0.state;
            if (state == 0 || state == 7) {
                if (state == 7) {
                    ctx->unk1CA3 = 0;
                }
                ret = 1;
                if (D_801E6EF0.flagsF06 & 8) {
                    arg1 = 0;
                }
                D_801E6EF0.level = D_801E6EF0.level - arg1;
                return ret;
            }
            Audio_PlaySfx(0x4806);
            return 0;
    }
    return 0;
}
