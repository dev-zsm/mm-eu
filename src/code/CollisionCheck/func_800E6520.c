// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_SetOCvsOC(struct PlayState* play, Collider* leftCol, ColliderElement* leftElem, Vec3f* leftPos,
                              Collider* rightCol, ColliderElement* rightElem, Vec3f* rightPos, f32 overlapSize) {
    f32 pad;
    f32 leftDispRatio;
    f32 rightDispRatio;
    f32 xzDist;
    f32 leftMass;
    f32 rightMass;
    f32 totalMass;
    f32 inverseTotalMass;
    f32 xDelta;
    f32 zDelta;
    Actor* leftActor = leftCol->actor;
    Actor* rightActor = rightCol->actor;
    s32 leftMassType;
    s32 rightMassType;

    leftCol->ocFlags1 |= OC1_HIT;
    leftCol->oc = rightActor;
    leftElem->ocElemFlags |= OCELEM_HIT;
    if (rightCol->ocFlags2 & OC2_TYPE_PLAYER) {
        leftCol->ocFlags2 |= OC2_HIT_PLAYER;
    }

    rightCol->ocFlags1 |= OC1_HIT;
    rightCol->oc = leftActor;
    rightElem->ocElemFlags |= OCELEM_HIT;
    if (leftCol->ocFlags2 & OC2_TYPE_PLAYER) {
        rightCol->ocFlags2 |= OC2_HIT_PLAYER;
    }

    if ((leftActor == NULL) || (rightActor == NULL) || (leftCol->ocFlags1 & OC1_NO_PUSH) ||
        (rightCol->ocFlags1 & OC1_NO_PUSH)) {
        return;
    }

    rightMassType = CollisionCheck_GetMassType(leftActor->colChkInfo.mass);
    leftMassType = CollisionCheck_GetMassType(rightActor->colChkInfo.mass);
    leftMass = leftActor->colChkInfo.mass;
    rightMass = rightActor->colChkInfo.mass;
    totalMass = leftMass + rightMass;

    if (IS_ZERO(totalMass)) {
        leftMass = rightMass = 1.0f;
        totalMass = 2.0f;
    }
    xDelta = rightPos->x - leftPos->x;
    zDelta = rightPos->z - leftPos->z;

    xzDist = sqrtf(SQ(xDelta) + SQ(zDelta));

    if (rightMassType == MASSTYPE_IMMOVABLE) {
        if (leftMassType == MASSTYPE_IMMOVABLE) {
            return;
        } else {
            leftDispRatio = 0;
            rightDispRatio = 1;
        }
    } else if (rightMassType == MASSTYPE_HEAVY) {
        if (leftMassType == MASSTYPE_IMMOVABLE) {
            leftDispRatio = 1;
            rightDispRatio = 0;
        } else if (leftMassType == MASSTYPE_HEAVY) {
            leftDispRatio = 0.5f;
            rightDispRatio = 0.5f;
        } else {
            leftDispRatio = 0;
            rightDispRatio = 1;
        }
    } else {
        if (leftMassType == MASSTYPE_NORMAL) {
            inverseTotalMass = 1.0f / totalMass;
            leftDispRatio = rightMass * inverseTotalMass;
            rightDispRatio = leftMass * inverseTotalMass;
        } else {
            leftDispRatio = 1;
            rightDispRatio = 0;
        }
    }

    if (!IS_ZERO(xzDist)) {
        xDelta *= overlapSize / xzDist;
        zDelta *= overlapSize / xzDist;
        leftActor->colChkInfo.displacement.x += -xDelta * leftDispRatio;
        leftActor->colChkInfo.displacement.z += -zDelta * leftDispRatio;
        rightActor->colChkInfo.displacement.x += xDelta * rightDispRatio;
        rightActor->colChkInfo.displacement.z += zDelta * rightDispRatio;
    } else if (overlapSize != 0.0f) {
        leftActor->colChkInfo.displacement.x += -overlapSize * leftDispRatio;
        rightActor->colChkInfo.displacement.x += overlapSize * rightDispRatio;
    } else {
        leftActor->colChkInfo.displacement.x += -leftDispRatio;
        rightActor->colChkInfo.displacement.x += rightDispRatio;
    }
}
