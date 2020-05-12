//libraries
#include <gb/gb.h>
#include <gb/font.h>
#include <stdio.h>
#include "bird.c"
#include "bg1.c"
#include "bg1map.c"
#include "windowmap.c"

//start up function
void main()
{
    UINT8 frameID = 0;

    //set up font
    font_t min_font;
    font_init();
    min_font = font_load(font_min);
    font_set(min_font);

    //set up background
    set_bkg_data(37, 6, bg1);
    set_bkg_tiles(0, 0, 40, 18, bg1map);

    //set up sprite
    set_sprite_data(0, 3, bird);
    set_sprite_tile(0, 0);
    move_sprite(0, 88, 78);

    //set up text window
    set_win_tiles(0, 0, 8, 1, windowmap);
    move_win(7, 120);

    //enables features
    SHOW_SPRITES;
    SHOW_BKG;
    SHOW_WIN;
    DISPLAY_ON;

    NR52_REG = 0x80; //turns sound on
    NR50_REG = 0x77; //gives dou sound
    NR51_REG = 0xFF; //enables all sound channels

    //jump sound
    // NR10_REG = 0x16;
    // NR11_REG = 0x40;
    // NR12_REG = 0x73;
    // NR13_REG = 0x00;
    // NR14_REG = 0xC3;

    
    //game loop
    while (1)
    {
        
        //uses arrow keys to move player
        switch (joypad())
        {
        case J_LEFT: 
            scroll_sprite(0, -2, 0);
            break;
        case J_RIGHT:
            scroll_sprite(0, 2, 0);
            break;
        case J_UP:
            scroll_sprite(0, 0, -2);
            break;
        case J_DOWN:
            scroll_sprite(0, 0, 2);
            break;
        default:
            break;
        }

        //plays music
        if (frameID == 0)
        {
            //frameID = 0;
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0x47;
            NR24_REG = 0x86;
        }
        else if(frameID == 4)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0x47;
            NR24_REG = 0x86;
        }
        else if(frameID == 8)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0xB7;
            NR24_REG = 0x86;
        }
        else if(frameID == 12)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0xB7;
            NR24_REG = 0x86;
        }
        else if(frameID == 16)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0xD7;
            NR24_REG = 0x86;
        }
        else if(frameID == 20)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0xD7;
            NR24_REG = 0x86;
        }
        else if(frameID == 24)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0xB7;
            NR24_REG = 0x86;
        }
        else if(frameID == 32)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0x97;
            NR24_REG = 0x86;
        }
        else if(frameID == 36)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0x97;
            NR24_REG = 0x86;
        }
        else if(frameID == 40)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0x87;
            NR24_REG = 0x86;
        }
        else if(frameID == 44)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0x87;
            NR24_REG = 0x86;
        }
        else if(frameID == 48)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0x67;
            NR24_REG = 0x86;
        }
        else if(frameID == 52)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0x67;
            NR24_REG = 0x86;
        }
        else if(frameID == 56)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0x47;
            NR24_REG = 0x86;
        }
        else if(frameID == 64)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0xB7;
            NR24_REG = 0x86;
        }
        else if(frameID == 68)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0xB7;
            NR24_REG = 0x86;
        }
        else if(frameID == 72)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0x97;
            NR24_REG = 0x86;
        }
        else if(frameID == 76)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0x97;
            NR24_REG = 0x86;
        }
        else if(frameID == 80)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0x87;
            NR24_REG = 0x86;
        }
        else if(frameID == 84)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0x87;
            NR24_REG = 0x86;
        }
        else if(frameID == 88)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0x67;
            NR24_REG = 0x86;
        }
        else if(frameID == 96)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0xB7;
            NR24_REG = 0x86;
        }
        else if(frameID == 100)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0xB7;
            NR24_REG = 0x86;
        }
        else if(frameID == 104)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0x97;
            NR24_REG = 0x86;
        }
        else if(frameID == 108)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0x97;
            NR24_REG = 0x86;
        }
        else if(frameID == 112)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0x87;
            NR24_REG = 0x86;
        }
        else if(frameID == 116)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0x87;
            NR24_REG = 0x86;
        }
        else if(frameID == 120)
        {
            NR21_REG = 0x00;
            NR22_REG = 0x84;
            NR23_REG = 0x67;
            NR24_REG = 0x86;
        }
        else if(frameID == 132)
        {
            frameID = -1;
        }
        

        //add a frame
        frameID++;

        //scroll background and sprites
        scroll_bkg(1, 0);
        set_sprite_tile(0, (int)frameID / 44);

        //set frame rate
        
        delay(120);
    }
    
}