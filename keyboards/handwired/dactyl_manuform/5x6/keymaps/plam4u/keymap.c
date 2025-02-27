#include QMK_KEYBOARD_H
#include "keymap.h"

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    APPPREV, APPNEXT,
    TR0, TR1, TR2, TR3, TR4, TR5, TR6, TR7, TR8, TR9, TR10, TR11,
    SS_DOTA1, SS_ASD
};
const uint16_t TR_ROWS_PER_SIDE = 3;
uint16_t cur_row = 0;
const uint16_t top_row_map[6][12] = {
    // Columns guide
 // { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
    // Left side
    { _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______ },
    { _______, KC_INT1, KC_INT2, KC_INT3, KC_INT4, KC_INT5, KC_INT6, KC_INT7, KC_INT8, KC_INT9, KC_NUM , _______ },
    { _______, KC_LANG1,KC_LANG2,KC_LANG3,KC_LANG4,KC_LANG5,KC_LANG6,KC_LANG7,KC_LANG8,KC_LANG9,KC_INS , _______ },
    // Right side
    { _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______ },
    { _______, KC_F11 , KC_F12 , KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , _______ },
    { _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______ },
};
enum layer_names {
    _QWERTY, _QWERTY_DESIGN, _GAMING, _DOTA, _DOTA_L, _DOTA_R,
    _STARBOUND, _STARBOUND_L,
    _LOWER1, _LOWER2, _LOWER3, _LOWER4,
    _RAISE1, _RAISE2, _RAISE3, _RAISE4,
    _BOTH1, _BOTH2, _BOTH3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_5x6(
        TD_TR_L, TR1    , TR2    , TR3    , TR4    , TR5    ,        TR6    , TR7    , TR8    , TR9    , TR10    , TD_TR_R,

        ENT_HPR, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P    , KC_COLN,
        ESC_MEH, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,        KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN , KC_QUOT,
        ALT_TLD, CTL_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,        KC_N   , KC_M   , KC_COMM, KC_DOT , CTL_SL  , ALT_BSL,
                          PB_10  , KC_SPC ,                                            KC_EQL , KC_MINS,
                                            ESC_LW1, SPC_SFT,        ENT_LW3, BSP_RS1,
                                            BSP_SFT, TAB_CMD,        OS_RSFT, OS_RCMD,
                                            OS_LALT, ENT_CTL,        OS_RCTL, OS_LALT
    ),

