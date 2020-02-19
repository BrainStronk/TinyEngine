#include "tinyengine.h"

static void
Tiny_PushInputEvent(tiny_event Event)
{
    Global_Platform.EventQueue[Global_Platform.EventQueueIndex] = Event;
    ++Global_Platform.EventQueueIndex;
}

static void
Tiny_ProcessDigitalButton(tiny_digital_button *Button, b32 WasDown)
{
    // TODO(hayden): Avoid wrapping Up/Down?
    Button->Down = WasDown ? ++Button->Down : false;
    Button->Up = !WasDown ? ++Button->Up : false;
    Button->Pressed = (Button->Down == 1);
    Button->Released = (Button->Up == 1);
}

inline b32
Tiny_GetMessage(tiny_platform *Platform, tiny_event *Event)
{
    static s32 CountUpToEventQueueIndex = 0;

    // Copy event over
    *Event = Platform->EventQueue[Platform->EventQueueIndex];

    // Copy over event type as boolean value (will always be > 0 if there is an event)
    b32 State = Event->Type;

    // First In, First Out
    if(CountUpToEventQueueIndex > Platform->EventQueueIndex)
    {
        Platform->EventQueueIndex = 0;
        CountUpToEventQueueIndex = 0;
        State = false; // Do not handle this event
    }
    else
    {
        ++CountUpToEventQueueIndex;
    }

    return(State);
}

b32 KeyboardButtonState[KEY_COUNT];
tiny_digital_button Keyboard[KEY_COUNT];
b32 MouseButtonState[MOUSE_COUNT];
tiny_digital_button Mouse[MOUSE_COUNT];

static void
Tiny_Update(tiny_platform *Platform)
{
    // TODO(hayden): Normalize mouse input here?

    { // Update input events
        // Update KeyboardState/MouseButtonState with new events
        tiny_event Event;
        while(Tiny_GetMessage(Platform, &Event))
        {
            if(Event.Type == TINY_EVENT_TYPE_KEYBOARD)
            {
                KeyboardButtonState[Event.Keyboard.KeyType] = Event.Keyboard.IsDown;
            }
            else if(Event.Type == TINY_EVENT_TYPE_MOUSE)
            {
                if(Event.Mouse.Type == TINY_EVENT_MOUSE_CLICK)
                {
                    MouseButtonState[Event.Mouse.Button] = Event.Mouse.IsDown;
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
        Win32PrintDebugString("%d\n", Keyboard[KEY_A].Pressed);
    }
}

static void
Tiny_Render()
{
    // Nothing happens! D:
}