// Copyright 2022 @waffle87
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "keymap_steno.h"

enum layers {
    _MAIN,
    _NUM,
    _ARROWS,
    _BRACKET,
    _STENO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = LAYOUT_ortho_4x12(
    KC_GRV,                KC_QUOT,      KC_COMM,      KC_DOT,       KC_P,                KC_Y,  KC_F,  KC_G,         KC_C,         KC_R,         KC_L,         KC_BSPC,
    LT(_BRACKET, KC_ESC),  LSFT_T(KC_A), LCTL_T(KC_O), LGUI_T(KC_E), LALT_T(KC_U),        KC_I,  KC_D,  RALT_T(KC_H), RGUI_T(KC_T), RCTL_T(KC_N), RSFT_T(KC_S), KC_ENT,
    TO(_MAIN),             KC_SCLN,      KC_Q,         KC_J,         KC_K,                KC_X,  KC_B,  KC_M,         KC_W,         KC_V,         KC_Z,         TO(_STENO),
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
  ),
  [_STENO] = LAYOUT_ortho_4x12(
    _______, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
    _______, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, STN_A,   STN_O,   _______, _______, STN_E,   STN_U,   _______, _______, _______
  )
};
