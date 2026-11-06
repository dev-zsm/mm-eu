// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_elf_msg2.h"

void ref_func_8096EE64(ElfMsg2* this, PlayState* play) {
    if (Actor_TextboxIsClosing(&this->actor, play)) {
        if (this->actor.csId != CS_ID_NONE) {
            if (CutsceneManager_GetCurrentCsId() == this->actor.csId) {
                CutsceneManager_Stop(this->actor.csId);
            }
        }

        if (this->actor.home.rot.z != 1) {
            Actor_Kill(&this->actor);
            if (ELFMSG2_GET_SWITCH_FLAG(&this->actor) != 0x7F) {
                Flags_SetSwitch(play, ELFMSG2_GET_SWITCH_FLAG(&this->actor));
            }
            return;
        }

        ElfMsg2_SetupAction(this, ref_func_8096EF98);
    } else if ((this->actor.csId != CS_ID_NONE) && (CutsceneManager_GetCurrentCsId() != this->actor.csId)) {
        if (CutsceneManager_GetCurrentCsId() == CS_ID_GLOBAL_TALK) {
            CutsceneManager_Stop(CS_ID_GLOBAL_TALK);
            CutsceneManager_Queue(this->actor.csId);
        } else if (CutsceneManager_IsNext(this->actor.csId)) {
            CutsceneManager_Start(this->actor.csId, &this->actor);
        } else {
            CutsceneManager_Queue(this->actor.csId);
        }
    }
}
