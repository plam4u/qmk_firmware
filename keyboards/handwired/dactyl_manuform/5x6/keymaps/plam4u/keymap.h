#pragma once

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

#define COPY LCMD(KC_C)
#define PASTE LCMD(KC_V)
#define PBRD LCMD(LSFT(KC_C))

#define CTL OSM(MOD_LCTL)
#define SHIFT OSM(MOD_LSFT)
#define ALT OSM(MOD_LALT)
#define CMD OSM(MOD_LGUI)

#define CTL_Z CTL_T(KC_Z)
#define CTL_SL RCTL_T(KC_SLSH)
#define CM_LBRC SGUI(KC_LBRC)
#define CM_RBRC SGUI(KC_RBRC)

