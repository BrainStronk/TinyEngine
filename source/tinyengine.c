static void
Tiny_PushInputEvent(tiny_event Event)
{
    Global_Platform.EventQueue[Global_Platform.EventQueueIndex] = Event;
    ++Global_Platform.EventQueueIndex;
}

// TODO(hayden): This might be useless/redundant now? Can this be skipped to process directly in TinyInput_UpdateActions()?
static void
Tiny_ProcessDigitalButton(tiny_digital_button *Button, b32 WasDown)
{
    // TODO(hayden): Avoid wrapping Up/Down?
    Button->Down = WasDown ? ++Button->Down : false; // TODO(hayden): This is also handled in TinyInput_UpdateActions() -- should it be removed here?
    Button->Up = !WasDown ? ++Button->Up : false; // TODO(hayden): This is also handled in TinyInput_UpdateActions() -- should it be removed here?
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
        State = 0; // Do not handle this event
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

tiny_action Actions[10]; // TODO(hayden): Example usage code -- Remove later!!!

static void
TinyInput_UpdateActions(tiny_action *Actions, int ActionsArraySize)
{
    for(int ActionIndex = 0; ActionIndex < ActionsArraySize; ++ActionIndex)
    {
        // TODO(hayden): Add other input methods once they are supported!

        tiny_action *Action = &Actions[ActionIndex];
        Action->Pressed = Keyboard[Action->KeyBinding].Pressed | Mouse[Action->MouseBinding].Pressed;
        Action->Released = Keyboard[Action->KeyBinding].Released | Mouse[Action->MouseBinding].Released;

        Action->Down = (Keyboard[Action->KeyBinding].Down | Mouse[Action->MouseBinding].Down) ? ++Action->Down : 0;
        Action->Up = (Keyboard[Action->KeyBinding].Up | Mouse[Action->MouseBinding].Up) ? ++Action->Up : 0;
    }
}

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
        
        // TODO(hayden): Example usage code -- Remove later!!!
    //  {
            // Update based on user input
            Actions[MOVE_LEFT].String = "Move Left";
            Actions[MOVE_LEFT].KeyBinding = KEY_A;
            Actions[MOVE_LEFT].MouseBinding = MOUSE_LEFT;

            // Update user defined actions
            TinyInput_UpdateActions(Actions, ArrayCount(Actions));
    //  }
    }
}

static void
Tiny_Render()
{
    // Nothing happens! D:
}