#include QMK_KEYBOARD_H
#include "keymap.h"

enum layer_names {
    _QWERTY,
    _COLEMAK,
    _DVORAK,
    _NUMPAD,
    _SYM_LEFT,
    _SYM_NAV,
    _META_LEFT // activated with both SYM layers
};
enum layer_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  SYM_LEFT,
  SYM_NAV
};

// Layer keys
#define NUM_ESC LT(_NUMPAD, KC_ESC)
#define NAV_BSPC LT(_SYM_NAV, KC_BSPC)
/* #define SYM_NAV MO(_SYM_NAV) */
/* #define SYM_LEFT MO(_SYM_LEFT) */
#define ADJUST MO(_META_LEFT)
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
// Combinations
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤   2   │   3   │   4   │   5   │ │   6   │   7   │   8   │   9   ├───────┬──────┐
 * │       │   1   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   0   │      │
 * ├───────┼───────┤   W   │   E   │   R   │   T   │ │   Y   │   U   │   I   │   O   ├───────┼──────┤
 * │   ⏎   │   Q   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   P   │      │
 * ├───────┼───────┤   S   │   D   │   F   │   G   │ │   H   │   J   │   K   │   L   ├───────┼──────┤
 * │  ESC  │   A   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤  : ;  │ ' "  │
 * ├───────┼───────┤   X   │   C   │   V   │   B   │ │   N   │   M   │  , <  │  . >  ├───────┼──────┤
 * │  ` ~  │  Z ⎈  ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤  / ⎈  │ \ |  │
 * └───────┴───────┤  TAB  │  OS⎇  │                                 │  = +  │  - _  ├───────┴──────┘
 *                 └───────┴───────┘                                 └───────┴───────┘
 *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
 *                                 ┃ESC_CMD┃SPC_SFT┃ ┃ENT_SFT┃NAV_BSP┃
 *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
 *                                 │NUM_ESC┃ALFRED ┃ ┃TAB_ALT┃TAB_ALT│
 *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
 *                                 │SPACE_L│SPACE_R│ │SPACE_R│SPACE_L│
 *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_QWERTY] = LAYOUT_5x6(
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        KC_ENT , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                       KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , _______,
        KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                       KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_GRV , CTL_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,                       KC_N   , KC_M   , KC_COMM, KC_DOT , CTL_SL , KC_BSLS,
                          KC_TAB , OS_LALT,                                                           KC_EQL , KC_MINS, 
                                           ESC_CMD , SPC_SFT,                       ENT_SFT,NAV_BSPC, 
                                           NUM_ESC , ALFRED ,                       TAB_ALT, TAB_ALT, 
                                           SPACE_L , SPACE_R,                       SPACE_R, SPACE_L
    ),

/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤  F3   │  F4   │  F5   │  F6   │ │       │       │       │       ├───────┬──────┐
 * │  F1   │  F2   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤   |   │   {   │   }   │   ^   │ │       │       │       │       ├───────┼──────┤
 * │       │   %   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤   #   │   (   │   )   │   *   │ │       │       │       │       ├───────┼──────┤
 * │       │   !   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤   &   │   [   │   ]   │   @   │ │       │       │       │       ├───────┼──────┤
 * │       │   ~   ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤       │      │
 * └───────┴───────┤   _   │   $   │                                 │       │       ├───────┴──────┘
 *                 └───────┴───────┘                                 └───────┴───────┘
 *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
 *                                 ┃       ┃       ┃ ┃       ┃       ┃
 *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
 *                                 │       ┃       ┃ ┃       ┃       │
 *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
 *                                 │       │       │ │       │       │
 *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_SYM_LEFT] = LAYOUT_5x6(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                    _______, _______, _______, _______, _______, _______,
        _______, KC_PERC, KC_PIPE, KC_LCBR, KC_RCBR, KC_CIRC,                    _______, _______, _______, _______, _______, _______,
        _______, KC_EXLM, KC_HASH, KC_LPRN, KC_RPRN, KC_ASTR,                    _______, _______, _______, _______, _______, _______,
        _______, KC_TILD, KC_AMPR, KC_LBRC, KC_RBRC, KC_AT  ,                    _______, _______, _______, _______, _______, _______,
                          KC_UNDS, KC_DLR ,                                                        _______, _______, 
                                            _______, _______,                    _______, _______, 
                                            _______, _______,                    _______, _______, 
                                            _______, _______,                    _______, _______
    ),

/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤  F3   │  F4   │  F5   │  F6   │ │  F6   │  F7   │  F8   │  F9   ├───────┬──────┐
 * │  F1   │  F2   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤  F10  │ F11  │
 * ├───────┼───────┤   |   │   {   │   }   │   ^   │ │ CMD+[ │ PLAY  │ MUTE  │ CMD+] ├───────┼──────┤
 * │       │   %   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │ MUTE │
 * ├───────┼───────┤   #   │   (   │   )   │   *   │ │   ←   │   ↓   │   ↑   │   →   ├───────┼──────┤
 * │       │   !   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │ VOL+ │
 * ├───────┼───────┤   &   │   [   │   ]   │   @   │ │  = +  │   ⌫   │   ⏎   │   ⌦   ├───────┼──────┤
 * │       │   ~   ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤       │ VOL- │
 * └───────┴───────┤   _   │   $   │                                 │       │       ├───────┴──────┘
 *                 └───────┴───────┘                                 └───────┴───────┘
 *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
 *                                 ┃       ┃       ┃ ┃       ┃       ┃
 *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
 *                                 │       ┃       ┃ ┃       ┃       │
 *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
 *                                 │       │       │ │       │       │
 *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_SYM_NAV] = LAYOUT_5x6(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                    KC_F6  , KC_F7  , KC_F8  , KC_F9   , KC_F10 , KC_F11 ,
        _______, KC_PERC, KC_PIPE, KC_LCBR, KC_RCBR, KC_CIRC,                    CM_LBRC, KC_MPLY, KC_MUTE, CM_RBRC , _______, KC_MUTE,
        _______, KC_EXLM, KC_HASH, KC_LPRN, KC_RPRN, KC_ASTR,                    KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT , _______, KC_VOLU,
        _______, KC_TILD, KC_AMPR, KC_LBRC, KC_RBRC, KC_AT  ,                    KC_EQL , KC_BSPC, KC_ENT , KC_DEL  , _______, KC_VOLD,
                          KC_UNDS, KC_DLR ,                                                        _______, _______,
                                            _______, _______,                    _______, _______, 
                                            _______, _______,                    _______, _______, 
                                            _______, _______,                    _______, _______
    ),

/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤       │       │       │       │ │       │       │   /   │   *   ├───────┬──────┐
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   -   │RESET │
 * ├───────┼───────┤       │       │       │  ▷ 2  │ │       │  P7   │  P8   │  P9   ├───────┼──────┤
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   +   │ ◎ 2  │
 * ├───────┼───────┤       │       │       │  ▷ 1  │ │       │  P4   │  P5   │  P6   ├───────┼──────┤
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   =   │ ◎ 1  │
 * ├───────┼───────┤       │       │       │       │ │       │  P1   │  P2   │  P3   ├───────┼──────┤
 * │       │       ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤   ⏎   │ ◎ ☐  │
 * └───────┴───────┤       │       │                                 │  P0   │  . >  ├───────┴──────┘
 *                 └───────┴───────┘                                 └───────┴───────┘
 *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
 *                                 ┃       ┃       ┃ ┃  P0   ┃  . >  ┃
 *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
 *                                 │       ┃       ┃ ┃   ⏎   ┃   ⌫   │
 *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
 *                                 │       │       │ │       │       │
 *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_NUMPAD] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,                    _______, _______, KC_PSLS, KC_PAST, KC_PMNS, RESET  ,
        _______, _______, _______, _______, _______, DM_PLY2,                    _______, KC_P7  , KC_P8  , KC_P9  , KC_PPLS, DM_REC2,
        _______, _______, _______, _______, _______, DM_PLY1,                    _______, KC_P4  , KC_P5  , KC_P6  , KC_PEQL, DM_REC1,
        _______, _______, _______, _______, _______, _______,                    _______, KC_P1  , KC_P2  , KC_P3  , KC_PENT, DM_RSTP,
                          _______, _______,                                                        KC_P0  , KC_DOT ,
                                            _______, _______,                    KC_P0  , KC_DOT , 
                                            _______, _______,                    KC_ENT , KC_BSPC, 
                                            _______, _______,                    _______, _______
    ),

/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤       │       │       │ RESET │ │       │       │       │       ├───────┬──────┐
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤       │       │       │       │ │       │       │       │       ├───────┼──────┤
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤       │       │       │       │ │       │       │       │       ├───────┼──────┤
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤       │       │       │       │ │       │       │       │       ├───────┼──────┤
 * │       │       ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤       │      │
 * └───────┴───────┤       │       │                                 │       │       ├───────┴──────┘
 *                 └───────┴───────┘                                 └───────┴───────┘
 *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
 *                                 ┃       ┃       ┃ ┃       ┃       ┃
 *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
 *                                 │       ┃       ┃ ┃       ┃       │
 *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
 *                                 │       │       │ │       │       │
 *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_META_LEFT] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, RESET  ,                       _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
                          _______, _______,                                                           _______, _______, 
                                            _______, _______,                       _______, _______, 
                                            _______, _______,                       _______, _______, 
                                            _______, _______,                       _______, _______
    )
};

// ----------------------------------------------------------------------------
// ------------------------------- COMBOS -------------------------------------
enum combos {
  JK_SYM_LEFT,
  DF_LAYER,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
combo_t key_combos[] = {
  [JK_SYM_LEFT] = COMBO(jk_combo, SYM_LEFT),
  [DF_LAYER] = COMBO(df_combo, NUM_ESC)
};

// ----------------------------------------------------------------------------
// ------------------------------- PROCESS ------------------------------------
uint8_t mod_state;
uint8_t oneshot_mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();
    switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;

        case SYM_LEFT:
          if (record->event.pressed) {
            layer_on(_SYM_LEFT);
          } else {
            layer_off(_SYM_LEFT);
          }
          update_tri_layer(_SYM_LEFT, _SYM_NAV, _META_LEFT);
          return false;
          break;
        case SYM_NAV:
          if (record->event.pressed) {
            layer_on(_SYM_NAV);
          } else {
            layer_off(_SYM_NAV);
          }
          update_tri_layer(_SYM_LEFT, _SYM_NAV, _META_LEFT);
          return false;
          break;

    case KC_SPC:
        if (mod_state & MOD_MASK_SHIFT) {
            if (record->event.pressed) {
                tap_code(KC_MINS); // The one-shot shift will convert it to an underscore
            }
            return false;
        }
        return true;
    }
    return true;
};

