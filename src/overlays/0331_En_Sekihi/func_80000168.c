// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_sekihi.h"

void ref_func_80A44DE8(EnSekihi* this, PlayState* play) {
    CollisionHeader* colHeader = NULL;
    s32 type;
    CollisionHeader* colHeaders[] = {
        &gSunsSongGraveTriforceCol, &gSunsSongGraveGoronCol, &gSunsSongGraveKokiriCol,
        &gSongOfSoaringPedestalCol, &gMikauGraveCol,
    };

    type = ENSIKIHI_GET_TYPE(&this->dyna.actor);
    if (Object_IsLoaded(&play->objectCtx, this->objectSlot)) {
        this->dyna.actor.objectSlot = this->objectSlot;
        this->dyna.actor.draw = EnSekihi_Draw;
        if (type == SEKIHI_TYPE_4) {
            this->actionFunc = ref_func_80A450B0;
        } else {
            this->actionFunc = EnSekihi_DoNothing;
        }

        Actor_SetObjectDependency(play, &this->dyna.actor);
        DynaPolyActor_Init(&this->dyna, 0);
        if (colHeaders[type] != NULL) {
            CollisionHeader_GetVirtual(colHeaders[type], &colHeader);
        }

        this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);
        if ((type == SEKIHI_TYPE_4) && (INV_CONTENT(ITEM_MASK_ZORA) != ITEM_MASK_ZORA)) {
            Actor_Kill(&this->dyna.actor);
        }
    }
}
