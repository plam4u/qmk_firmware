#include QMK_KEYBOARD_H

#ifdef QMK_KEYBOARD
// QMK_KEYBOARD is always defined.
// We use it to as a folding region.

enum custom_keycodes {
    APPPREV = SAFE_RANGE,
    APPNEXT,
    SS_ASD
};

enum layer_names {
    _QWERTY,
    _LOWER1, _LOWER2,
    _RAISE1, _RAISE2,
};

// Layer keys
#define ESC_LW1 LT(_LOWER1, KC_ESC)
#define BSP_RS1 LT(_RAISE1, KC_BSPC)
#define ENT_RS2 LT(_RAISE2, KC_ENT)
#define LOWER2  TO(_LOWER2)
#define RAISE2  TO(_RAISE2)

// Apps
#define ALFRED  G(KC_SPC)
#define ITERM   G(KC_ESC)
#define HIDEAPP MEH(KC_G)
#define FOCUS   HYPR(KC_F16)
#define APPWINS G(KC_GRV)
#define APPQUIT G(KC_Q)

#define APP01   S(KC_F11)
#define APP02   S(KC_F12)
#define APP03   S(KC_F13)
#define APP04   S(KC_F14)
#define APP05   S(KC_F15)
#define APP06   S(KC_F16)
#define APP07   S(KC_F17)
#define APP08   S(KC_F18)
#define APP09   S(KC_F19)
#define APP10   S(KC_F20)

#define APP11   A(KC_F11)
#define APP12   A(KC_F12)
#define APP13   A(KC_F13)
#define APP14   A(KC_F14)
#define APP15   A(KC_F15)
#define APP16   A(KC_F16)
#define APP17   A(KC_F17)
#define APP18   A(KC_F18)
#define APP19   A(KC_F19)
#define APP20   A(KC_F20)

#define APP21   C(KC_F11)
#define APP22   C(KC_F12)
#define APP23   C(KC_F13)
#define APP24   C(KC_F14)
#define APP25   C(KC_F15)
#define APP26   C(KC_F16)
#define APP27   C(KC_F17)
#define APP28   C(KC_F18)
#define APP29   C(KC_F19)
#define APP30   C(KC_F20)

// Miscellaneous
#define CLIPBRD HYPR(KC_C)
#define CUT     G(KC_X)
#define COPY    G(KC_C)
#define PASTE   G(KC_V)
#define UNDO    G(KC_Z)
#define REDO    LSG(KC_Z)

// Combinations
#define CTL_Z   CTL_T(KC_Z)
#define CTL_SL  RCTL_T(KC_SLSH)
#define ALT_TLD ALT_T(KC_GRV)
#define ALT_BSL ALT_T(KC_BSLS)
#define G_LBRC  G(KC_LBRC)
#define G_RBRC  G(KC_RBRC)
#define BACK    G_LBRC
#define FORWARD G_RBRC
#define SG_LBRC RSG(KC_LBRC)
#define SG_RBRC RSG(KC_RBRC)
#define TABPREV SG_LBRC
#define TABNEXT SG_RBRC
#define BSP_CMD CMD_T(KC_BSPC)
#define TAB_SFT SFT_T(KC_TAB)
#define ESC_MEH MEH_T(KC_ESC)
#define ENT_HPR HYPR_T(KC_ENT)
#define SPC_SFT LSFT_T(KC_SPC)
#define ENT_SFT RSFT_T(KC_ENT)
#define ENT_CTL CTL_T(KC_ENT)
#define BSP_SFT RSFT_T(KC_BSPC)
#define ACCENT  A(KC_E)
#define CENTER  MEH(KC_I)
#define CTRL_C  C(KC_C)
#define CMD_01  G(KC_1)
#define CMD_02  G(KC_2)
#define CMD_03  G(KC_3)
#define CMD_04  G(KC_4)
#define CMD_05  G(KC_5)
#define CMD_06  G(KC_6)
#define CMD_07  G(KC_7)
#define CMD_08  G(KC_8)
#define CMD_09  G(KC_9)
#define CMD_00  G(KC_0)
#define CMD_A   G(KC_A)

#endif

