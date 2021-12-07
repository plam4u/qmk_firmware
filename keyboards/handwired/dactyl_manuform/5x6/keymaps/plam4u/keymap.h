#pragma once
#include QMK_KEYBOARD_H

#ifdef TAP_DANCE_ENABLE
typedef enum {
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_DOUBLE_HOLD,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
    TD_NONE,
    TD_UNKNOWN,
} td_state_t;
typedef struct {
    td_state_t state;
} td_tap_t;
td_state_t cur_dance(qk_tap_dance_state_t *state);
// Tap dance enums
enum {
    TD_CLN_SCLN,
    TD_SPC_ENT,
    TD_TOPROW,
    TD_THUMB1,
};
#define TD_CLN TD(TD_CLN_SCLN)
#define TD_SPC TD(TD_SPC_ENT)
void spc_finished(qk_tap_dance_state_t *state, void *user_data);
void spc_reset(qk_tap_dance_state_t *state, void *user_data);
#define TD_TR TD(TD_TOPROW)
#define TD_T1 TD(TD_THUMB1)
void thumb1_finished(qk_tap_dance_state_t *state, void *user_data);
void thumb1_reset(qk_tap_dance_state_t *state, void *user_data);
#endif // end TAP_DANCE_ENABLE


// Layer keys
#define ESC_LW1 LT(_LOWER1, KC_ESC)
#define BSP_RS1 LT(_RAISE1, KC_BSPC)
#define BOTH1 MO(_BOTH1)

// Apps
#define ALFRED G(KC_SPC)
#define ITERM G(KC_ESC)
#define QUITAPP G(KC_Q)
#define MEETING HYPR(KC_F16)

// Miscellaneous
#define CUT G(KC_X)
#define COPY G(KC_C)
#define PASTE G(KC_V)
#define CLIPBRD LSG(KC_C)
#define UNDO G(KC_Z)
#define REDO LSG(KC_Z)

// macOS navigation
#define SPC_L MEH_T(KC_F17)
#define SPC_R HYPR_T(KC_F16)

// Combinations
#define CTL_Z CTL_T(KC_Z)
#define CTL_SL RCTL_T(KC_SLSH)
#define G_LBRC G(KC_LBRC)
#define G_RBRC G(KC_RBRC)
#define SG_LBRC RSG(KC_LBRC)
#define SG_RBRC RSG(KC_RBRC)
#define TAB_ALT ALT_T(KC_TAB)
#define TAB_CMD CMD_T(KC_TAB)
#define TAB_SFT SFT_T(KC_TAB)
#define TAB_CTL CTL_T(KC_TAB)
#define ESC_CMD CMD_T(KC_ESC)
#define ESC_MEH MEH_T(KC_ESC)
#define ENT_HPR HYPR_T(KC_ENT)
#define SPC_SFT LSFT_T(KC_SPC) 
#define ENT_SFT RSFT_T(KC_ENT) 

// One Shot Modifiers
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_LALT)
#define OS_LCMD OSM(MOD_LGUI)
#define OS_RCMD OSM(MOD_RGUI)

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

