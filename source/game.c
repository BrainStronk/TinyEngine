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
    #if 0
    // TODO(hayden): Example usage code -- Remove later!!!
//  {
        // Update based on user input
        Actions[MOVE_LEFT].String = "Move Left";
        Actions[MOVE_LEFT].KeyBinding = KEY_A;
        Actions[MOVE_LEFT].MouseBinding = MOUSE_LEFT;

        // Update user defined actions
        TinyActions_Update(Actions, ArrayCount(Actions));
//  }
#endif
}

static void
Tiny_GameRender()
{
    
}