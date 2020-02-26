#ifndef TINYENGINE_ACTIONS_H
#define TINYENGINE_ACTIONS_H

#ifdef TINY_ACTIONS

typedef struct tiny_action
{
    u8 *String;

    b32 Up;
    b32 Down;
    b32 Pressed;
    b32 Released;

    s32 KeyBinding;
    s32 MouseBinding;
    s32 JoystickBinding;
    s32 GamepadBinding;
    s32 ControllerBinding; // XInput
} tiny_action;

// TODO(hayden): Example usage code -- Remove later!!!
//{
    typedef enum example_actions
    {
        MOVE_LEFT,
        MOVE_RIGHT,
    } example_actions;
//}

static void TinyActions_Update(tiny_action *Actions, int ActionsArraySize);

#endif

#endif // TINYENGINE_ACTIONS_H