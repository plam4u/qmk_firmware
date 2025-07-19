#include QMK_KEYBOARD_H

#define HEADER
#ifdef HEADER

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
#define MEETING HYPR(KC_F16)
#define APPWINS G(KC_GRV)

// Left hand
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

// Miscellaneous
#define CLIPBRD LSG(KC_C)

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
#define TAB_CMD CMD_T(KC_TAB)
#define ESC_MEH MEH_T(KC_ESC)
#define ENT_HPR HYPR_T(KC_ENT)
#define SPC_SFT LSFT_T(KC_SPC)
#define ENT_SFT RSFT_T(KC_ENT)
#define ENT_CTL CTL_T(KC_ENT)
#define BSP_SFT RSFT_T(KC_BSPC)
#define ACCENT  A(KC_E)
#define CENTER  MEH(KC_I)

// One Shot Modifiers
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LCMD OSM(MOD_LGUI)
#define OS_RCMD OSM(MOD_RGUI)

// Mouse
#ifdef MOUSEKEY_ENABLE
#    define MOUSE MO(_MOUSE)
#    define MS_CAPS LT(_MOUSE, KC_CAPS)
#else
#    define MOUSE KC_TRNS
#    define MS_CAPS KC_CAPS
#endif
#endif

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_5x6(
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,  KC_BSPC,

        ENT_HPR, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P    , KC_COLN,
        ESC_MEH, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,        KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN , KC_QUOT,
        ALT_TLD, CTL_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,        KC_N   , KC_M   , KC_COMM, KC_DOT , CTL_SL  , ALT_BSL,
                          PB_10  , KC_SPC ,                                            KC_EQL , KC_MINS,
                                            ESC_LW1, SPC_SFT,        ENT_RS2, BSP_RS1,
                                            BSP_SFT, TAB_CMD,        OS_RSFT, OS_RCMD,
                                            OS_LALT, ENT_CTL,        OS_RCTL, OS_LALT
    ),

    [_LOWER1] = LAYOUT_5x6(
        SS_ASD , _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,

        MEETING, _______, TABPREV, BACK   , FORWARD, TABNEXT,        KC_SLSH, KC_7   , KC_8   , KC_9   , KC_0   , _______,
        ITERM  , ALFRED ,  ACCENT, APPPREV, APPNEXT, HIDEAPP,        KC_ASTR, KC_4   , KC_5   , KC_6   , KC_COLN, _______,
        APPWINS, KC_LCTL, KC_LALT, KC_LCMD, KC_LSFT, CLIPBRD,        KC_EQL , KC_1   , KC_2   , KC_3   , KC_DOT , _______,
                          _______, _______,                                            KC_PLUS, KC_MINS,
                                            _______, LOWER2 ,        _______, _______,
                                            _______, _______,        _______, _______,
                                            _______, _______,        _______, _______
    ),

    [_LOWER2] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,

        _______, APP01  , APP02  , APP03  , APP04  , APP05  ,        DM_PLY1, KC_F7  , KC_F8  , KC_F9  , KC_F12 , _______,
        _______, APP06  , APP07  , APP08  , APP09  , APP10  ,        DM_RSTP, KC_F4  , KC_F5  , KC_F6  , KC_F11 , _______,
        _______, OS_LCTL, OS_LALT, OS_LCMD, OS_LSFT, CENTER ,        DM_REC1, KC_F1  , KC_F2  , KC_F3  , KC_F10 , _______,
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
                          _______, _______,                                            RAISE2 , _______,
                                            _______, _______,        _______, _______,
                                            _______, _______,        _______, _______,
                                            _______, _______,        _______, _______
    ),

    [_RAISE2] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,

        _______, _______, KC_BTN2, KC_BTN3, KC_BTN1, _______,        _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,
        _______, _______, KC_ACL2, KC_ACL1, KC_ACL0, _______,        KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
        _______, OS_LCTL, OS_LALT, OS_LCMD, OS_LSFT, KC_BTN3,        KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L, _______, _______,
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
        case ENT_SFT:
            return true;

        // case SPC_SFT:
        //     // press the key instead of holding it when another key is pressed
        //     return false;

        default:
            return false;
    }
}

