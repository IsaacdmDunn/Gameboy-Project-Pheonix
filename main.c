//libraries
#include <gb/gb.h>
#include <gb/font.h>
#include <stdio.h>
#include "BirdImg.c"
#include "bg1.c"
#include "bg1map.c"
#include "windowmap.c"
#include "menu.c"
#include "menuimg.c"
#include "GameChar.c"

struct GameChar bird;
UBYTE spritesize = 8;
UINT8 spriteCount = 0;
UINT8 frameID = 0;

//moves and animates characters
void MoveGameCharacter(struct GameChar* character, UINT8 x, UINT8 y){
    if (frameID == 0)
    {
        move_sprite(character->spriteID[4], x, y);
        move_sprite(character->spriteID[2], x + spritesize, y);
        move_sprite(character->spriteID[1], x, y + spritesize);
        move_sprite(character->spriteID[3], x + spritesize, y + spritesize);
        //move_sprite(character->spriteID[0], 0, 0);
        move_sprite(character->spriteID[6], 0, 0);
        move_sprite(character->spriteID[5], 0, 0);
        move_sprite(character->spriteID[7], 0, 0);
        move_sprite(character->spriteID[8], 0, 0);
        move_sprite(character->spriteID[10], 0, 0);
        move_sprite(character->spriteID[9], 0, 0);
        move_sprite(character->spriteID[11], 0, 0);
        move_sprite(character->spriteID[12], 0, 0);
        move_sprite(character->spriteID[14], 0, 0);
        move_sprite(character->spriteID[13], 0, 0);
        move_sprite(character->spriteID[15], 0, 0);
    }
    else if (frameID == 1)
    {
        //move_sprite(character->spriteID[0], 0, 0);
        move_sprite(character->spriteID[2], 0, 0);
        move_sprite(character->spriteID[1], 0, 0);
        move_sprite(character->spriteID[3], 0, 0);
        move_sprite(character->spriteID[4], x, y);
        move_sprite(character->spriteID[6], x + spritesize, y);
        move_sprite(character->spriteID[5], x, y + spritesize);
        move_sprite(character->spriteID[7], x + spritesize, y + spritesize);
        move_sprite(character->spriteID[8], 0, 0);
        move_sprite(character->spriteID[10], 0, 0);
        move_sprite(character->spriteID[9], 0, 0);
        move_sprite(character->spriteID[11], 0, 0);
        move_sprite(character->spriteID[12], 0, 0);
        move_sprite(character->spriteID[14], 0, 0);
        move_sprite(character->spriteID[13], 0, 0);
        move_sprite(character->spriteID[15], 0, 0);
    }
    else if (frameID == 2)
    {
        //move_sprite(character->spriteID[0], 0, 0);
        move_sprite(character->spriteID[2], 0, 0);
        move_sprite(character->spriteID[1], 0, 0);
        move_sprite(character->spriteID[3], 0, 0);
        move_sprite(character->spriteID[4], 0, 0);
        move_sprite(character->spriteID[6], 0, 0);
        move_sprite(character->spriteID[5], 0, 0);
        move_sprite(character->spriteID[7], 0, 0);
        move_sprite(character->spriteID[8], x, y);
        move_sprite(character->spriteID[10], x + spritesize, y);
        move_sprite(character->spriteID[9], x, y + spritesize);
        move_sprite(character->spriteID[11], x + spritesize, y + spritesize);
        move_sprite(character->spriteID[12], 0, 0);
        move_sprite(character->spriteID[14], 0, 0);
        move_sprite(character->spriteID[13], 0, 0);
        move_sprite(character->spriteID[15], 0, 0);
    }
    else if (frameID == 3)
    {
        //move_sprite(character->spriteID[0], 0, 0);
        move_sprite(character->spriteID[2], 0, 0);
        move_sprite(character->spriteID[1], 0, 0);
        move_sprite(character->spriteID[3], 0, 0);
        move_sprite(character->spriteID[4], 0, 0);
        move_sprite(character->spriteID[6], 0, 0);
        move_sprite(character->spriteID[5], 0, 0);
        move_sprite(character->spriteID[7], 0, 0);
        move_sprite(character->spriteID[8], 0, 0);
        move_sprite(character->spriteID[10], 0, 0);
        move_sprite(character->spriteID[9], 0, 0);
        move_sprite(character->spriteID[11], 0, 0);
        move_sprite(character->spriteID[12], x, y);
        move_sprite(character->spriteID[14], x + spritesize, y);
        move_sprite(character->spriteID[13], x, y + spritesize);
        move_sprite(character->spriteID[15], 0,0);
    }
}

