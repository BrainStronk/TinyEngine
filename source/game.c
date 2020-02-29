/* *** NOTE: EXAMPLE USAGE CODE!!! *** */

// M O D U L E S /////////////////////////////////////////////////////////////////

#define TINY_ACTIONS
#include "tinyengine_actions.h"
#include "tinyengine_actions.c"

//////////////////////////////////////////////////////////////////////////////////

tiny_action Actions[10];

static void
Tiny_GameUpdate(tiny_platform *Platform)
{
    //Win32PrintDebugString("A[0]: %d, A[1]: %d, A[2]: %d, A[3]: %d\n", Platform->EventQueue[0].Keyboard.KeyType, Platform->EventQueue[1].Keyboard.KeyType, Platform->EventQueue[2].Keyboard.KeyType, Platform->EventQueue[3].Keyboard.KeyType);
}

static void
Tiny_GameRender()
{
    
}