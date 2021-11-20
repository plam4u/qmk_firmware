#include QMK_KEYBOARD_H
#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤   2   │   3   │   4   │   5   │ │   6   │   7   │   8   │   9   ├───────┬──────┐
 * │  ` ~  │   1   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   0   │      │
 * ├───────┼───────┤   W   │   E   │   R   │   T   │ │   Y   │   U   │   I   │   O   ├───────┼──────┤
 * │  TAB  │   Q   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   P   │ ` ~  │
 * ├───────┼───────┤   S   │   D   │   F   │   G   │ │   H   │   J   │   K   │   L   ├───────┼──────┤
 * │  ESC  │   A   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤  : ;  │ ' "  │
 * ├───────┼───────┤   X   │   C   │   V   │   B   │ │   N   │   M   │  , <  │  . >  ├───────┼──────┤
 * │  OS⎇  │  Z ⎈  ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤  / ⎈  │ \ |  │
 * └───────┴───────┤  TAB  │NUM_ESC│                                 │  OS◆  │  OS⎇  ├───────┴──────┘
 *                 └───────┴───────┘                                 └───────┴───────┘
 *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
 *                                 ┃ ESC ◆ ┃ SPC ⇧ ┃ ┃ ENT ⇧ ┃NAV_BSP┃
 *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
 *                                 │       ┃ TAB ⎇ ┃ ┃       ┃       │
 *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
 *                                 │SPACE_L│SPACE_R│ │SPACE_L│SPACE_R│
 *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_QWERTY] = LAYOUT_5x6(
        KC_GRV  ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                           KC_6    ,KC_7   ,KC_8   ,KC_9   ,KC_0     ,_______,
        KC_TAB  ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                           KC_Y    ,KC_U   ,KC_I   ,KC_O   ,KC_P     ,KC_GRV ,
        KC_ESC  ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,                           KC_H    ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN  ,KC_QUOT,
        OS_LALT ,CTL_Z  ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,                           KC_N    ,KC_M   ,KC_COMM,KC_DOT ,CTL_SL   ,KC_BSLS,
                         KC_TAB ,NUM_ESC,                                                            OS_RCMD,OS_RALT, 
                                      CMD_T(KC_ESC), LSFT_T(KC_SPC),            RSFT_T(KC_ENT),NAV_BSPC, 
                                            _______, OPT_T(KC_TAB) ,            _______, _______, 
                                            SPACE_L, SPACE_R,                   SPACE_L, SPACE_R
    ),

/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤       │       │       │       │ │       │       │   /   │   *   ├───────┬──────┐
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   -   │      │
 * ├───────┼───────┤ CMD+W │       │       │   |   │ │       │  P7   │  P8   │  P9   ├───────┼──────┤
 * │  ▷ 2  │ CMD+Q ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   +   │ ◎ 2  │
 * ├───────┼───────┤ CMD+S │       │       │   &   │ │       │  P4   │  P5   │  P6   ├───────┼──────┤
 * │  ▷ 1  │ CMD+A ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   =   │ ◎ 1  │
 * ├───────┼───────┤  CUT  │ COPY  │ PASTE │  - _  │ │       │  P1   │  P2   │  P3   ├───────┼──────┤
 * │ REDO  │ UNDO  ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤   ⏎   │ ◎ ☐  │
 * └───────┴───────┤       │       │                                 │  P0   │  . >  ├───────┴──────┘
 *                 └───────┴───────┘                                 └───────┴───────┘
 *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
 *                                 ┃       ┃       ┃ ┃       ┃       ┃
 *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
 *                                 │       ┃       ┃ ┃       ┃       │
 *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
 *                                 │       │       │ │ RESET │       │
 *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_NUMPAD] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,                            _______,_______,KC_PSLS,KC_PAST,KC_PMNS,_______,
        DM_PLY2,G(KC_Q),G(KC_W),_______,_______,KC_PIPE,                            _______, KC_P7 , KC_P8 , KC_P9 ,KC_PPLS,DM_REC2,
        DM_PLY1,G(KC_A),G(KC_S),_______,_______,KC_AMPR,                            _______, KC_P4 , KC_P5 , KC_P6 ,KC_PEQL,DM_REC1,
        REDO   ,  UNDO ,  CUT  , COPY  , PASTE ,KC_MINS,                            _______, KC_P1 , KC_P2 , KC_P3 ,KC_PENT,DM_RSTP,
                       _______,_______,                                                              KC_P0 , KC_DOT,
                                            _______, _______,                   _______, _______, 
                                            _______, _______,                   _______, _______, 
                                            _______, _______,                   RESET  , _______
    ),

