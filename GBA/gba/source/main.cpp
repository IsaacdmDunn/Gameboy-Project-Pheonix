#include "toolbox.h"

int main()
{
    REG_DISPCNT= DCNT_MODE3 | DCNT_BG2;

	u32 t = 0;
    while(1)
	{
		u32 x,y;
		for (x = 0; x < SCREEN_W; x++) {
		    for (y= 0; y< SCREEN_H; y++) {
			    PlotP(x,y,SetColour((x&y)+t*5, (x&y)+t*3, (x&y)+t));
			}
			
		}
		t++;
	}

    return 0;
}