//sets up bird with sprites, bounding box and position
void SetUpBird(){
    bird.x = 80;
    bird.y = 130;
    bird.width = 16;
    bird.height = 16;

    for (spriteCount = 1; spriteCount < 15; spriteCount++)
    {
        set_sprite_tile(spriteCount, spriteCount);
        bird.spriteID[spriteCount] = spriteCount;
    }

    MoveGameCharacter(&bird, bird.x, bird.y);
}

//adds delay
void GBDelay(UINT8 delayCount)
{
    UINT8 currentDelayCount;

    for(currentDelayCount = 0; currentDelayCount < delayCount; currentDelayCount++)
    {
        wait_vbl_done();
    }     
}

//changes screen colour to fade out
void FadeOut()
{
    UINT8 i;
	for(i = 0; i < 4; i++)
    {
		switch(i)
        {
			case 0:
				BGP_REG = 0xE4;
				break;
			case 1:
				BGP_REG = 0xF9;
				break;
			case 2:
				BGP_REG = 0xFE;
				break;
			case 3:
				BGP_REG = 0xFF;	
				break;						
		}
		GBDelay(5);
	}
}

//changes screen colour to fade in
void FadeIn()
{
    UINT8 i;
	for (i = 0; i < 3; i++) 
    {
		switch(i)
        {
			case 0:
				BGP_REG = 0xFE;
				break;
			case 1:
				BGP_REG = 0xF9;
				break;
			case 2:
				BGP_REG = 0xE4;
				break;					
		}
		GBDelay(5);
	}
}

//start up function
void main()
{
    

    //set up font
    font_t min_font;
    font_init();
    min_font = font_load(font_min);
    font_set(min_font);


    //set up menu background
    set_bkg_data(0, 128, menuimg);
    set_bkg_tiles(0, 0, 20, 18, menu);

    //wait til player starts game then fade out
    waitpad(J_START);
    FadeOut();
    
    //set up background
    set_bkg_data(128, 6, bg1);
    set_bkg_tiles(0, 0, 40, 18, bg1map);

    //set up sprite
    set_sprite_data(0, 15, BirdImg);
    SetUpBird();

    //fade back in once everything is loaded
    FadeIn();

    //set up text window
    // set_win_tiles(0, 0, 8, 1, windowmap);
    // move_win(7, 120);

    //enables features
    SHOW_SPRITES;
    SHOW_BKG;
    SHOW_WIN;
    DISPLAY_ON;

    NR52_REG = 0x80; //turns sound on
    NR50_REG = 0x77; //gives dou sound
    NR51_REG = 0xFF; //enables all sound channels


    //game loop
    while (1)
    {
        
        //uses arrow keys to move player
        switch (joypad())
        {
        case J_LEFT: 
            bird.x -= 2;
            break;
        case J_RIGHT:
            bird.x += 2;
            break;
        case J_UP:
            bird.y -= 2;
            break;
        case J_DOWN:
            bird.y += 2;
            break;
        default:
            break;
        }
    

        MoveGameCharacter(&bird, bird.x, bird.y);

        if(frameID == 4)
        {
            frameID = -1;
        }
        

        //add a frame
        frameID++;

        //scroll background and sprites
        scroll_bkg(1, 0);

        //set frame rate
        GBDelay(5);
    }
    
}
