// toolbox.h: 
//
// === NOTES ===
// * This is a _small_ set of typedefs, #defines and inlines that can 
//   be found in tonclib, and might not represent the 
//   final forms.


#ifndef GFX_H
#define GFX_H
#include "toolbox.h"



INLINE void m3_plot(u32 x, u32 y, COLOR clr)
{
    vid_mem[y * SCREEN_W + x] = clr;
}

#define CLR_BLACK   0x0000
#define CLR_RED     0x001F
#define CLR_LIME    0x03E0
#define CLR_YELLOW  0x03FF
#define CLR_BLUE    0x7C00
#define CLR_MAG     0x7C1F
#define CLR_CYAN    0x7FE0
#define CLR_WHITE   0x7FFF


u16 SetColour(u8 r, u8 g, u8 b)
{
    return (r&0x1F) | (g&0x1F)<<5 | (b&0x1F)<<10;
}

void PlotP(u32 x,u32 y,u16 clr)
{
	vid_mem[y*SCREEN_W+x]=clr;
}

void DrawRect(u32 left, u32 top, u32 width, u32 height, u16 clr)
{
	for (u32 y = 0; y < height; y++) {
		for (u32 x = 0; x < width; x++) {
			PlotP(left+x,top+y,clr);
		}	
	}
	
}

void DrawLine(u32 x1, u32 y1, u32 x2, u32 y2, u16 clr)
{
	u32 w = x2-x1;
	u32 h = y2-y1;
	
	u32 dx1 = 0, dx2 =0, dy1 = 0, dy2 =0;
	if(w<0)dx1=dx2=-1; else if (w>0) dx1=dx2=1;
	if(h<0)dy1=dy2=-1; else if (h>0) dy1=dy2=1;
	
	u32 longest = abs(w);
	u32 shortest = abs(h);
	
	if (shortest > longest) {
		longest ^= shortest; shortest ^= longest; longest ^= shortest;
		if(h<0)dy2=-1;else if(h>0)dy2=1;
		dx2=0;
	}
	
	u32 numerator = longest >> 1;
	for (u32 i = 0; i <= longest; i++) {
		PlotP(x1,y1,clr);
		numerator += shortest;
		if (numerator > longest) {
		    numerator -= longest;
			x1 += dx1;
			y1 += dy1;
		}
		else {
			x1 += dx2;
			y1 += dy2;
		}
		
	}
	
	
}

#endif // TOOLBOX_H

