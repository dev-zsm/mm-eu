// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skin.h"

void Skin_ApplyLimbModifications(GraphicsContext* gfxCtx, Skin* skin, s32 limbIndex, s32 arg3) {
    s32 modifCount;
    SkinLimb** skeleton;
    s32 pad;
    SkinAnimatedLimbData* data;
    s32 pad2[5];
    SkinLimbModif* modif;
    SkinLimbVtx* vtxEntry;
    s32 pad3;
    s32 transformCount;
    f32 scale;
    SkinVertex* skinVertices;
    Vec3f sp88;
    Vtx* vtxBuf;
    SkinTransformation* limbTransformations;
    Vec3f spDC;
    Vec3f spD0;
    SkinTransformation* transformationEntry;
    SkinLimb* limb;
    SkinLimbModif* modifications;

    OPEN_DISPS(gfxCtx);

    skeleton = (SkinLimb**)Lib_SegmentedToVirtual(skin->skeletonHeader->segment);
    limb = (SkinLimb*)Lib_SegmentedToVirtual(skeleton[limbIndex]);
    data = Lib_SegmentedToVirtual(limb->segment);
    modifications = (SkinLimbModif*)Lib_SegmentedToVirtual(data->limbModifications);

    vtxEntry = &skin->vtxTable[limbIndex];

    vtxBuf = vtxEntry->buf[vtxEntry->index];
    modifCount = data->limbModifCount;

    for (modif = modifications; modif < &modifications[modifCount]; modif++) {
        Vec3f spAC;
        Vec3f spA0;

        skinVertices = (SkinVertex*)Lib_SegmentedToVirtual(modif->skinVertices);
        limbTransformations = (SkinTransformation*)Lib_SegmentedToVirtual(modif->limbTransformations);
        transformCount = modif->transformCount;

        if (transformCount == 1) {
            spAC.x = limbTransformations[0].x;
            spAC.y = limbTransformations[0].y;
            spAC.z = limbTransformations[0].z;

            SkinMatrix_Vec3fMtxFMultXYZ(&gSkinLimbMatrices[limbTransformations[0].limbIndex], &spAC, &spDC);
        } else if (arg3) {
            transformationEntry = &limbTransformations[modif->unk_04];

            spA0.x = transformationEntry->x;
            spA0.y = transformationEntry->y;
            spA0.z = transformationEntry->z;
            SkinMatrix_Vec3fMtxFMultXYZ(&gSkinLimbMatrices[transformationEntry->limbIndex], &spA0, &spDC);
        } else {
            spDC.x = 0.0f;
            spDC.y = 0.0f;
            spDC.z = 0.0f;

            for (transformationEntry = limbTransformations; transformationEntry < &limbTransformations[transformCount];
                 transformationEntry++) {
                scale = transformationEntry->scale * 0.01f;

                sp88.x = transformationEntry->x;
                sp88.y = transformationEntry->y;
                sp88.z = transformationEntry->z;

                SkinMatrix_Vec3fMtxFMultXYZ(&gSkinLimbMatrices[transformationEntry->limbIndex], &sp88, &spD0);

                spDC.x += spD0.x * scale;
                spDC.y += spD0.y * scale;
                spDC.z += spD0.z * scale;
            }
        }

        Skin_UpdateVertices(&gSkinLimbMatrices[limbTransformations[modif->unk_04].limbIndex], skinVertices, modif,
                            vtxBuf, &spDC);
    }

    gSPSegment(POLY_OPA_DISP++, 0x08, vtxEntry->buf[vtxEntry->index]);

    vtxEntry->index = (vtxEntry->index == 0);

    CLOSE_DISPS(gfxCtx);
}
