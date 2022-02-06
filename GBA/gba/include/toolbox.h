// toolbox.h: 
//
// === NOTES ===
// * This is a _small_ set of typedefs, #defines and inlines that can 
//   be found in tonclib, and might not represent the 
//   final forms.


#ifndef TOOLBOX_H
#define TOOLBOX_H
#include <stdint.h>
//#include <stdlib.h>
#include <stdbool.h>
// === (from tonc_types.h) ============================================

typedef unsigned char   u8;
typedef unsigned short  u16;
typedef unsigned int    u32;

typedef u16 COLOR;

#define INLINE static inline

// === (from tonc_memmap.h) ===========================================

#define MEM_IO      0x04000000
#define MEM_VRAM    0x06000000

#define REG_DISPCNT     *((volatile u32*)(MEM_IO+0x0000))

// === (from tonc_memdef.h) ===========================================

// --- REG_DISPCNT defines ---
#define DCNT_MODE0     0x0000
#define DCNT_MODE1      0x0001
#define DCNT_MODE2      0x0002
#define DCNT_MODE3      0x0003
#define DCNT_MODE4      0x0004
#define DCNT_MODE5      0x0005
// layers
#define DCNT_BG0        0x0100
#define DCNT_BG1        0x0200
#define DCNT_BG2        0x0400
#define DCNT_BG3        0x0800
#define DCNT_OBJ        0x1000


// === (from tonc_video.h) ============================================

#define SCREEN_W  240
#define SCREEN_H  160

#define vid_mem     ((u16*)MEM_VRAM)
u32 RSEED = 42;
u32 seed(u32 seed)
{
	u32 oldSeed = RSEED;
	RSEED = seed;
	return oldSeed;
}

u32 rand()
{
	RSEED = 1664525 * RSEED + 1013904223;
	return (RSEED >> 16) & 0x7FFF;
}

u32 randRange(u32 min, u32 max) 
{
	return (rand() * (max-min)>>15)+min;
}


#define REG_VCOUNT *(volatile unsigned short*)0x04000006
void vsync()
{
	while(REG_VCOUNT >= SCREEN_H);
	while(REG_VCOUNT < SCREEN_H);
}

u32 abs(u32 val) 
{
	u32 mask = val >> 31;
	return(val ^ mask) - mask;
}


#endif // TOOLBOX_H

