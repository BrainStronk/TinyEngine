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

b32 KeyboardButtonState[KEY_COUNT];
tiny_digital_button Keyboard[KEY_COUNT];
b32 MouseButtonState[MOUSE_COUNT];
tiny_digital_button Mouse[MOUSE_COUNT];
b32 ControllerButtonState[CONTROLLER_COUNT];
tiny_digital_button Controller[CONTROLLER_COUNT];

#include "game.c"

static void
Tiny_Update(tiny_platform *Platform)
{
    // TODO(hayden): Normalize mouse input here?

    // Flatten state NOTE(hayden): Does NOT clear event queue
    tiny_event Event;
    while(Tiny_GetMessage(Platform, &Event))
    {
        if(Event.Type == TINY_EVENT_TYPE_KEYBOARD)
        {
            KeyboardButtonState[Event.Keyboard.KeyType] = Event.Keyboard.KeyIsDown;
        }
        else if(Event.Type == TINY_EVENT_TYPE_MOUSE)
        {
            if(Event.Mouse.InputType == TINY_EVENT_INPUT_TYPE_CLICK)
            {
                MouseButtonState[Event.Mouse.Button] = Event.Mouse.ButtonIsDown;
            }
        }
        else if(Event.Type == TINY_EVENT_TYPE_CONTROLLER)
        {
            if(Event.Controller.InputType == TINY_EVENT_INPUT_TYPE_BUTTON)
            {
                ControllerButtonState[Event.Controller.Button] = Event.Controller.ButtonIsDown;
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
        Tiny_ProcessDigitalButton(&Keyboard[InputIndex], KeyboardButtonState[InputIndex]);
    }

    // Update Mouse based on MouseButtonState
    for(int InputIndex = 0; InputIndex < MOUSE_COUNT; ++InputIndex)
    {
        Tiny_ProcessDigitalButton(&Mouse[InputIndex], MouseButtonState[InputIndex]);
    }

    Tiny_GameUpdate(Platform);
    Tiny_GameRender();

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
Tiny_Render()
{
    // Nothing happens! D:
}