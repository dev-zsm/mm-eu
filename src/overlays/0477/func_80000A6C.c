// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spidertent.h"

void ObjSpidertent_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjSpidertent* this = (ObjSpidertent*)thisx;
    s32 temp_s1 = OBJSPIDERTENT_GET_1(&this->dyna.actor);
    ObjSpidertentStruct* ptr = &ref_D_80B31350[temp_s1];
    ColliderTrisElementInit* element;
    Vec3f sp70[3];
    Vec3f sp64;
    s32 i;
    s32 j;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, 0);
    Collider_InitTris(play, &this->collider);

    if (Flags_GetSwitch(play, OBJSPIDERTENT_GET_SWITCH_FLAG(&this->dyna.actor))) {
        Actor_Kill(&this->dyna.actor);
        return;
    }

    DynaPolyActor_LoadMesh(play, &this->dyna, ptr->unk_04);
    Collider_SetTris(play, &this->collider, &this->dyna.actor, ref_D_80B31350[temp_s1].unk_08, this->colliderElements);
    Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                                 this->dyna.actor.world.pos.z, &this->dyna.actor.shape.rot);

    sp64.x = ptr->unk_10 * 1.2f;
    sp64.y = ptr->unk_10 * 1.2f;
    sp64.z = ptr->unk_10 * 1.2f;

    Matrix_MultVec3f(&sp64, &this->dyna.actor.focus.pos);
    Matrix_Translate(ptr->unk_10, ptr->unk_14 + 5.0f, ptr->unk_18, MTXMODE_APPLY);
    Matrix_Scale(ptr->unk_0C, ptr->unk_0C, ptr->unk_0C, MTXMODE_APPLY);
    Matrix_Translate(-ptr->unk_10, -ptr->unk_14, -ptr->unk_18, MTXMODE_APPLY);

    for (i = 0; i < 6; i++) {
        element = &ptr->unk_08->elements[i];

        for (j = 0; j < ARRAY_COUNT(sp70); j++) {
            Matrix_MultVec3f(&element->dim.vtx[j], &sp70[j]);
        }

        Collider_SetTrisVertices(&this->collider, i, &sp70[0], &sp70[1], &sp70[2]);
    }

    ref_func_80B307E0(this);
}
