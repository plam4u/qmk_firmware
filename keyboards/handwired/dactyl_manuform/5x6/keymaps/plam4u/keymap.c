#include QMK_KEYBOARD_H
#include "keymap.h"

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    APPPREV, APPNEXT,
    TR0, TR1, TR2, TR3, TR4, TR5, TR6, TR7, TR8, TR9, TR10, TR11,
};
const uint16_t TR_ROWS_PER_SIDE = 3;
uint16_t cur_row = 0;
const uint16_t top_row_map[6][12] = {
    // Columns guide
 // { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
    // Left side
    { _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______ },
    { _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______ },
    { _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______ },
    // Right side
    { _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______ },
    { _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______ },
    { _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______ },
};
enum layer_names {
    _QWERTY,
    _LOWER1, _LOWER2, _LOWER3, 
    _RAISE1, _RAISE2, 
    _BOTH1, _BOTH2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤  TR2  │  TR3  │  TR4  │  TR5  │ │  TR6  │  TR7  │  TR8  │  TR9  ├───────┬──────┐
 * │TD_TR_L│  TR1  ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤ TR10  │TD_TR_│
 * ├───────┼───────┤   W   │   E   │   R   │   T   │ │   Y   │   U   │   I   │   O   ├───────┼──────┤
 * │ENT_HPR│   Q   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   P   │      │
 * ├───────┼───────┤   S   │   D   │   F   │   G   │ │   H   │   J   │   K   │   L   ├───────┼──────┤
 * │ESC_MEH│   A   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤TD_CLN │ ' "  │
 * ├───────┼───────┤   X   │   C   │   V   │   B   │ │   N   │   M   │  , <  │  . >  ├───────┼──────┤
 * │  ` ~  │  Z ⎈  ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤  / ⎈  │ \ |  │
 * └───────┴───────┤  TAB  │ LEAD  │                                 │  = +  │  - _  ├───────┴──────┘
 *                 └───────┴───────┘                                 └───────┴───────┘
 *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
 *                                 ┃ TD_T1 ┃SPC_SFT┃ ┃ENT_SFT┃BSP_RS1┃
 *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
 *                                 │ESC_CMD┃SPC_SFT┃ ┃  OS⇧  ┃  OS◆  │
 *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
 *                                 │TAB_CTL│TAB_ALT│ │  OS⎇  │  OS⎈  │
 *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_QWERTY] = LAYOUT_5x6(
        TD_TR_L, TR1    , TR2    , TR3    , TR4    , TR5    ,                       TR6    , TR7    , TR8    , TR9    , TR10    , TD_TR_R,

        ENT_HPR, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                       KC_Y   , KC_U   , KC_I   , KC_O   , KC_P    , _______,
        ESC_MEH, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                       KC_H   , KC_J   , KC_K   , KC_L   , TD_CLN  , KC_QUOT,
        KC_GRV , CTL_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,                       KC_N   , KC_M   , KC_COMM, KC_DOT , CTL_SL  , KC_BSLS,
                          KC_TAB , KC_LEAD,                                                           KC_EQL , KC_MINS,
                                            TD_T1  , SPC_SFT,                       ENT_SFT, BSP_RS1,
                                            ESC_CMD, SPC_SFT,                       OS_RSFT, OS_RCMD,
                                            TAB_CTL, TAB_ALT,                       OS_RALT, OS_RCTL
    ),

/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤       │       │       │       │ │       │       │       │       ├───────┬──────┐
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤SG_LBRC│G_LBRC │G_RBRC │SG_RBRC│ │  / ?  │   7   │   8   │   9   ├───────┼──────┤
 * │MEETING│       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   0   │      │
 * ├───────┼───────┤ SPC_L │APPPREV│APPNEXT│ SPC_R │ │   *   │   4   │   5   │   6   ├───────┼──────┤
 * │ ITERM │   ⌫   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   :   │      │
 * ├───────┼───────┤  CUT  │ COPY  │ PASTE │CLIPBRD│ │  = +  │   1   │   2   │   3   ├───────┼──────┤
 * │QUITAPP│   ⏎   ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤  . >  │      │
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
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,

        MEETING, _______, SG_LBRC, G_LBRC , G_RBRC , SG_RBRC,                    KC_SLSH, KC_7   , KC_8   , KC_9   , KC_0   , _______,
        ITERM  , KC_BSPC, SPC_L  , APPPREV, APPNEXT, SPC_R  ,                    KC_ASTR, KC_4   , KC_5   , KC_6   , KC_COLN, _______,
        QUITAPP, KC_ENT , CUT    , COPY   , PASTE  , CLIPBRD,                    KC_EQL , KC_1   , KC_2   , KC_3   , KC_DOT , _______,
                          _______, _______,                                                        KC_PLUS, KC_MINS,
                                            _______, _______,                    _______, BOTH1  ,
                                            _______, _______,                    _______, _______,
                                            _______, _______,                    _______, _______
    ),

/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤       │       │       │       │ │       │       │       │       ├───────┬──────┐
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤ KP_2  │ KP_3  │ KP_4  │ KP_5  │ │       │  F6   │  F7   │  F8   ├───────┼──────┤
 * │ KP_0  │ KP_1  ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤  F15  │  F16  │  F17  │  F18  │ │       │       │       │       ├───────┼──────┤
 * │  F13  │  F14  ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤  F21  │  F22  │  F23  │  F24  │ │       │       │       │       ├───────┼──────┤
 * │  F19  │  F20  ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤       │      │
 * └───────┴───────┤       │       │                                 │       │       ├───────┴──────┘
 *                 └───────┴───────┘                                 └───────┴───────┘
 *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
 *                                 ┃       ┃       ┃ ┃       ┃       ┃
 *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
 *                                 │       ┃       ┃ ┃       ┃       │
 *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
 *                                 │       │       │ │       │       │
 *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_LOWER2] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,

        KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5,                    _______, KC_F6  , KC_F7  , KC_F8  , _______, _______,
        KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 ,                    _______, _______, _______, _______, _______, _______,
        KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 ,                    _______, _______, _______, _______, _______, _______,
                          _______, _______,                                                        _______, _______,
                                            _______, _______,                    _______, _______,
                                            _______, _______,                    _______, _______,
                                            _______, _______,                    _______, _______
    ),

/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤       │       │       │       │ │       │       │       │       ├───────┬──────┐
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤       │       │       │       │ │       │       │       │       ├───────┼──────┤
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤       │       │   X   │       │ │       │       │       │       ├───────┼──────┤
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
    [_LOWER3] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_X   , _______,                    _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
                          _______, _______,                                                        _______, _______,
                                            _______, _______,                    _______, _______,
                                            _______, _______,                    _______, _______,
                                            _______, _______,                    _______, _______
    ),

/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤       │       │       │       │ │       │       │       │       ├───────┬──────┐
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤   @   │   {   │   }   │   ^   │ │SG_LBRC│ PLAY  │ MUTE  │SG_RBRC├───────┼──────┤
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
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,

        KC_QUES, KC_PERC, KC_AT  , KC_LCBR, KC_RCBR, KC_CIRC,                    SG_LBRC, KC_MPLY, KC_MUTE, SG_RBRC , _______, KC_MUTE,
        KC_EXLM, KC_UNDS, KC_AMPR, KC_LPRN, KC_RPRN, KC_DLR ,                    KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT , _______, KC_VOLU,
        KC_TILD, KC_HASH, KC_PIPE, KC_LBRC, KC_RBRC, KC_ASTR,                    KC_EQL , KC_BSPC, KC_ENT , KC_DEL  , _______, KC_VOLD,
                          _______, _______,                                                        _______, _______,
                                            BOTH1  , _______,                    _______, _______,
                                            _______, _______,                    _______, _______,
                                            _______, _______,                    _______, _______
    ),

/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤       │       │       │       │ │       │       │       │       ├───────┬──────┐
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤       │       │       │  ▷ 2  │ │  ◎ 2  │       │       │       ├───────┼──────┤
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤       │       │       │  ▷ 1  │ │  ◎ 1  │ RESET │ DEBUG │       ├───────┼──────┤
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤       │       │       │       │ │  ◎ ☐  │       │       │       ├───────┼──────┤
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
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______, DM_PLY2,                    DM_REC2, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, DM_PLY1,                    DM_REC1, RESET  , DEBUG  , _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                    DM_RSTP, _______, _______, _______, _______, _______,
                          _______, _______,                                                        _______, _______,
                                            _______, _______,                    _______, _______,
                                            _______, _______,                    _______, _______,
                                            _______, _______,                    _______, _______
    ),

};


// ----------------------------------------------------------------------------
// ------------------------------ TAP DANCE -----------------------------------
#ifdef TAP_DANCE_ENABLE
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    switch (state->count) {
        case 1: 
            if (state->pressed) {
                return TD_SINGLE_HOLD;
            } else {
                return TD_SINGLE_TAP;
            }
        case 2:
            if (state->pressed) {
                return TD_DOUBLE_HOLD;
            } else {
                return TD_DOUBLE_TAP;
            }
        case 3:
            if (state->pressed) {
                return TD_TRIPLE_HOLD;
            } else {
                return TD_TRIPLE_TAP;
            }
        default:
            return TD_UNKNOWN;
    }
}

// ============================================================================
// =============================== TD SPACE ===================================
static td_tap_t spc_td_state = {
    .state = TD_NONE
};
void spc_finished(qk_tap_dance_state_t *state, void *user_data) {
    spc_td_state.state = cur_dance(state);
    switch (spc_td_state.state) {
        case TD_SINGLE_TAP: 
            println("SINGLE TAP Finished!");
            register_code(KC_SPC); 
            break;
        case TD_SINGLE_HOLD: 
            println("SINGLE HOLD Finished!"); 
            register_code(KC_LSFT); 
            break;
        case TD_DOUBLE_TAP: 
            println("DOUBLE TAP Finished!");
            register_code(KC_ENT); 
            break;
        case TD_DOUBLE_HOLD: 
            println("DOUBLE HOLD Finished!");
            layer_on(_LOWER3); 
            break;
        default: 
            println("DEFAULT Finished!");
            break;
    }
}
void spc_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (spc_td_state.state) {
        case TD_SINGLE_TAP: 
            println("SINGLE TAP Reset!");
            unregister_code(KC_SPC); 
            break;
        case TD_SINGLE_HOLD: 
            println("SINGLE HOLD Reset!"); 
            unregister_code(KC_LSFT); 
            break;
        case TD_DOUBLE_TAP: 
            println("DOUBLE TAP Reset!");
            unregister_code(KC_ENT); 
            break;
        case TD_DOUBLE_HOLD: 
            println("DOUBLE HOLD Finished!");
            layer_off(_LOWER3); 
        default: break;
    }
    spc_td_state.state = TD_NONE;
}
// ============================================================================
// =============================== TD THUMB 1 =================================
static td_tap_t thumb1_td_state = {
    .state = TD_NONE
};
// Called on key press ONLY
void thumb1_each(qk_tap_dance_state_t *state, void *user_data) {
    thumb1_td_state.state = cur_dance(state);
    switch (thumb1_td_state.state) {
        case TD_SINGLE_HOLD: 
            layer_on(_LOWER1);
            layer_off(_LOWER2);
            break;
        case TD_DOUBLE_HOLD: 
            layer_off(_LOWER1);
            layer_on(_LOWER2);
            break;
        default: 
            layer_off(_LOWER1);
            layer_off(_LOWER2);
            break;
    }
}
void thumb1_finished(qk_tap_dance_state_t *state, void *user_data) {
    thumb1_td_state.state = cur_dance(state);
    switch (thumb1_td_state.state) {
        case TD_SINGLE_TAP: register_code(KC_ESC); break;
        case TD_DOUBLE_TAP: tap_code16(ALFRED); break;
        default: break;
    }
}
void thumb1_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (thumb1_td_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_ESC); break;
        case TD_DOUBLE_TAP: break;
        default: break;
    }
    layer_off(_LOWER1);
    layer_off(_LOWER2);
    thumb1_td_state.state = TD_NONE;
}

// ============================================================================
// =============================== TD TOP ROW =================================
void dance_tr_left(qk_tap_dance_state_t *state, void *user_data) {
    cur_row = state->count - 1;
    if (cur_row >= TR_ROWS_PER_SIDE) {
        cur_row = TR_ROWS_PER_SIDE;
    }
    reset_tap_dance(state);
}
void dance_tr_right(qk_tap_dance_state_t *state, void *user_data) {
    cur_row = TR_ROWS_PER_SIDE + state->count - 1;
    if (cur_row >= TR_ROWS_PER_SIDE * 2) {
        cur_row = TR_ROWS_PER_SIDE;
    }
    reset_tap_dance(state);
}
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CLN_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_COLN, KC_SCLN),
    [TD_SPC_ENT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, spc_finished, spc_reset),
    [TD_TR_LEFT] = ACTION_TAP_DANCE_FN(dance_tr_left),
    [TD_TR_RIGHT] = ACTION_TAP_DANCE_FN(dance_tr_right),
    [TD_THUMB1] = ACTION_TAP_DANCE_FN_ADVANCED(thumb1_each, thumb1_finished, thumb1_reset),
};
#endif


// ----------------------------------------------------------------------------
// ------------------------------- PROCESS ------------------------------------
uint8_t mod_state;
uint8_t oneshot_mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf(
        "KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n",
        keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count
    );
#endif

    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();

    switch (keycode) {
        case TR0: case TR1: case TR2: case TR3: case TR4: case TR5: 
        case TR6: case TR7: case TR8: case TR9: case TR10: case TR11: ;
            uint16_t idx = keycode - TR0;
            if (record->event.pressed) {
                register_code16(top_row_map[cur_row][idx]);
            } else {
                unregister_code16(top_row_map[cur_row][idx]);
            }
           
            return false;

        case LT(_LOWER1, KC_ESC):
        case TD_T1:
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
                unregister_code(KC_LSFT);
                register_code(KC_LCMD);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;

        case TD_CLN:
            if (mod_state & MOD_MASK_SHIFT) {
                if (record->event.pressed) {
                    unregister_code(KC_LSFT);
                    tap_code(KC_SCLN);
                    register_code(KC_LSFT);
                }
                return false;
            }
            break;

    }

    return true;
};

