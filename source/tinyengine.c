static void
Tiny_PushInputEvent(tiny_event Event)
{
    GlobalPlatform.EventQueue[GlobalPlatform.EventQueueSize] = Event;
    ++GlobalPlatform.EventQueueSize;
}

// TODO(hayden): This might be useless/redundant now? Can this be skipped to process directly in TinyInput_UpdateActions()?
static void
Tiny_ProcessDigitalButton(tiny_digital_button *Button, b32 IsDown)
{
    // TODO(hayden): Avoid wrapping Up/Down?
    b32 WasDown = Button->Down;
    Button->Down = IsDown;
    Button->Pressed = !WasDown && IsDown;
    Button->Released = WasDown && !IsDown;
}

inline b32
Tiny_GetMessage(tiny_platform *Platform, tiny_event *Event)
{
    static s32 CountUpToEventQueueIndex = 0;

    // Type will always be greater than 0 if there is an event
    b32 EventIsValid = Platform->EventQueue[CountUpToEventQueueIndex].Type;

    // First In, First Out Queue
    if(CountUpToEventQueueIndex >= Platform->EventQueueSize)
    {
        CountUpToEventQueueIndex = 0;
        EventIsValid = false;
    }
    else
    {
        if(EventIsValid)
        {
            *Event = Platform->EventQueue[CountUpToEventQueueIndex];
            ++CountUpToEventQueueIndex;
        }
    }

    return(EventIsValid);
}

///

// Processed button state
// TODO(hayden): Unnecessary?
tiny_digital_button MouseButtons[MOUSE_COUNT];
tiny_digital_button ControllerButtons[CONTROLLER_COUNT];

// Flattened state
tiny_keyboard TinyInternalKeyboard;
tiny_controller TinyInternalController;
tiny_mouse TinyInternalMouse;

#include "game.c"

// Raw binary state
b32 KeyboardButtonState[KEY_COUNT];
b32 MouseButtonState[MOUSE_COUNT];
b32 ControllerButtonState[CONTROLLER_COUNT];

