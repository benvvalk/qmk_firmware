// Copyright 2022 @waffle87
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
    _MAIN,
    _RAISE,
    _LOWER,
};

#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_QUOT,      KC_COMM,      KC_DOT,       KC_P,         KC_Y,   KC_F,   KC_G,         KC_C,         KC_R,         KC_L,         KC_BSPC,
    KC_ESC,  LSFT_T(KC_A), LCTL_T(KC_O), LGUI_T(KC_E), LALT_T(KC_U), KC_I,   KC_D,   RALT_T(KC_H), RGUI_T(KC_T), RCTL_T(KC_N), RSFT_T(KC_S), KC_QUOT,
    KC_LSFT, KC_SCLN,      KC_Q,         KC_J,         KC_K,         KC_X,   KC_B,   KC_M,         KC_W,         KC_V,         KC_Z,         KC_ENT,
    KC_PIPE, KC_LCTL,      KC_LALT,      KC_LGUI,      LOWER,        KC_SPC, KC_SPC, RAISE,        KC_LEFT,      KC_DOWN,      KC_UP,        KC_RGHT
  ),
  [_RAISE] = LAYOUT_ortho_4x12(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    QK_BOOT,   _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
  ),
  [_LOWER] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  )
};
