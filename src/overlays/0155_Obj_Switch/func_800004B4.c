// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_switch.h"

void ObjSwitch_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    s32 type;
    u32 isSwitchFlagSet;
    ObjSwitch* this = (ObjSwitch*)thisx;
    s32 pad2;

    isSwitchFlagSet = Flags_GetSwitch(play, OBJ_SWITCH_GET_SWITCH_FLAG(&this->dyna.actor));
    type = OBJ_SWITCH_GET_TYPE(&this->dyna.actor);
    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    Actor_SetScale(&this->dyna.actor, sScale[type]);

    if (type == OBJSWITCH_TYPE_FLOOR || type == OBJSWITCH_TYPE_FLOOR_RUSTY || type == OBJSWITCH_TYPE_FLOOR_LARGE) {
        if (type == OBJSWITCH_TYPE_FLOOR_LARGE) {
            this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y + 1.9f;
        } else {
            this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y + 1.0f;
        }
        DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
        DynaPolyActor_LoadMesh(play, &this->dyna, &gFloorSwitchCol);
    }
    if (type == OBJSWITCH_TYPE_FLOOR) {
        if (play->sceneId == SCENE_SECOM) {
            this->floorSwitchUpScale = 33.0f / 200.0f / 3.0f;
            this->floorSwitchDownScale = 33.0f / 2000.0f / 3.0f;
        } else {
            this->floorSwitchUpScale = 33.0f / 200.0f;
            this->floorSwitchDownScale = 33.0f / 2000.0f;
        }
    }
    if (type == OBJSWITCH_TYPE_FLOOR || type == OBJSWITCH_TYPE_FLOOR_LARGE) {
        if (play->sceneId == SCENE_SECOM) {
            Color_RGB8* color = &sSakonHideoutColor[OBJ_SWITCH_GET_COLOR_ID(&this->dyna.actor)];

            this->color.r = color->r;
            this->color.g = color->g;
            this->color.b = color->b;
            this->dyna.actor.shape.rot.z = 0;
            this->dyna.actor.world.rot.z = 0;
        } else {
            this->color.r = 255;
            this->color.g = 255;
            this->color.b = 255;
        }
    }
    Actor_SetFocus(&this->dyna.actor, sHeights[type]);

    if (type == OBJSWITCH_TYPE_FLOOR_RUSTY) {
        ObjSwitch_InitTrisCollider(&this->dyna.actor, play, &sRustyFloorTrisInit);
    } else if (type == OBJSWITCH_TYPE_EYE) {
        ObjSwitch_InitTrisCollider(&this->dyna.actor, play, &sEyeSwitchTrisInit);
    } else if (type == OBJSWITCH_TYPE_CRYSTAL || type == OBJSWITCH_TYPE_CRYSTAL_TARGETABLE) {
        ObjSwitch_InitJntSphCollider(&this->dyna.actor, play, &sJntSphInit);
    }
    if (type == OBJSWITCH_TYPE_CRYSTAL_TARGETABLE) {
        this->dyna.actor.attentionRangeType = ATTENTION_RANGE_4;
        this->dyna.actor.flags |= 1;
    }
    this->dyna.actor.colChkInfo.mass = MASS_IMMOVABLE;
    if (OBJ_SWITCH_IS_FROZEN(&this->dyna.actor)) {
        if (ObjSwitch_SpawnIce(this, play) == NULL) {
            OBJ_SWITCH_UNSET_FROZEN(&this->dyna.actor);
        }
        this->sfxTimer = 0;
    } else {
        this->sfxTimer = 10;
    }
    if (OBJ_SWITCH_IS_INVISIBLE(&this->dyna.actor)) {
        this->dyna.actor.flags |= 0x80;
    }
    if (type == OBJSWITCH_TYPE_EYE) {
        if (!sTexturesDesegmented) {
            s32 i;
            s32 j;

            sTexturesDesegmented = true;

            for (i = 0; i < ARRAY_COUNT(sEyeSwitchTextures); i++) {
                for (j = 0; j < ARRAY_COUNT(*sEyeSwitchTextures); j++) {
                    sEyeSwitchTextures[i][j] = Lib_SegmentedToVirtual(sEyeSwitchTextures[i][j]);
                }
            }
        }
    }
    if (type == OBJSWITCH_TYPE_CRYSTAL) {
        sCrystalSwitchAnimatedMat = Lib_SegmentedToVirtual(gCrystalSwitchTexAnim);
    }
    if (OBJ_SWITCH_IS_FROZEN(&this->dyna.actor)) {
        ObjSwitch_EyeSwitchFrozenInit(this);
    } else if (type == OBJSWITCH_TYPE_FLOOR || type == OBJSWITCH_TYPE_FLOOR_RUSTY) {
        if (OBJ_SWITCH_GET_SUBTYPE(&this->dyna.actor) == OBJSWITCH_SUBTYPE_RESET_INVERTED) {
            if (isSwitchFlagSet) {
                ObjSwitch_FloorSwitchUpInit(this);
            } else {
                ObjSwitch_FloorSwitchDownInit(this);
            }
        } else {
            if (isSwitchFlagSet) {
                ObjSwitch_FloorSwitchDownInit(this);
            } else {
                ObjSwitch_FloorSwitchUpInit(this);
            }
        }
    } else if (type == OBJSWITCH_TYPE_EYE) {
        if (isSwitchFlagSet) {
            ObjSwitch_EyeSwitchClosedInit(this);
        } else {
            ObjSwitch_EyeSwitchOpenInit(this);
        }
    } else if (type == OBJSWITCH_TYPE_CRYSTAL || type == OBJSWITCH_TYPE_CRYSTAL_TARGETABLE) {
        if (isSwitchFlagSet) {
            ObjSwitch_CrystalSwitchOnInit(this);
        } else {
            ObjSwitch_CrystalSwitchOffInit(this);
        }
    } else if (type == OBJSWITCH_TYPE_FLOOR_LARGE) {
        if (OBJ_SWITCH_GET_SUBTYPE(&this->dyna.actor) == OBJSWITCH_SUBTYPE_RESET_INVERTED) {
            if (isSwitchFlagSet) {
                ObjSwitch_LargeFloorSwitchUpInit(this);
            } else {
                ObjSwitch_LargeFloorSwitchDownInit(this);
            }
        } else {
            if (isSwitchFlagSet) {
                ObjSwitch_LargeFloorSwitchDownInit(this);
            } else {
                ObjSwitch_LargeFloorSwitchUpInit(this);
            }
        }
    }
}
