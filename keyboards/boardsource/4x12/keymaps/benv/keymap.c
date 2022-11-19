// Copyright 2022 @waffle87
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
    _MAIN,
    _NUM,
    _ARROWS,
    _BRACKET,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = LAYOUT_ortho_4x12(
    KC_GRV,                KC_QUOT,      KC_COMM,      KC_DOT,       KC_P,                KC_Y,  KC_F,  KC_G,         KC_C,         KC_R,         KC_L,         KC_BSPC,
    LT(_BRACKET, KC_ESC),  LSFT_T(KC_A), LCTL_T(KC_O), LGUI_T(KC_E), LALT_T(KC_U),        KC_I,  KC_D,  RALT_T(KC_H), RGUI_T(KC_T), RCTL_T(KC_N), RSFT_T(KC_S), KC_ENT,
    KC_LSFT,               KC_SCLN,      KC_Q,         KC_J,         KC_K,                KC_X,  KC_B,  KC_M,         KC_W,         KC_V,         KC_Z,         KC_RSFT,
    KC_PIPE,               KC_LCTL,      KC_LALT,      MO(_NUM),     LT(_ARROWS, KC_TAB), KC_NO, KC_NO, KC_SPC,       KC_LEFT,      KC_DOWN,      KC_UP,        KC_RGHT
  ),
  [_NUM] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, KC_7, KC_8,   KC_9,    _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_4, KC_5,   KC_6,    _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2,   KC_3,    _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_0, KC_DOT, _______, _______, _______
  ),
  [_ARROWS] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_BRACKET] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};
