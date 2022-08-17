#pragma once

// taken from GLFW
enum KeyCodes
{
    /* The unknown key */
    VK_KEY_UNKNOWN =            -1,

    /* Printable keys */
    VK_KEY_SPACE =              32,
    VK_KEY_APOSTROPHE =         39,  /* ' */
    VK_KEY_COMMA =              44,  /* , */
    VK_KEY_MINUS =              45,  /* - */
    VK_KEY_PERIOD =             46,  /* . */
    VK_KEY_SLASH =              47,  /* / */
    VK_KEY_0 =                  48,
    VK_KEY_1 =                  49,
    VK_KEY_2 =                  50,
    VK_KEY_3 =                  51,
    VK_KEY_4 =                  52,
    VK_KEY_5 =                  53,
    VK_KEY_6 =                  54,
    VK_KEY_7 =                  55,
    VK_KEY_8 =                  56,
    VK_KEY_9 =                  57,
    VK_KEY_SEMICOLON =          59,  /* ; */
    VK_KEY_EQUAL =              61,  /* = */
    VK_KEY_A =                  65,
    VK_KEY_B =                  66,
    VK_KEY_C =                  67,
    VK_KEY_D =                  68,
    VK_KEY_E =                  69,
    VK_KEY_F =                  70,
    VK_KEY_G =                  71,
    VK_KEY_H =                  72,
    VK_KEY_I =                  73,
    VK_KEY_J =                  74,
    VK_KEY_K =                  75,
    VK_KEY_L =                  76,
    VK_KEY_M =                  77,
    VK_KEY_N =                  78,
    VK_KEY_O =                  79,
    VK_KEY_P =                  80,
    VK_KEY_Q =                  81,
    VK_KEY_R =                  82,
    VK_KEY_S =                  83,
    VK_KEY_T =                  84,
    VK_KEY_U =                  85,
    VK_KEY_V =                  86,
    VK_KEY_W =                  87,
    VK_KEY_X =                  88,
    VK_KEY_Y =                  89,
    VK_KEY_Z =                  90,
    VK_KEY_LEFT_BRACKET =       91,  /* [ */
    VK_KEY_BACKSLASH =          92,  /* \ */
    VK_KEY_RIGHT_BRACKET =      93,  /* ] */
    VK_KEY_GRAVE_ACCENT =       96,  /* ` */
    VK_KEY_WORLD_1 =            161, /* non-US #1 */
    VK_KEY_WORLD_2 =            162, /* non-US #2 */

/* Function keys */
    VK_KEY_ESCAPE =             256,
    VK_KEY_ENTER =              257,
    VK_KEY_TAB =                258,
    VK_KEY_BACKSPACE =          259,
    VK_KEY_INSERT =             260,
    VK_KEY_DELETE =             261,
    VK_KEY_RIGHT =              262,
    VK_KEY_LEFT =               263,
    VK_KEY_DOWN =               264,
    VK_KEY_UP =                 265,
    VK_KEY_PAGE_UP =            266,
    VK_KEY_PAGE_DOWN =          267,
    VK_KEY_HOME =               268,
    VK_KEY_END =                269,
    VK_KEY_CAPS_LOCK =          280,
    VK_KEY_SCROLL_LOCK =        281,
    VK_KEY_NUM_LOCK =           282,
    VK_KEY_PRINT_SCREEN =       283,
    VK_KEY_PAUSE =              284,
    VK_KEY_F1 =                 290,
    VK_KEY_F2 =                 291,
    VK_KEY_F3 =                 292,
    VK_KEY_F4 =                 293,
    VK_KEY_F5 =                 294,
    VK_KEY_F6 =                 295,
    VK_KEY_F7 =                 296,
    VK_KEY_F8 =                 297,
    VK_KEY_F9 =                 298,
    VK_KEY_F10 =                299,
    VK_KEY_F11 =                300,
    VK_KEY_F12 =                301,
    VK_KEY_F13 =                302,
    VK_KEY_F14 =                303,
    VK_KEY_F15 =                304,
    VK_KEY_F16 =                305,
    VK_KEY_F17 =                306,
    VK_KEY_F18 =                307,
    VK_KEY_F19 =                308,
    VK_KEY_F20 =                309,
    VK_KEY_F21 =                310,
    VK_KEY_F22 =                311,
    VK_KEY_F23 =                312,
    VK_KEY_F24 =                313,
    VK_KEY_F25 =                314,
    VK_KEY_KP_0 =               320,
    VK_KEY_KP_1 =               321,
    VK_KEY_KP_2 =               322,
    VK_KEY_KP_3 =               323,
    VK_KEY_KP_4 =               324,
    VK_KEY_KP_5 =               325,
    VK_KEY_KP_6 =               326,
    VK_KEY_KP_7 =               327,
    VK_KEY_KP_8 =               328,
    VK_KEY_KP_9 =               329,
    VK_KEY_KP_DECIMAL =         330,
    VK_KEY_KP_DIVIDE =          331,
    VK_KEY_KP_MULTIPLY =        332,
    VK_KEY_KP_SUBTRACT =        333,
    VK_KEY_KP_ADD =             334,
    VK_KEY_KP_ENTER =           335,
    VK_KEY_KP_EQUAL =           336,
    VK_KEY_LEFT_SHIFT =         340,
    VK_KEY_LEFT_CONTROL =       341,
    VK_KEY_LEFT_ALT =           342,
    VK_KEY_LEFT_SUPER =         343,
    VK_KEY_RIGHT_SHIFT =        344,
    VK_KEY_RIGHT_CONTROL =      345,
    VK_KEY_RIGHT_ALT =          346,
    VK_KEY_RIGHT_SUPER =        347,
    VK_KEY_MENU =               348,

    VK_KEY_LAST =               VK_KEY_MENU,
};

// taken from GLFW
enum mouseCodes
{
    VK_MOUSE_BUTTON_1 =         0,
    VK_MOUSE_BUTTON_2 =         1,
    VK_MOUSE_BUTTON_3 =         2,
    VK_MOUSE_BUTTON_4 =         3,
    VK_MOUSE_BUTTON_5 =         4,
    VK_MOUSE_BUTTON_6 =         5,
    VK_MOUSE_BUTTON_7 =         6,
    VK_MOUSE_BUTTON_8 =         7,
    VK_MOUSE_BUTTON_LAST =      VK_MOUSE_BUTTON_8,
    VK_MOUSE_BUTTON_LEFT =      VK_MOUSE_BUTTON_1,
    VK_MOUSE_BUTTON_RIGHT =     VK_MOUSE_BUTTON_2,
    VK_MOUSE_BUTTON_MIDDLE =    VK_MOUSE_BUTTON_3,
};