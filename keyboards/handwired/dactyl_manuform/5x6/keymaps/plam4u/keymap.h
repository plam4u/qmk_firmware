#pragma once
#include QMK_KEYBOARD_H

// Layer keys
#define ESC_LW1 LT(_LOWER1, KC_ESC)
#define BSP_RS1 LT(_RAISE1, KC_BSPC)
#define BOTH1 MO(_BOTH1)

// One Shot Modifiers
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_LALT)
#define OS_LCMD OSM(MOD_LGUI)
#define OS_RCMD OSM(MOD_RGUI)

// Miscellaneous
#define CUT LCMD(KC_X)
#define COPY LCMD(KC_C)
#define PASTE LCMD(KC_V)
#define PBRD LSG(KC_C)
#define UNDO LCMD(KC_Z)
#define REDO LSG(KC_Z)
#define ALFRED G(KC_SPC)

// macOS spaces navigation
#define SPACE_L MEH_T(KC_F17)
#define SPACE_R HYPR_T(KC_F16)

// Combinations
#define CTL_Z CTL_T(KC_Z)
#define CTL_SL RCTL_T(KC_SLSH)
#define CM_LBRC RSG(KC_LBRC)
#define CM_RBRC RSG(KC_RBRC)
#define TAB_ALT ALT_T(KC_TAB)
#define TAB_CMD CMD_T(KC_TAB)
#define TAB_SFT SFT_T(KC_TAB)
#define TAB_CTL CTL_T(KC_TAB)
#define ESC_CMD CMD_T(KC_ESC)
#define ESC_MEH MEH_T(KC_ESC)
#define ENT_HPR HYPR_T(KC_ENT)
#define SPC_SFT LSFT_T(KC_SPC) 
#define ENT_SFT RSFT_T(KC_ENT) 

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)

// Mouse
#ifdef MOUSEKEY_ENABLE
#    define MOUSE MO(_MOUSE)
#    define MS_CAPS LT(_MOUSE, KC_CAPS)
#else
#    define MOUSE KC_TRNS
#    define MS_CAPS KC_CAPS
#endif

// Steno
#ifdef STENO_ENABLE
#    define PLOVER TG(_PLOVER)
#else
#    define PLOVER KC_TRNS
#endif

