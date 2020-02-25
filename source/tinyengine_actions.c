static void
TinyActions_Update(tiny_action *Actions, int ActionsArraySize)
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