//libraries
#include <gb/gb.h>
#include <gb/font.h>
#include <stdio.h>
#include <stdlib.h>
#include <rand.h> 
#include "sprites/BirdImg.c"
#include "backgrounds/bg1img.c"
#include "backgrounds/bg1map.c"
#include "windowmap.c"
#include "backgrounds/menu.c"
#include "backgrounds/menuimg.c"
#include "GameChar.c"
#include "GameItem.c"

UINT8 ParalaxBGOffset1, ParalaxBGOffset2, ParalaxBGOffset3;

struct GameChar bird;
struct GameChar tank;
struct GameChar plane;

struct GameItems bullet;
struct GameItems bomb;
struct GameItems ball;
struct GameItems toast;
struct GameItems cereal;

UBYTE spritesize = 8;
UINT8 spriteCount = 0;
UINT8 frameID = 0;

//moves sections of the background at given point on screen to create a paralax effect 
void ParalaxScroll(){
    switch (LYC_REG)
    {
        case 0x00:
            move_bkg(ParalaxBGOffset1, 0);
            LYC_REG = 0x3D;
            break;
        case 0x3D:
            move_bkg(ParalaxBGOffset2, 0);
            LYC_REG = 0x74;
            break;
        case 0x74:
            move_bkg(ParalaxBGOffset3, 0);
            LYC_REG = 0x00;
            break;            
    }
}
void MoveGameCharacter(struct GameChar* character, UINT8 x, UINT8 y)
{
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
void MoveTank(struct GameChar* character, UINT8 x, UINT8 y)
{
    if (frameID == 0 || frameID == 2)
    {
        move_sprite(character->spriteID[4], x, y);
        move_sprite(character->spriteID[6], x + spritesize, y);
        move_sprite(character->spriteID[5], x, y + spritesize);
        move_sprite(character->spriteID[7], x + spritesize, y + spritesize);
        move_sprite(character->spriteID[0], 0, 0);
        move_sprite(character->spriteID[1], 0, 0);
        move_sprite(character->spriteID[2], 0, 0);
        move_sprite(character->spriteID[3], 0, 0);
    }
    else if (frameID == 1 || frameID == 3)
    {
        move_sprite(character->spriteID[0], x, y);
        move_sprite(character->spriteID[2], x + spritesize, y);
        move_sprite(character->spriteID[1], x, y + spritesize);
        move_sprite(character->spriteID[3], x + spritesize, y + spritesize);
        move_sprite(character->spriteID[4], 0, 0);
        move_sprite(character->spriteID[5], 0, 0);
        move_sprite(character->spriteID[6], 0, 0);
        move_sprite(character->spriteID[7], 0, 0);
    }
}
void MovePlane(struct GameChar* character, UINT8 x, UINT8 y)
{
        move_sprite(character->spriteID[0], x, y);
        move_sprite(character->spriteID[2], x + spritesize, y);
        move_sprite(character->spriteID[1], x, y + spritesize);
        move_sprite(character->spriteID[3], x + spritesize, y + spritesize);
}
void MoveItem(struct GameItems* item, UINT8 x, UINT8 y) 
{
    move_sprite(item->spriteID, x, y);
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
void SetUpTank(){
    tank.x = 140;
    tank.y = 125;
    tank.width = 16;
    tank.height = 16;

    for (spriteCount = 16; spriteCount < 24; spriteCount++)
    {
        set_sprite_tile(spriteCount, spriteCount);
        tank.spriteID[spriteCount - 16] = spriteCount;
    }

    MoveGameCharacter(&tank, tank.x, tank.y);
}
void SetUpPlane(){
    plane.x = 14;
    plane.y = 80;
    plane.width = 16;
    plane.height = 16;

    for (spriteCount = 24; spriteCount < 28; spriteCount++)
    {
        set_sprite_tile(spriteCount, spriteCount);
        plane.spriteID[spriteCount - 24] = spriteCount;
    }

    MoveGameCharacter(&plane, plane.x, plane.y);
}
void SetupFood() 
{
    toast.x = 80;
    toast.y = 30;
    toast.width = 8;
    toast.height = 8;
    set_sprite_tile(34, 34);
    toast.spriteID = 34;

    cereal.x = 40;
    cereal.y = 40;
    cereal.width = 8;
    cereal.height = 8;
    set_sprite_tile(35, 35);
    cereal.spriteID = 35;

    MoveItem(&cereal, cereal.x, cereal.y);
    MoveItem(&toast, toast.x, toast.y);
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

void CheckEnemyCollisions(struct GameChar* character1, struct GameChar* character2)
{
    if (character1->x < character2->x + character2->width && 
        character1->x + character1->width > character2->x &&
        character1->y < character2->y + character2->height && 
        character1->y + character1->height > character2->y)
    {
        character1->x = 40;
        character1->y = 40;
    }
}
void CheckItemCollisions(struct GameChar* character1, struct GameItems* item)
{
   if (character1->x < item->x + item->width && 
        character1->x + character1->width > item->x &&
        character1->y < item->y + item->height && 
        character1->y + character1->height > item->y)
    {
        item->x = rand() % 80 + 20;
        item->y = rand() % 80 + 20;
    } 
}
void CheckBulletCollisions(struct GameChar* character1, struct GameItems* item)
{
    if (character1->x < item->x + item->width && 
        character1->x + character1->width > item->x &&
        character1->y < item->y + item->height && 
        character1->y + character1->height > item->y)
    {
        character1->x = 0;
        character1->y = 0;
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

    ParalaxBGOffset1 = 0;
    ParalaxBGOffset2 = 0; 
    ParalaxBGOffset3 = 0;

    //set up menu background
    set_bkg_data(0, 128, menuimg);
    set_bkg_tiles(0, 0, 20, 18, menu);

    //wait til player starts game then fade out
    waitpad(J_START);
    FadeOut();
    
    //set up background
    set_bkg_data(128, 32, bg1img);
    set_bkg_tiles(0, 0, 40, 18, bg1map);

    STAT_REG = 0x45; // enable LYC=LY interrupt so that we can set a specific line it will fire at
    LYC_REG = 0x00;

    disable_interrupts();
    add_LCD(ParalaxScroll);
    enable_interrupts();

    set_interrupts(VBL_IFLAG | LCD_IFLAG);

    //set up sprite
    set_sprite_data(0, 36, BirdImg);
    SetUpBird();
    SetUpTank();
    SetUpPlane();
    SetupFood();

    //fade back in once everything is loaded
    FadeIn();

    //set up text window
    // set_win_tiles(0, 0, 8, 1, windowmap);
    // move_win(7, 120);

    //enables features
    SHOW_SPRITES;
    SHOW_BKG;
    //SHOW_WIN;
    DISPLAY_ON;
    NR52_REG = 0x80; //turns sound on
    NR50_REG = 0x77; //gives dou sound
    NR51_REG = 0xFF; //enables all sound channels

    //game loop
    while (1)
    {
        ParalaxBGOffset1 += 1;
        ParalaxBGOffset2 += 2;
        ParalaxBGOffset3 += 10;

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
        tank.x -= 2;
        plane.x -= 5;

        MoveTank(&tank, tank.x, tank.y);
        MovePlane(&plane, plane.x, plane.y);
        MoveGameCharacter(&bird, bird.x, bird.y);
        MoveItem(&toast, toast.x, toast.y);
        MoveItem(&cereal, cereal.x, cereal.y);

        CheckEnemyCollisions(&bird, &tank);
        CheckEnemyCollisions(&bird, &plane);

        CheckItemCollisions(&bird, &toast);
        CheckItemCollisions(&bird, &cereal);
        
        CheckBulletCollisions(&bird, &bullet);
        CheckBulletCollisions(&bird, &bomb);
        CheckBulletCollisions(&bird, &ball);

        if(frameID == 3)
        {
            frameID = -1;
        }

        //add a frame
        frameID++;

        //set frame rate
        GBDelay(5);
    }
    
}
