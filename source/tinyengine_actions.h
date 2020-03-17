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
        s32 X, Y;
        f32 NormalizedX, NormalizedY;
        s32 Value;

        union
        {
            tiny_keyboard_enum KeyboardBinding;
            tiny_mouse_enum MouseBinding;
            tiny_controller_enum ControllerBinding; // XInput
            // TODO(hayden): JoystickBinding
            // TODO(hayden): GamepadBinding
        };
    } tiny_action;

    static void TinyActions_Update(tiny_action *Actions, int ActionsArraySize);
#endif // TINY_ACTIONS

#endif // TINYENGINE_ACTIONS_H