static void
Tiny_Update(tiny_platform *Platform)
{
    // Flatten state
    {
        // Mouse
        s32 MouseWheelDelta = 0;
        u32 MouseX = 0;
        u32 MouseY = 0;
        b32 ThereWasAMouseMoveEvent = false;

        // Controller
        s32 StickLeftX = 0, StickLeftY = 0;
        s32 StickRightX = 0, StickRightY = 0;
        f32 StickLeftXNormalized = 0, StickLeftYNormalized = 0;
        f32 StickRightXNormalized = 0, StickRightYNormalized = 0;
        u32 MagnitudeLeft = 0, MagnitudeRight = 0;
        f32 MagnitudeLeftNormalized = 0, MagnitudeRightNormalized = 0;
        u8 TriggerLeft = 0;
        u8 TriggerRight = 0;
        b32 ThereWasALeftTriggerEvent = false, ThereWasARightTriggerEvent = false;
        b32 ThereWasALeftThumbstickEvent = false, ThereWasARightThumbstickEvent = false;
        //u8 ControllerNumber; // TODO(hayden): Unsupported currently

        tiny_event Event;
        while(Tiny_GetMessage(Platform, &Event)) // NOTE(hayden): Does NOT clear event queue
        {
            if(Event.Type == TINY_EVENT_TYPE_KEYBOARD)
            {
                KeyboardButtonState[Event.Keyboard.KeyType] = Event.Keyboard.KeyIsDown;
            }
            else if(Event.Type == TINY_EVENT_TYPE_MOUSE)
            {
                if(Event.Mouse.InputType == TINY_INPUT_TYPE_BUTTON)
                {
                    MouseButtonState[Event.Mouse.Button] = Event.Mouse.ButtonIsDown;
                }
                else if(Event.Mouse.InputType == TINY_INPUT_TYPE_SCROLL_WHEEL)
                {
                    MouseWheelDelta += Event.Mouse.WheelDelta;
                }
                else if(Event.Mouse.InputType == TINY_INPUT_TYPE_MOVE)
                {
                    MouseX = Event.Mouse.X;
                    MouseY = Event.Mouse.Y;
                    ThereWasAMouseMoveEvent = true;
                }
            }
            else if(Event.Type == TINY_EVENT_TYPE_CONTROLLER)
            {
                if(Event.Controller.InputType == TINY_INPUT_TYPE_BUTTON)
                {
                    ControllerButtonState[Event.Controller.Button] = Event.Controller.ButtonIsDown;
                }
                else if(Event.Controller.InputType == TINY_INPUT_TYPE_TRIGGER)
                {
                    if(Event.Controller.Button == CONTROLLER_TRIGGER_LEFT)
                    {
                        TriggerLeft = Event.Controller.Trigger;
                        ThereWasALeftTriggerEvent = true;
                    }
                    else if(Event.Controller.Button == CONTROLLER_TRIGGER_RIGHT)
                    {
                        TriggerRight = Event.Controller.Trigger;
                        ThereWasARightTriggerEvent = true;
                    }
                }
                else if(Event.Controller.InputType == TINY_INPUT_TYPE_THUMBSTICK)
                {
                    if(Event.Controller.Button == CONTROLLER_THUMBSTICK_LEFT)
                    {
                        StickLeftX = Event.Controller.DeadzonedX;
                        StickLeftY = Event.Controller.DeadzonedY;
                        StickLeftXNormalized = Event.Controller.DeadzonedXNormalized;
                        StickLeftYNormalized = Event.Controller.DeadzonedYNormalized;
                        MagnitudeLeft = Event.Controller.Magnitude;
                        MagnitudeLeftNormalized = Event.Controller.MagnitudeNormalized;
                        ThereWasALeftThumbstickEvent = true;
                    }
                    else if(Event.Controller.Button == CONTROLLER_THUMBSTICK_RIGHT)
                    {
                        StickRightX = Event.Controller.DeadzonedX;
                        StickRightY = Event.Controller.DeadzonedY;
                        StickRightXNormalized = Event.Controller.DeadzonedXNormalized;
                        StickRightYNormalized = Event.Controller.DeadzonedYNormalized;
                        MagnitudeRight = Event.Controller.Magnitude;
                        MagnitudeRightNormalized = Event.Controller.MagnitudeNormalized;
                        ThereWasARightThumbstickEvent = true;
                    }
                }
            }
            else
            {
                Assert(!"Unhandled message!");
            }
        }

        // Update Keyboard based on KeyboardState
        for(int InputIndex = 0; InputIndex < KEY_COUNT; ++InputIndex)
        {
            Tiny_ProcessDigitalButton(&TinyInternalKeyboard.A + InputIndex, KeyboardButtonState[InputIndex]);
        }

        // Update Mouse
        {
            // Update Mouse based on MouseButtonState
            Tiny_ProcessDigitalButton(&TinyInternalMouse.Left,   MouseButtonState[MOUSE_LEFT]);
            Tiny_ProcessDigitalButton(&TinyInternalMouse.Middle, MouseButtonState[MOUSE_MIDDLE]);
            Tiny_ProcessDigitalButton(&TinyInternalMouse.Right,  MouseButtonState[MOUSE_RIGHT]);
            Tiny_ProcessDigitalButton(&TinyInternalMouse.Extra1, MouseButtonState[MOUSE_EXTRA1]);
            Tiny_ProcessDigitalButton(&TinyInternalMouse.Extra2, MouseButtonState[MOUSE_EXTRA2]);

            TinyInternalMouse.WheelDelta = MouseWheelDelta;

            // TODO(hayden): What should Mouse.X and Mouse.Y be if the mouse isn't on the screen?
            // NOTE(hayden): Mouse.X and Mouse.Y persist across frames unless the location is updated
            if(ThereWasAMouseMoveEvent)
            {
                TinyInternalMouse.X = MouseX;
                TinyInternalMouse.Y = MouseY;
            }

            // TODO(hayden): Normalized mouse input
        }

        // Update Controller
        {
            Tiny_ProcessDigitalButton(&TinyInternalController.Up,               ControllerButtonState[CONTROLLER_BUTTON_UP]);
            Tiny_ProcessDigitalButton(&TinyInternalController.Down,             ControllerButtonState[CONTROLLER_BUTTON_DOWN]);
            Tiny_ProcessDigitalButton(&TinyInternalController.Left,             ControllerButtonState[CONTROLLER_BUTTON_LEFT]);
            Tiny_ProcessDigitalButton(&TinyInternalController.Right,            ControllerButtonState[CONTROLLER_BUTTON_RIGHT]);
            Tiny_ProcessDigitalButton(&TinyInternalController.A,                ControllerButtonState[CONTROLLER_BUTTON_A]);
            Tiny_ProcessDigitalButton(&TinyInternalController.B,                ControllerButtonState[CONTROLLER_BUTTON_B]);
            Tiny_ProcessDigitalButton(&TinyInternalController.X,                ControllerButtonState[CONTROLLER_BUTTON_X]);
            Tiny_ProcessDigitalButton(&TinyInternalController.Y,                ControllerButtonState[CONTROLLER_BUTTON_Y]);
            Tiny_ProcessDigitalButton(&TinyInternalController.Start,            ControllerButtonState[CONTROLLER_BUTTON_START]);
            Tiny_ProcessDigitalButton(&TinyInternalController.Back,             ControllerButtonState[CONTROLLER_BUTTON_BACK]);
            Tiny_ProcessDigitalButton(&TinyInternalController.ThumbButtonLeft,  ControllerButtonState[CONTROLLER_BUTTON_THUMB_LEFT]);
            Tiny_ProcessDigitalButton(&TinyInternalController.ThumbButtonRight, ControllerButtonState[CONTROLLER_BUTTON_THUMB_RIGHT]);
            Tiny_ProcessDigitalButton(&TinyInternalController.BumperLeft,       ControllerButtonState[CONTROLLER_BUTTON_BUMPER_LEFT]);
            Tiny_ProcessDigitalButton(&TinyInternalController.BumperRight,      ControllerButtonState[CONTROLLER_BUTTON_BUMPER_RIGHT]);

            if(ThereWasALeftTriggerEvent)  { TinyInternalController.TriggerLeft  = TriggerLeft; }
            if(ThereWasARightTriggerEvent) { TinyInternalController.TriggerRight = TriggerRight; }

            if(ThereWasALeftThumbstickEvent)
            {
                TinyInternalController.StickLeftX = StickLeftX;
                TinyInternalController.StickLeftY = StickLeftY;
                TinyInternalController.StickLeftXNormalized = StickLeftXNormalized;
                TinyInternalController.StickLeftYNormalized = StickLeftYNormalized;
                TinyInternalController.MagnitudeLeft = MagnitudeLeft;
                TinyInternalController.MagnitudeLeftNormalized = MagnitudeLeftNormalized;
            }

            if(ThereWasARightThumbstickEvent)
            {
                TinyInternalController.StickRightX = StickRightX;
                TinyInternalController.StickRightY = StickRightY;
                TinyInternalController.StickRightXNormalized = StickRightXNormalized;
                TinyInternalController.StickRightYNormalized = StickRightYNormalized;
                TinyInternalController.MagnitudeRight = MagnitudeRight;
                TinyInternalController.MagnitudeRightNormalized = MagnitudeRightNormalized;
            }
        }
    }

    // GAME *****************/
    Tiny_GameUpdate(Platform);
    Tiny_GameRender();
    /************************/
}

static void
Tiny_Render()
{
    // Nothing happens! D:
}