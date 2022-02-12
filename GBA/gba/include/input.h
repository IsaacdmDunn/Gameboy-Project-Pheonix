#ifndef INPUT_H
#define INPUT_H
#include "toolbox.h"


extern u16 __key_curr, __key_prev;

#define KEY_A        0x0001
#define KEY_B        0x0002
#define KEY_SELECT   0x0004
#define KEY_START    0x0008
#define KEY_RIGHT    0x0010
#define KEY_LEFT     0x0020
#define KEY_UP       0x0040
#define KEY_DOWN     0x0080
#define KEY_R        0x0100
#define KEY_L        0x0200

#define REG_BASE 0x04000000
#define KEY_MASK     0x03FF
#define REG_KEYCNT   0x04000130
#define REG_KEYINPUT 0x04000130

// Polling function
INLINE void key_poll()
{
    __key_prev= __key_curr;
    __key_curr= ~REG_KEYINPUT & KEY_MASK;
}

// Basic state checks
INLINE u32 key_curr_state()         {   return __key_curr;          }
INLINE u32 key_prev_state()         {   return __key_prev;          }
INLINE u32 key_is_down(u32 key)     {   return  __key_curr & key;   }
INLINE u32 key_is_up(u32 key)       {   return ~__key_curr & key;   }
INLINE u32 key_was_down(u32 key)    {   return  __key_prev & key;   }
INLINE u32 key_was_up(u32 key)      {   return ~__key_prev & key;   }

// Key is changing state.
INLINE u32 key_transit(u32 key)
{   return ( __key_curr ^  __key_prev) & key;   }

// Key is held (down now and before).
INLINE u32 key_held(u32 key)
{   return ( __key_curr &  __key_prev) & key;  }

// Key is being hit (down now, but not before).
INLINE u32 key_hit(u32 key)
{   return ( __key_curr &~ __key_prev) & key;  }

//Key is being released (up now but down before)
INLINE u32 key_released(u32 key)
{   return (~__key_curr &  __key_prev) & key;  }

enum eKeyIndex
{
    KI_A=0, KI_B, KI_SELECT, KI_START, 
    KI_RIGHT, KI_LEFT, KI_UP, KI_DOWN,
    KI_R, KI_L, KI_MAX
};
INLINE int bit_tribool(u32 x, int plus, int minus)
{   return ((x>>plus)&1) - ((x>>minus)&1);  }

// --- TRISTATES ---
INLINE int key_tri_horz()       // right/left : +/-
{   return bit_tribool(__key_curr, KI_RIGHT, KI_LEFT);  }

INLINE int key_tri_vert()       // down/up : +/-
{   return bit_tribool(__key_curr, KI_DOWN, KI_UP);     }

INLINE int key_tri_shoulder()   // R/L : +/-
{   return bit_tribool(__key_curr, KI_R, KI_L);         }

INLINE int key_tri_fire()       // B/A : -/+
{   return bit_tribool(__key_curr, KI_A, KI_B);         }

#endif // TOOLBOX_H

