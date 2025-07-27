#include QMK_KEYBOARD_H

#ifndef NO_ACTION_LAYER
enum layer_names {
  _BASE,
  _GAMING,

  // Left hand
  _NUMPAD,
  _FNUMPAD,
  _L_SH_LETTER,
  _L_SH_KEYPAD,
  _L_SH_FKEY,
  _L_SH_ARROW,

  // Right hand
  _ARROWS,
  _R_SYMBOLS,
  _R_MOUSE,

  _EMPTY,
};
#define TO_QWER TO(_BASE)
#define TO_GAME TO(_GAMING)
#define LT_NP_E LT(_NUMPAD, KC_ESC)
#define LT_AR_B LT(_ARROWS, KC_BSPC)
#define TG_SYMB TG(_R_SYMBOLS)
#define MO_SYMB MO(_R_SYMBOLS)
#define LT_SYMB LT(_R_SYMBOLS, KC_ENT)
#define EQL_SYM LT(_R_SYMBOLS, KC_EQL)
#define LT_AM_E LT(_R_MOUSE, KC_ENT)
#define TG_MOUS TG(_R_MOUSE)
#define TO_FPAD TO(_FNUMPAD)
#define TG_SHLT TG(_L_SH_LETTER)
#define TG_SHKP TG(_L_SH_KEYPAD)
#define TG_SHFK TG(_L_SH_FKEY)
#define TG_SHAR TG(_L_SH_ARROW)
#endif

#ifdef QMK_KEYBOARD
// QMK_KEYBOARD is always defined.
// We use it to as a folding region.

enum custom_keycodes {
    APPPREV = SAFE_RANGE,
    APPNEXT,
    SS_ASD
};

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

#ifndef TAP_DANCE_ENABLE
#   define TD_CLN KC_SCLN
#elif
enum {
    TD_SCLN_COLN,
};
tap_dance_action_t tap_dance_actions[] = {
    [TD_SCLN_COLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
};
#   define TD_CLN TD(TD_SCLN_COLN)
#endif

#ifdef LEADER_ENABLE
void leader_start_user(void) {
    // Do something when the leader key is pressed
}
void leader_end_user(void) {
    if (leader_sequence_one_key(REDO)) {
        swap_hands_toggle();
    }
    else if (leader_sequence_two_keys(KC_D, KC_D)) {
        SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    }
    else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
        SEND_STRING("https://start.duckduckgo.com\n");
    }
    else if (leader_sequence_two_keys(KC_A, KC_S)) {
        tap_code16(LGUI(KC_S));
    }
}
#endif

