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
typedef struct 
{
  u8 pad0[0x14];
  u32 unk14;
  u8 pad18[0x108];
  u32 unk120;
} Boot;
typedef struct 
{
  u8 pad0[4];
  u32 unk4;
  u8 pad8[4];
  u32 unkC;
  u8 pad10[4];
  u32 unk14;
  u8 pad18[4];
  u32 unk1C;
  u8 pad20[4];
  u32 unk24;
  u8 pad28[4];
  u32 unk2C;
  u8 pad30[4];
  u32 unk34;
  u8 pad38[4];
  u32 unk3C;
  u8 pad40[4];
  u32 unk44;
  u8 pad48[4];
  u32 unk4C;
  u8 pad50[4];
  u32 unk54;
  u8 pad58[4];
  u32 unk5C;
  u8 pad60[4];
  u32 unk64;
  u8 pad68[4];
  u32 unk6C;
  u8 pad70[4];
  u32 unk74;
  u8 pad78[4];
  u32 unk7C;
  u8 pad80[4];
  u32 unk84;
  u8 pad88[4];
  u32 unk8C;
  u8 pad90[4];
  u32 unk94;
  u8 pad98[4];
  u32 unk9C;
  u8 padA0[4];
  u32 unkA4;
  u8 padA8[4];
  u32 unkAC;
  u8 padB0[4];
  u32 unkB4;
  u8 padB8[4];
  u32 unkBC;
  u8 padC0[4];
  u32 unkC4;
  u8 padC8[4];
  u32 unkCC;
  u8 padD0[4];
  u32 unkD4;
  u8 padD8[4];
  u32 unkDC;
  u8 padE0[4];
  u32 unkE4;
  u8 padE8[4];
  u32 unkEC;
  u8 padF0[8];
  u32 unkF8;
  u32 unkFC;
  u8 pad100[4];
  u32 unk104;
  u8 pad108[4];
  u32 unk10C;
} Chan;
extern void func_8008198C();
extern void Fault_LogFReg();
extern void Fault_LogFPCSR();
extern u8 D_80098A40[];
extern u8 D_80098A44[];
extern u8 D_80098A5C[];
extern u8 D_80098A7C[];
extern u8 D_80098A9C[];
extern u8 D_80098ABC[];
extern u8 D_80098ADC[];
extern u8 D_80098AFC[];
extern u8 D_80098B1C[];
extern u8 D_80098B3C[];
extern u8 D_80098B5C[];
extern u8 D_80098B7C[];
extern u8 D_80098B9C[];
extern u8 D_80098BBC[];
extern u8 D_80098BC0[];
extern u8 D_80098BC4[];
extern u8 D_80098BC8[];
extern u8 D_80098BCC[];
extern u8 D_80098BD0[];
extern u8 D_80098BD4[];
extern u8 D_80098BD8[];
extern u8 D_80098BDC[];
extern u8 D_80098BE0[];
extern u32 D_80096D20[];
void Fault_LogThreadContext(Boot *arg)
{
  s16 v;
  Chan *t;
  v = (arg->unk120 >> 2) & 0x1F;
  if (v == 0x17)
  {
    v = 0x10;
  }
  if (v == 0x1F)
  {
    v = 0x11;
  }
  t = (Chan *) (((u8 *) arg) + 0x20);
  func_8008198C(&D_80098A40);
  func_8008198C(&D_80098A44, arg->unk14, (s32) v, D_80096D20[v]);
  func_8008198C(&D_80098A5C, t->unkFC, t->unkF8, t->unk104);
  func_8008198C(&D_80098A7C, t->unk4, t->unkC, t->unk14);
  func_8008198C(&D_80098A9C, t->unk1C, t->unk24, t->unk2C);
  func_8008198C(&D_80098ABC, t->unk34, t->unk3C, t->unk44);
  func_8008198C(&D_80098ADC, t->unk4C, t->unk54, t->unk5C);
  if (((!arg->unk120) && (!arg->unk120)) && (!arg->unk120))
  {
  }
  func_8008198C(&D_80098AFC, t->unk64, t->unk6C, t->unk74);
  func_8008198C(&D_80098B1C, t->unk7C, t->unk84, t->unk8C);
  func_8008198C(&D_80098B3C, t->unk94, t->unk9C, t->unkA4);
  func_8008198C(&D_80098B5C, t->unkAC, t->unkB4, t->unkBC);
  func_8008198C(&D_80098B7C, t->unkC4, t->unkCC, t->unkD4);
  func_8008198C(&D_80098B9C, t->unkDC, t->unkE4, t->unkEC);
  func_8008198C(&D_80098BBC);
  Fault_LogFPCSR(t->unk10C);
  func_8008198C(&D_80098BC0);
  Fault_LogFReg(0, ((u8 *) t) + 0x114);
  Fault_LogFReg(2, ((u8 *) t) + 0x11C);
  func_8008198C(&D_80098BC4);
  Fault_LogFReg(4, ((u8 *) t) + 0x124);
  Fault_LogFReg(6, ((u8 *) t) + 0x12C);
  func_8008198C(&D_80098BC8);
  Fault_LogFReg(8, ((u8 *) t) + 0x134);
  Fault_LogFReg(0xA, ((u8 *) t) + 0x13C);
  func_8008198C(&D_80098BCC);
  Fault_LogFReg(0xC, ((u8 *) t) + 0x144);
  Fault_LogFReg(0xE, ((u8 *) t) + 0x14C);
  func_8008198C(&D_80098BD0);
  Fault_LogFReg(0x10, ((u8 *) t) + 0x154);
  Fault_LogFReg(0x12, ((u8 *) t) + 0x15C);
  func_8008198C(&D_80098BD4);
  Fault_LogFReg(0x14, ((u8 *) t) + 0x164);
  Fault_LogFReg(0x16, ((u8 *) t) + 0x16C);
  func_8008198C(&D_80098BD8);
  Fault_LogFReg(0x18, ((u8 *) t) + 0x174);
  Fault_LogFReg(0x1A, ((u8 *) t) + 0x17C);
  func_8008198C(&D_80098BDC);
  Fault_LogFReg(0x1C, ((u8 *) t) + 0x184);
  Fault_LogFReg(0x1E, ((u8 *) t) + 0x18C);
  func_8008198C(&D_80098BE0);
}
