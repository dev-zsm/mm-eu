#ifndef LIBM_H
#define LIBM_H

#include "types.h"

/* Single-precision math of libultra. sinf/cosf are kept under the double-underscore name of the ROM. */
f32 __sinf(f32 x);
f32 __cosf(f32 x);
s16 sins(u16 x);
f32 sqrtf(f32 x);
f32 fmodf(f32 x, f32 y);
f32 floorf(f32 x);
f32 roundf(f32 x);
f32 func_80086D18(f32 x); /* ceilf-like */
f32 func_80086D50(f32 x); /* truncf-like */
f32 func_80086D88(f32 x); /* nearbyintf-like */
s32 func_80086D68(f32 x); /* truncation to s32 */
s32 func_80086D78(f64 x); /* truncation to s32 */

f32 Math_FTanF(f32 x);
f32 Math_FFloorF(f32 x);
f32 Math_FCeilF(f32 x);
f32 Math_FRoundF(f32 x);
f32 Math_FTruncF(f32 x);
f32 Math_FNearbyIntF(f32 x);
f32 Math_FAtanTaylorQF(f32 x);
f32 Math_FAtanTaylorF(f32 x);
f32 Math_FAtanContFracF(f32 x);
f32 Math_FAtanF(f32 x);
f32 Math_FAtan2F(f32 y, f32 x);
f32 Math_FAsinF(f32 x);
f32 Math_FAcosF(f32 x);

extern s32 D_8009D0E0;   /* selects the arctangent: 0 for the Taylor series, otherwise the continued fraction */
extern f32 D_800976C4;   /* quiet NaN, result for an undefined arctangent */
extern f32 D_80099374;   /* tan(pi/8), |x| below it uses the kernel directly */
extern f32 D_80099378;   /* tan(3*pi/8), |x| above it is reduced with 1/x */
extern f32 D_8009937C;   /* pi/2 */
extern f32 D_80099380;   /* pi/4 */
extern f32 D_80099384;   /* pi/2, x > 1 */
extern f32 D_80099388;   /* -pi/2, x < -1 */
extern f32 D_8009938C;   /* pi/2, y > 0 and x == 0 */
extern f32 D_80099390;   /* -pi/2, y < 0 and x == 0 */
extern f32 D_80099394;   /* pi, subtracted for x < 0 and y < 0 */
extern f32 D_80099398;   /* pi, used for x < 0 and y >= 0 */
extern f32 D_8009939C;   /* pi/2, acos(x) = pi/2 - asin(x) */

/* Coefficients and constants of __sinf and __cosf. */
extern f64 D_800995F0[];  /* sine polynomial, index 1 to 4 */
extern f64 D_80099618;    /* 1/pi, quadrant count */
extern f64 D_80099620;    /* pi, high part */
extern f64 D_80099628;    /* pi, low part */
extern f32 D_80099630;    /* result for an argument too large to reduce */
extern f64 D_800997D0[];  /* cosine polynomial, index 1 to 4 */
extern f64 D_800997F8;    /* 1/pi, quadrant count */
extern f64 D_80099800;    /* pi, high part */
extern f64 D_80099808;    /* pi, low part */
extern f32 D_80099810;    /* result for an argument too large to reduce */
extern f32 D_80099820;    /* result for a NaN argument */
extern s16 D_800977D0[];  /* quarter wave of the sine, 0x400 entries */

/* Linear congruential generator, one global state or a caller state. */
extern u32 D_800976D0;    /* global state */
extern u32 D_8009D120;    /* float bit pattern built for Rand_ZeroOne and Rand_Centered */

u32 Rand_Next(void);
void Rand_Seed(u32 seed);
f32 Rand_ZeroOne(void);
f32 Rand_Centered(void);
void Rand_Seed_Variable(u32 *rand, u32 seed);
u32 Rand_Next_Variable(u32 *rand);
f32 Rand_ZeroOne_Variable(u32 *rand);
f32 Rand_Centered_Variable(u32 *rand);

#endif
