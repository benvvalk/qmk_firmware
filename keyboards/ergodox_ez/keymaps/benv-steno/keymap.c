#include QMK_KEYBOARD_H
#include "keymap_steno.h"

#define BASE 0    // default layer (Dvorak)
#define NUM 1     // numbers layer
#define SYML 2    // left symbols layer
#define FN 3      // function keys layer (e.g. F1)
#define SYMR 4    // right symbols layer
#define NAV 5     // navigation (arrows, page up/down)
#define TXBOLT 6  // TxBolt Steno Virtual Serial
#define STENONAV 7 // quick access to arrow keys from TXBOLT layer
#define QWERTY 8  // QWERTY layout

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Default (Dvorak)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | ,/<  | ./>  |   P  |   Y  |      |           |      |   F  |   G  |   C  |   R  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | '/"    |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  | L      |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Shift  | ;/:  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | Shift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | Gui  | Alt  |      |      |                                        |     |      | Alt  | Gui  | Ctrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Esc  | Tab  |------|       |------| Enter  |Space |
 *                                 |(Shft)| (NAV)| BOLT |       |      | (NUM)  |(Shft)|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
  // left hand
  KC_NO,    KC_NO,           KC_NO,          KC_NO,         KC_NO,         KC_NO,    KC_NO,
  KC_NO,    KC_NO,           KC_COMM,        KC_DOT,        KC_P,          KC_Y,     KC_NO,
  KC_QUOT,  LT(SYMR, KC_A),  LCTL_T(KC_O),   LGUI_T(KC_E),  LALT_T(KC_U),  KC_I,
  KC_LSFT,  KC_SCLN,         KC_Q,           KC_J,          KC_K,          KC_X,     KC_NO,
  KC_LCTL,  KC_LGUI,         KC_LALT,        KC_NO,         KC_NO,
                                                                               KC_NO,  KC_NO,
                                                                                       KC_NO,
                                                 LSFT_T(KC_ESC), LT(NAV, KC_TAB), TG(TXBOLT),
  // right hand
  KC_NO,   KC_NO,        KC_NO,         KC_NO,          KC_NO,            KC_NO,         KC_NO,
  KC_NO,   KC_F,         KC_G,          KC_C,           KC_R,             KC_NO,         KC_NO,
           KC_D,  RALT_T(KC_H),  RGUI_T(KC_T),   RCTL_T(KC_N),   LT(SYML, KC_S),  LT(FN, KC_L),
  KC_NO,   KC_B,         KC_M,          KC_W,           KC_V,             KC_Z,        KC_RSFT,
                         KC_NO,         KC_NO,        KC_RALT,          KC_RGUI,       KC_RCTL,
  KC_NO, KC_NO,
  KC_NO,
  KC_NO, LT(NUM, KC_ENT), RSFT_T(KC_SPC)
),
/* Keymap 1: NUM layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   7  |  8   |  9   |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   4  |  5   |  6   |  -   |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   1  |  2   |  3   |  =   |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   0  |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[NUM] = LAYOUT_ergodox(
  // left hand
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_7,        KC_8,       KC_9,      KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_4,        KC_5,       KC_6,      KC_MINUS,
  KC_TRNS,   KC_TRNS,    KC_1,        KC_2,       KC_3,      KC_EQUAL,  KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,
                                                                        KC_TRNS,  KC_TRNS,
                                                                                  KC_TRNS,
                                                                 KC_0,  KC_TRNS,  KC_TRNS,
  // right hand
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
             KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
                         KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: SYML layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   &  |  *   |  (   |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   $  |  %   |  ^   |  _   |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   !  |  @   |  #   |  +   |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   )  |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYML] = LAYOUT_ergodox(
  // left hand
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_AMPR,     KC_ASTR,    KC_LPRN,   KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_DLR,      KC_PERC,    KC_CIRC,   KC_UNDS,
  KC_TRNS,   KC_TRNS,    KC_EXLM,     KC_AT,      KC_HASH,   KC_PLUS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,
                                                                        KC_TRNS,  KC_TRNS,
                                                                                  KC_TRNS,
                                                               KC_RPRN, KC_TRNS,  KC_TRNS,
  // right hand
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
             KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
                         KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: FN layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  F7  |  F8  |  F9  | F12  |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  F4  |  F5  |  F6  | F11  |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  F1  |  F2  |  F3  | F10  |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | F10  | F11  |------|       |------|      |      |
 *                                 |      |      | F12  |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[FN] = LAYOUT_ergodox(
  // left hand
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_F7,       KC_F8,      KC_F9,     KC_F12,    KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_F4,       KC_F5,      KC_F6,     KC_F11,
  KC_TRNS,   KC_TRNS,    KC_F1,       KC_F2,      KC_F3,     KC_F10,    KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,
                                                                        KC_TRNS,  KC_TRNS,
                                                                                  KC_TRNS,
                                                               KC_F10,  KC_F11,   KC_F12,
  // right hand
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
             KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
                         KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 4: SYMR layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  `   |  {   |  }   |  ?   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|  ~   |  (   |  )   |  /   |  \   |   |    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  [   |  ]   |  .   |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMR] = LAYOUT_ergodox(
  // left hand
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,
                                                                        KC_TRNS,  KC_TRNS,
                                                                                  KC_TRNS,
                                                              KC_TRNS,  KC_TRNS,  KC_TRNS,
  // right han
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   
  KC_TRNS,   KC_GRV,     KC_LCBR,     KC_RCBR,    KC_QUES,   KC_TRNS,   KC_TRNS,
             KC_TILDE,   KC_LPRN,     KC_RPRN,    KC_SLSH,   KC_BSLS,   KC_PIPE,
  KC_TRNS,   KC_TRNS,    KC_LBRC,     KC_RBRC,    KC_DOT,    KC_TRNS,   KC_TRNS,
                         KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 5: NAV Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | PgDn | PgUp |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Home | Left | Down | Up   | Right| End    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      | Del  | Bspc |
 *                                 `--------------------'       `--------------------'
 */
