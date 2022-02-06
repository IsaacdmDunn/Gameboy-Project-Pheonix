#include "toolbox.h"
#include "gfx.h"

int main()
{
    REG_DISPCNT= DCNT_MODE3 | DCNT_BG2;
	
	seed(23343);

	u32 t = 0;
    while(1)
	{
	
		vsync();
		//randVal = (-20,20);
		u32 x=0,y=0;
		for (y = 0; y < 8; y++) {
		    for (x= 0; x< 12; x++) {
				
				u32 r = rand(); r=randRange(0,21);
				u32 g = rand();	g=randRange(0,21);
				u32 b = rand(); b=randRange(0,21);
			    DrawRect(x*20+1,y*20+1,19,19,SetColour(r,g,b));
				DrawLine(x*20+20,0,x*20+20,SCREEN_H,SetColour(31,31,31));
				DrawLine(0,y*20+20,SCREEN_W,y*20+20,SetColour(31,31,31));
				//
			}
			
		}
		t++;
	}

    return 0;
}