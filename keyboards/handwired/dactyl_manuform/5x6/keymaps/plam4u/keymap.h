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
    TD_ACCENT_A,
    TD_ACCENT_E,
    TD_ACCENT_U,
    TD_ACCENT_I,
    TD_ACCENT_O,
    TD_CLN_SCLN,
    TD_SPC_ENT,
    TD_TR_LEFT,
    TD_TR_RIGHT,
    TD_COPY_PASTE,
    TD_THUMB1,
    TD_X_CUT,
    TD_C_COPY,
    TD_V_PASTE,
};
#define TD_AA TD(TD_ACCENT_A)
#define TD_AE TD(TD_ACCENT_E)
#define TD_AU TD(TD_ACCENT_U)
#define TD_AI TD(TD_ACCENT_I)
#define TD_AO TD(TD_ACCENT_O)
void dance_accent_a(qk_tap_dance_state_t *state, void *user_data);
void dance_accent_e(qk_tap_dance_state_t *state, void *user_data);
void dance_accent_u(qk_tap_dance_state_t *state, void *user_data);
void dance_accent_i(qk_tap_dance_state_t *state, void *user_data);
void dance_accent_o(qk_tap_dance_state_t *state, void *user_data);
#define TD_XCUT TD(TD_X_CUT)
#define TD_CCPY TD(TD_C_COPY)
#define TD_VPST TD(TD_V_PASTE)
void dance_x_cut(qk_tap_dance_state_t *state, void *user_data);
void dance_c_copy(qk_tap_dance_state_t *state, void *user_data);
void dance_v_paste(qk_tap_dance_state_t *state, void *user_data);
#define TD_CLN TD(TD_CLN_SCLN)
#define TD_SPC TD(TD_SPC_ENT)
void spc_finished(qk_tap_dance_state_t *state, void *user_data);
void spc_reset(qk_tap_dance_state_t *state, void *user_data);
#define TD_TR_L TD(TD_TR_LEFT)
#define TD_TR_R TD(TD_TR_RIGHT)
void dance_tr_left(qk_tap_dance_state_t *state, void *user_data);
void dance_tr_right(qk_tap_dance_state_t *state, void *user_data);
#define TD_CYPE TD(TD_COPY_PASTE)
void dance_copy_paste(qk_tap_dance_state_t *state, void *user_data);
#define TD_LWR1 TD(TD_THUMB1)
void thumb1_finished(qk_tap_dance_state_t *state, void *user_data);
void thumb1_reset(qk_tap_dance_state_t *state, void *user_data);
#endif // end TAP_DANCE_ENABLE

// Layer keys
#define ESC_LW1 LT(_LOWER1, KC_ESC)
#define ENT_LW3 LT(_LOWER3, KC_ENT)
#define BSP_RS1 LT(_RAISE1, KC_BSPC)
#define DEL_RS1 LT(_RAISE1, KC_DEL)
#define SCL_LW3 LT(_LOWER3, KC_SCLN)
#define LOWER2 TO(_LOWER2)
#define LOWER3 TO(_LOWER3)
#define LOWER4 TO(_LOWER4)
#define RAISE2 TO(_RAISE2)
#define RAISE3 TO(_RAISE3)
#define RAISE4 TO(_RAISE4)
#define BOTH1 MO(_BOTH1)
#define DF_QWR1 DF(_QWERTY)
#define DF_QWR2 DF(_QWERTY_DESIGN)

// Apps
#define ALFRED G(KC_SPC)
#define ITERM G(KC_ESC)
#define QUITAPP G(KC_Q)
#define HIDEAPP MEH(KC_G)
#define MEETING HYPR(KC_F16)
#define APPWINS G(KC_GRV)

// Left hand
#define APP01 S(KC_F11)
#define APP02 S(KC_F12)
#define APP03 S(KC_F13)
#define APP04 S(KC_F14)
#define APP05 S(KC_F15)

#define APP06 S(KC_F16)
#define APP07 S(KC_F17)
#define APP08 S(KC_F18)
#define APP09 S(KC_F19)
#define APP10 S(KC_F20)

// Left hand
#define APP11 A(KC_F11)
#define APP12 A(KC_F12)
#define APP13 A(KC_F13)
#define APP14 A(KC_F14)
#define APP15 A(KC_F15)

#define APP16 A(KC_F16)
#define APP17 A(KC_F17)
#define APP18 A(KC_F18)
#define APP19 A(KC_F19)
#define APP20 A(KC_F20)

// Right hand
#define APP21 C(KC_F11)
#define APP22 C(KC_F12)
#define APP23 C(KC_F13)
#define APP24 C(KC_F14)
#define APP25 C(KC_F15)

#define APP26 C(KC_F16)
#define APP27 C(KC_F17)
#define APP28 C(KC_F18)
#define APP29 C(KC_F19)
#define APP30 C(KC_F20)

#define APP31 C(KC_F21)
#define APP32 C(KC_F22)
#define APP33 C(KC_F23)
#define APP34 C(KC_F24)
#define APP35 A(KC_F21)

// Miscellaneous
#define CUT G(KC_X)
#define COPY G(KC_C)
#define PASTE G(KC_V)
#define CLIPBRD LSG(KC_C)
#define UNDO G(KC_Z)
#define REDO LSG(KC_Z)

// macOS navigation
#define SPACE_L MEH_T(KC_F17)
#define SPACE_R HYPR_T(KC_F16)

// Combinations
#define CTL_Z CTL_T(KC_Z)
#define CTL_SL RCTL_T(KC_SLSH)
#define G_LBRC G(KC_LBRC)
#define G_RBRC G(KC_RBRC)
#define BACK G_LBRC
#define FORWARD G_RBRC
#define SG_LBRC RSG(KC_LBRC)
#define SG_RBRC RSG(KC_RBRC)
#define TABPREV SG_LBRC
#define TABNEXT SG_RBRC
#define TAB_ALT ALT_T(KC_TAB)
#define TAB_CMD CMD_T(KC_TAB)
#define TAB_SFT SFT_T(KC_TAB)
#define TAB_CTL CTL_T(KC_TAB)
#define ESC_CMD CMD_T(KC_ESC)
#define ESC_SFT SFT_T(KC_ESC)
#define ESC_MEH MEH_T(KC_ESC)
#define ENT_HPR HYPR_T(KC_ENT)
#define SPC_SFT LSFT_T(KC_SPC) 
#define ENT_SFT RSFT_T(KC_ENT) 
#define ENT_CTL CTL_T(KC_ENT) 
#define ENT_CMD CMD_T(KC_ENT) 
#define ENT_ALT ALT_T(KC_ENT) 
#define BSP_SFT RSFT_T(KC_BSPC) 
#define ACCENT A(KC_E)
#define CENTER MEH(KC_I)

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