[NAV] = LAYOUT_ergodox(
       // left hand
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
                                                       KC_TRNS,KC_TRNS,
                                                               KC_TRNS,
                                               KC_TRNS,KC_TRNS,KC_TRNS,
    // right hand
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_HOME,  KC_PGDOWN, KC_PGUP,  KC_TRNS,   KC_TRNS,
              KC_HOME,  KC_LEFT,  KC_DOWN,   KC_UP,    KC_RIGHT,  KC_END, 
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,
              KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_DEL, KC_BSPC
),
/* Keymap 6: TxBolt (Serial)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   #  |   #  |   #  |   #  |   #  |      |           |      |   #  |   #  |   #  |   #  |   #  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   S  |   T  |   P  |   H  |   *  |      |           |      |   *  |   F  |   P  |   L  |   T  |   D    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  NAV   |   S  |   K  |   W  |   R  |   *  |------|           |------|   *  |   R  |   B  |   G  |   S  |   Z    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | NAV  | BOLT |       | NAV  | BOLT |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   A  |   O  |------|       |------|   E  |   U  |
 *                                 |      |      | BOLT |       | BOLT |      |      |
 *                                 `--------------------'       `--------------------'
 */
// TxBolt over Serial
[TXBOLT] = LAYOUT_ergodox(
       // left hand
       KC_NO,        STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  KC_NO,
       KC_NO,        STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, KC_NO,
       MO(STENONAV), STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,
	   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                                    MO(NAV), TG(TXBOLT),
                                                                  KC_NO,
                                               STN_A, STN_O, TG(TXBOLT),
       // right hand
       KC_NO,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  KC_NO,
       KC_NO,  STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
               STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
       KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       TG(TXBOLT), MO(NAV),
       KC_NO,
       TG(TXBOLT), STN_E, STN_U
),
/* Keymap 7: Steno Navigation Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | Win  |      |      |------|           |------| PgUp | Home |  Up  | End  |Ctrl+E| BkSpc  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Shft | Ctrl | Alt  |      |      |           |      | PgDn | Left | Down | Right|Ctrl+Y|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Spc  | BkSpc|------|       |------| Enter| Tab  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[STENONAV] = LAYOUT_ergodox(
       // left hand
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LGUI,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                       KC_TRNS,KC_TRNS,
                                                               KC_TRNS,
                                                KC_SPC,KC_BSPC,KC_TRNS,
    // right hand
    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,
    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,
               KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   LCTL(KC_E), KC_BSPC,
    KC_TRNS, KC_PGDOWN,  KC_LEFT,  KC_DOWN,  KC_RIGHT, LCTL(KC_Y), KC_TRNS,
               KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_ENT, KC_TAB
),
/* Keymap 8: Basic layer (QWERTY)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | `/~    |   1  |   2  |   3  |   4  |   5  | '/"  |           | }/]  |   6  |   7  |   8  |   9  |   0  | Esc    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  (   |           |  )   |   Y  |   U  |   I  |   O  |   P  | BkSpc  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CapsLk |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;/: | Enter  |
 * |--------+------+------+------+------+------|  -/_ |           | +/=  |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  ,/< |  ./> |  //? | Shift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | Win  | Alt  | [/{  |  L1  |                                       |  L1  |  \|  |  Alt |  Win | Ctrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | NAV  | BOLT |       | BOLT |  NAV   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Space| Ctrl |------|       |------|  Ctrl  | Tab  |
 *                                 |      |      | Alt  |       | Alt  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[QWERTY] = LAYOUT_ergodox(  // layer 0 : default
  // left hand
  KC_ESC,      KC_1,      KC_2,      KC_3,      KC_4,       KC_5,  KC_MINS,
  KC_TAB,      KC_Q,      KC_W,      KC_E,      KC_R,       KC_T,  KC_LPRN,
  KC_CLCK,     KC_A,      KC_S,      KC_D,      KC_F,       KC_G,
  KC_LSFT,     KC_Z,      KC_X,      KC_C,      KC_V,       KC_B,  KC_MINS,
  KC_LCTL,     KC_LWIN,   KC_LALT,   KC_LBRC,   MO(NUM),
                                                             MO(NAV), TG(TXBOLT),
                                                                           KC_NO,
                                                        KC_SPC, KC_LCTL, KC_LALT,
  // right hand
  KC_RBRC,  KC_6,      KC_7,      KC_8,      KC_9,       KC_0,   KC_ESC,
  KC_RPRN,  KC_Y,      KC_U,      KC_I,      KC_O,       KC_P,   KC_BSPC,
            KC_H,      KC_J,      KC_K,      KC_L,    KC_SCLN,   KC_ENT,
   KC_EQL,  KC_N,      KC_M,   KC_COMM,    KC_DOT,    KC_SLSH,   KC_RSFT,
         MO(NUM),   KC_BSLS,   KC_RALT,   KC_RWIN,    KC_RCTL,
  TG(TXBOLT), MO(NAV),
  KC_NO,
  KC_RALT, KC_RCTL, KC_TAB
),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    steno_set_mode(STENO_MODE_BOLT);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case TXBOLT:
            ergodox_right_led_1_on();
            break;
        default:
            break;
    }

};
