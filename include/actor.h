#ifndef ACTOR_H
#define ACTOR_H

#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;   /* 0xC */
typedef struct { s16 x, y, z; } Vec3s;   /* 0x6 */

typedef struct PosRot {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3s rot;
} PosRot;   /* 0x14 */

typedef struct DamageTable DamageTable;
typedef struct CollisionPoly CollisionPoly;
typedef struct Lights Lights;
typedef struct ActorOverlay ActorOverlay;
typedef struct GraphicsContext GraphicsContext;
typedef struct PlayState PlayState;
typedef struct Actor Actor;

typedef void (*ActorFunc)(Actor *thisx, PlayState *play);
typedef void (*ActorShadowFunc)(Actor *actor, Lights *mapper, PlayState *play);

typedef struct CollisionCheckInfo {
    /* 0x00 */ DamageTable *damageTable;
    /* 0x04 */ Vec3f displacement;
    /* 0x10 */ s16 cylRadius;
    /* 0x12 */ s16 cylHeight;
    /* 0x14 */ s16 cylYShift;
    /* 0x16 */ u8 mass;
    /* 0x17 */ u8 health;
    /* 0x18 */ u8 damage;
    /* 0x19 */ u8 damageEffect;
    /* 0x1A */ u8 atHitEffect;
    /* 0x1B */ u8 acHitEffect;
} CollisionCheckInfo;   /* 0x1C */

typedef struct ActorShape {
    /* 0x00 */ Vec3s rot;
    /* 0x06 */ s16 face;
    /* 0x08 */ f32 yOffset;
    /* 0x0C */ ActorShadowFunc shadowDraw;
    /* 0x10 */ f32 shadowScale;
    /* 0x14 */ u8 shadowAlpha;
    /* 0x15 */ u8 feetFloorFlags;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ Vec3f feetPos[2];
} ActorShape;   /* 0x30 */

/* Every actor instance starts with this block and the fields of one actor type follow it. The size is checked against the
 * ROM: 0x144 is the smallest instance size found in its actor profiles (tools/signatures/sig_actors.py). The fields are taken
 * from the reference decompilation of the US release and are not checked one by one against this ROM. */
struct Actor {
    /* 0x000 */ s16 id;
    /* 0x002 */ u8 category;
    /* 0x003 */ s8 room;
    /* 0x004 */ u32 flags;
    /* 0x008 */ PosRot home;
    /* 0x01C */ s16 params;
    /* 0x01E */ s8 objectSlot;
    /* 0x01F */ s8 attentionRangeType;
    /* 0x020 */ s16 halfDaysBits;
    /* 0x024 */ PosRot world;
    /* 0x038 */ s8 csId;
    /* 0x039 */ u8 audioFlags;
    /* 0x03C */ PosRot focus;
    /* 0x050 */ u16 sfxId;
    /* 0x054 */ f32 lockOnArrowOffset;
    /* 0x058 */ Vec3f scale;
    /* 0x064 */ Vec3f velocity;
    /* 0x070 */ f32 speed;
    /* 0x074 */ f32 gravity;
    /* 0x078 */ f32 terminalVelocity;
    /* 0x07C */ CollisionPoly *wallPoly;
    /* 0x080 */ CollisionPoly *floorPoly;
    /* 0x084 */ u8 wallBgId;
    /* 0x085 */ u8 floorBgId;
    /* 0x086 */ s16 wallYaw;
    /* 0x088 */ f32 floorHeight;
    /* 0x08C */ f32 depthInWater;
    /* 0x090 */ u16 bgCheckFlags;
    /* 0x092 */ s16 yawTowardsPlayer;
    /* 0x094 */ f32 xyzDistToPlayerSq;
    /* 0x098 */ f32 xzDistToPlayer;
    /* 0x09C */ f32 playerHeightRel;
    /* 0x0A0 */ CollisionCheckInfo colChkInfo;
    /* 0x0BC */ ActorShape shape;
    /* 0x0EC */ Vec3f projectedPos;
    /* 0x0F8 */ f32 projectedW;
    /* 0x0FC */ f32 cullingVolumeDistance;
    /* 0x100 */ f32 cullingVolumeScale;
    /* 0x104 */ f32 cullingVolumeDownward;
    /* 0x108 */ Vec3f prevPos;
    /* 0x114 */ u8 isLockedOn;
    /* 0x115 */ u8 targetPriority;
    /* 0x116 */ u16 textId;
    /* 0x118 */ u16 freezeTimer;
    /* 0x11A */ u16 colorFilterParams;
    /* 0x11C */ u8 colorFilterTimer;
    /* 0x11D */ u8 isDrawn;
    /* 0x11E */ u8 dropFlag;
    /* 0x11F */ u8 hintId;
    /* 0x120 */ Actor *parent;
    /* 0x124 */ Actor *child;
    /* 0x128 */ Actor *prev;
    /* 0x12C */ Actor *next;
    /* 0x130 */ ActorFunc init;
    /* 0x134 */ ActorFunc destroy;
    /* 0x138 */ ActorFunc update;
    /* 0x13C */ ActorFunc draw;
    /* 0x140 */ ActorOverlay *overlayEntry;
};   /* 0x144 */

/* the size is checked when the header is compiled: a wrong field makes the array size negative */
typedef char ActorSizeIs0x144[sizeof(Actor) == 0x144 ? 1 : -1];
typedef char ActorFuncsAt0x130[(unsigned)&((Actor *)0)->init == 0x130 ? 1 : -1];

/* Passed to every actor handler. Only the first field is known (the graphics calls of the actors read it first); the size and the
 * rest of the layout are not, so neither sizeof nor pointer arithmetic on it means anything yet. */
struct PlayState {
    /* 0x00 */ GraphicsContext *gfxCtx;
};

#endif
