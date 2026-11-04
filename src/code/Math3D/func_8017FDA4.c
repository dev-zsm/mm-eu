// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_CylTriVsIntersect(Cylinder16* cyl, TriNorm* tri, Vec3f* intersect) {
    static Sphere16 sTopSphere;
    static Sphere16 sBottomSphere;
    static Vec3f sCylIntersectA;
    static Vec3f sCylIntersectB;
    f32 yIntersect;
    f32 cylTop;
    f32 cylBottom;
    f32 minDistSq;
    f32 radiusTodistFromCylYIntersectTov0v1;
    f32 distFromPointAToIntersectASq;
    Vec3f cylIntersectCenter;

    cylBottom = (f32)cyl->pos.y + cyl->yShift;
    cylTop = cyl->height + cylBottom;

    if (((tri->vtx[0].y < cylBottom) && (tri->vtx[1].y < cylBottom) && (tri->vtx[2].y < cylBottom)) ||
        ((cylTop < tri->vtx[0].y) && (cylTop < tri->vtx[1].y) && (cylTop < tri->vtx[2].y))) {
        
        return false;
    }

    minDistSq = 1.e38f;
    if (Math3D_CylVsLineSeg(cyl, &tri->vtx[0], &tri->vtx[1], &sCylIntersectA, &sCylIntersectB)) {
        distFromPointAToIntersectASq = Math3D_Vec3fDistSq(&sCylIntersectA, &tri->vtx[0]);
        minDistSq = distFromPointAToIntersectASq;
        *intersect = sCylIntersectA;
    }

    if (Math3D_CylVsLineSeg(cyl, &tri->vtx[2], &tri->vtx[1], &sCylIntersectA, &sCylIntersectB)) {
        distFromPointAToIntersectASq = Math3D_Vec3fDistSq(&sCylIntersectA, &tri->vtx[2]);
        if (distFromPointAToIntersectASq < minDistSq) {
            *intersect = sCylIntersectA;
            minDistSq = distFromPointAToIntersectASq;
        }
    }

    if (Math3D_CylVsLineSeg(cyl, &tri->vtx[0], &tri->vtx[2], &sCylIntersectA, &sCylIntersectB)) {
        distFromPointAToIntersectASq = Math3D_Vec3fDistSq(&sCylIntersectA, &tri->vtx[0]);
        if (distFromPointAToIntersectASq < minDistSq) {
            *intersect = sCylIntersectA;
            minDistSq = distFromPointAToIntersectASq;
        }
    }

    if (minDistSq != 1.e38f) {
        return true;
    }

    if (Math3D_TriChkLineSegParaYIntersect(&tri->vtx[0], &tri->vtx[1], &tri->vtx[2], tri->plane.normal.x,
                                           tri->plane.normal.y, tri->plane.normal.z, tri->plane.originDist, cyl->pos.z,
                                           cyl->pos.x, &yIntersect, cylBottom, cylTop)) {
        Vec3f midpointv0v1;
        Vec3f diffMidpointIntersect;
        f32 distFromCylYIntersectTov0v1;
        s32 pad;

        cylIntersectCenter.x = cyl->pos.x;
        cylIntersectCenter.y = yIntersect;
        cylIntersectCenter.z = cyl->pos.z;

        midpointv0v1.x = (tri->vtx[0].x + tri->vtx[1].x) * 0.5f;
        midpointv0v1.y = (tri->vtx[0].y + tri->vtx[1].y) * 0.5f;
        midpointv0v1.z = (tri->vtx[0].z + tri->vtx[1].z) * 0.5f;

        Math_Vec3f_Diff(&midpointv0v1, &cylIntersectCenter, &diffMidpointIntersect);
        distFromCylYIntersectTov0v1 = sqrtf(SQ(diffMidpointIntersect.x) + SQ(diffMidpointIntersect.z));

        if (IS_ZERO(distFromCylYIntersectTov0v1)) {
            Math_Vec3f_Copy(intersect, &midpointv0v1);
            return true;
        }

        radiusTodistFromCylYIntersectTov0v1 = cyl->radius / distFromCylYIntersectTov0v1;
        Math3D_PointOnDirectedLine(&cylIntersectCenter, &diffMidpointIntersect, radiusTodistFromCylYIntersectTov0v1,
                                   intersect);
        return true;
    }

    sTopSphere.center.x = sBottomSphere.center.x = cyl->pos.x;
    sTopSphere.center.z = sBottomSphere.center.z = cyl->pos.z;
    sTopSphere.center.y = cylTop;
    sBottomSphere.center.y = cylBottom;
    sTopSphere.radius = sBottomSphere.radius = cyl->radius;

    if (Math3D_TriVsSphIntersect(&sTopSphere, tri, intersect) ||
        Math3D_TriVsSphIntersect(&sBottomSphere, tri, intersect)) {
        return true;
    }
    return false;
}
