/* *** NOTE: EXAMPLE USAGE CODE!!! *** */

// M O D U L E S /////////////////////////////////////////////////////////////////

#define TINY_ACTIONS
#include "tinyengine_actions.h"
#include "tinyengine_actions.c"

//////////////////////////////////////////////////////////////////////////////////

typedef enum example_actions
{
    MOVE_LEFT,
    MOVE_RIGHT,
    CURSOR,
    EXAMPLE_ACTIONS_COUNT,
} example_actions;

tiny_action Actions[EXAMPLE_ACTIONS_COUNT];

static void
Tiny_GameUpdate(tiny_platform *Platform)
{
    // Update based on user input
    Actions[MOVE_LEFT].String = (u8*)"Test";
    //Actions[MOVE_LEFT].KeyboardBinding = ;
    Actions[MOVE_LEFT].MouseBinding = MOUSE_LEFT;
    //Actions[MOVE_LEFT].ControllerBinding = CONTROLLER_LEFT;

    // Update user defined actions
    TinyActions_Update(Actions, ArrayCount(Actions));

    Win32PrintDebugString("Up: %d, Down: %d\n", Actions[MOVE_LEFT].Up, Actions[MOVE_LEFT].Down);
}

static void
Tiny_GameRender()
{
    
}