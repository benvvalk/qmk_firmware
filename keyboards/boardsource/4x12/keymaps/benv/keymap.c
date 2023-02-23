// Copyright 2022 @waffle87
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "keymap_steno.h"

enum layers {
    _MAIN,
    _NUM,
    _SYM,
    _FKEY,
    _ARROWS,
    _BRACKET,
    _STENO,
    _MODE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = LAYOUT_ortho_4x12(
    KC_GRV,            KC_QUOT,      KC_COMM,      LT(_BRACKET, KC_DOT), KC_P,                 KC_Y,     KC_F,     KC_G,             LT(_SYM, KC_C), KC_R,         KC_L,         KC_SLSH,
    LT(_MODE, KC_ESC), LSFT_T(KC_A), LCTL_T(KC_O), LGUI_T(KC_E),         LALT_T(KC_U),         KC_I,     KC_D,     RALT_T(KC_H),     RGUI_T(KC_T),   RCTL_T(KC_N), RSFT_T(KC_S), KC_ENT,
    KC_LSFT,           KC_SCLN,      KC_Q,         KC_J,                 KC_K,                 KC_X,     KC_B,     KC_M,             KC_W,           KC_V,         KC_Z,         KC_RSFT,
    KC_LCTL,           KC_LGUI,      KC_LALT,      LT(_FKEY, KC_DEL),    LT(_ARROWS, KC_BSPC), KC_LSFT,  KC_RSFT,  LT(_NUM, KC_SPC), KC_TAB,         XXXXXXX,      XXXXXXX,      PB_1
  ),
  [_NUM] = LAYOUT_ortho_4x12(
    _______, _______, KC_1,    KC_2,   KC_3, _______,  _______, _______, _______, _______, _______, _______,
    _______, _______, KC_4,    KC_5,   KC_6, KC_MINUS, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_7,    KC_8,   KC_9, KC_EQL,   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_DOT, KC_0, _______,  _______, _______, _______, _______, _______, _______
  ),
  [_SYM] = LAYOUT_ortho_4x12(
    _______, _______, KC_EXLM, KC_AT,   KC_HASH, _______,  _______, _______, _______, _______, _______, _______,
    _______, _______, KC_DLR,  KC_PERC, KC_CIRC, KC_UNDS,  _______, _______, _______, _______, _______, _______,
    _______, _______, KC_AMPR, KC_ASTR, KC_LPRN, KC_PLUS,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_DOT,  KC_RPRN, _______,  _______, _______, _______, _______, _______, _______
  ),
  [_FKEY] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, KC_F1,  KC_F2,   KC_F3,   KC_F11,  KC_PSCR,
    _______, _______, _______, _______, _______, _______, _______, KC_F4,  KC_F5,   KC_F6,   KC_F12,  _______,
    _______, _______, _______, _______, _______, _______, _______, KC_F7,  KC_F8,   KC_F9,   _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_F10, _______, _______, _______, _______
  ),
  [_ARROWS] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_BRACKET] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______, KC_PIPE,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_UNDS, _______, _______, _______
  ),
  [_STENO] = LAYOUT_ortho_4x12(
    STN_N1,    STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
    MO(_MODE), STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
    _______,   STN_N1,  STN_ST1, _______, _______, _______, _______, _______, _______, STN_ST2, STN_N2,  _______,
    _______,   _______, _______, STN_A,   STN_O,   STN_N1,  STN_N2,  STN_E,   STN_U,   _______, _______, _______
  ),
  [_MODE] = LAYOUT_ortho_4x12(
    _______, _______, KC_LCTL, KC_LSFT, KC_LSFT, _______, KC_DEL,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  TO(_MAIN),
    _______, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, PB_2,
    _______, _______, _______, _______, _______, _______, KC_TAB,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};

// Prototypes for internal QMK functions we call below.
bool add_gemini_key_to_chord(uint8_t key);
void send_steno_chord_gemini(void);
void steno_clear_chord(void);

// QMK callback for custom handling of key press/release events.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch(keycode) {

    case PB_1:

        // Momentarily switching to _STENO layer using foot pedal.
        //
        // Note: The "PB" in "PB_1" stands for "Programmable Button".
        // The PB_* keys are extra keycodes that have no predefined
        // meaning to the O/S (Windows, Mac, or Linux).

        if (record->event.pressed) {

            // Footswitch was pressed, so enable _STENO layer.

            layer_on(_STENO);

            // Auto-send the "T-FP" chord when entering the steno
            // layer, which maps to Plover "attach" command
            // ("{^}"). This prevents Plover from inserting a space
            // before the first word.
            //
            // This is critical for smoothly switching between steno
            // and regular typing, since I always expect the first
            // word after entering steno mode to appear exactly at the
            // cursor position.
            //
            // Note: See `quantum/process_keycode/process_steno.c` for
            // further examples of how these functions are used.

            add_gemini_key_to_chord(STN_TL - QK_STENO);
            add_gemini_key_to_chord(STN_FR - QK_STENO);
            add_gemini_key_to_chord(STN_PR - QK_STENO);

            send_steno_chord_gemini();
            steno_clear_chord();

            return false;
        }
        else
        {
            // Footswitch was released, so disable _STENO layer.
            layer_off(_STENO);
            return false;
        }

        break;

    case PB_2:

        // Switch to _STENO layer using key on _MODE layer.
        //
        // Note: The "PB" in "PB_2" stands for "Programmable Button".
        // The PB_* keys are extra keycodes that have no predefined
        // meaning to the O/S (Windows, Mac, or Linux).

        if (record->event.pressed) {

            // Enable steno layer (defined above).

            layer_on(_STENO);

            // Auto-send the "T-FP" chord when entering the steno
            // layer, which maps to Plover "attach" command
            // ("{^}"). This prevents Plover from inserting a space
            // before the first word.
            //
            // This is critical for smoothly switching between steno
            // and regular typing, since I always expect the first
            // word after entering steno mode to appear exactly at the
            // cursor position.
            //
            // Note: See `quantum/process_keycode/process_steno.c` for
            // further examples of how these functions are used.

            add_gemini_key_to_chord(STN_TL - QK_STENO);
            add_gemini_key_to_chord(STN_FR - QK_STENO);
            add_gemini_key_to_chord(STN_PR - QK_STENO);

            send_steno_chord_gemini();
            steno_clear_chord();

            return false;
        }

        break;
    }
    return true;
}
