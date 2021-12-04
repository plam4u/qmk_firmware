#include QMK_KEYBOARD_H
#include "keymap.h"

enum layer_keycodes {
  QWERTY = SAFE_RANGE,
  APPNEXT,
  APPPREV,
};
enum layer_names {
    _QWERTY,
    _LOWER1,
    _RAISE1,
    _BOTH1,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤   2   │   3   │   4   │   5   │ │   6   │   7   │   8   │   9   ├───────┬──────┐
 * │   ⌫   │   1   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   0   │RESET │
 * ├───────┼───────┤   W   │   E   │   R   │   T   │ │   Y   │   U   │   I   │   O   ├───────┼──────┤
 * │ENT_HPR│   Q   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   P   │DEBUG │
 * ├───────┼───────┤   S   │   D   │   F   │   G   │ │   H   │   J   │   K   │   L   ├───────┼──────┤
 * │ESC_MEH│   A   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   :   │ ' "  │
 * ├───────┼───────┤   X   │   C   │   V   │   B   │ │   N   │   M   │  , <  │  . >  ├───────┼──────┤
 * │  ` ~  │  Z ⎈  ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤  / ⎈  │ \ |  │
 * └───────┴───────┤  TAB  │ LEAD  │                                 │  = +  │  - _  ├───────┴──────┘
 *                 └───────┴───────┘                                 └───────┴───────┘
 *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
 *                                 ┃ESC_LW1┃SPC_SFT┃ ┃ENT_SFT┃BSP_RS1┃
 *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
 *                                 │ESC_CMD┃SPC_SFT┃ ┃  OS⇧  ┃  OS◆  │
 *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
 *                                 │TAB_CTL│TAB_ALT│ │  OS⎇  │  OS⎈  │
 *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_QWERTY] = LAYOUT_5x6(
        KC_BSPC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , RESET  ,
        ENT_HPR, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                       KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , DEBUG  ,
        ESC_MEH, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                       KC_H   , KC_J   , KC_K   , KC_L   , KC_COLN, KC_QUOT,
        KC_GRV , CTL_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,                       KC_N   , KC_M   , KC_COMM, KC_DOT , CTL_SL , KC_BSLS,
                          KC_TAB , KC_LEAD,                                                           KC_EQL , KC_MINS, 
                                            ESC_LW1, SPC_SFT,                       ENT_SFT, BSP_RS1, 
                                            ESC_CMD, SPC_SFT,                       OS_RSFT, OS_RCMD, 
                                            TAB_CTL, TAB_ALT,                       OS_RALT, OS_RCTL
    ),

/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤       │       │       │       │ │       │  . >  │   0   │       ├───────┬──────┐
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤ CMD+[ │ SPC_L │ SPC_R │ CMD+] │ │  / ?  │   7   │   8   │   9   ├───────┼──────┤
 * │MEETING│QUITAPP├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤       │APPPREV│APPNEXT│ALFRED │ │   *   │   4   │   5   │   6   ├───────┼──────┤
 * │ ITERM │   ⌫   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   :   │      │
 * ├───────┼───────┤  CUT  │ COPY  │ PASTE │CLIPBRD│ │  = +  │   1   │   2   │   3   ├───────┼──────┤
 * │       │   ⏎   ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤       │      │
 * └───────┴───────┤       │       │                                 │   +   │  - _  ├───────┴──────┘
 *                 └───────┴───────┘                                 └───────┴───────┘
 *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
 *                                 ┃       ┃       ┃ ┃       ┃ BOTH1 ┃
 *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
 *                                 │       ┃       ┃ ┃       ┃       │
 *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
 *                                 │       │       │ │       │       │
 *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_LOWER1] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,                    _______, KC_DOT , KC_0   , _______, _______, _______,
        MEETING, QUITAPP, CM_LBRC, SPC_L  , SPC_R  , CM_RBRC,                    KC_SLSH, KC_7   , KC_8   , KC_9   , _______, _______,
        ITERM  , KC_BSPC, _______, APPPREV, APPNEXT, ALFRED ,                    KC_ASTR, KC_4   , KC_5   , KC_6   , KC_COLN, _______,
        _______, KC_ENT , CUT    , COPY   , PASTE  , CLIPBRD,                    KC_EQL , KC_1   , KC_2   , KC_3   , _______, _______,
                          _______, _______,                                                        KC_PLUS, KC_MINS,
                                            _______, _______,                    _______, BOTH1  ,
                                            _______, _______,                    _______, _______,
                                            _______, _______,                    _______, _______
    ),

/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤  F3   │  F4   │  F5   │  F6   │ │  F6   │  F7   │  F8   │  F9   ├───────┬──────┐
 * │  F1   │  F2   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤  F10  │ F11  │
 * ├───────┼───────┤   @   │   {   │   }   │   ^   │ │ CMD+[ │ PLAY  │ MUTE  │ CMD+] ├───────┼──────┤
 * │   ?   │   %   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │ MUTE │
 * ├───────┼───────┤   &   │   (   │   )   │   $   │ │   ←   │   ↓   │   ↑   │   →   ├───────┼──────┤
 * │   !   │   _   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │ VOL+ │
 * ├───────┼───────┤   |   │   [   │   ]   │   *   │ │  = +  │   ⌫   │   ⏎   │   ⌦   ├───────┼──────┤
 * │   ~   │   #   ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤       │ VOL- │
 * └───────┴───────┤       │       │                                 │       │       ├───────┴──────┘
 *                 └───────┴───────┘                                 └───────┴───────┘
 *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
 *                                 ┃ BOTH1 ┃       ┃ ┃       ┃       ┃
 *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
 *                                 │       ┃       ┃ ┃       ┃       │
 *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
 *                                 │       │       │ │       │       │
 *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_RAISE1] = LAYOUT_5x6(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                    KC_F6  , KC_F7  , KC_F8  , KC_F9   , KC_F10 , KC_F11 ,
        KC_QUES, KC_PERC, KC_AT  , KC_LCBR, KC_RCBR, KC_CIRC,                    CM_LBRC, KC_MPLY, KC_MUTE, CM_RBRC , _______, KC_MUTE,
        KC_EXLM, KC_UNDS, KC_AMPR, KC_LPRN, KC_RPRN, KC_DLR ,                    KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT , _______, KC_VOLU,
        KC_TILD, KC_HASH, KC_PIPE, KC_LBRC, KC_RBRC, KC_ASTR,                    KC_EQL , KC_BSPC, KC_ENT , KC_DEL  , _______, KC_VOLD,
                          _______, _______,                                                        _______, _______, 
                                            BOTH1  , _______,                    _______, _______, 
                                            _______, _______,                    _______, _______, 
                                            _______, _______,                    _______, _______
    ),

/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤       │   R   │   R   │   R   │ │       │       │       │       ├───────┬──────┐
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤       │   R   │   R   │   R   │ │       │       │       │       ├───────┼──────┤
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤       │   R   │   R   │   R   │ │       │       │       │       ├───────┼──────┤
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤       │   R   │   R   │   R   │ │       │       │       │       ├───────┼──────┤
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
    [_BOTH1] = LAYOUT_5x6(
        _______, _______, _______, KC_R   , KC_R   , KC_R   ,                    _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_R   , KC_R   , KC_R   ,                    _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_R   , KC_R   , KC_R   ,                    _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_R   , KC_R   , KC_R   ,                    _______, _______, _______, _______, _______, _______,
                          _______, _______,                                                        _______, _______, 
                                            _______, _______,                    _______, _______, 
                                            _______, _______,                    _______, _______, 
                                            _______, _______,                    _______, _______
    ),

};


// ----------------------------------------------------------------------------
// ------------------------------- COMBOS -------------------------------------
#ifdef COMBO_ENABLE
enum combos {
  JK_X,
  DF_X,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
combo_t key_combos[] = {
  [JK_X] = COMBO(jk_combo, KC_X),
  [DF_X] = COMBO(df_combo, KC_X)
};
#endif


// ----------------------------------------------------------------------------
// ------------------------------ TAP DANCE -----------------------------------
#ifdef TAP_DANCE_ENABLE
enum {
    TD_ESC_CAPS,
};
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};
#endif


// ----------------------------------------------------------------------------
// ------------------------------- PROCESS ------------------------------------
uint8_t mod_state;
uint8_t oneshot_mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", 
//             keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
// #endif 

    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();

    switch (keycode) {
        case LT(_LOWER1, KC_ESC):
            if (!record->event.pressed) {
                unregister_code(KC_LCMD);
            }
            break;

        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            break;

        case APPPREV:
            if (record->event.pressed) {
                register_code(KC_LCMD);
                register_code(KC_LSFT);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
                unregister_code(KC_LSFT);
            }
            return false;

        case APPNEXT:
            if (record->event.pressed) {
                register_code(KC_LCMD);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;

        case KC_COLN:
            if (mod_state & MOD_MASK_SHIFT) {
                if (record->event.pressed) {
                    clear_mods();
                    tap_code(KC_SCLN);
                    set_mods(mod_state);
                }
                return false;
            }
            break;

    }

    return true;
};

