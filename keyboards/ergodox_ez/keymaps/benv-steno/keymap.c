#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "sendchar.h"
#include "virtser.h"

#define BASE 0    // default layer (Dvorak)
#define NUM 1     // numbers layer
#define SYML 2    // left symbols layer
#define SYMR 3    // right symbols layer
#define TXBOLT 4  // TxBolt Steno Virtual Serial
#define STENONAV 5 // quick access to arrow keys from TXBOLT layer
#define NAV 6     // navigation (arrows, page up/down)
#define QWERTY 7  // QWERTY layout

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
 *   |      |      |      |      |      |                                        |     |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Esc  | Tab  |------|       |------| Enter  |Space |
 *                                 |(Shft)|      | BOLT |       |      | (NUM)  |(Shft)|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
  // left hand
  KC_NO,       KC_NO,            KC_NO,          KC_NO,         KC_NO, KC_NO,          KC_NO,
  KC_NO,       KC_QUOT,          KC_COMM,        KC_DOT,        KC_P,  KC_Y,           KC_NO,
  KC_QUOT,     LCTL_T(KC_A),     LGUI_T(KC_O),   LALT_T(KC_E),  KC_U,  KC_I,
  KC_LSFT,     KC_SCLN,          KC_Q,           KC_J,          KC_K,  KC_X,           KC_NO,
  KC_NO,       KC_NO,            KC_NO,          KC_NO,         KC_NO,
                                                                               KC_NO,  KC_NO,
                                                                                       KC_NO,
                                                             LSFT_T(KC_ESC),  KC_TAB,  TG(TXBOLT),
  // right hand
  KC_NO,   KC_NO,     KC_NO,         KC_NO,          KC_NO,         KC_NO,      KC_NO,   
  KC_NO,   KC_F,      KC_G,          KC_C,           KC_R,          KC_NO,      KC_NO,
           KC_D,      KC_H,  RALT_T(KC_T),   RGUI_T(KC_N),   RCTL_T(KC_S),      LT(SYML, KC_L),
  KC_NO,   KC_B,      KC_M,          KC_W,           KC_V,           KC_Z,    KC_RSFT,
           KC_NO,     KC_NO,         KC_NO,         KC_NO,          KC_NO,
  KC_NO, KC_NO,
  KC_NO,
  KC_NO, LT(NUM, KC_ENT), RSFT_T(KC_SPC),
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
  KC_TRNS,   KC_TRNS,    KC_4,        KC_5,       KC_6,      KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_1,        KC_2,       KC_3,      KC_TRNS,   KC_TRNS,
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
  KC_TRNS,   KC_TRNS,    KC_DLR,      KC_PERC,    KC_CIRC,   KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_EXLM,     KC_AT,      KC_HASH,   KC_TRNS,   KC_TRNS,
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
/* Keymap 3: SYMR layer
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
[SYMR] = LAYOUT_ergodox(
  // left hand
  KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_7,        KC_8,       KC_9,      KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_4,        KC_5,       KC_6,      KC_TRNS,
  KC_TRNS,   KC_TRNS,    KC_1,        KC_2,       KC_3,      KC_TRNS,   KC_TRNS,
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
// TxBolt Codes
#define Sl 0b00000001
#define Tl 0b00000010
#define Kl 0b00000100
#define Pl 0b00001000
#define Wl 0b00010000
#define Hl 0b00100000
#define Rl 0b01000001
#define Al 0b01000010
#define Ol 0b01000100
#define X  0b01001000
#define Er 0b01010000
#define Ur 0b01100000
#define Fr 0b10000001
#define Rr 0b10000010
#define Pr 0b10000100
#define Br 0b10001000
#define Lr 0b10010000
#define Gr 0b10100000
#define Tr 0b11000001
#define Sr 0b11000010
#define Dr 0b11000100
#define Zr 0b11001000
#define NM 0b11010000
#define GRPMASK 0b11000000
#define GRP0 0b00000000
#define GRP1 0b01000000
#define GRP2 0b10000000
#define GRP3 0b11000000
/* Keymap 4: TxBolt (Serial)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | BKSPC  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   #  |   #  |   #  |   #  |   #  |      |           |      |   #  |   #  |   #  |   #  |   #  |   #    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   S  |   T  |   P  |   H  |   *  |------|           |------|   *  |   F  |   P  |   L  |   T  |   D    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  NAV   |   S  |   K  |   W  |   R  |   *  |      |           |      |   *  |   R  |   B  |   G  |   S  |   Z    |
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
       KC_BSPC,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,        M(NM),   M(NM),   M(NM),   M(NM),   M(NM),  KC_NO,
       KC_NO,        M(Sl),   M(Tl),   M(Pl),   M(Hl),   M(X),
	   MO(STENONAV), M(Sl),   M(Kl),   M(Wl),   M(Rl),   M(X),   KC_NO,
       KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                       MO(NAV), TG(TXBOLT),
                                                     KC_NO,
                                  M(Al), M(Ol), TG(TXBOLT),
    // right hand
       KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,  M(NM),   M(NM),   M(NM),   M(NM),   M(NM),   M(NM),
               M(X),    M(Fr),   M(Pr),   M(Lr),   M(Tr),   M(Dr),
       KC_NO,  M(X),    M(Rr),   M(Br),   M(Gr),   M(Sr),   M(Zr),
                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       TG(TXBOLT), MO(NAV),
       KC_NO,
       TG(TXBOLT), M(Er), M(Ur)
),
/* Keymap 5: Steno Navigation Layer
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
/* Keymap 6: Navigation Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Win  |      |      |      |      |           |      | PgUp | Home |  Up  | End  | PgUp |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Shft | Ctrl | Alt  |      |      |------|           |------| PgDn | Left | Down | Right| PgDn |        |
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
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NAV] = LAYOUT_ergodox(
       // left hand
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_LGUI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                       KC_TRNS,KC_TRNS,
                                                               KC_TRNS,
                                               KC_TRNS,KC_TRNS,KC_TRNS,
    // right hand
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,   KC_TRNS,
            KC_PGDOWN,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_PGDOWN, KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
              KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 7: Basic layer (QWERTY)
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

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(NUM)                // FN1 - Momentary Layer 1 (Symbols)
};

uint8_t chord[4] = {0,0,0,0};
uint8_t pressed_count = 0;

void send_chord(void)
{
  for(uint8_t i = 0; i < 4; i++)
  {
    if(chord[i])
      virtser_send(chord[i]);
  }
  virtser_send(0);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  // We need to track keypresses in all modes, in case the user
  // changes mode whilst pressing other keys.
  if (record->event.pressed)
    pressed_count++;
  else
    pressed_count--;
  return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function

  if (record->event.pressed) {
    uint8_t grp = (id & GRPMASK) >> 6;
    chord[grp] |= id;
  }
  else {
    if (pressed_count == 0) {
      send_chord();
      chord[0] = chord[1] = chord[2] = chord[3] = 0;
    }
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
