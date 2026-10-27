#include "types.h"
typedef struct {
    u16 base;
    u16 startFrame;
    u16 endFrame;
    u8 sourceStrength;
    u8 duration;
    u8 decreaseRate;
} CsCmdRumble;
typedef struct { u8 pad0[0x9C]; u32 gameplayFrames; } Play;
typedef struct { u8 pad0[0x10]; u16 frames; } Cs;
extern void Rumble_Request(f32 a, u8 b, u8 c, u8 d);
void CutsceneCmd_RumbleController(Play *play, Cs *csCtx, CsCmdRumble *cmd) {
    switch (cmd->base) {
        case 1:
            if (csCtx->frames == cmd->startFrame) {
                Rumble_Request(0.0f, cmd->sourceStrength, cmd->duration, cmd->decreaseRate);
            }
            break;
        case 2:
            if (csCtx->frames >= cmd->startFrame && cmd->endFrame >= csCtx->frames &&
                (csCtx->frames == cmd->startFrame || !(play->gameplayFrames & 0x3F))) {
                Rumble_Request(0.0f, cmd->sourceStrength, cmd->duration, cmd->decreaseRate);
            }
            break;
    }
}
