#include "tinyengine_platform.h"

static void
Tiny_ProcessDigitalButton(tiny_digital_button *Button, b32 WasDown)
{
    // TODO(hayden): Avoid wrapping Up/Down?
    Button->Down = WasDown ? ++Button->Down : false;
    Button->Up = !WasDown ? ++Button->Up : false;
    Button->Pressed = (Button->Down == 1);
    Button->Released = (Button->Up == 1);
}

static b32
Tiny_GetMessage(tiny_platform *Platform, tiny_event *Event)
{
    b32 HasRemainingData;
    static s32 CountUpToEventQueueIndex = 0;

    // Copy event over
    *Event = Platform->EventQueue[Platform->EventQueueIndex];
    
    // Clear the Platform's event
    Platform->EventQueue[Platform->EventQueueIndex] = (tiny_event){0};

    // If the event has a Type, assume there is remaining data
    HasRemainingData = Event->Type;

    // First In, First Out
    if(CountUpToEventQueueIndex == Platform->EventQueueIndex)
    {
        Platform->EventQueueIndex = 0;
        CountUpToEventQueueIndex = 0;
    }
    else
    {
        ++CountUpToEventQueueIndex;
    }

    return(HasRemainingData);
}

b32 KeyboardButtonState[KEY_COUNT]; // NOTE: true == IsDown
tiny_digital_button Keyboard[KEY_COUNT];
b32 MouseButtonState[MOUSE_COUNT]; // NOTE: true == IsDown
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
    }
}

static void
Tiny_Render()
{
    // Nothing happens! D:
}