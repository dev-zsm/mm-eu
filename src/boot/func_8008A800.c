// FLAGS: -O1 -g0
#include "types.h"

/* PI (cart bus) timing registers, domain 1 and domain 2. */
#define PI_BSD_DOM1_LAT_REG 0xA4600014
#define PI_BSD_DOM1_PWD_REG 0xA4600018
#define PI_BSD_DOM1_PGS_REG 0xA460001C
#define PI_BSD_DOM1_RLS_REG 0xA4600020
#define PI_BSD_DOM2_LAT_REG 0xA4600024
#define PI_BSD_DOM2_PWD_REG 0xA4600028
#define PI_BSD_DOM2_PGS_REG 0xA460002C
#define PI_BSD_DOM2_RLS_REG 0xA4600030

extern s8 D_8009D504;    /* stores the constant 7 */
extern s8 D_8009D505;    /* DOM1 LAT copy */
extern s8 D_8009D506;    /* DOM1 PGS copy */
extern s8 D_8009D507;    /* DOM1 RLS copy */
extern s8 D_8009D508;    /* DOM1 PWD copy */
extern s8 D_8009D57C;    /* stores the constant 7 */
extern s8 D_8009D57D;    /* DOM2 LAT copy */
extern s8 D_8009D57E;    /* DOM2 PGS copy */
extern s8 D_8009D57F;    /* DOM2 RLS copy */
extern s8 D_8009D580;    /* DOM2 PWD copy */

/*
 * Saves the PI domain 1 and domain 2 timing registers into RAM globals.
 * Likely used to restore cart bus timing later; SDK name unknown.
 * The stored values are truncated to 8 bits by the s8 globals.
 */
void func_8008A800(void) {
    D_8009D504 = 7;
    D_8009D505 = *(u32 *)PI_BSD_DOM1_LAT_REG;
    D_8009D508 = *(u32 *)PI_BSD_DOM1_PWD_REG;
    D_8009D506 = *(u32 *)PI_BSD_DOM1_PGS_REG;
    D_8009D507 = *(u32 *)PI_BSD_DOM1_RLS_REG;
    D_8009D57C = 7;
    D_8009D57D = *(u32 *)PI_BSD_DOM2_LAT_REG;
    D_8009D580 = *(u32 *)PI_BSD_DOM2_PWD_REG;
    D_8009D57E = *(u32 *)PI_BSD_DOM2_PGS_REG;
    D_8009D57F = *(u32 *)PI_BSD_DOM2_RLS_REG;
}