    [_QWERTY_DESIGN] = LAYOUT_5x6(
        TD_TR_L, TR1    , TR2    , TR3    , TR4    , TR5    ,        TR6    , TR7    , TR8    , TR9    , TR10    , TD_TR_R,

        ENT_HPR, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P    , KC_COLN,
        ESC_MEH, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,        KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN , KC_QUOT,
        KC_GRV , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,        KC_N   , KC_M   , KC_COMM, KC_DOT , CTL_SL  , KC_BSLS,
                          KC_LBRC, KC_RBRC,                                            KC_EQL , KC_MINS,
                                            ESC_LW1, KC_SPC ,        ENT_LW3, BSP_RS1,
                                            KC_LSFT, KC_LCMD,        OS_RSFT, OS_RCMD,
                                            KC_LALT, KC_LCTL,        OS_RCTL, OS_LALT
    ),
    [_GAMING] = LAYOUT_5x6(
        KC_TAB , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,        KC_6   , KC_7   , KC_8   , KC_9   , KC_0    , DF(_QWERTY),

        KC_F1  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P    , _______,
        KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,        KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN , KC_QUOT,
        KC_LALT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,        KC_N   , KC_M   , KC_COMM, KC_DOT , CTL_SL  , ALT_BSL,
                          KC_LSFT, KC_LCMD,                                            KC_EQL , KC_MINS,
                                            KC_ESC , KC_SPC ,        ENT_LW3, BSP_RS1,
                                            KC_F9  , KC_GRV ,        KC_TAB , OS_RCMD,
                                            KC_F2  , KC_U   ,        OS_RCTL, OS_LALT
    ),
    [_DOTA] = LAYOUT_5x6(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,        _______, _______, _______, _______, _______, _______,

        KC_KP_8, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,        _______, _______, _______, _______, _______, _______,
        KC_F11 , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,        _______, _______, _______, _______, _______, _______,
        KC_BSPC, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,        _______, _______, _______, _______, _______, _______,
                          KC_LBRC, KC_RBRC,                                            _______, _______,
                                            DOTA_L , DOTA_R ,     _______, _______,
                                            KC_LCTL, KC_LSFT,     _______, _______,
                                            KC_LALT,   KC_F1,     _______, _______
    ),
    [_DOTA_L] = LAYOUT_5x6(
        KC_MINS, C(KC_1), C(KC_2), C(KC_3), C(KC_4), C(KC_5),        _______, _______, _______, _______, _______, _______,

        KC_BSLS, KC_P   , KC_O   , KC_I   , KC_U   , KC_Y   ,        _______, _______, _______, _______, _______, _______,
        KC_QUOT, KC_SCLN, KC_L   , KC_K   , KC_J   , KC_H   ,        _______, _______, _______, _______, _______, _______,
        KC_F2  , KC_SLSH, KC_DOT , KC_COMM, KC_M   , KC_N   ,        _______, _______, _______, _______, _______, _______,
                          KC_F3  , KC_F4  ,                                            _______, _______,
                                            XXXXXXX, DF_QWR1,     _______, _______,
                                            _______, _______,     _______, _______,
                                            _______, _______,     _______, _______
    ),
    [_DOTA_R] = LAYOUT_5x6(
         KC_F10 , KC_F9  , KC_F8  , KC_F7  , KC_F6  , KC_F5  ,        _______, _______, _______, _______, _______, _______,

         KC_0   , KC_9   , KC_8   , KC_UP  , KC_7   , KC_6   ,        _______, _______, _______, _______, _______, _______,
         KC_KP_0, KC_KP_9, KC_LEFT, KC_DOWN, KC_RGHT, KC_F14,        _______, _______, _______, _______, _______, _______,
         KC_KP_1, KC_KP_2, KC_KP_3, KC_F12, KC_KP_4, KC_KP_5,        _______, _______, _______, _______, _______, _______,
                           KC_KP_6, KC_KP_7,                                            _______, _______,
                                            _______, XXXXXXX,     _______, _______,
                                            _______, _______,     _______, _______,
                                            _______, _______,     _______, _______
    ),
    [_STARBOUND] = LAYOUT_5x6(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,        _______, _______, _______, _______, _______, _______,

        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,        _______, _______, _______, _______, _______, _______,
        KC_F11 , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,        _______, _______, _______, _______, _______, _______,
        KC_BSPC, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,        _______, _______, _______, _______, _______, _______,
                          KC_LBRC, KC_RBRC,                                            _______, _______,
                                            STARB_L, KC_SPC ,     _______, _______,
                                            KC_LCTL, KC_LSFT,     _______, _______,
                                            KC_LALT, KC_F1  ,     _______, _______
    ),
    [_STARBOUND_L] = LAYOUT_5x6(
        KC_MINS, KC_0   , KC_9   , KC_8   , KC_7   , KC_6   ,        _______, _______, _______, _______, _______, _______,

        KC_BSLS, KC_P   , KC_O   , KC_I   , KC_U   , KC_Y   ,        _______, _______, _______, _______, _______, _______,
        KC_QUOT, KC_SCLN, KC_L   , KC_K   , KC_J   , KC_H   ,        _______, _______, _______, _______, _______, _______,
        KC_F2  , KC_SLSH, KC_DOT , KC_COMM, KC_M   , KC_N   ,        _______, _______, _______, _______, _______, _______,
                          KC_F3  , KC_F4  ,                                            _______, _______,
                                            XXXXXXX, DF_QWR1,     _______, _______,
                                            _______, _______,     _______, _______,
                                            _______, _______,     _______, _______
    ),
    [_LOWER1] = LAYOUT_5x6(
         SS_ASD, _______, _______, _______, DF_QWR5, DF_QWR4,        _______, _______, _______, _______, _______, _______,

        MEETING, _______, TABPREV, BACK   , FORWARD, TABNEXT,        KC_SLSH, KC_7   , KC_8   , KC_9   , KC_0   , DF_QWR3,
        ITERM  , ALFRED ,  ACCENT, APPPREV, APPNEXT, HIDEAPP,        KC_ASTR, KC_4   , KC_5   , KC_6   , KC_COLN, DF_QWR1,
        APPWINS, KC_LCTL, KC_LALT, KC_LCMD, KC_LSFT, CLIPBRD,        KC_EQL , KC_1   , KC_2   , KC_3   , KC_DOT , DF_QWR2,
                          LOWER4 , LOWER3 ,                                            KC_PLUS, KC_MINS,
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

    [_LOWER3] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,

        _______, _______, KC_BTN2, KC_BTN3, KC_BTN1, TD_CYPE,        TD_CYPE, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,
        _______, _______, KC_ACL2, KC_ACL1, KC_ACL0, _______,        KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
        _______, OS_LCTL, OS_LALT, OS_LCMD, OS_LSFT, KC_BTN3,        KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L, _______, _______,
                          _______, _______,                                            _______, _______,
                                            _______, _______,        _______, _______,
                                            _______, _______,        _______, _______,
                                            _______, _______,        _______, _______
    ),

