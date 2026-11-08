// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_weather_tag.h"

void EnWeatherTag_Init(Actor* thisx, PlayState* play) {
    EnWeatherTag* this = (EnWeatherTag*)thisx;
    s32 pad;
    Path* path;
    s32 pathIndex;

    
    this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;

    switch (WEATHER_TAG_TYPE(&this->actor)) {
        case WEATHERTAG_TYPE_UNK0:
            this->unk154 = 0;
            this->fadeDistance = this->actor.world.rot.x;
            this->unk158 = this->actor.world.rot.y;
            EnWeatherTag_SetupAction(this, ref_func_80966A08);
            break;

        case WEATHERTAG_TYPE_UNK1:
            if (CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_STONE_TOWER_TEMPLE)) {
                Actor_Kill(&this->actor);
            }
            EnWeatherTag_SetupAction(this, ref_func_80966B08);
            break;

        case WEATHERTAG_TYPE_WINTERFOG:
            EnWeatherTag_SetupAction(this, ref_func_80966E0C);
            break;

        case WEATHERTAG_TYPE_UNK3:
            EnWeatherTag_SetupAction(this, ref_func_80966EF0);
            break;

        case WEATHERTAG_TYPE_SKYBOX_STARS:
            EnWeatherTag_SetupAction(this, ref_func_80966FEC);
            break;

        case WEATHERTAG_TYPE_UNK5:
            Actor_ChangeCategory(play, &play->actorCtx, &this->actor, ACTORCAT_ITEMACTION);
            play->skyboxId = SKYBOX_3;
            play->envCtx.lightConfig = 5;
            play->envCtx.changeLightNextConfig = 5;
            ref_D_801F4E74 = 1.0f;
            EnWeatherTag_SetupAction(this, ref_func_80966BF4);
            break;

        case WEATHERTAG_TYPE_WATERMURK:
            pathIndex = WEATHER_TAG_GET_PATH_INDEX(&this->actor);
            path = &play->setupPathList[pathIndex];
            this->pathPoints = Lib_SegmentedToVirtual(path->points);
            this->pathCount = path->count;
            EnWeatherTag_SetupAction(this, ref_func_809672DC);
            break;

        case WEATHERTAG_TYPE_LOCALDAY2RAIN:
            EnWeatherTag_SetupAction(this, ref_func_809674C8);
            break;

        default:
            break;
    }
}
