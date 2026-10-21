// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_8008B7A0(void);
float sqrtf(float);
#pragma intrinsic (sqrtf)

void func_8008D970(f32 (*mf)[4], u8 *lk, s32 *tex, f32 ex, f32 ey, f32 ez, f32 ax, f32 ay, f32 az, f32 ux, f32 uy, f32 uz, f32 lx, f32 ly, f32 lz, f32 mx, f32 my, f32 mz, s32 i18, s32 i19) {
    f32 dx, dy, dz, len, inv;
    f32 zx, zy, zz;
    f32 cx, cy, cz, lenc, invc;
    f32 xx, xy, xz;
    f32 yx, yy, yz, leny, invy;
    f32 nyx, nyy, nyz;
    f32 lnx, lny, lnz, lenl, invl;
    f32 hx, hy, hz, lenh, invh;
    f32 hnx, hny, hnz;
    f32 vx, vy, vz, lenv, invv;
    f32 h2x, h2y, h2z, lenh2, invh2;
    f32 t;

    func_8008B7A0();

    dx = ax - ex;
    dy = ay - ey;
    dz = az - ez;
    len = sqrtf(dx * dx + dy * dy + dz * dz);
    inv = -1.0 / len;
    zx = dx * inv;
    zy = dy * inv;
    zz = dz * inv;

    cx = uy * zz - uz * zy;
    cy = uz * zx - ux * zz;
    cz = ux * zy - uy * zx;
    lenc = sqrtf(cx * cx + cy * cy + cz * cz);
    invc = 1.0 / lenc;
    xx = cx * invc;
    xy = cy * invc;
    xz = cz * invc;

    yx = zy * xz - zz * xy;
    yy = zz * xx - zx * xz;
    yz = zx * xy - zy * xx;
    leny = sqrtf(yx * yx + yy * yy + yz * yz);
    invy = 1.0 / leny;
    nyx = yx * invy;
    nyy = yy * invy;
    nyz = yz * invy;

    lenl = sqrtf(lx * lx + ly * ly + lz * lz);
    invl = 1.0 / lenl;
    lnx = lx * invl;
    lny = ly * invl;
    lnz = lz * invl;

    hx = lnx + zx;
    hy = lny + zy;
    hz = lnz + zz;
    lenh = sqrtf(hx * hx + hy * hy + hz * hz);
    if (0.1 < lenh) {
        invh = 1.0 / lenh;
        hnx = hx * invh;
        hny = hy * invh;
        hnz = hz * invh;
        tex[0] = (s32)((f32)(i18 << 2) + ((hnx * xx + hny * xy + hnz * xz) * (f32)i18) * 2.0f);
        tex[1] = (s32)((f32)(i19 << 2) + ((hnx * nyx + hny * nyy + hnz * nyz) * (f32)i19) * 2.0f);
    } else {
        tex[0] = i18 << 1;
        tex[1] = i19 << 1;
    }

    lenv = sqrtf(mx * mx + my * my + mz * mz);
    invv = 1.0 / lenv;
    vx = mx * invv;
    vy = my * invv;
    vz = mz * invv;

    h2x = vx + zx;
    h2y = vy + zy;
    h2z = vz + zz;
    lenh2 = sqrtf(h2x * h2x + h2y * h2y + h2z * h2z);
    if (0.1 < lenh2) {
        invh2 = 1.0 / lenh2;
        hnx = h2x * invh2;
        hny = h2y * invh2;
        hnz = h2z * invh2;
        tex[2] = (s32)((f32)(i18 << 2) + ((hnx * xx + hny * xy + hnz * xz) * (f32)i18) * 2.0f);
        tex[3] = (s32)((f32)(i19 << 2) + ((hnx * nyx + hny * nyy + hnz * nyz) * (f32)i19) * 2.0f);
    } else {
        tex[2] = i18 << 1;
        tex[3] = i19 << 1;
    }

    t = xx * 128.0f;
    lk[8] = (s32)(t < 127.0f ? t : 127.0f);
    t = xy * 128.0f;
    lk[9] = (s32)(t < 127.0f ? t : 127.0f);
    t = xz * 128.0f;
    lk[10] = (s32)(t < 127.0f ? t : 127.0f);
    t = nyx * 128.0f;
    lk[0x18] = (s32)(t < 127.0f ? t : 127.0f);
    t = nyy * 128.0f;
    lk[0x19] = (s32)(t < 127.0f ? t : 127.0f);
    t = nyz * 128.0f;
    lk[0x1A] = (s32)(t < 127.0f ? t : 127.0f);

    lk[0] = 0;
    lk[1] = 0;
    lk[2] = 0;
    lk[3] = 0;
    lk[4] = 0;
    lk[5] = 0;
    lk[6] = 0;
    lk[7] = 0;
    lk[0x10] = 0;
    lk[0x11] = 0x80;
    lk[0x12] = 0;
    lk[0x13] = 0;
    lk[0x14] = 0;
    lk[0x15] = 0x80;
    lk[0x16] = 0;
    lk[0x17] = 0;

    mf[0][0] = xx;
    mf[1][0] = xy;
    mf[2][0] = xz;
    mf[3][0] = -(ex * xx + ey * xy + ez * xz);
    mf[0][1] = nyx;
    mf[1][1] = nyy;
    mf[2][1] = nyz;
    mf[3][1] = -(ex * nyx + ey * nyy + ez * nyz);
    mf[0][2] = zx;
    mf[1][2] = zy;
    mf[2][2] = zz;
    mf[3][2] = -(ex * zx + ey * zy + ez * zz);
    mf[0][3] = 0.0f;
    mf[1][3] = 0.0f;
    mf[2][3] = 0.0f;
    mf[3][3] = 1.0f;
}
