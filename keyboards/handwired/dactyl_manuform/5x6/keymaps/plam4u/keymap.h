#pragma once

#include QMK_KEYBOARD_H

uint8_t mod_state;
uint8_t oneshot_mod_state;

enum layer_names {
    _QWERTY,
    _SYM_NAV,
    _NUMPAD,
    _ADJUST,
};

// Layer keys
#define NUM_ESC LT(_NUMPAD, KC_ESC)
#define NAV_BSPC LT(_SYM_NAV, KC_BSPC)
#define SYM_NAV MO(_SYM_NAV)
#define ADJUST MO(_ADJUST)

#ifdef MOUSEKEY_ENABLE
#    define MOUSE MO(_MOUSE)
#    define MS_CAPS LT(_MOUSE, KC_CAPS)
#else
#    define MOUSE KC_TRNS
#    define MS_CAPS KC_CAPS
#endif

#ifdef STENO_ENABLE
#    define PLOVER TG(_PLOVER)
#else
#    define PLOVER KC_TRNS
#endif


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

// Miscellaneous
#define CUT LCMD(KC_X)
#define COPY LCMD(KC_C)
#define PASTE LCMD(KC_V)
#define PBRD LSG(KC_C)
#define UNDO LCMD(KC_Z)
#define REDO LSG(KC_Z)
#define ALFRED G(KC_SPC)

// One Shot Modifiers
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_LALT)
#define OS_LCMD OSM(MOD_LGUI)
#define OS_RCMD OSM(MOD_RGUI)

// macOS spaces navigation
#define SPACE_L MEH_T(KC_F17)
#define SPACE_R HYPR_T(KC_F16)

#define CTL_Z CTL_T(KC_Z)
#define CTL_SL RCTL_T(KC_SLSH)
#define CM_LBRC RSG(KC_LBRC)
#define CM_RBRC RSG(KC_RBRC)
#define TAB_ALT ALT_T(KC_TAB)
#define ESC_CMD CMD_T(KC_ESC)
#define SPC_SFT LSFT_T(KC_SPC) 
#define ENT_SFT RSFT_T(KC_ENT) 

// Tap Dance
#ifdef TAP_DANCE_ENABLE
enum {
    DOT_TD = 0,
};

#define TD_DOT TD(DOT_TD)
#else
#define TD_DOT KC_DOT
#endif

