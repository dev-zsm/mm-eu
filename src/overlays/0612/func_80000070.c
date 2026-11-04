// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_scopecoin.h"

void EnScopecoin_Init(Actor* thisx, PlayState* play) {
    EnScopecoin* this = (EnScopecoin*)thisx;

    Actor_SetScale(&this->actor, 0.01f);
    ActorShape_Init(&this->actor.shape, 0, ActorShadow_DrawCircle, 10.0f);

    this->rupeeIndex = OBJMUPICT_GET_RUPEE_INDEX(&this->actor);
    if ((this->rupeeIndex < 0) || (this->rupeeIndex > 7)) {
        this->rupeeIndex = 0;
    }

    if (play->actorCtx.flags & ACTORCTX_FLAG_TELESCOPE_ON) {
        if ((this->rupeeIndex == 2) || (this->rupeeIndex == 6)) {
            if (Flags_GetCollectible(play, OBJMUPICT_GET_RUPEE_FLAG(&this->actor))) {
                Actor_Kill(&this->actor);
                return;
            }
        }
        this->actor.shape.yOffset = 700.0f;
        this->actionFunc = EnScopecoin_Spin;
    } else {
        if ((this->rupeeIndex == 2) || (this->rupeeIndex == 6)) {
            if (Flags_GetCollectible(play, OBJMUPICT_GET_RUPEE_FLAG(&this->actor))) {
                Actor_Kill(&this->actor);
                return;
            }
            this->actor.draw = NULL;
            this->actionFunc = EnScopecoin_CheckCollectible;
        } else {
            Actor_Kill(&this->actor);
        }
    }
}
