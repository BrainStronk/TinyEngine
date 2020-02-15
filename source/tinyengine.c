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

b32 KeyboardState[TINY_EVENT_MAX_KEYS]; // NOTE: true == IsDown
tiny_digital_button Keyboard[TINY_EVENT_MAX_KEYS];

static void
Tiny_Update(tiny_platform *Platform)
{
    // TODO(hayden): Normalize mouse input here?

    { // Update input events
        // Update KeyboardState with new events
        for(int EventIndex = 0; EventIndex < Platform->EventQueueIndex; ++EventIndex)
        {
            if(Platform->EventQueue[EventIndex].Type == TINY_EVENT_TYPE_KEYBOARD)
            {
                KeyboardState[Platform->EventQueue[EventIndex].Keyboard.KeyType] = Platform->EventQueue[EventIndex].Keyboard.IsDown;
            }
        }

        // Update Keyboard based on KeyboardState
        for(int InputIndex = 0; InputIndex < TINY_EVENT_MAX_KEYS; ++InputIndex)
        {
            Tiny_ProcessDigitalButton(&Keyboard[InputIndex], KeyboardState[InputIndex]);
        }

        // Clear event queue
        for(int ClearIndex = 0; ClearIndex < Global_Platform.EventQueueIndex; ++ClearIndex)
        {
            // TODO(hayden): Set everything to TINY_EVENT_NO_INPUT?
            tiny_event NoEvent = {TINY_EVENT_NO_INPUT};
            Global_Platform.EventQueue[ClearIndex] = NoEvent;
        }
        Global_Platform.EventQueueIndex = 0;
    }
}

static void
Tiny_Render()
{
    // Nothing happens! D:
}