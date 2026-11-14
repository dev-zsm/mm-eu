// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_tsn.h"

void func_8000004C(EnTsn* this, PlayState* play) {
    this->actionFunc = EnTsn_Object_Idle;
    this->actor.update = EnTsn_UpdateObject;
    this->actor.destroy = NULL;
    this->actor.draw = NULL;
    this->actor.attentionRangeType = ATTENTION_RANGE_7;

    switch (ENTSN_GET_OBJECT_TYPE(&this->actor)) {
        case ENTSN_OBJ_SEAHORSE:
            if (CHECK_WEEKEVENTREG(WEEKEVENTREG_RECEIVED_SEAHORSE)) {
            Actor_Kill(&this->actor);
            return;
            }
            this->actor.textId = 0x106E;
            break;

        case ENTSN_OBJ_POSTER:
            if (CHECK_WEEKEVENTREG(WEEKEVENTREG_LOOKED_AT_PIRATE_POSTER)) {
            this->actor.textId = 0x1091;
            } else {
            this->actor.textId = 0x108A;
            }
            break;

        default:
            break;
    }

    if (CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_GREAT_BAY_TEMPLE)) {
        if ((ENTSN_GET_OBJECT_TYPE(&this->actor)) == ENTSN_OBJ_SEAHORSE) {
            this->actionFunc = EnTsn_Seahorse_Idle;
        } else {
            Actor_Kill(&this->actor);
        }
        return;
    }

    this->fisherman = EnTsn_FindFisherman(play);
    this->flags = 0;

    if (this->fisherman == NULL) {
        Actor_Kill(&this->actor);
        return;
    }

    if ((ENTSN_GET_OBJECT_TYPE(&this->actor)) == ENTSN_OBJ_POSTER) {
        Actor_ChangeCategory(play, &play->actorCtx, &this->actor, ACTORCAT_PROP);
    }
}
