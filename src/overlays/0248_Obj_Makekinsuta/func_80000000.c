// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_makekinsuta.h"

bool ref_func_8099FA40(ObjMakekinsuta* this, PlayState* play) {
    s32 chestFlag = -1;
    s32 skulltulaParams = (OBJMAKEKINSUTA_GET_1F(&this->actor) << 2) | 0xFF01;

    if (OBJMAKEKINSUTA_GETS_3(skulltulaParams)) {
        chestFlag = OBJMAKEKINSUTA_GETS_3FC(skulltulaParams);
    }
    return (chestFlag < 0) == true || !Flags_GetTreasure(play, chestFlag);
}
