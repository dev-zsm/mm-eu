#ifndef OS_PFS_H
#define OS_PFS_H

#include "ultra64.h"
#include "os_cont.h"

/* OSPfs.status */
#define PFS_INITIALIZED 0x01
#define PFS_CORRUPTED 0x02
#define PFS_ID_BROKEN 0x04
#define PFS_MOTOR_INITIALIZED 0x08

/* Error codes of the Controller Pak functions. */
#define PFS_ERR_NOPACK 1
#define PFS_ERR_NEW_PACK 2
#define PFS_ERR_INCONSISTENT 3
#define PFS_ERR_CONTRFAIL 4
#define PFS_ERR_INVALID 5
#define PFS_ERR_BAD_DATA 6
#define PFS_DATA_FULL 7
#define PFS_DIR_FULL 8
#define PFS_ERR_EXIST 9
#define PFS_ERR_ID_FATAL 10
#define PFS_ERR_DEVICE 11

#define PFS_BLOCKSIZE 32      /* bytes of one Pak block */
#define PFS_ONE_PAGE 8        /* blocks in a page */
#define PFS_PAGE_SIZE 0x100   /* bytes of a page */
#define PFS_INODE_ENTRIES 128 /* entries of an inode page */

#define PFS_READ 0
#define PFS_WRITE 1

typedef struct {
    /* 0x00 */ s32 status;
    /* 0x04 */ OSMesgQueue *queue;
    /* 0x08 */ s32 channel;
    /* 0x0C */ u8 id[32];
    /* 0x2C */ u8 label[32];
    /* 0x4C */ s32 version;
    /* 0x50 */ s32 dirSize;
    /* 0x54 */ s32 inodeTable;
    /* 0x58 */ s32 minodeTable;
    /* 0x5C */ s32 dirTable;
    /* 0x60 */ s32 inodeStartPage;
    /* 0x64 */ u8 banks;
    /* 0x65 */ u8 activeBank;
} OSPfs;

typedef struct {
    /* 0x00 */ u32 fileSize;
    /* 0x04 */ u32 gameCode;
    /* 0x08 */ u16 companyCode;
    /* 0x0A */ u8 extName[4];
    /* 0x0E */ u8 gameName[16];
} OSPfsState;

/* Where a file page lives: the bank of the Pak RAM and the page inside it. */
typedef union {
    struct {
        /* 0x0 */ u8 bank;
        /* 0x1 */ u8 page;
    } inode_t;
    /* 0x0 */ u16 ipage;
} __OSInodeUnit;

typedef struct {
    /* 0x00 */ __OSInodeUnit inodePage[PFS_INODE_ENTRIES];
} __OSInode;

/* Directory entry, 32 bytes. */
typedef struct {
    /* 0x00 */ u32 gameCode;
    /* 0x04 */ u16 companyCode;
    /* 0x06 */ __OSInodeUnit startPage;
    /* 0x08 */ u8 status;
    /* 0x09 */ s8 reserved;
    /* 0x0A */ u16 dataSum;
    /* 0x0C */ u8 extName[4];
    /* 0x10 */ u8 gameName[16];
} __OSDir;

/* Identification block of a Pak (block 1 of bank 0). */
typedef struct {
    /* 0x00 */ u32 repaired;
    /* 0x04 */ u32 random;
    /* 0x08 */ u64 serialMid;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u16 deviceid;
    /* 0x1A */ u8 banks;
    /* 0x1B */ u8 version;
    /* 0x1C */ u16 checksum;
    /* 0x1E */ u16 invertedChecksum;
} __OSPackId;

/* Copy of the last inode page read, with the channel and bank it came from. */
extern s32 D_800980F0;      /* channel of the cached inode page */
extern u8 D_800980F4;       /* bank of the cached inode page; 0xFA after a status request */
extern __OSInode D_8009E7E0;

/* Assembly helpers. */
void bcopy(const void *src, void *dst, u32 n);
s32 bcmp(const void *a, const void *b, u32 n);

s32 osPfsInitPak(OSMesgQueue *queue, OSPfs *pfs, s32 channel);
s32 osPfsChecker(OSPfs *pfs);
s32 osPfsIsPlug(OSMesgQueue *queue, u8 *pattern);
s32 osPfsFreeBlocks(OSPfs *pfs, s32 *bytesNotUsed);
s32 osPfsAllocateFile(OSPfs *pfs, u16 companyCode, u32 gameCode, u8 *gameName, u8 *extName, s32 fileSizeInBytes,
                      s32 *fileNo);
s32 osPfsFindFile(OSPfs *pfs, u16 companyCode, u32 gameCode, u8 *gameName, u8 *extName, s32 *fileNo);
s32 osPfsDeleteFile(OSPfs *pfs, u16 companyCode, u32 gameCode, u8 *gameName, u8 *extName);
s32 osPfsReadWriteFile(OSPfs *pfs, s32 fileNo, u8 flag, s32 offset, s32 size, u8 *data);
s32 osPfsFileState(OSPfs *pfs, s32 fileNo, OSPfsState *state);

s32 osMotorInit(OSMesgQueue *mq, OSPfs *pfs, s32 channel);
s32 __osMotorAccess(OSPfs *pfs, s32 flag);

u16 __osSumcalc(u8 *ptr, s32 length);
s32 __osIdCheckSum(u16 *ptr, u16 *checksum, u16 *inverseChecksum);
s32 __osCheckPackId(OSPfs *pfs, __OSPackId *temp);
s32 __osRepairPackId(OSPfs *pfs, __OSPackId *badid, __OSPackId *newid);
s32 __osGetId(OSPfs *pfs);
s32 __osCheckId(OSPfs *pfs);

s32 __osPfsGetNextPage(OSPfs *pfs, u8 *bank, __OSInode *inode, __OSInodeUnit *page);
s32 __osPfsGetStatus(OSMesgQueue *queue, s32 channel);
void __osPfsRequestOneChannel(s32 channel, u8 poll);
void __osPfsGetOneChannelData(s32 channel, OSContStatus *data);
s32 __osPfsDeclearPage(OSPfs *pfs, __OSInode *inode, s32 fileSizeInPages, s32 *startPage, u8 bank, s32 *decl,
                       s32 *lastPage);
s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank);
s32 __osPfsReleasePages(OSPfs *pfs, __OSInode *inode, u8 startPage, u8 bank, __OSInodeUnit *finalPage);
void __osPfsRequestData(u8 cmd);
void __osPfsGetInitData(u8 *pattern, OSContStatus *data);
s32 __osPfsSelectBank(OSPfs *pfs, u8 bank);
s32 __osPfsCheckRamArea(OSPfs *pfs);

#endif
