#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ s16 normalX;
    /* 0x0A */ s16 normalY;
    /* 0x0C */ s16 normalZ;
} CollisionPoly;

extern s16 Math_Atan2S_XY(f32, f32);

void Actor_GetSlopeDirection(CollisionPoly *poly, Vec3f *slopeNormal, s16 *downwardSlopeYaw) {
    slopeNormal->x = poly->normalX * (1.0f / 32767);
    slopeNormal->y = poly->normalY * (1.0f / 32767);
    slopeNormal->z = poly->normalZ * (1.0f / 32767);
    *downwardSlopeYaw = Math_Atan2S_XY(slopeNormal->z, slopeNormal->x);
}
