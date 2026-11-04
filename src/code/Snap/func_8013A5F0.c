// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_snap.h"

s32 Snap_RecordPictographedActors(PlayState* play) {
    PictoActor* pictoActor;
    Actor* actor;
    s32 category = 0;
    s32 seen;
    s32 validCount = 0;

    gSaveContext.save.saveInfo.pictoFlags0 = 0;
    gSaveContext.save.saveInfo.pictoFlags1 = 0;

    if (play->sceneId == SCENE_20SICHITAI) {
        Snap_SetFlag(PICTO_VALID_IN_SWAMP);
    }

    for (; category < ACTORCAT_MAX; category++) {
        for (actor = play->actorCtx.actorLists[category].first; actor != NULL; actor = actor->next) {
            seen = 0;

            
            switch (play->sceneId) {
                case SCENE_20SICHITAI:
                    if ((actor->id == ACTOR_EN_MNK) || (actor->id == ACTOR_EN_BIGOKUTA)) {
                        seen = PICTO_SEEN_IN_SCENE;
                    }
                    break;

                default:
                    seen = 0;
                    break;
            }

            
            switch (actor->id) {
                case ACTOR_EN_KAKASI:
                    if (KAKASI_GET_ABOVE_GROUND(actor) == 1) {
                        seen |= PICTO_SEEN_ANYWHERE;
                        break; 
                    }
                    FALLTHROUGH;
                case ACTOR_EN_ZOV:
                    seen |= PICTO_SEEN_ANYWHERE;
                    break;

                case ACTOR_EN_BAL:
                    seen |= PICTO_SEEN_ANYWHERE;
                    break;

                case ACTOR_EN_DNQ:
                    seen |= PICTO_SEEN_ANYWHERE;
                    break;

                case ACTOR_EN_GE1:
                case ACTOR_EN_GE3:
                case ACTOR_EN_KAIZOKU:
                case ACTOR_EN_GE2:
                    seen |= PICTO_SEEN_ANYWHERE;
                    break;

                default:
                    break;
            }

            if (!seen) {
                continue;
            }

            
            pictoActor = (PictoActor*)actor;
            if (pictoActor->validationFunc != NULL) {
                if (pictoActor->validationFunc(play, actor) == 0) {
                    validCount++;
                }
            }
        }
    }

    return validCount;
}
