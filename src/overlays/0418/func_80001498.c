// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_osn.h"

void func_80001498(Actor* thisx, PlayState* play) {
    s32 pad;
    EnOsn* this = (EnOsn*)thisx;
    u32 isSwitchFlagSet = Flags_GetSwitch(play, 0);

    this->actionFunc(this, play);
    Actor_MoveWithGravity(&this->actor);
    SkelAnime_Update(&this->skelAnime);

    if (ENOSN_GET_TYPE(&this->actor) == OSN_TYPE_CHOOSE) {
        if (isSwitchFlagSet) {
            this->actor.flags |= ACTOR_FLAG_ATTENTION_ENABLED;
            EnOsn_UpdateCollider(this, play);
            this->actor.draw = EnOsn_Draw;
        } else {
            this->actor.draw = NULL;
            this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
        }
    }

    Actor_TrackPlayer(play, &this->actor, &this->headRot, &this->torsoRot, this->actor.focus.pos);
}
