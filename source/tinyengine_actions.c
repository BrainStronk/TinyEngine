static void
TinyActions_Update(tiny_action *TinyAction, int ActionsArraySize)
{
    for(int ActionIndex = 0; ActionIndex < ActionsArraySize; ++ActionIndex)
    {
        // TODO(hayden): Add other input methods once they are supported!
        b32 KeyboardButtonIsDown = false;
        b32 MouseButtonIsDown = false;
        b32 ControllerButtonIsDown = false;
        s32 X, Y;
        f32 NormalizedX, NormalizedY;
        s32 Value;

        tiny_action *Action = &TinyAction[ActionIndex];

        // Keyboard
        if(Action->KeyboardBinding)
        {
            KeyboardButtonIsDown = (*(&TinyInternalKeyboard.A + (Action->KeyboardBinding - 1))).Down; // NOTE(hayden): "- 1" because enums start at 1
        }
        
        // Mouse
        if(Action->MouseBinding)
        {
            MouseButtonIsDown = (*(&TinyInternalMouse.Left + (Action->MouseBinding - 1))).Down; // NOTE(hayden): "- 1" because enums start at 1
            X = (s32)TinyInternalMouse.X;
            Y = (s32)TinyInternalMouse.Y;
            NormalizedX = TinyInternalMouse.XNormalized;
            NormalizedY = TinyInternalMouse.YNormalized;
            if(Action->MouseBinding == MOUSE_MIDDLE)
            { 
                Value = TinyInternalMouse.WheelDelta;
            }
        }

        // Controller
        if(Action->ControllerBinding >= CONTROLLER_BUTTON_UP && Action->ControllerBinding <= CONTROLLER_BUTTON_BUMPER_RIGHT)
        {
            // Button Event
            ControllerButtonIsDown = (*(&TinyInternalController.Up + (Action->ControllerBinding - 1))).Down; // NOTE(hayden): "- 1" because enums start at 1
        }
        else if(Action->ControllerBinding == CONTROLLER_TRIGGER_LEFT || Action->ControllerBinding == CONTROLLER_TRIGGER_RIGHT)
        {
            // Trigger Event
            Value = (Action->ControllerBinding == CONTROLLER_TRIGGER_LEFT) ? TinyInternalController.TriggerLeft : TinyInternalController.TriggerRight;
        }
        else if(Action->ControllerBinding == CONTROLLER_THUMBSTICK_LEFT || Action->ControllerBinding == CONTROLLER_THUMBSTICK_RIGHT)
        {
            // Thumbstick Event
            X = (Action->ControllerBinding == CONTROLLER_THUMBSTICK_LEFT) ? TinyInternalController.StickLeftX : TinyInternalController.StickRightX;
            Y = (Action->ControllerBinding == CONTROLLER_THUMBSTICK_LEFT) ? TinyInternalController.StickLeftY : TinyInternalController.StickRightY;
            NormalizedX = (Action->ControllerBinding == CONTROLLER_THUMBSTICK_LEFT) ? TinyInternalController.StickLeftXNormalized : TinyInternalController.StickRightXNormalized;
            NormalizedY = (Action->ControllerBinding == CONTROLLER_THUMBSTICK_LEFT) ? TinyInternalController.StickLeftYNormalized : TinyInternalController.StickRightYNormalized;
        }

        b32 IsDown = KeyboardButtonIsDown || MouseButtonIsDown || ControllerButtonIsDown;
        Action->Pressed = IsDown && !Action->Down;
        Action->Released = !IsDown && Action->Down;
        Action->Down = IsDown ? ++Action->Down : 0;
        Action->Up = !IsDown ? ++Action->Up : 0;
    }
}