/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤  F2   │  F3   │  F4   │  F5   │ │  F6   │  F7   │  F8   │  F9   ├───────┬──────┐
 * │  F12  │  F1   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤  F10  │ F11  │
 * ├───────┼───────┤   ^   │   {   │   }   │   |   │ │ CMD+[ │ PLAY  │ MUTE  │ CMD+] ├───────┼──────┤
 * │       │   %   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │ MUTE │
 * ├───────┼───────┤   $   │   (   │   )   │   &   │ │   ←   │   ↓   │   ↑   │   →   ├───────┼──────┤
 * │       │   @   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │ VOL+ │
 * ├───────┼───────┤   *   │   [   │   ]   │  - _  │ │  = +  │   ⌫   │   ⏎   │   ⌦   ├───────┼──────┤
 * │       │   #   ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤       │ VOL- │
 * └───────┴───────┤       │       │                                 │       │       ├───────┴──────┘
 *                 └───────┴───────┘                                 └───────┴───────┘
 *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
 *                                 ┃   _   ┃   $   ┃ ┃       ┃       ┃
 *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
 *                                 │       ┃  ` ~  ┃ ┃       ┃       │
 *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
 *                                 │       │       │ │       │       │
 *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_SYM_NAV] = LAYOUT_5x6(
        KC_F12  ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                           KC_F6   ,KC_F7  ,KC_F8  ,KC_F9   ,KC_F10 ,KC_F11 ,
        _______ ,KC_PERC,KC_CIRC,KC_LCBR,KC_RCBR,KC_PIPE,                           CM_LBRC ,KC_MPLY,KC_MUTE,CM_RBRC ,_______,KC_MUTE,
        _______ ,KC_AT  ,KC_DLR ,KC_LPRN,KC_RPRN,KC_AMPR,                           KC_LEFT ,KC_DOWN,KC_UP  ,KC_RGHT ,_______,KC_VOLU,
        _______ ,KC_HASH,KC_ASTR,KC_LBRC,KC_RBRC,KC_MINS,                           KC_EQL  ,KC_BSPC,KC_ENT ,KC_DEL  ,_______,KC_VOLD,
                         _______,_______,                                                            _______, _______, 
                                            KC_UNDS, KC_DLR ,                    _______, _______, 
                                            _______, KC_GRV ,                    _______, _______, 
                                            _______, _______,                    _______, _______
    ),

/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤  F2   │  F3   │  F4   │  F5   │ │  F6   │  F7   │  F8   │  F9   ├───────┬──────┐
 * │  F12  │  F1   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤  F10  │ F11  │
 * ├───────┼───────┤   ^   │   {   │   }   │   |   │ │ CMD+[ │ PLAY  │ MUTE  │ CMD+] ├───────┼──────┤
 * │       │   %   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │ MUTE │
 * ├───────┼───────┤   $   │   (   │   )   │   &   │ │   ←   │   ↓   │   ↑   │   →   ├───────┼──────┤
 * │       │   @   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │ VOL+ │
 * ├───────┼───────┤   *   │   [   │   ]   │  - _  │ │  = +  │   ⌫   │   ⏎   │   ⌦   ├───────┼──────┤
 * │       │   #   ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤       │ VOL- │
 * └───────┴───────┤       │       │                                 │       │       ├───────┴──────┘
 *                 └───────┴───────┘                                 └───────┴───────┘
 *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
 *                                 ┃   _   ┃   $   ┃ ┃       ┃       ┃
 *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
 *                                 │       ┃  ` ~  ┃ ┃       ┃       │
 *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
 *                                 │       │       │ │       │       │
 *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_ADJUST] = LAYOUT_5x6(
        KC_F12  ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                           KC_F6   ,KC_F7  ,KC_F8  ,KC_F9   ,KC_F10 ,KC_F11 ,
        _______ ,KC_PERC,KC_CIRC,KC_LCBR,KC_RCBR,KC_PIPE,                           CM_LBRC ,KC_MPLY,KC_MUTE,CM_RBRC ,_______,KC_MUTE,
        _______ ,KC_AT  ,KC_DLR ,KC_LPRN,KC_RPRN,KC_AMPR,                           KC_LEFT ,KC_DOWN,KC_UP  ,KC_RGHT ,_______,KC_VOLU,
        _______ ,KC_HASH,KC_ASTR,KC_LBRC,KC_RBRC,KC_MINS,                           KC_EQL  ,KC_BSPC,KC_ENT ,KC_DEL  ,_______,KC_VOLD,
                         _______,_______,                                                            _______, _______, 
                                            KC_UNDS, KC_DLR ,                    _______, _______, 
                                            _______, KC_GRV ,                    _______, _______, 
                                            _______, _______,                    _______, _______
    )
};

enum combos {
  AB_ESC,
  JK_TAB,
  QW_SFT,
  DF_LAYER,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM ab_combo[] = {KC_A, KC_B, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};

combo_t key_combos[] = {
  [AB_ESC] = COMBO(ab_combo, KC_ESC),
  [JK_TAB] = COMBO(jk_combo, KC_TAB),
  [QW_SFT] = COMBO(qw_combo, KC_LSFT),
  [DF_LAYER] = COMBO(df_combo, MO(_ADJUST))
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();
    switch (keycode) {

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

