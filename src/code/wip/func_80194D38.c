// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

typedef struct {
    /* 0x00 */ u8 flags;
    /* 0x01 */ u8 state;
    /* 0x02 */ u8 pad2[6];
    /* 0x08 */ s16 unk8;
    /* 0x0A */ u8 padA[2];
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[2];
    /* 0x12 */ s16 unk12;
    /* 0x14 */ u8 pad14[8];
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ u8 pad28[4];
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ u8 pad30[4];
    /* 0x34 */ f32 unk34;
    /* 0x38 */ u8 pad38[0x120];
    /* 0x158 */ s8 unk158[1];
} AudioPlayer;

typedef struct {
    /* 0x0 */ u8 op;
    /* 0x1 */ u8 arg1;
    /* 0x2 */ u8 arg2;
    /* 0x3 */ u8 arg3;
    union {
        /* 0x4 */ s32 i;
        /* 0x4 */ f32 f;
        /* 0x4 */ s8 b;
    } data;
} AudioCmd;

void AudioThread_ProcessSeqPlayerCmd(AudioPlayer *player, AudioCmd *cmd) {
    f32 volume;
    f32 oldVolume;
    s32 frames;

    switch (cmd->op) {
        case 0x41:
            if (player->unk2C != cmd->data.f) {
                player->unk2C = cmd->data.f;
                player->flags |= 4;
            }
            break;
        case 0x47:
            player->unk8 = cmd->data.i * 48;
            break;
        case 0x49:
            player->unkC = cmd->data.i * 48;
            break;
        case 0x4E:
            player->unkC = cmd->data.i;
            break;
        case 0x48:
            player->unkE = cmd->data.b;
            break;
        case 0x46:
            player->unk158[cmd->arg3] = cmd->data.b;
            break;
        case 0x4A:
            volume = (s32)cmd->arg2 / 127.0f;
            goto set_volume;
        case 0x4B:
            volume = (s32)cmd->arg2 / 100.0f * player->unk1C;
        set_volume:
            if (player->state != 2) {
                oldVolume = player->unk1C;
                player->unk24 = oldVolume;
                frames = cmd->data.i;
                if (frames == 0) {
                    player->unk1C = volume;
                } else {
                    player->state = 0;
                    player->unk12 = frames;
                    player->unk20 = (volume - oldVolume) / frames;
                }
            }
            break;
        case 0x4C:
            if (player->state != 2) {
                frames = cmd->data.i;
                if (frames == 0) {
                    player->unk1C = player->unk24;
                } else {
                    player->state = 0;
                    player->unk12 = frames;
                    player->unk20 = (player->unk24 - player->unk1C) / frames;
                }
            }
            break;
        case 0x4D:
            player->unk34 = cmd->data.f;
            if (player->unk34 == 1.0f) {
                player->flags &= ~1;
            } else {
                player->flags |= 1;
            }
            break;
    }
}
