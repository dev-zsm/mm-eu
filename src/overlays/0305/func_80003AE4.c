// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A26B74(ObjIceblock* this, PlayState* play) {
    Gfx_DrawDListXlu(play, gIceBlockCubeDL);
    if (ICEBLOCK_GET_ICEBERG(&this->dyna.actor) && (this->unk_2B4 > 0.0f)) {
        AnimatedMat_Draw(play, Lib_SegmentedToVirtual(gIceBlockIceBergSublimatingAirTexAnim));
        Gfx_DrawDListXlu(play, gIceBlockIceBergDL);
    }
}