    [_LOWER4] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,

        _______, APP11  , APP12  , APP13  , APP14  , APP15  ,        APP21  , APP22  , APP23  , APP24  , APP25  , _______,
        _______, APP16  , APP17  , APP18  , APP19  , APP20  ,        APP26  , APP27  , APP28  , APP29  , APP30  , _______,
        _______, OS_LCTL, OS_LALT, OS_LCMD, OS_LSFT, _______,        APP31  , APP32  , APP33  , APP34  , APP35  , _______,
                          _______, _______,                                            _______, _______,
                                            _______, _______,        _______, _______,
                                            _______, _______,        _______, _______,
                                            _______, _______,        _______, _______
    ),

    [_RAISE1] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, DF_QWR5, DF_QWR4, DF_QWR1,

        KC_QUES, KC_PERC, KC_AT  , KC_LCBR, KC_RCBR, KC_CIRC,        SG_LBRC, KC_MPLY, KC_MNXT, SG_RBRC, _______, _______,
        KC_EXLM, KC_UNDS, KC_AMPR, KC_LPRN, KC_RPRN, KC_DLR ,        KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
        KC_TILD, KC_HASH, KC_PIPE, KC_LBRC, KC_RBRC, KC_ASTR,        _______, KC_BSPC, KC_ENT , KC_DEL , _______, _______,
                          _______, _______,                                            RAISE2 , RAISE3 ,
                                            _______, _______,        _______, _______,
                                            _______, _______,        _______, _______,
                                            _______, _______,        _______, _______
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
// ================================= TD XCV ===================================
static td_tap_t xcv_td_state = {
    .state = TD_NONE
};
void dance_x_cut(qk_tap_dance_state_t *state, void *user_data) {
    xcv_td_state.state = cur_dance(state);
    switch (xcv_td_state.state) {
        case TD_SINGLE_HOLD:
            tap_code16(LCMD(KC_X));
            break;
        default:
            tap_code(KC_X);
    }
    reset_tap_dance(state);
    xcv_td_state.state = TD_NONE;
}
void dance_c_copy(qk_tap_dance_state_t *state, void *user_data) {
    xcv_td_state.state = cur_dance(state);
    switch (xcv_td_state.state) {
        case TD_SINGLE_HOLD:
            tap_code16(LCMD(KC_C));
            break;
        default:
            tap_code(KC_C);
    }
    reset_tap_dance(state);
    xcv_td_state.state = TD_NONE;
}
void dance_v_paste(qk_tap_dance_state_t *state, void *user_data) {
    xcv_td_state.state = cur_dance(state);
    switch (xcv_td_state.state) {
        case TD_SINGLE_HOLD:
            tap_code16(LCMD(KC_V));
            break;
        default:
            tap_code(KC_V);
    }
    reset_tap_dance(state);
    xcv_td_state.state = TD_NONE;
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
    [TD_X_CUT] = ACTION_TAP_DANCE_FN(dance_x_cut),
    [TD_C_COPY] = ACTION_TAP_DANCE_FN(dance_c_copy),
    [TD_V_PASTE] = ACTION_TAP_DANCE_FN(dance_v_paste),
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

        case SS_DOTA1:
            if (record->event.pressed) {
                register_code(KC_LCMD);
                register_code(KC_LSFT);
                tap_code(KC_4);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCMD);
            }
            return false;
        case SS_ASD:
            if (record->event.pressed) {
                SEND_STRING("$init(asdasd)\n");
            }
            return false;



        case ESC_LW1:
        case TD_LWR1:
            if (!record->event.pressed) {
                unregister_code(KC_LCMD);
                layer_off(_LOWER1);
                layer_off(_LOWER2);
                layer_off(_LOWER3);
                layer_off(_LOWER4);
            }
            break;

        case BSP_RS1:
            if (!record->event.pressed) {
                layer_off(_RAISE1);
                layer_off(_RAISE2);
                layer_off(_RAISE3);
                layer_off(_RAISE4);
}
            break;

       // case DM_REC1:
       //     if (!record->event.pressed) {
       //         layer_clear();
       //     }
       //     break;

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
        case DOTA_L:
        case DOTA_R:
            // Immediately select the hold action when another key is pressed.
            return true;
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
        default:
            return false;
    }
}

