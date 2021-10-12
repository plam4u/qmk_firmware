#include QMK_KEYBOARD_H

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

#define CTL OSM(MOD_LCTL)
#define SHIFT OSM(MOD_LSFT)
#define ALT OSM(MOD_LALT)
#define CMD OSM(MOD_LGUI)

#define CTL_Z CTL_T(KC_Z)
#define CTL_SL RCTL_T(KC_SLSH)
#define CM_LBRC SGUI(KC_LBRC)
#define CM_RBRC SGUI(KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_5x6(
        KC_GRV  ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                           KC_6    ,KC_7   ,KC_8   ,KC_9   ,KC_0     ,RESET  ,
        KC_TAB  ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                           KC_Y    ,KC_U   ,KC_I   ,KC_O   ,KC_P     ,KC_MINS,
        KC_ESC  ,HOME_A ,HOME_S ,HOME_D ,HOME_F ,KC_G   ,                           KC_H    ,HOME_J ,HOME_K ,HOME_L ,HOME_SCLN,KC_QUOT,
        SHIFT   ,CTL_Z  ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,                           KC_N    ,KC_M   ,KC_COMM,KC_DOT ,CTL_SL   ,KC_BSLS,
                        ALT, CMD,                                                            KC_LGUI, KC_LALT, 
                                    MO(1), KC_SPC,                                  KC_ENT, MO(2), 
                                        KC_BSPC, KC_TAB,                        KC_BSPC, KC_ESC, 
                                        MEH_T(KC_F17), ALL_T(KC_F16),           KC_GRV, MO(_RAISE)
    ),
    [1] = LAYOUT_5x6(
        KC_F12  , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                           KC_F6   ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
        _______ ,KC_PERC,KC_CIRC,KC_LCBR,KC_RCBR,KC_PIPE,                           _______ ,KC_P7  ,KC_P8  ,KC_P9  ,_______,_______,
        _______ ,KC_AT  ,KC_DLR ,KC_LPRN,KC_RPRN,KC_AMPR,                           _______ ,KC_P4  ,KC_P5  ,KC_P6  ,KC_MINS,_______,
        _______ ,KC_HASH,KC_ASTR,KC_LBRC,KC_RBRC,KC_MINS,                           KC_EQL  ,KC_P1  ,KC_P2  ,KC_P3  ,KC_EQL ,_______,
                    _______, _______,                                                           KC_DOT, KC_P0, 
                                    _______, _______,                               _______, _______, 
                                        _______, _______,                       _______, _______, 
                                        _______, _______,                       _______, _______
    ),
    [2] = LAYOUT_5x6(
        KC_F12  ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                           KC_F6   ,KC_F7  ,KC_F8  ,KC_F9   ,KC_F10 ,KC_F11 ,
        _______ ,KC_PERC,KC_CIRC,KC_LCBR,KC_RCBR,KC_PIPE,                           CM_LBRC ,KC_MPLY,KC_MUTE,CM_RBRC ,_______,KC_MUTE,
        _______ ,KC_AT  ,KC_DLR ,KC_LPRN,KC_RPRN,KC_AMPR,                           KC_LEFT ,KC_DOWN,KC_UP  ,KC_RGHT ,_______,KC_VOLU,
        _______ ,KC_HASH,KC_ASTR,KC_LBRC,KC_RBRC,KC_MINS,                           KC_EQL  ,KC_BSPC,KC_ENT ,KC_DEL  ,_______,KC_VOLD,
                    _______, _______,                                                           _______, _______, 
                                    _______, _______,                               _______, _______, 
                                        _______, _______,                       _______, _______, 
                                        _______, _______,                       _______, _______
    )
};
