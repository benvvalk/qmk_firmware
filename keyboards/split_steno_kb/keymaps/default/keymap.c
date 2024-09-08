// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _STENO,
    _NAV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_STENO] = LAYOUT(
        STN_N1, STN_S1, STN_TL, STN_PL, STN_HL, STN_ST1,                 STN_ST3, STN_FR, STN_PR, STN_LR, STN_TR, STN_DR,
        STN_N1, STN_S2, STN_KL, STN_WL, STN_RL, STN_ST2,                 STN_ST4, STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR,
                                        STN_A,  STN_O,   PB_1,   STN_N2, STN_E,   STN_U
    ),
    [_NAV] = LAYOUT(
        _______, KC_LSFT, KC_MEH,  KC_HYPR, KC_LALT, _______,                      KC_DEL,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
        _______, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, _______,                      KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,
                                            _______, _______,  _______,   KC_BSPC, KC_SPC,  KC_TAB
    )
};

// Prototypes for internal QMK functions we call below.
bool add_gemini_key_to_chord(uint8_t key);
void send_steno_chord_gemini(void);
void steno_clear_chord(void);

// Clear any currently pressed steno keys (i.e. behave as if those
// keys were never pressed), then reset Plover to its default state
// by sending my custom "SKWH-FBGS" chord.
void reset_steno_state(void)
{
    // Clear any steno keys that are currently being held down.
    // (Behave as if those keys were never pressed.)
    //
    // This generally happens when I'm on the _STENO layer and I try
    // to press the momentary _NAV key (Capslock) and a modifier key
    // (e.g. K for Ctrl) at the same time. My intention is to press
    // the Ctrl key, but if the K keypress gets registered first, it
    // gets treated as the steno key for K. As a result, I end up
    // getting a "ghost" steno chord when I release the K key (K ->
    // "can"), and the Ctrl modifier never gets pressed like I wanted.
    //
    // I haven't found a good solution for this issue yet. For the
    // time being, I need to be careful to hold down the
    // Capslock/_MODE key before pressing any modifier/arrow keys on
    // the _MODE layer.

    steno_clear_chord();

    // Auto-send the "SKWH-FBGS" chord when entering the steno
    // layer, which I have mapped to "{MODE:RESET}{}{^}" in my
    // `user.json`. This resets the Plover state in various ways:
    //
    // * "{MODE:RESET}" disables any special output mode
    //   that might be active, such as CapsLock mode ("{MODE:CAPS}")
    //   or Title Case mode ("MODE:TITLE").
    //
    // * "{}" tells Plover to cancel any pending formatting
    //   commands for the next word. For example, if we told Plover
    //   to capitalize the next word with "{-|}", "{}" will
    //   cancel that instruction and ensure that the next
    //   is not capitalized.
    //
    // * "{^}" tells Plover to "attach" the next word.
    //   In other words, don't automatically insert a
    //   space before the next word.
    //
    // Note: See `quantum/process_keycode/process_steno.c` for
    // further examples of how the function below are used.

    add_gemini_key_to_chord(STN_SL - QK_STENO);
    add_gemini_key_to_chord(STN_KL - QK_STENO);
    add_gemini_key_to_chord(STN_WL - QK_STENO);
    add_gemini_key_to_chord(STN_HL - QK_STENO);
    add_gemini_key_to_chord(STN_FR - QK_STENO);
    add_gemini_key_to_chord(STN_BR - QK_STENO);
    add_gemini_key_to_chord(STN_GR - QK_STENO);
    add_gemini_key_to_chord(STN_SR - QK_STENO);

    send_steno_chord_gemini();
    steno_clear_chord();
}

// QMK callback for custom handling of key press/release events.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch(keycode) {

    case PB_1:

        // Capslock key on _STENO layer: Momentary switch to
        // _MODE layer (also provides modifier and arrow keys).
        //
        // Note: The "PB" in "PB_1" stands for "Programmable Button".
        // The PB_* keys are extra keycodes that have no predefined
        // meaning to the O/S (Windows, Mac, or Linux).

        if (record->event.pressed) {
            reset_steno_state();
            layer_on(_NAV);
        }
        else {
            layer_off(_NAV);
        }

        return false;
    }

    return true;
}