#ifndef TINYENGINE_PLATFORM_H
#define TINYENGINE_PLATFORM_H

// E V E N T /////////////////////////////////////////////////////////////////////

typedef enum tiny_event_type
{
    TINY_EVENT_TYPE_KEYBOARD = 1, // NOTE(hayden): Starts at 1 so that 0 can represent no input
    TINY_EVENT_TYPE_MOUSE,  
    TINY_EVENT_TYPE_CONTROLLER,
} tiny_event_type;

typedef enum tiny_event_input_type
{
    TINY_EVENT_INPUT_TYPE_BUTTON = 1,
    TINY_EVENT_INPUT_TYPE_MOVE,
    TINY_EVENT_INPUT_TYPE_CLICK,
    TINY_EVENT_INPUT_TYPE_THUMBSTICK,
    TINY_EVENT_INPUT_TYPE_SHOULDER,
} tiny_event_input_type;

// M O U S E /////////////////////////////////////////////////////////////////////

typedef enum tiny_event_mouse_enum
{
    MOUSE_LEFT = 1,
    MOUSE_MIDDLE,
    MOUSE_RIGHT,
    MOUSE_EXTRA1,
    MOUSE_EXTRA2,

    MOUSE_COUNT,
} tiny_event_mouse_enum;

typedef struct tiny_event_mouse
{
    tiny_event_input_type InputType;
    u32 X, Y;
    s16 WheelDelta;
    f32 NormalizedX, NormalizedY;
    tiny_event_mouse_enum Button;
    b32 ButtonIsDown;
} tiny_event_mouse;

// C O N T R O L L E R ///////////////////////////////////////////////////////////

typedef enum tiny_event_controller_enum
{
    CONTROLLER_BUTTON_UP = 1,
    CONTROLLER_BUTTON_DOWN,
    CONTROLLER_BUTTON_LEFT,
    CONTROLLER_BUTTON_RIGHT,
    CONTROLLER_BUTTON_A,
    CONTROLLER_BUTTON_B,
    CONTROLLER_BUTTON_X,
    CONTROLLER_BUTTON_Y,
    CONTROLLER_BUTTON_START,
    CONTROLLER_BUTTON_BACK,

    CONTROLLER_THUMBSTICK_LEFT,
    CONTROLLER_THUMBSTICK_RIGHT,

    CONTROLLER_SHOULDER_LEFT,
    CONTROLLER_SHOULDER_RIGHT,

    CONTROLLER_COUNT,
} tiny_event_controller_enum;

typedef struct tiny_event_controller
{
    tiny_event_input_type InputType;
    tiny_event_controller_enum Button;
    b32 ButtonIsDown;
    s32 X, Y;
    u8 Trigger;
    u8 ControllerNumber;
} tiny_event_controller;

// K E Y B O A R D ///////////////////////////////////////////////////////////////

