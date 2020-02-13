#ifndef TINYENGINE_PLATFORM_H
#define TINYENGINE_PLATFORM_H

#define TE_EVENT_NO_INPUT -1
typedef enum te_event_type
{
    TE_EVENT_TYPE_KEYBOARD,
    TE_EVENT_TYPE_MOUSE,  
} te_event_type;

typedef enum te_event_mouse_button
{
    MOUSE_LEFT,
    MOUSE_MIDDLE,
    MOUSE_RIGHT,
    MOUSE_EXTRA1,
    MOUSE_EXTRA2,
} te_event_mouse_button;

// NOTE(hayden): The order here matters for calculations from KEY_0 to KEY_DOWN
typedef enum te_event_key_type
{
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

    KEY_A,
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
} te_event_key_type;

typedef struct te_event_keyboard
{
    te_event_key_type KeyType;
    b32 IsDown;
} te_event_keyboard;

// TODO(hayden): Preface with TE_EVENT or not?
typedef enum te_event_mouse_event_type
{
    TE_EVENT_MOUSE_MOVE,
    TE_EVENT_MOUSE_CLICK,
} te_event_mouse_event_type;

typedef struct te_event_mouse
{
    te_event_mouse_event_type Type;
    u32 X, Y;
    s16 WheelDelta;
    f32 NormalizedX, NormalizedY;
    te_event_mouse_button Button;
    b32 IsDown;
} te_event_mouse;

typedef struct te_event
{
    te_event_type Type;
    union
    {
        struct { te_event_keyboard Keyboard; };
        struct { te_event_mouse Mouse; };
    };
} te_event;

typedef struct tiny_platform_audio
{
    u32 ChannelCount;
    u32 SampleRate;
    s32 SampleCount;
    
    void *Buffer;
} tiny_platform_audio;

#endif // TINYENGINE_PLATFORM_H