#ifdef SWAP_HANDS_ENABLE
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    // Left hand keys are swapped with right hand keys
    {{0, 0}, {4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}},
    {{5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7}, {0, 7}},
    {{5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}},
    {{5, 9}, {4, 9}, {3, 9}, {2, 9}, {1, 9}, {0, 9}},
    {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}},
    {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}},

    // Right hand keys are swapped with left hand keys
    {{5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {5, 6}},
    {{5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
    {{5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
    {{5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
    {{0, 10}, {1, 10}, {2, 10}, {3, 10}, {10, 10}, {5, 10}},
    {{0, 11}, {1, 11}, {2, 11}, {3, 11}, {4, 11}, {11, 11}},
};
#endif

#ifdef COMBO_ENABLE
const uint16_t PROGMEM test_combo1[] = {KC_BSPC, KC_TAB, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_J, KC_K, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, KC_ENT),
    COMBO(test_combo2, KC_ESC),
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_5x6(
    _______, _______, _______, _______, _______, _______,        TO_QWER, _______, _______, _______, _______, TO_GAME,
    ENT_HPR, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_COLN,
    ESC_MEH, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,        KC_H   , KC_J   , KC_K   , KC_L   , TD_CLN , KC_QUOT,
    ALT_TLD, CTL_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,        KC_N   , KC_M   , KC_COMM, KC_DOT , CTL_SL , ALT_BSL,
                      KC_BSPC, KC_TAB ,                                            EQL_SYM , KC_MINS,
                                        LT_NP_E, KC_SPC ,        LT_SYMB, LT_AR_B,
                                        KC_LGUI, KC_LSFT,        OS_RSFT, OS_RGUI,
                                        KC_LALT, KC_LCTL,        OS_RCTL, OS_LALT
  ),

  [_NUMPAD] = LAYOUT_5x6(
    SS_ASD , _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, QK_BOOT,
    FOCUS  , APPQUIT, TABPREV, BACK   , FORWARD, TABNEXT,        KC_SLSH, KC_7   , KC_8   , KC_9   , KC_0   , _______,
    ITERM  , OS_LCTL, OS_LSFT, OS_LALT, OS_LGUI, HIDEAPP,        KC_ASTR, KC_4   , KC_5   , KC_6   , KC_COLN, KC_UNDS,
    APPWINS, ALFRED , ACCENT , APPPREV, APPNEXT, CLIPBRD,        KC_EQL , KC_1   , KC_2   , KC_3   , KC_DOT , KC_COMM,
                      TG_SHLT, TG_SHAR,                                            KC_PLUS, KC_MINS,
                                        _______, TO_FPAD,        _______, _______,
                                        _______, _______,        _______, _______,
                                        _______, _______,        _______, _______
  ),

  [_FNUMPAD] = LAYOUT_5x6(
    _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
    _______, APP01  , APP02  , APP03  , APP04  , APP05  ,        _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
    _______, OS_LCTL, OS_LSFT, OS_LALT, OS_LGUI, CENTER ,        _______, KC_F4  , KC_F5  , KC_F6  , KC_F11 , _______,
    _______, APP06  , APP07  , APP08  , APP09  , APP10  ,        _______, KC_F1  , KC_F2  , KC_F3  , KC_F12 , _______,
                      _______, _______,                                            _______, _______,
                                        _______, _______,        _______, _______,
                                        _______, _______,        _______, _______,
                                        _______, _______,        _______, _______
  ),

  [_ARROWS] = LAYOUT_5x6(
    _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,        SG_LBRC, KC_MPLY, KC_MNXT, SG_RBRC, _______, _______,
    _______, OS_LCTL, OS_LSFT, OS_LALT, OS_LGUI, _______,        KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
    _______, UNDO   , CUT    , COPY   , PASTE  , REDO   ,        TG_SYMB, KC_BSPC, KC_ENT , KC_DEL , KC_TAB , _______,
                      _______, _______,                                            _______, _______,
                                        _______, _______,        _______, _______,
                                        _______, _______,        _______, _______,
                                        _______, _______,        _______, _______
  ),

  [_R_SYMBOLS] = LAYOUT_5x6(
    _______, _______, _______, _______, _______, _______,        _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
    KC_QUES, KC_PERC, KC_AT  , KC_LCBR, KC_RCBR, KC_CIRC,        KC_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
    KC_EXLM, KC_UNDS, KC_AMPR, KC_LPRN, KC_RPRN, KC_DLR ,        KC_WH_R, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_L, _______,
    KC_TILD, KC_HASH, KC_PIPE, KC_LBRC, KC_RBRC, KC_ASTR,        _______, KC_WH_U, KC_WH_D, _______, _______, _______,
                      _______, _______,                                            _______, _______,
                                        _______, _______,        _______, _______,
                                        _______, _______,        _______, _______,
                                        _______, _______,        _______, _______
  ),

  [_L_SH_LETTER] = LAYOUT_5x6(
    TO_QWER, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
    _______, KC_P   , KC_O   , KC_I   , KC_U   , KC_Y   ,        KC_T   , KC_R   , KC_E   , KC_W   , KC_Q   , _______,
    _______, KC_SCLN, KC_L   , KC_K   , KC_J   , KC_H   ,        KC_G   , KC_F   , KC_D   , KC_S   , KC_A   , _______,
    _______, KC_SLSH, KC_DOT , KC_COMM, KC_M   , KC_N   ,        KC_B   , KC_V   , KC_C   , KC_X   , KC_Z   , _______,
                      TG_SHKP, TG_SHFK,                                            _______, _______,
                                        _______, _______,        _______, _______,
                                        _______, _______,        _______, _______,
                                        _______, _______,        _______, _______
  ),

  [_L_SH_KEYPAD] = LAYOUT_5x6(
    TO_QWER, _______, KC_1   , KC_2   , KC_3   , _______,        _______, _______, _______, _______, _______, _______,
    KC_PDOT, KC_PEQL, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0,        _______, _______, _______, _______, _______, _______,
    KC_HOME, KC_PAST, KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS,        _______, _______, _______, _______, _______, _______,
    _______, KC_PSLS, KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS,        _______, _______, _______, _______, _______, _______,
                      _______, _______,                                   _______, _______,
                                        _______, _______,        _______, _______,
                                        _______, _______,        _______, _______,
                                        _______, _______,        _______, _______
  ),

  [_L_SH_FKEY] = LAYOUT_5x6(
    TO_QWER, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
    _______, _______, KC_F7  , KC_F8  , KC_F9  , _______,        _______, _______, _______, _______, _______, _______,
    _______, _______, KC_F4  , KC_F5  , KC_F6  , _______,        _______, _______, _______, _______, _______, _______,
    _______, _______, KC_F1  , KC_F2  , KC_F3  , _______,        _______, _______, _______, _______, _______, _______,
                      _______, _______,                                   _______, _______,
                                        _______, _______,        _______, _______,
                                        _______, _______,        _______, _______,
                                        _______, _______,        _______, _______
  ),

  [_L_SH_ARROW] = LAYOUT_5x6(
    TO_QWER, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
    _______, _______, PB_10  , KC_UP  , KC_MPLY, _______,        _______, _______, _______, _______, _______, _______,
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,        _______, _______, _______, _______, _______, _______,
    _______, _______, KC_BSPC, KC_ENT , KC_DEL , _______,        _______, _______, _______, _______, _______, _______,
                      _______, _______,                                   _______, _______,
                                        _______, _______,        _______, _______,
                                        _______, _______,        _______, _______,
                                        _______, _______,        _______, _______
  ),

  [_GAMING] = LAYOUT_5x6(
    _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,        TO_QWER, _______, _______, _______, _______, _______,
    KC_ENT , KC_T   , KC_Q   , KC_W   , KC_E   , KC_R   ,        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_COLN,
    KC_ESC , KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   ,        KC_H   , KC_J   , KC_K   , KC_L   , TD_CLN , KC_QUOT,
    KC_LALT, KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   ,        KC_N   , KC_M   , KC_COMM, KC_DOT , CTL_SL , ALT_BSL,
                      KC_BSPC, KC_TAB ,                                            KC_EQL , KC_MINS,
                                        KC_ESC , KC_SPC ,        LT_AM_E, LT_AR_B,
                                        KC_LCTL, KC_LSFT,        OS_RSFT, OS_RCTL,
                                        KC_LALT, KC_LGUI,        OS_RGUI, OS_LALT
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t os_locked_mods = get_oneshot_locked_mods();

    switch (keycode) {

        case SS_ASD:
            if (record->event.pressed) {
                SEND_STRING("$init(asdasd)\n");
            }
            return false;


        case LT_NP_E:
            if (!record->event.pressed) {
                if (!(os_locked_mods & MOD_MASK_GUI)) {
                    unregister_code(KC_LCMD);
                }
                layer_clear(); // reset layers for predictable behavior
            }
            break;

        case LT_AR_B:
            if (!record->event.pressed) {
                layer_clear(); // reset layers for predictable behavior
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

    case LT_AM_E:
    case LT_AR_B:
    case LT_NP_E:
    case ENT_CTL:
    case ENT_HPR:
    case ENT_SFT:
    case ALT_BSL:
    case ALT_TLD:
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

