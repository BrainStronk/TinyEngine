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

static void
Tiny_ClearEventQueue(void)
{
    for(int ClearIndex = 0; ClearIndex < Global_Platform.EventQueueIndex; ++ClearIndex)
    {
        // TODO(hayden): Set everything to TINY_EVENT_NO_INPUT?
        tiny_event NoEvent = {0};
        Global_Platform.EventQueue[ClearIndex] = NoEvent;
    }
    Global_Platform.EventQueueIndex = 0;
}

static b32
Tiny_GetMessage(tiny_platform *Platform, tiny_event *Event)
{
    b32 HasRemainingData;

    // Copy event over
    *Event = Platform->EventQueue[Platform->EventQueueIndex];
    
    // Clear the Platform's event
    Platform->EventQueue[Platform->EventQueueIndex] = (tiny_event){0};

    // If the event has a Type, assume there is remaining data
    HasRemainingData = Event->Type;

    // Decrement EventQueueIndex for next time
    --Platform->EventQueueIndex;

    return(HasRemainingData);
}

b32 KeyboardState[TINY_EVENT_MAX_KEYS]; // NOTE: true == IsDown
tiny_digital_button Keyboard[TINY_EVENT_MAX_KEYS];

static void
Tiny_Update(tiny_platform *Platform)
{
    // TODO(hayden): Normalize mouse input here?

    { // Update input events
        // Update KeyboardState with new events
        tiny_event Event;
        while(Tiny_GetMessage(Platform, &Event)) // TODO(hayden): fix
        {
            if(Event.Type == TINY_EVENT_TYPE_KEYBOARD)
            {
                KeyboardState[Event.Keyboard.KeyType] = Event.Keyboard.IsDown;
            }
            else if(Event.Type == TINY_EVENT_TYPE_MOUSE)
            {
                // TODO(hayden): Mouse!
            }
        }

        // Update Keyboard based on KeyboardState
        for(int InputIndex = 0; InputIndex < TINY_EVENT_MAX_KEYS; ++InputIndex)
        {
            Tiny_ProcessDigitalButton(&Keyboard[InputIndex], KeyboardState[InputIndex]);
        }
    }
}

static void
Tiny_Render()
{
    // Nothing happens! D:
}