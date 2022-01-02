/* Copyright 2017 Joseph Wasson
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef PROCESS_STENO_H
#define PROCESS_STENO_H

#include "quantum.h"

typedef enum { STENO_MODE_BOLT, STENO_MODE_GEMINI } steno_mode_t;

bool     process_steno(uint16_t keycode, keyrecord_t *record);
void     steno_init(void);
void     steno_set_mode(steno_mode_t mode);
uint8_t *steno_get_state(void);
uint8_t *steno_get_chord(void);

// Note:
//
// I (benv) changed the methods from private to public by
// removing the `static` keyword from the function definitions in
// `process_steno.c` and adding the lines below.
//
// I use these two functions in my `keymap.c` to auto-send the "T-FP"
// chord (attach) whenever I switch my steno/TXBOLT layer. (See
// `process_record_user` function in
// `keyboards/ergodox_ez/keymaps/benv-steno/keymap.c`).

void     send_steno_chord(void);
bool     update_state_bolt(uint8_t key, bool press);

#endif
