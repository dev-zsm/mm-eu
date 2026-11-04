// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_collect.h"

void DynaPolyActor_UpdateCarriedActorPos(CollisionContext* colCtx, s32 bgId, Actor* carriedActor) {
    MtxF prevTransform;
    MtxF prevTransformInv;
    MtxF curTransform;
    Vec3f pos;
    Vec3f tempPos;

    if (!DynaPoly_IsBgIdBgActor(bgId)) {
        return;
    }

    SkinMatrix_SetScaleRotateYRPTranslate(
        &prevTransform, colCtx->dyna.bgActors[bgId].prevTransform.scale.x,
        colCtx->dyna.bgActors[bgId].prevTransform.scale.y, colCtx->dyna.bgActors[bgId].prevTransform.scale.z,
        colCtx->dyna.bgActors[bgId].prevTransform.rot.x, colCtx->dyna.bgActors[bgId].prevTransform.rot.y,
        colCtx->dyna.bgActors[bgId].prevTransform.rot.z, colCtx->dyna.bgActors[bgId].prevTransform.pos.x,
        colCtx->dyna.bgActors[bgId].prevTransform.pos.y, colCtx->dyna.bgActors[bgId].prevTransform.pos.z);

    if (SkinMatrix_Invert(&prevTransform, &prevTransformInv) == 2) {
        return;
    }

    SkinMatrix_SetScaleRotateYRPTranslate(
        &curTransform, colCtx->dyna.bgActors[bgId].curTransform.scale.x,
        colCtx->dyna.bgActors[bgId].curTransform.scale.y, colCtx->dyna.bgActors[bgId].curTransform.scale.z,
        colCtx->dyna.bgActors[bgId].curTransform.rot.x, colCtx->dyna.bgActors[bgId].curTransform.rot.y,
        colCtx->dyna.bgActors[bgId].curTransform.rot.z, colCtx->dyna.bgActors[bgId].curTransform.pos.x,
        colCtx->dyna.bgActors[bgId].curTransform.pos.y, colCtx->dyna.bgActors[bgId].curTransform.pos.z);

    
    
    
    SkinMatrix_Vec3fMtxFMultXYZ(&prevTransformInv, &carriedActor->world.pos, &tempPos);
    SkinMatrix_Vec3fMtxFMultXYZ(&curTransform, &tempPos, &pos);

    carriedActor->world.pos = pos;
}
