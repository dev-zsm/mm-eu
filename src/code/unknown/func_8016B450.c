// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play.h"

void Play_Init(GameState* thisx) {
    PlayState* this = (PlayState*)thisx;
    GraphicsContext* gfxCtx = this->state.gfxCtx;
    s32 pad;
    uintptr_t zAlloc;
    s32 zAllocSize;
    Player* player;
    s32 i;
    s32 scene;
    u8 sceneLayer;
    s32 pad2;

    if ((gSaveContext.respawnFlag == -4) || (gSaveContext.respawnFlag == -0x63)) {
        if (CHECK_EVENTINF(EVENTINF_TRIGGER_DAYTELOP)) {
            CLEAR_EVENTINF(EVENTINF_TRIGGER_DAYTELOP);
            STOP_GAMESTATE(&this->state);
            SET_NEXT_GAMESTATE(&this->state, DayTelop_Init, sizeof(DayTelopState));
            return;
        }

        gSaveContext.unk_3CA7 = 1;
        if (gSaveContext.respawnFlag == -0x63) {
            gSaveContext.respawnFlag = 2;
        }
    } else {
        gSaveContext.unk_3CA7 = 0;
    }

    if (gSaveContext.save.entrance == -1) {
        gSaveContext.save.entrance = 0;
        STOP_GAMESTATE(&this->state);
        SET_NEXT_GAMESTATE(&this->state, TitleSetup_Init, sizeof(TitleSetupState));
        return;
    }

    if ((gSaveContext.nextCutsceneIndex == 0xFFEF) || (gSaveContext.nextCutsceneIndex == 0xFFF0)) {
        scene = ((void)0, gSaveContext.save.entrance) >> 9;

        if (CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_SNOWHEAD_TEMPLE)) {
            if (scene == ENTR_SCENE_MOUNTAIN_VILLAGE_WINTER) {
                scene = ENTR_SCENE_MOUNTAIN_VILLAGE_SPRING;
            } else if (scene == ENTR_SCENE_GORON_VILLAGE_WINTER) {
                scene = ENTR_SCENE_GORON_VILLAGE_SPRING;
            } else if (scene == ENTR_SCENE_PATH_TO_GORON_VILLAGE_WINTER) {
                scene = ENTR_SCENE_PATH_TO_GORON_VILLAGE_SPRING;
            } else if ((scene == ENTR_SCENE_SNOWHEAD) || (scene == ENTR_SCENE_PATH_TO_SNOWHEAD) ||
                       (scene == ENTR_SCENE_PATH_TO_MOUNTAIN_VILLAGE) || (scene == ENTR_SCENE_GORON_SHRINE) ||
                       (scene == ENTR_SCENE_GORON_RACETRACK)) {
                gSaveContext.nextCutsceneIndex = 0xFFF0;
            }
        }

        if (CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_WOODFALL_TEMPLE)) {
            if (scene == ENTR_SCENE_SOUTHERN_SWAMP_POISONED) {
                scene = ENTR_SCENE_SOUTHERN_SWAMP_CLEARED;
            } else if (scene == ENTR_SCENE_WOODFALL) {
                gSaveContext.nextCutsceneIndex = 0xFFF1;
            }
        }

        if (CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_STONE_TOWER_TEMPLE) && (scene == ENTR_SCENE_IKANA_CANYON)) {
            gSaveContext.nextCutsceneIndex = 0xFFF2;
        }

        if (CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_GREAT_BAY_TEMPLE) &&
            ((scene == ENTR_SCENE_GREAT_BAY_COAST) || (scene == ENTR_SCENE_ZORA_CAPE))) {
            gSaveContext.nextCutsceneIndex = 0xFFF0;
        }

        
        if (INV_CONTENT(ITEM_OCARINA_OF_TIME) != ITEM_OCARINA_OF_TIME) {
            if ((scene == ENTR_SCENE_TERMINA_FIELD) &&
                (((void)0, gSaveContext.save.entrance) != ENTRANCE(TERMINA_FIELD, 10))) {
                gSaveContext.nextCutsceneIndex = 0xFFF4;
            }
        }
        gSaveContext.save.entrance = Entrance_Create(scene, (((void)0, gSaveContext.save.entrance) >> 4) & 0x1F,
                                                     ((void)0, gSaveContext.save.entrance) & 0xF);
    }

    GameState_Realloc(&this->state, 0);
    KaleidoManager_Init(this);
    ShrinkWindow_Init();
    View_Init(&this->view, gfxCtx);
    Audio_SetExtraFilter(0);
    Quake_Init();
    Distortion_Init(this);

    for (i = 0; i < ARRAY_COUNT(this->cameraPtrs); i++) {
        this->cameraPtrs[i] = NULL;
    }

    Camera_Init(&this->mainCamera, &this->view, &this->colCtx, this);
    Camera_ChangeStatus(&this->mainCamera, CAM_STATUS_ACTIVE);

    for (i = 0; i < ARRAY_COUNT(this->subCameras); i++) {
        Camera_Init(&this->subCameras[i], &this->view, &this->colCtx, this);
        Camera_ChangeStatus(&this->subCameras[i], CAM_STATUS_INACTIVE);
    }

    this->cameraPtrs[CAM_ID_MAIN] = &this->mainCamera;
    this->cameraPtrs[CAM_ID_MAIN]->uid = CAM_ID_MAIN;
    this->activeCamId = CAM_ID_MAIN;

    Camera_OverwriteStateFlags(&this->mainCamera, CAM_STATE_0 | CAM_STATE_CHECK_WATER | CAM_STATE_2 | CAM_STATE_3 |
                                                      CAM_STATE_4 | CAM_STATE_DISABLE_MODE_CHANGE | CAM_STATE_6);
    Sram_Alloc(&this->state, &this->sramCtx);
    Regs_InitData(this);
    Message_Init(this);
    GameOver_Init(this);
    SoundSource_InitAll(this);
    EffFootmark_Init(this);
    Effect_Init(this);
    EffectSs_InitInfo(this, 100);
    CollisionCheck_InitContext(this, &this->colChkCtx);
    AnimTaskQueue_Reset(&this->animTaskQueue);
    Cutscene_InitContext(this, &this->csCtx);

    if (gSaveContext.nextCutsceneIndex != 0xFFEF) {
        gSaveContext.save.cutsceneIndex = gSaveContext.nextCutsceneIndex;
        gSaveContext.nextCutsceneIndex = 0xFFEF;
    }

    if (gSaveContext.save.cutsceneIndex == 0xFFFD) {
        gSaveContext.save.cutsceneIndex = 0;
    }

    if (gSaveContext.nextDayTime != NEXT_TIME_NONE) {
        gSaveContext.save.time = gSaveContext.nextDayTime;
        gSaveContext.skyboxTime = gSaveContext.nextDayTime;
    }

    if ((CURRENT_TIME >= CLOCK_TIME(18, 0)) || (CURRENT_TIME < CLOCK_TIME(6, 30))) {
        gSaveContext.save.isNight = true;
    } else {
        gSaveContext.save.isNight = false;
    }

    ref_func_800EDDB0(this);

    if (((gSaveContext.gameMode != GAMEMODE_NORMAL) && (gSaveContext.gameMode != GAMEMODE_TITLE_SCREEN)) ||
        (gSaveContext.save.cutsceneIndex >= 0xFFF0)) {
        gSaveContext.nayrusLoveTimer = 0;
        Magic_Reset(this);
        gSaveContext.sceneLayer = (gSaveContext.save.cutsceneIndex & 0xF) + 1;

        
        gSaveContext.save.cutsceneIndex = 0;
    } else {
        gSaveContext.sceneLayer = 0;
    }

    sceneLayer = gSaveContext.sceneLayer;

    Play_SpawnScene(
        this, Entrance_GetSceneIdAbsolute(((void)0, gSaveContext.save.entrance) + ((void)0, gSaveContext.sceneLayer)),
        Entrance_GetSpawnNum(((void)0, gSaveContext.save.entrance) + ((void)0, gSaveContext.sceneLayer)));
    KaleidoScopeCall_Init(this);
    Interface_Init(this);

    if (gSaveContext.nextDayTime != NEXT_TIME_NONE) {
        if (gSaveContext.nextDayTime == NEXT_TIME_DAY) {
            gSaveContext.save.day++;
            gSaveContext.save.eventDayCount++;
            gSaveContext.dogIsLost = true;
            gSaveContext.nextDayTime = NEXT_TIME_DAY_SET;
        } else {
            gSaveContext.nextDayTime = NEXT_TIME_NIGHT_SET;
        }
    }

    Play_InitMotionBlur();

    R_PAUSE_BG_PRERENDER_STATE = PAUSE_BG_PRERENDER_OFF;
    R_PICTO_PHOTO_STATE = PICTO_PHOTO_STATE_OFF;

    PreRender_Init(&this->pauseBgPreRender);
    PreRender_SetValuesSave(&this->pauseBgPreRender, gCfbWidth, gCfbHeight, NULL, NULL, NULL);
    PreRender_SetValues(&this->pauseBgPreRender, gCfbWidth, gCfbHeight, NULL, NULL);

    this->unk_18E64 = gWorkBuffer;
    this->pictoPhotoI8 = gHiBuffer.pictoPhotoI8;
    this->unk_18E68 = gHiBuffer.ref_D_80784600;
    this->unk_18E58 = gHiBuffer.ref_D_80784600;
    this->unk_18E60 = gHiBuffer.ref_D_80784600;
    gTransitionTileState = TRANS_TILE_OFF;
    this->transitionMode = TRANS_MODE_OFF;
    ref_D_801D0D54 = false;

    FrameAdvance_Init(&this->frameAdvCtx);
    Rand_Seed(osGetTime());
    Matrix_Init(&this->state);

    this->state.main = Play_Main;
    this->state.destroy = Play_Destroy;

    this->transitionTrigger = TRANS_TRIGGER_END;
    this->worldCoverAlpha = 0;
    this->bgCoverAlpha = 0;
    this->haltAllActors = false;
    this->soaringCsOrSoTCsPlaying = false;

    if (gSaveContext.gameMode != GAMEMODE_TITLE_SCREEN) {
        if (gSaveContext.nextTransitionType == TRANS_NEXT_TYPE_DEFAULT) {
            this->transitionType =
                (Entrance_GetTransitionFlags(((void)0, gSaveContext.save.entrance) + sceneLayer) >> 7) & 0x7F;
        } else {
            this->transitionType = gSaveContext.nextTransitionType;
            gSaveContext.nextTransitionType = TRANS_NEXT_TYPE_DEFAULT;
        }
    } else {
        this->transitionType = TRANS_TYPE_FADE_BLACK;
    }

    TransitionFade_Init(&this->unk_18E48);
    TransitionFade_SetType(&this->unk_18E48, 3);
    TransitionFade_SetColor(&this->unk_18E48, RGBA8(160, 160, 160, 255));
    TransitionFade_Start(&this->unk_18E48);
    VisMono_Init(&sPlayVisMono);

    gPlayVisMonoColor.a = 0;
    sPlayVisFbufInstance = &sPlayVisFbuf;
    VisFbuf_Init(sPlayVisFbufInstance);
    sPlayVisFbufInstance->lodProportion = 0.0f;
    sPlayVisFbufInstance->mode = VIS_FBUF_MODE_GENERAL;
    sPlayVisFbufInstance->primColor.r = 0;
    sPlayVisFbufInstance->primColor.g = 0;
    sPlayVisFbufInstance->primColor.b = 0;
    sPlayVisFbufInstance->primColor.a = 0;
    sPlayVisFbufInstance->envColor.r = 0;
    sPlayVisFbufInstance->envColor.g = 0;
    sPlayVisFbufInstance->envColor.b = 0;
    sPlayVisFbufInstance->envColor.a = 0;
    CutsceneFlags_UnsetAll(this);
    THA_GetRemaining(&this->state.tha);
    zAllocSize = THA_GetRemaining(&this->state.tha);
    zAlloc = (uintptr_t)THA_AllocTailAlign16(&this->state.tha, zAllocSize);

    
    ZeldaArena_Init((void*)((zAlloc + 8) & ~0xF), (zAllocSize - ((zAlloc + 8) & ~0xF)) + zAlloc);

    Actor_InitContext(this, &this->actorCtx, this->linkActorEntry);

    
    while (!Room_ProcessRoomRequest(this, &this->roomCtx)) {}

    if ((CURRENT_DAY != 0) &&
        ((this->roomCtx.curRoom.type == ROOM_TYPE_DUNGEON) || (this->roomCtx.curRoom.type == ROOM_TYPE_BOSS))) {
        Actor_Spawn(&this->actorCtx, this, ACTOR_EN_TEST4, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0);
    }

    player = GET_PLAYER(this);

    Camera_InitFocalActorSettings(&this->mainCamera, &player->actor);
    gDbgCamEnabled = false;

    if (PLAYER_GET_BG_CAM_INDEX(&player->actor) != 0xFF) {
        Camera_ChangeActorCsCamIndex(&this->mainCamera, PLAYER_GET_BG_CAM_INDEX(&player->actor));
    }

    CutsceneManager_StoreCamera(&this->mainCamera);
    Interface_SetSceneRestrictions(this);
    Environment_PlaySceneSequence(this);
    gSaveContext.seqId = this->sceneSequences.seqId;
    gSaveContext.ambienceId = this->sceneSequences.ambienceId;
    AnimTaskQueue_Update(this, &this->animTaskQueue);
    Cutscene_HandleEntranceTriggers(this);
    gSaveContext.respawnFlag = 0;
    sBombersNotebookOpen = false;
    BombersNotebook_Init(&sBombersNotebook);
}
