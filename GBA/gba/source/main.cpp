#include "toolbox.h"
#include "gfx.h"
#include "input.h"

int main()
{
    REG_DISPCNT= DCNT_MODE3 | DCNT_BG2;
	seed(23343);
	u32 t = 0;
	//bool isPaused = false;
    COLOR clr;
	int frame=0;
	
    int ii;
    u32 btn;
    while(1)
	{
		for(ii=0; ii<KI_MAX; ii++)
        {
            clr=0;
            btn= 1<<ii;
			
            if(key_is_down(btn))
                clr= CLR_RED;
            else if(key_released(btn))
                clr= CLR_YELLOW;
            else if(key_held(btn))
                clr= CLR_LIME;
            else
                clr= CLR_BLACK;
            //pal_bg_mem[BTN_PAL_ID+ii]= clr;
        }
		vsync();
		//randVal = (-20,20);
		u32 x=0,y=0;
		//if (!isPaused) {
		    
		
		
		for (y = 0; y < 8; y++) {
		    for (x= 0; x< 12; x++) {
				
				u32 r = rand(); r=randRange(0,21);
				u32 g = rand();	g=randRange(0,21);
				u32 b = rand(); b=randRange(0,21);
			    DrawRect(x*20+1,y*20+1,19,19,clr);
				DrawLine(x*20+20,0,x*20+20,SCREEN_H,SetColour(31,31,31));
				DrawLine(0,y*20+20,SCREEN_W,y*20+20,SetColour(31,31,31));
				//
			}
			
		}
		t++;
		frame++;
	//}
	}
    return 0;
}