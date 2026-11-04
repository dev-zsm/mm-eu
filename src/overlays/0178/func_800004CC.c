// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mure2.h"

void ObjMure2_KillChildren(ObjMure2* this, PlayState* play) {
    s32 i;

    for (i = 0; i < sChildCounts[OBJ_MURE2_GET_CHILD_TYPE(&this->actor)]; i++) {
        if (((this->spawnFlags >> i) & 1) == 0) {
            if (this->actors[i] != NULL) {
                if (Actor_HasParent(this->actors[i], play)) {
                    this->spawnFlags |= 1 << i;
                } else {
                    Actor_Kill(this->actors[i]);
                }
                this->actors[i] = NULL;
            }
        } else {
            this->actors[i] = NULL;
        }
    }
}
