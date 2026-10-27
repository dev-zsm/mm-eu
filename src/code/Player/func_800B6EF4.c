#include "types.h"

typedef struct {
    u8 pad0[0x390];
    struct {
        u8 pad0[0x1EC];
        u32 flags;
    } *unk390;
} Player;

typedef struct {
    u8 pad0[0x186E3];
    u8 unk186E3;
} PlayState;

extern void *Play_GetCamera(PlayState *play, s32 a1);
extern void Camera_ChangeSetting(void *a0, s32 a1);

void Player_SetCameraHorseSetting(PlayState *play, Player *player) {
    if (play->unk186E3 != 4) {
        if (*(s16 *)player == 0) {
            if (player->unk390 != NULL) {
                if (!(player->unk390->flags & 0x10)) {
                    Camera_ChangeSetting(Play_GetCamera(play, 0), 4);
                }
            }
        }
    }
}