// NOTE(hayden): The order here matters for calculations from KEY_0 to KEY_DOWN
typedef enum tiny_event_keyboard_enum
{
    KEY_A = 1, // NOTE(hayden): Starts at 1 so that 0 can represent no input
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_E,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,
    KEY_K,
    KEY_L,
    KEY_M,
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,
    KEY_U,
    KEY_V,
    KEY_W,
    KEY_X,
    KEY_Y,
    KEY_Z,

    KEY_0,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,

    KEY_NUMPAD_0,
    KEY_NUMPAD_1,
    KEY_NUMPAD_2,
    KEY_NUMPAD_3,
    KEY_NUMPAD_4,
    KEY_NUMPAD_5,
    KEY_NUMPAD_6,
    KEY_NUMPAD_7,
    KEY_NUMPAD_8,
    KEY_NUMPAD_9,
    KEY_NUMPAD_MULTIPLY,
    KEY_NUMPAD_ADD,
    KEY_NUMPAD_SEPARATOR, // TODO(hayden): What is this? Seems to trigger if any numpad button is pressed..?
    KEY_NUMPAD_SUBTRACT,
    KEY_NUMPAD_DECIMAL,
    KEY_NUMPAD_DIVIDE,

    KEY_F1,
    KEY_F2,
    KEY_F3,
    KEY_F4,
    KEY_F5,
    KEY_F6,
    KEY_F7,
    KEY_F8,
    KEY_F9,
    KEY_F10,
    KEY_F11,
    KEY_F12,
    KEY_F13,
    KEY_F14,
    KEY_F15,
    KEY_F16,
    KEY_F17,
    KEY_F18,
    KEY_F19,
    KEY_F20,
    KEY_F21,
    KEY_F22,
    KEY_F23,
    KEY_F24,

    KEY_LEFT,
    KEY_UP,
    KEY_RIGHT,
    KEY_DOWN,

    KEY_BACKSPACE,
    KEY_TAB,
    KEY_RETURN,
    KEY_SPACE,
    KEY_LSHIFT,
    KEY_RSHIFT,
    KEY_LCONTROL,
    KEY_RCONTROL,
    KEY_LALT,
    KEY_RALT,
    KEY_LSUPER, // Windows Key
    KEY_RSUPER, // Windows Key
    KEY_CAPSLOCK,

    KEY_ESCAPE,
    KEY_PAGEUP,
    KEY_PAGEDOWN,
    KEY_HOME,
    KEY_END,
    KEY_INSERT,
    KEY_DELETE,
    KEY_PAUSE,
    KEY_NUMLOCK,
    KEY_SCROLLLOCK, // TODO(hayden): NOT WORKING!!!
    KEY_PRINTSCREEN,

    // TODO(hayden): Non-US/manufacturer-specific handling
    KEY_PLUS,
    KEY_COMMA,
    KEY_MINUS,
    KEY_SEMICOLON,
    KEY_OEM_1 = KEY_SEMICOLON,
    KEY_SLASH,
    KEY_OEM_2 = KEY_SLASH,
    KEY_GRAVE,
    KEY_OEM_3 = KEY_GRAVE,
    KEY_LBRACKET,
    KEY_OEM_4 = KEY_LBRACKET,
    KEY_RBRACKET,
    KEY_OEM_6 = KEY_RBRACKET,
    KEY_BACKSLASH,
    KEY_OEM_5 = KEY_BACKSLASH,
    KEY_QUOTE,
    KEY_OEM_7 = KEY_QUOTE,
    KEY_OEM_8,
    KEY_OEM_102,
    KEY_OEM_SPECIFIC1,
    KEY_OEM_SPECIFIC2,
    KEY_OEM_SPECIFIC3,
    KEY_OEM_CLEAR,

    // TODO(hayden): Most of these values are untested
    KEY_BROWSER_BACK,
    KEY_BROWSER_FORWARD,
    KEY_BROWSER_REFRESH,
    KEY_BROWSER_STOP,
    KEY_BROWSER_SEARCH,
    KEY_BROWSER_FAVORITES,
    KEY_BROWSER_HOME,

    KEY_VOLUME_MUTE,
    KEY_VOLUME_UP,
    KEY_VOLUME_DOWN,

    KEY_MEDIA_NEXT_TRACK,
    KEY_MEDIA_PREV_TRACK,
    KEY_MEDIA_STOP,
    KEY_MEDIA_PLAYPAUSE,

    KEY_LAUNCH_MAIL,
    KEY_LAUNCH_MEDIASELECT,
    KEY_LAUNCH_APPLICATION1,
    KEY_LAUNCH_APPLICATION2,

    KEY_HELP,
    KEY_MENU,
    KEY_PRINT,
    KEY_SELECT,
    KEY_EXEC, // TODO(hayden): KEY_EXECUTE was already defined somewhere... Undefine it or leave this as the only abbreviated key?
    KEY_APPLICATIONS,
    KEY_SLEEP,  

    // TODO(hayden): Where are VK_IME_* defined???
    KEY_IME_ON,
    KEY_IME_OFF,
    KEY_IME_MODECHANGE,
    KEY_IME_CONVERT,
    KEY_IME_NONCONVERT, 
    KEY_IME_ACCEPT,
    KEY_IME_PROCESS,

    KEY_MODE_KANA,
    KEY_MODE_HANGEUL = KEY_MODE_KANA,
    KEY_MODE_HANGUL = KEY_MODE_KANA,
    KEY_MODE_JUNJA,
    KEY_MODE_FINAL,
    KEY_MODE_HANJA,
    KEY_MODE_KANJI = KEY_MODE_HANJA,

    KEY_ATTN,
    KEY_CRSEL,
    KEY_EXSEL,
    KEY_EREOF,
    KEY_PLAY,
    KEY_ZOOM,
    KEY_NONAME,
    KEY_PA1,

    KEY_COUNT,
} tiny_event_keyboard_enum;

typedef struct tiny_event_keyboard
{
    tiny_event_keyboard_enum KeyType;
    b32 KeyIsDown;
} tiny_event_keyboard;

// T I N Y _ E V E N T ///////////////////////////////////////////////////////////

typedef struct tiny_digital_button
{
    b32 Pressed;
    b32 Released;
    b32 Up;
    b32 Down;
} tiny_digital_button;

typedef struct tiny_event
{
    tiny_event_type Type;
    union
    {
        struct { tiny_event_keyboard Keyboard; };
        struct { tiny_event_mouse Mouse; };
        struct { tiny_event_controller Controller; };
    };
} tiny_event;

// P L A T F O R M ///////////////////////////////////////////////////////////////

typedef struct tiny_platform_audio
{
    u32 ChannelCount;
    u32 SampleRate;
    s32 SampleCount;
    
    void *Buffer;
} tiny_platform_audio;

typedef struct tiny_platform
{
    tiny_event EventQueue[512];
    int EventQueueSize;
    b32 Quit;
} tiny_platform;

tiny_platform GlobalPlatform; // TODO(hayden): Is it better for this to be here or the platform-specific layer?

#endif // TINYENGINE_PLATFORM_H