#ifdef TAP_DANCE_ENABLE
enum {
    TD_SCLN_COLN,
};
tap_dance_action_t tap_dance_actions[] = {
    [TD_SCLN_COLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
};
#define TD_CLN TD(TD_SCLN_COLN)
#endif

#ifdef LEADER_ENABLE
// void leader_start_user(void) {
//     // Do something when the leader key is pressed
// }
// void leader_end_user(void) {
//     if (leader_sequence_one_key(KC_F)) {
//         SEND_STRING("QMK is awesome.");
//     }
//     else if (leader_sequence_two_keys(KC_D, KC_D)) {
//         SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
//     }
//     else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
//         SEND_STRING("https://start.duckduckgo.com\n");
//     }
//     else if (leader_sequence_two_keys(KC_A, KC_S)) {
//         tap_code16(LGUI(KC_S));
//     }
// }
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_5x6(
        QK_LEAD, REDO   , CUT    , COPY   , PASTE  , UNDO   ,        _______, _______, CTRL_C , _______, _______,  QK_LEAD,

        ENT_HPR, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P    , KC_COLN,
        ESC_MEH, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,        KC_H   , KC_J   , KC_K   , KC_L   , TD_CLN  , KC_QUOT,
        ALT_TLD, CTL_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,        KC_N   , KC_M   , KC_COMM, KC_DOT , CTL_SL  , ALT_BSL,
                          KC_LBRC, KC_RBRC,                                            KC_EQL , KC_MINS,
                                            ESC_LW1, KC_SPC ,        ENT_RS2, BSP_RS1,
                                            ENT_CTL, TAB_SFT,        OS_RSFT, OS_RCTL,
                                            OS_LALT, BSP_CMD,        OS_RGUI, OS_LALT
    ),

    [_LOWER1] = LAYOUT_5x6(
        SS_ASD , CMD_01 , CMD_02 , CMD_03 , CMD_04 , CMD_05 ,        CMD_06 , CMD_07 , CMD_08 , CMD_09 , CMD_00 , QK_BOOT,

        FOCUS  , APPQUIT, TABPREV, BACK   , FORWARD, TABNEXT,        KC_SLSH, KC_7   , KC_8   , KC_9   , KC_0   , _______,
        ITERM  , ALFRED , ACCENT , APPPREV, APPNEXT, HIDEAPP,        KC_ASTR, KC_4   , KC_5   , KC_6   , KC_COLN, _______,
        APPWINS, OS_LCTL, OS_LSFT, OS_LALT, OS_LGUI, CLIPBRD,        KC_EQL , KC_1   , KC_2   , KC_3   , KC_DOT , _______,
                          PB_10  , CMD_A  ,                                            KC_PLUS, KC_MINS,
                                            _______, LOWER2 ,        _______, _______,
                                            _______, _______,        _______, _______,
                                            _______, _______,        _______, _______
    ),

    [_LOWER2] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,

        _______, APP01  , APP02  , APP03  , APP04  , APP05  ,        DM_PLY1, KC_F7  , KC_F8  , KC_F9  , KC_F12 , _______,
        _______, APP06  , APP07  , APP08  , APP09  , APP10  ,        DM_RSTP, KC_F4  , KC_F5  , KC_F6  , KC_F11 , _______,
        _______, OS_LCTL, OS_LSFT, OS_LALT, OS_LGUI, CENTER ,        DM_REC1, KC_F1  , KC_F2  , KC_F3  , KC_F10 , _______,
                          _______, _______,                                            _______, _______,
                                            _______, _______,        _______, _______,
                                            _______, _______,        _______, _______,
                                            _______, _______,        _______, _______
    ),

     [_RAISE1] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,

        KC_QUES, KC_PERC, KC_AT  , KC_LCBR, KC_RCBR, KC_CIRC,        SG_LBRC, KC_MPLY, KC_MNXT, SG_RBRC, _______, _______,
        KC_EXLM, KC_UNDS, KC_AMPR, KC_LPRN, KC_RPRN, KC_DLR ,        KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
        KC_TILD, KC_HASH, KC_PIPE, KC_LBRC, KC_RBRC, KC_ASTR,        _______, KC_BSPC, KC_ENT , KC_DEL , _______, _______,
                          _______, _______,                                            _______, _______,
                                            _______, _______,        _______, _______,
                                            _______, _______,        _______, _______,
                                            _______, _______,        _______, _______
    ),

    [_RAISE2] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,

        _______, APP11  , APP12  , APP13  , APP14  , APP15  ,        _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,
        _______, KC_ACL2, KC_ACL2, KC_ACL1, KC_ACL0, _______,        KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
        _______, APP16  , APP17  , APP18  , APP19  , APP20  ,        KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L, _______, _______,
                          _______, _______,                                            _______, _______,
                                            _______, _______,        _______, _______,
                                            _______, _______,        _______, _______,
                                            _______, _______,        _______, _______
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        case SS_ASD:
            if (record->event.pressed) {
                SEND_STRING("$init(asdasd)\n");
            }
            return false;

        case ESC_LW1:
            // clear keys used in other combianations
            if (!record->event.pressed) {
                unregister_code(KC_LCMD);
                layer_off(_LOWER1);
                layer_off(_LOWER2);
            }
            break;

        case BSP_RS1:
            // clear keys used in other combianations
            if (!record->event.pressed) {
                layer_off(_RAISE1);
                layer_off(_RAISE2);
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
    }

    return true;
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case ALT_TLD:
        case ENT_HPR:
        case ESC_LW1:
        case BSP_RS1:
        case ALT_BSL:
        case ENT_CTL:
        case ENT_RS2:
            // Immediately select the hold action when another key is pressed.
            return true;

        case CTL_Z:
        case CTL_SL:
            // Press the key instead holding it when another key is pressed.
            return false;

        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SPC_SFT:
        case TAB_SFT:
        case ENT_CTL:
        case BSP_CMD:
        case ENT_SFT:
            return true;

        // case SPC_SFT:
        //     // press the key instead of holding it when another key is pressed
        //     return false;

        default:
            return false;
    }
}

