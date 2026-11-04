// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skin_awb.h"

void Skin_InitAnimatedLimb(GameState* gameState, Skin* skin, s32 limbIndex) {
    s32 i;
    SkinLimb** skeleton = Lib_SegmentedToVirtual(skin->skeletonHeader->segment);
    SkinAnimatedLimbData* animatedLimbData =
        Lib_SegmentedToVirtual(((SkinLimb*)Lib_SegmentedToVirtual(skeleton[limbIndex]))->segment);
    SkinLimbModif* limbModifications = Lib_SegmentedToVirtual(animatedLimbData->limbModifications);

    for (i = 0; i < ARRAY_COUNT(skin->vtxTable->buf); i++) {
        Vtx* vertices = skin->vtxTable[limbIndex].buf[i];
        SkinLimbModif* modifEntry;

        for (modifEntry = limbModifications; modifEntry < &limbModifications[animatedLimbData->limbModifCount];
             modifEntry++) {
            SkinVertex* skinVertices = Lib_SegmentedToVirtual(modifEntry->skinVertices);
            SkinVertex* skinVtxEntry;

            for (skinVtxEntry = skinVertices; skinVtxEntry < &skinVertices[modifEntry->vtxCount];) {
                Vtx* vtx = &vertices[skinVtxEntry->index];

                vtx->n.flag = 0;
                vtx->n.tc[0] = skinVtxEntry->s;
                vtx->n.tc[1] = skinVtxEntry->t;
                vtx->n.a = skinVtxEntry->alpha;
                skinVtxEntry++;
            }
        }
    }
}
