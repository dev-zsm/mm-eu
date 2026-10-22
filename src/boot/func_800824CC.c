// FLAGS: -O2 -g3 -mips2 -trapuv

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
extern void FaultDrawer_Printf();
extern void Fault_PrintFReg(s32 arg0, u8 *arg1);
extern void Fault_PrintFPCSR(s32 arg0);
extern void FaultDrawer_SetCharPad(s32 a, s32 b);
extern void FaultDrawer_SetCursor(s32 a, s32 b);
extern void FaultDrawer_FillScreen();
extern void FaultDrawer_DrawText(s32 a, s32 b, void *c, f64 d);
extern s32 D_80096D20[];
extern u8 D_800988C4[];
extern u8 D_800988D8[];
extern u8 D_800988F4[];
extern u8 D_80098910[];
extern u8 D_8009892C[];
extern u8 D_80098948[];
extern u8 D_80098964[];
extern u8 D_80098980[];
extern u8 D_8009899C[];
extern u8 D_800989B8[];
extern u8 D_800989D4[];
extern u8 D_800989F0[];
extern u8 D_80098A10[];
extern u8 D_80098A14[];
extern u8 D_80098A18[];
extern u8 D_80098A1C[];
extern u8 D_80098A20[];
extern u8 D_80098A24[];
extern u8 D_80098A28[];
extern u8 D_80098A2C[];
extern u8 D_80098A30[];
extern u8 D_80098A34[];
extern f32 D_8009C224;
typedef struct 
{
  s32 w[0x80 / 4];
} Sub;
typedef struct 
{
  u8 pad0[0x20];
  Sub sub;
} Arg;
void Fault_PrintThreadContext(Arg *arg0)
{
  s16 var_s0;
  Sub *temp_s0;
  var_s0 = (s16) ((((u32) (*((s32 *) (((u8 *) arg0) + 0x120)))) >> 2) & 0x1F);
  if (var_s0 == 0x17)
  {
    var_s0 = 0x10;
  }
  if (var_s0 == 0x1F)
  {
    var_s0 = 0x11;
  }
  temp_s0 = &arg0->sub;
  FaultDrawer_FillScreen();
  FaultDrawer_SetCharPad(-2, 4);
  FaultDrawer_SetCursor(0x16, 0x14);
  FaultDrawer_Printf(D_800988C4, *((s32 *) (((u8 *) arg0) + 0x14)), (s32) var_s0, D_80096D20[var_s0]);
  FaultDrawer_SetCharPad(-1, 0);
  FaultDrawer_Printf(D_800988D8, temp_s0->w[0x3f], temp_s0->w[0x3e], temp_s0->w[0x41]);
  FaultDrawer_Printf(D_800988F4, temp_s0->w[0x1], temp_s0->w[0x3], temp_s0->w[0x5]);
  FaultDrawer_Printf(D_80098910, temp_s0->w[0x7], temp_s0->w[0x9], temp_s0->w[0xb]);
  FaultDrawer_Printf(D_8009892C, temp_s0->w[0xd], temp_s0->w[0xf], temp_s0->w[0x11]);
  FaultDrawer_Printf(D_80098948, temp_s0->w[0x13], temp_s0->w[0x15], temp_s0->w[0x17]);
  FaultDrawer_Printf(D_80098964, temp_s0->w[0x19], temp_s0->w[0x1b], temp_s0->w[0x1d]);
  FaultDrawer_Printf(D_80098980, temp_s0->w[0x1f], temp_s0->w[0x21], temp_s0->w[0x23]);
  FaultDrawer_Printf(D_8009899C, temp_s0->w[0x25], temp_s0->w[0x27], temp_s0->w[0x29]);
  FaultDrawer_Printf(D_800989B8, temp_s0->w[0x2b], temp_s0->w[0x2d], temp_s0->w[0x2f]);
  FaultDrawer_Printf(D_800989D4, temp_s0->w[0x31], temp_s0->w[0x33], temp_s0->w[0x35]);
  FaultDrawer_Printf(D_800989F0, temp_s0->w[0x37], temp_s0->w[0x39], temp_s0->w[0x3b]);
  Fault_PrintFPCSR(temp_s0->w[0x43]);
  FaultDrawer_Printf(D_80098A10);
  Fault_PrintFReg(0, ((u8 *) temp_s0) + 0x114);
  Fault_PrintFReg(2, ((u8 *) temp_s0) + 0x11C);
  FaultDrawer_Printf(D_80098A14);
  Fault_PrintFReg(4, ((u8 *) temp_s0) + 0x124);
  Fault_PrintFReg(6, ((u8 *) temp_s0) + 0x12C);
  FaultDrawer_Printf(D_80098A18);
  Fault_PrintFReg(8, ((u8 *) temp_s0) + 0x134);
  Fault_PrintFReg(0xA, ((u8 *) temp_s0) + 0x13C);
  FaultDrawer_Printf(D_80098A1C);
  Fault_PrintFReg(0xC, ((u8 *) temp_s0) + 0x144);
  Fault_PrintFReg(0xE, ((u8 *) temp_s0) + 0x14C);
  FaultDrawer_Printf(D_80098A20);
  Fault_PrintFReg(0x10, ((u8 *) temp_s0) + 0x154);
  if (((!arg0) && (!arg0)) && (!arg0))
  {
  }
  Fault_PrintFReg(0x12, ((u8 *) temp_s0) + 0x15C);
  FaultDrawer_Printf(D_80098A24);
  Fault_PrintFReg(0x14, ((u8 *) temp_s0) + 0x164);
  Fault_PrintFReg(0x16, ((u8 *) temp_s0) + 0x16C);
  FaultDrawer_Printf(D_80098A28);
  Fault_PrintFReg(0x18, ((u8 *) temp_s0) + 0x174);
  Fault_PrintFReg(0x1A, ((u8 *) temp_s0) + 0x17C);
  FaultDrawer_Printf(D_80098A2C);
  Fault_PrintFReg(0x1C, ((u8 *) temp_s0) + 0x184);
  Fault_PrintFReg(0x1E, ((u8 *) temp_s0) + 0x18C);
  FaultDrawer_Printf(D_80098A30);
  FaultDrawer_SetCharPad(0, 0);
  if (D_8009C224 != 0.0f)
  {
    FaultDrawer_DrawText(0xA0, 0xD8, D_80098A34, (f64) D_8009C224);
  }
}
