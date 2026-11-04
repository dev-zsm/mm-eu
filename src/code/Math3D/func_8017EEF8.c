// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_TriVsSphIntersect(Sphere16* sphere, TriNorm* tri, Vec3f* intersectPoint) {
    static Linef sTriTestLine;
    static Vec3f sSphereCenter;
    static Vec3f sSphPlanePos;
    f32 radius;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 planeDist;

    sSphereCenter.x = sphere->center.x;
    sSphereCenter.y = sphere->center.y;
    sSphereCenter.z = sphere->center.z;
    radius = sphere->radius;

    if (!Math3D_SphCubeVsTriCube(&tri->vtx[0], &tri->vtx[1], &tri->vtx[2], &sSphereCenter, radius)) {
        return false;
    }

    planeDist = Math3D_UDistPlaneToPos(tri->plane.normal.x, tri->plane.normal.y, tri->plane.normal.z,
                                       tri->plane.originDist, &sSphereCenter);
    if (radius < planeDist) {
        
        
        return false;
    }

    
    sTriTestLine.a = tri->vtx[0];
    sTriTestLine.b = tri->vtx[1];
    if (Math3D_LineVsSph(sphere, &sTriTestLine)) {
        Math3D_GetSphVsTriIntersectPoint(sphere, tri, intersectPoint);
        return true;
    }

    sTriTestLine.a = tri->vtx[1];
    sTriTestLine.b = tri->vtx[2];
    if (Math3D_LineVsSph(sphere, &sTriTestLine)) {
        Math3D_GetSphVsTriIntersectPoint(sphere, tri, intersectPoint);
        return true;
    }

    sTriTestLine.a = tri->vtx[2];
    sTriTestLine.b = tri->vtx[0];
    if (Math3D_LineVsSph(sphere, &sTriTestLine)) {
        Math3D_GetSphVsTriIntersectPoint(sphere, tri, intersectPoint);
        return true;
    }

    nx = tri->plane.normal.x * planeDist;
    ny = tri->plane.normal.y * planeDist;
    nz = tri->plane.normal.z * planeDist;

    if (Math3D_PlaneF(tri->plane.normal.x, tri->plane.normal.y, tri->plane.normal.z, tri->plane.originDist,
                      &sSphereCenter) > 0.0f) {
        sSphPlanePos.x = sSphereCenter.x - nx;
        sSphPlanePos.y = sSphereCenter.y - ny;
        sSphPlanePos.z = sSphereCenter.z - nz;
    } else {
        sSphPlanePos.x = sSphereCenter.x + nx;
        sSphPlanePos.y = sSphereCenter.y + ny;
        sSphPlanePos.z = sSphereCenter.z + nz;
    }

    if (fabsf(tri->plane.normal.y) > 0.5f) {
        if (Math3D_TriChkPointParaYDeterminate(&tri->vtx[0], &tri->vtx[1], &tri->vtx[2], sSphPlanePos.z, sSphPlanePos.x,
                                               0.0f, tri->plane.normal.y)) {
            Math3D_GetSphVsTriIntersectPoint(sphere, tri, intersectPoint);
            return true;
        }
    } else if (fabsf(tri->plane.normal.x) > 0.5f) {
        if (Math3D_TriChkPointParaXDeterminate(&tri->vtx[0], &tri->vtx[1], &tri->vtx[2], sSphPlanePos.y, sSphPlanePos.z,
                                               0.0f, tri->plane.normal.x)) {
            Math3D_GetSphVsTriIntersectPoint(sphere, tri, intersectPoint);
            return true;
        }
    } else if (Math3D_TriChkPointParaZDeterminate(&tri->vtx[0], &tri->vtx[1], &tri->vtx[2], sSphPlanePos.x,
                                                  sSphPlanePos.y, 0.0f, tri->plane.normal.z)) {
        Math3D_GetSphVsTriIntersectPoint(sphere, tri, intersectPoint);
        return true;
    }
    return false;
}
