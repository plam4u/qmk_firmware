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
    { _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______ },
    { _______, KC_INT1, KC_INT2, KC_INT3, KC_INT4, KC_INT5, KC_INT6, KC_INT7, KC_INT8, KC_INT9, KC_NUM , _______ },
    // Right side
    { _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______ },
    { _______, KC_F11 , KC_F12 , KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , _______ },
    { _______, KC_LANG1,KC_LANG2,KC_LANG3,KC_LANG4,KC_LANG5,KC_LANG6,KC_LANG7,KC_LANG8,KC_LANG9,KC_INS , _______ },
};
enum layer_names {
    _QWERTY,
    _LOWER1, _LOWER2, _LOWER3, 
    _RAISE1, _RAISE2, _RAISE3,
    _BOTH1, _BOTH2, _BOTH3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤  TR2  │  TR3  │  TR4  │  TR5  │ │  TR6  │  TR7  │  TR8  │  TR9  ├───────┬──────┐
 * │TD_TR_L│  TR1  ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤ TR10  │TD_TR_│
 * ├───────┼───────┤   W   │   E   │   R   │   T   │ │   Y   │   U   │   I   │   O   ├───────┼──────┤
 * │ENT_HPR│   Q   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   P   │  :   │
 * ├───────┼───────┤   S   │   D   │   F   │   G   │ │   H   │   J   │   K   │   L   ├───────┼──────┤
 * │ESC_MEH│   A   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤  : ;  │ ' "  │
 * ├───────┼───────┤   X   │   C   │   V   │   B   │ │   N   │   M   │  , <  │  . >  ├───────┼──────┤
 * │  ` ~  │  Z ⎈  ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤  / ⎈  │ \ |  │
 * └───────┴───────┤SPACE_L│SPACE_R│                                 │  = +  │  - _  ├───────┴──────┘
 *                 └───────┴───────┘                                 └───────┴───────┘
 *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
 *                                 ┃ESC_LW1┃SPC_SFT┃ ┃ENT_SFT┃BSP_RS1┃
 *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
 *                                 │  OS⇧  ┃TAB_CMD┃ ┃  OS◆  ┃  OS⇧  │
 *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
 *                                 │  OS⎇  │  OS⎈  │ │  OS⎈  │  OS⎇  │
 *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_QWERTY] = LAYOUT_5x6(
        TD_TR_L, TR1    , TR2    , TR3    , TR4    , TR5    ,                       TR6    , TR7    , TR8    , TR9    , TR10    , TD_TR_R,

        ENT_HPR, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                       KC_Y   , KC_U   , KC_I   , KC_O   , KC_P    , KC_COLN,
        ESC_MEH, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                       KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN , KC_QUOT,
        KC_GRV , CTL_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,                       KC_N   , KC_M   , KC_COMM, KC_DOT , CTL_SL  , KC_BSLS,
                          SPACE_L, SPACE_R,                                                           KC_EQL , KC_MINS,
                                            ESC_LW1, SPC_SFT,                       ENT_SFT, BSP_RS1,
                                            OS_LSFT, TAB_CMD,                       OS_RCMD, OS_RSFT,
                                            OS_LALT, OS_LCTL,                       OS_RCTL, OS_LALT
    ),

/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤       │       │       │       │ │       │       │       │       ├───────┬──────┐
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤TABPREV│ BACK  │FORWARD│TABNEXT│ │  / ?  │   7   │   8   │   9   ├───────┼──────┤
 * │MEETING│       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   0   │RESET │
 * ├───────┼───────┤       │APPPREV│APPNEXT│HIDEAPP│ │   *   │   4   │   5   │   6   ├───────┼──────┤
 * │ ITERM │ALFRED ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   :   │      │
 * ├───────┼───────┤LALT ⎇ │ LCMD  │LSFT ⇧ │       │ │  = +  │   1   │   2   │   3   ├───────┼──────┤
 * │       │LCTL ⎈ ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤  . >  │      │
 * └───────┴───────┤LOWER3 │LOWER2 │                                 │   +   │  - _  ├───────┴──────┘
 *                 └───────┴───────┘                                 └───────┴───────┘
 *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
 *                                 ┃       ┃       ┃ ┃       ┃       ┃
 *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
 *                                 │       ┃       ┃ ┃       ┃       │
 *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
 *                                 │       │       │ │       │       │
 *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_LOWER1] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,

        MEETING, _______, TABPREV, BACK   , FORWARD, TABNEXT,                    KC_SLSH, KC_7   , KC_8   , KC_9   , KC_0   , RESET  ,
        ITERM  , ALFRED , _______, APPPREV, APPNEXT, HIDEAPP,                    KC_ASTR, KC_4   , KC_5   , KC_6   , KC_COLN, _______,
        _______, KC_LCTL, KC_LALT, KC_LCMD, KC_LSFT, _______,                    KC_EQL , KC_1   , KC_2   , KC_3   , KC_DOT , _______,
                          LOWER3 , LOWER2 ,                                                        KC_PLUS, KC_MINS,
                                            _______, _______,                    _______, _______,
                                            _______, _______,                    _______, _______,
                                            _______, _______,                    _______, _______
    ),

/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤       │       │       │       │ │       │       │       │       ├───────┬──────┐
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤ APP02 │ APP03 │ APP04 │ APP05 │ │       │  F7   │  F8   │  F9   ├───────┼──────┤
 * │       │ APP01 ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤  F12  │      │
 * ├───────┼───────┤ APP07 │ APP08 │ APP09 │ APP10 │ │       │  F4   │  F5   │  F6   ├───────┼──────┤
 * │       │ APP06 ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤  F11  │      │
 * ├───────┼───────┤  OS⎇  │  OS◆  │  OS⇧  │       │ │       │  F1   │  F2   │  F3   ├───────┼──────┤
 * │       │  OS⎈  ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤  F10  │      │
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

        _______, APP01  , APP02  , APP03  , APP04  , APP05  ,                    _______, KC_F7  , KC_F8  , KC_F9  , KC_F12 , _______,
        _______, APP06  , APP07  , APP08  , APP09  , APP10  ,                    _______, KC_F4  , KC_F5  , KC_F6  , KC_F11 , _______,
        _______, OS_LCTL, OS_LALT, OS_LCMD, OS_LSFT, _______,                    _______, KC_F1  , KC_F2  , KC_F3  , KC_F10 , _______,
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
 * ├───────┼───────┤       │       │       │       │ │       │       │       │       ├───────┼──────┤
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤  OS⎇  │  OS◆  │  OS⇧  │       │ │       │       │       │       ├───────┼──────┤
 * │       │  OS⎈  ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤       │      │
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
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
        _______, OS_LCTL, OS_LALT, OS_LCMD, OS_LSFT, _______,                    _______, _______, _______, _______, _______, _______,
                          _______, _______,                                                        _______, _______,
                                            _______, _______,                    _______, _______,
                                            _______, _______,                    _______, _______,
                                            _______, _______,                    _______, _______
    ),

/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤       │       │       │       │ │       │       │       │       ├───────┬──────┐
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤   @   │   {   │   }   │   ^   │ │SG_LBRC│ PLAY  │ MUTE  │SG_RBRC├───────┼──────┤
 * │   ?   │   %   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   ⌦   │      │
 * ├───────┼───────┤   &   │   (   │   )   │   $   │ │   ←   │   ↓   │   ↑   │   →   ├───────┼──────┤
 * │   !   │   _   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤   ⏎   │      │
 * ├───────┼───────┤   |   │   [   │   ]   │   *   │ │   ⌫   │RSFT ⇧ │ RCMD  │LALT ⎇ ├───────┼──────┤
 * │   ~   │   #   ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤RCTL ⎈ │      │
 * └───────┴───────┤       │       │                                 │RAISE2 │RAISE3 ├───────┴──────┘
 *                 └───────┴───────┘                                 └───────┴───────┘
 *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
 *                                 ┃       ┃       ┃ ┃       ┃       ┃
 *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
 *                                 │       ┃       ┃ ┃       ┃       │
 *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
 *                                 │       │       │ │       │       │
 *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_RAISE1] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,

        KC_QUES, KC_PERC, KC_AT  , KC_LCBR, KC_RCBR, KC_CIRC,                    SG_LBRC, KC_MPLY, KC_MUTE, SG_RBRC, KC_DEL , _______,
        KC_EXLM, KC_UNDS, KC_AMPR, KC_LPRN, KC_RPRN, KC_DLR ,                    KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_ENT , _______,
        KC_TILD, KC_HASH, KC_PIPE, KC_LBRC, KC_RBRC, KC_ASTR,                    KC_BSPC, KC_RSFT, KC_RCMD, KC_LALT, KC_RCTL, _______,
                          _______, _______,                                                        RAISE2 , RAISE3 ,
                                            _______, _______,                    _______, _______,
                                            _______, _______,                    _______, _______,
                                            _______, _______,                    _______, _______
    ),

/*                 ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
 * ┌───────┬───────┤       │       │       │       │ │       │       │       │       ├───────┬──────┐
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤WHEEL ↓│MOUSE ↑│WHEEL ↑│       │ │TD_CYPE│ BTN1  │ BTN3  │ BTN2  ├───────┼──────┤
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │ ▷ 1  │
 * ├───────┼───────┤MOUSE ←│MOUSE ↓│MOUSE →│ WH_R  │ │       │ ACL2  │ ACL1  │ ACL0  ├───────┼──────┤
 * │       │ WH_L  ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │ ◎ ☐  │
 * ├───────┼───────┤  OS⎇  │  OS◆  │  OS⇧  │ BTN3  │ │       │  OS⇧  │  OS◆  │  OS⎇  ├───────┼──────┤
 * │       │  OS⎈  ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤  OS⎈  │ ◎ 1  │
 * └───────┴───────┤       │       │                                 │       │       ├───────┴──────┘
 *                 └───────┴───────┘                                 └───────┴───────┘
 *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
 *                                 ┃       ┃       ┃ ┃       ┃       ┃
 *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
 *                                 │       ┃       ┃ ┃       ┃       │
 *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
 *                                 │       │       │ │       │       │
 *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_RAISE2] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,

        _______, _______, KC_WH_D, KC_MS_U, KC_WH_U, _______,                    TD_CYPE, KC_BTN1, KC_BTN3, KC_BTN2, _______, DM_PLY1,
        _______, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,                    _______, KC_ACL2, KC_ACL1, KC_ACL0, _______, DM_RSTP,
        _______, OS_LCTL, OS_LALT, OS_LCMD, OS_LSFT, KC_BTN3,                    _______, OS_RSFT, OS_RCMD, OS_LALT, OS_RCTL, DM_REC1,
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
 * ├───────┼───────┤       │       │       │       │ │       │       │       │       ├───────┼──────┤
 * │       │       ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤       │      │
 * ├───────┼───────┤       │       │       │       │ │       │RSFT ⇧ │ RCMD  │LALT ⎇ ├───────┼──────┤
 * │       │       ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤RCTL ⎈ │      │
 * └───────┴───────┤       │       │                                 │       │       ├───────┴──────┘
 *                 └───────┴───────┘                                 └───────┴───────┘
 *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
 *                                 ┃       ┃       ┃ ┃       ┃       ┃
 *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
 *                                 │       ┃       ┃ ┃       ┃       │
 *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
 *                                 │       │       │ │       │       │
 *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_RAISE3] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                    _______, KC_RSFT, KC_RCMD, KC_LALT, KC_RCTL, _______,
                          _______, _______,                                                        _______, _______,
                                            _______, _______,                    _______, _______,
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
// ============================= TD ACCENTS ===================================
void dance_accent_a(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_A);
    } else {
        tap_code16(LALT(KC_E));
        tap_code(KC_A);
    }
    reset_tap_dance(state);
}
void dance_accent_e(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_E);
    } else {
        tap_code16(LALT(KC_E));
        tap_code(KC_E);
    }
    reset_tap_dance(state);
}
void dance_accent_u(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_U);
    } else {
        tap_code16(LALT(KC_E));
        tap_code(KC_U);
    }
    reset_tap_dance(state);
}
void dance_accent_i(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_I);
    } else {
        tap_code16(LALT(KC_E));
        tap_code(KC_I);
    }
    reset_tap_dance(state);
}
void dance_accent_o(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_O);
    } else {
        tap_code16(LALT(KC_E));
        tap_code(KC_O);
    }
    reset_tap_dance(state);
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
// ============================ TD COPY PASTE =================================
void dance_copy_paste(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(G(KC_C));
    } else {
        tap_code16(G(KC_V));
    }
}

// ============================================================================
// =============================== TD TOP ROW =================================
void dance_toprow_left(qk_tap_dance_state_t *state, void *user_data) {
    cur_row = state->count - 1;
    if (cur_row >= TR_ROWS_PER_SIDE) {
        cur_row = TR_ROWS_PER_SIDE;
    }
    reset_tap_dance(state);
}
void dance_toprow_right(qk_tap_dance_state_t *state, void *user_data) {
    cur_row = TR_ROWS_PER_SIDE + state->count - 1;
    if (cur_row >= TR_ROWS_PER_SIDE * 2) {
        cur_row = TR_ROWS_PER_SIDE;
    }
    reset_tap_dance(state);
}
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ACCENT_A] = ACTION_TAP_DANCE_FN(dance_accent_a),
    [TD_ACCENT_E] = ACTION_TAP_DANCE_FN(dance_accent_e),
    [TD_ACCENT_U] = ACTION_TAP_DANCE_FN(dance_accent_u),
    [TD_ACCENT_I] = ACTION_TAP_DANCE_FN(dance_accent_i),
    [TD_ACCENT_O] = ACTION_TAP_DANCE_FN(dance_accent_o),
    [TD_CLN_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_COLN, KC_SCLN),
    [TD_SPC_ENT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, spc_finished, spc_reset),
    [TD_TR_LEFT] = ACTION_TAP_DANCE_FN(dance_toprow_left),
    [TD_TR_RIGHT] = ACTION_TAP_DANCE_FN(dance_toprow_right),
    [TD_COPY_PASTE] = ACTION_TAP_DANCE_FN(dance_copy_paste),
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

        case ESC_LW1:
        case TD_LWR1:
            if (!record->event.pressed) {
                unregister_code(KC_LCMD);
                // Reset all layers including _RAISE2 used for mouse keys
                layer_clear();
            }
            break;

        case BSP_RS1:
            if (record->event.pressed) {
                // Clear _RAISE2 when we begin a new Raise sequence
                // in case it was left from before
                layer_off(_RAISE2);
            } else {
                layer_off(_RAISE1);
                layer_off(_RAISE3);
            }
            break;

        case DM_REC1:
            if (record->event.pressed) {
                layer_clear();
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

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ESC_LW1:
        case BSP_RS1:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

