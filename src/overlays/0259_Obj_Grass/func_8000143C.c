// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_grass.h"

void ObjGrass_DrawOpa(Actor* thisx, PlayState* play2) {
    ObjGrass* this = (ObjGrass*)thisx;
    PlayState* play = play2;
    Lights* lights;
    ObjGrassGroup* grassGroup;
    s32 i;
    s32 j;
    Vec3s rot = { 0, 0, 0 };
    ObjGrassElement* grassElem;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);
    gSPDisplayList(POLY_OPA_DISP++, gObjGrass_D_809AA9F0);

    for (i = 0; i < this->activeGrassGroups; i++) {
        grassGroup = &this->grassGroups[i];

        if (grassGroup->flags & OBJ_GRASS_GROUP_DRAW) {
            lights = LightContext_NewLights(&play->lightCtx, play->state.gfxCtx);
            Lights_BindAll(lights, play->lightCtx.listHead, &grassGroup->homePos, play);
            Lights_Draw(lights, play->state.gfxCtx);

            for (j = 0; j < grassGroup->count; j++) {
                grassElem = &grassGroup->elements[j];

                if ((grassElem->flags & OBJ_GRASS_ELEM_DRAW) && (grassElem->alpha == 255)) {
                    rot.y = grassElem->rotY;
                    Matrix_SetTranslateRotateYXZ(grassElem->pos.x, grassElem->pos.y, grassElem->pos.z, &rot);
                    Matrix_Scale(this->actor.scale.x, this->actor.scale.y, this->actor.scale.z, MTXMODE_APPLY);
                    if (grassElem->flags & OBJ_GRASS_ELEM_ANIM) {
                        ObjGrass_OverrideMatrixCurrent(&this->distortionMtx[j]);
                    }

                    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
                    gSPDisplayList(POLY_OPA_DISP++, gObjGrass_D_809AAAE0);
                }
            }
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
