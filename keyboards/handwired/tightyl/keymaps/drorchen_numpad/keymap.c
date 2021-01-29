/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 * Copyright 2020 Okke Formsma <okke@formsma.nl>
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
#include QMK_KEYBOARD_H

enum layers { QWERTY = 0, ARROWS, NUMBERS, RAISE };

#define DC_ARROWS MO(ARROWS)
#define DC_RAISE MO(RAISE)

/*
#define DC_A MT(MOD_LGUI, KC_A)
#define DC_S MT(MOD_LSFT, KC_S)
#define DC_D MT(MOD_LCTL, KC_D)
#define DC_F MT(MOD_LALT, KC_F)

#define DC_J MT(MOD_RALT, KC_J)
#define DC_K MT(MOD_RCTL, KC_K)
#define DC_L MT(MOD_RSFT, KC_L)
#define DC_SCLN MT(MOD_RGUI, KC_SCLN)
*/

#define DC_LCTL LM(RAISE, MOD_LCTL)
#define DC_TAB MT(MOD_LSFT, KC_TAB)

#define DC_BSPC LT(ARROWS, KC_BSPC)
#define DC_ESC LT(ARROWS, KC_ESC)
#define DC_ENT LT(NUMBERS, KC_ENT)

#define DC_ARRW 0x999
#define DC_NEQL 0x1000

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DC_ARRW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;
        case DC_NEQL:
            if (record->event.pressed) {
                SEND_STRING("!=");
            }
            break;
        }
    return true;
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
};


/*
#define DC_F5 MT(MOD_LGUI, KC_F5)
#define DC_F6 MT(MOD_LSFT, KC_F6)
#define DC_F7 MT(MOD_LCTL, KC_F7)
#define DC_F8 MT(MOD_LALT, KC_F8)

#define DC_LEFT MT(MOD_RALT, KC_LEFT)
#define DC_DOWN MT(MOD_RCTL, KC_DOWN)
#define DC_RGHT MT(MOD_RSFT, KC_RGHT)
*/

/*
#define DC_LT MT(MOD_LGUI, KC_LT)
#define DC_GT MT(MOD_LSFT, KC_GT)
#define DC_LBRC MT(MOD_LCTL, KC_LBRC)
#define DC_RBRC MT(MOD_LALT, KC_RBRC)

#define DC_4 MT(MOD_RALT, KC_4)
#define DC_5 MT(MOD_RCTL, KC_5)
#define DC_6 MT(MOD_RSFT, KC_6)
#define DC_0 MT(MOD_RGUI, KC_0)
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                ,-------------------------------------------.
 * |        | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  |                | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  |        |
 * |-------------------------------------------|                |-------------------------------------------|
 * |        |   Q  |   W  |   E  |   R  |   T  |                |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
 * |        |   A  |   S  |  D   |   F  |   G  |                |   H  |   J  |   K  |   L  | ;  : |        |
 * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |                |   N  |   M  | ,  < | . >  | /  ? |        |
 * `----------------------+------+------+------+------,  ,------+------+------+------+----------------------'
 *                 | raise| gui  | alt  | tab  | space|  | bspc | enter| esc  | del  |  |   |
 *                 |      |      |      | shift| ctrl |  |      | NUMS | ARWS |      |      |
 *                 `----------------------------------'  '--------------------'------'------'
 */
    [QWERTY] = LAYOUT(
      _______,   KC_1,   KC_2,     KC_3,    KC_4,       KC_5 ,                                      KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    _______,
      _______,   KC_Q,   KC_W,     KC_E,    KC_R,       KC_T,                                       KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    _______,
      _______,   KC_A,   KC_S,     KC_D,    KC_F,       KC_G,                                       KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
      _______,   KC_Z,   KC_X,     KC_C,    KC_V,       KC_B,                                       KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                         KC_LGUI,  KC_LALT, KC_LCTL,    DC_TAB, KC_SPACE,                  KC_BSPC, DC_ENT, DC_ESC,  KC_DEL,  KC_QUOT
    ),

/*
 * Arrows
 *
 * ,-------------------------------------------.                ,-------------------------------------------.
 * |        |      |      |      |      |      |                |      |      |      |      |      |        |
 * |-------------------------------------------|                |-------------------------------------------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |                |      | home | up   | end  |      |        |
 * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                |      | left | down | right|      |        |
 * |--------+------+------+------+------+------+                +------+------+------+------+------+--------|
 * |        |  F9  |  F10 |  F11 |  F12 | CAPS |                |      | pgdn | pgup |      |      |        |
 * `----------------------+------+------+------+------,  ,------+------+------+------+----------------------'
 *                 | RST  | gui  | ARWS | tab  | space|  | bspc | enter| esc  | del  |  |   |
 *                 |      |      |      | NUMS |      |  |      | ctrl | shift|      |      |
 *                 `----------------------------------'  '--------------------'------'------'
 * mous4 = back
 * mous5 = forward
 */
    [ARROWS] = LAYOUT(
      _______,   _______, _______, _______, _______,    _______,                                    _______, _______, _______, _______,  _______, _______,
      _______,   KC_CIRC, KC_AMPR, KC_ASTR, KC_PERC,    _______,                                    _______, KC_HOME, KC_UP,   KC_END,   _______, _______,
      _______,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,     _______,                                    _______, KC_LEFT, KC_DOWN, KC_RGHT,  _______, _______,
      _______,  _______, _______, _______, _______,     _______,                                    _______, KC_PGUP, KC_PGDN, _______,  _______, _______,
                          _______,   _______, _______,    _______, _______,                 _______,  _______, _______, _______, _______
    ),
/*
 * Numbers: numbers, specials
 * keep ,. for easy typing of numbers and IPs, keep backspace for obvious reasons
 * ,-------------------------------------------.                ,-------------------------------------------.
 * |        |      |      |      |      |      |                |      |      |  /   |  *   |  -   |        |
 * |-------------------------------------------|                |-------------------------------------------|
 * |        | ` ~  | - _  | = +  | ' "  |      |                |      |  7   |  8   |  9   |  +   |        |
 * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
 * |        |  <   |  >   |  [   |  ]   |      |                |      |  4   |  5   |  6   |  0   |        |
 * |--------+------+------+------+------+------+                +------+------+------+------+------+--------|
 * |        |      |      |  {   |  }   |      |                |      |  1   |  2   |  3   | \ |  |        |
 * `----------------------+------+------+------+------,  ,------+------+------+------+----------------------'
 *                 | RST  | gui  | ARWS | tab  | space|  | bspc | enter| esc  |  0   |  .   |
 *                 |      |      |      | NUMS |      |  |      | ctrl | shift|      |      |
 *                 `----------------------------------'  '--------------------'------'------'

 */
    [NUMBERS] = LAYOUT(
      RESET,   _______, _______, _______, _______,   _______,                                       _______, _______, KC_PSLS, KC_PAST, KC_PMNS, _______,
      _______, KC_TILD, KC_UNDS, KC_PLUS, KC_PIPE,   KC_LBRC,                                       KC_RBRC, KC_7,    KC_8,    KC_9,    KC_PPLS, _______,
      _______, KC_GRV,  KC_MINS, KC_EQL,  KC_BSLS,   KC_LPRN,                                       KC_RPRN, KC_4,    KC_5,    KC_6,    KC_0,    _______,
      _______, _______, _______, DC_ARRW, DC_NEQL,   KC_LCBR,                                       KC_RCBR,  KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
                        _______, _______, _______,   _______, _______,                    _______,  _______, _______, KC_0,  KC_PDOT
    ),
/*
 * ,-------------------------------------------.                ,-------------------------------------------.
 * |        | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  |                | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  |        |
 * |-------------------------------------------|                |-------------------------------------------|
 * |        |   Q  |   W  |   E  |   R  |   T  |                |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
 * |        |   A  |   S  |  D   |   F  |   G  |                |   H  |   J  |   K  |   L  | ;  : |        |
 * |--------+------+------+------+------+------|                |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |                |   N  |   M  | ,  < | . >  | /  ? |        |
 * `----------------------+------+------+------+------,  ,------+------+------+------+----------------------'
 *                 |      | gui  | alt  | tab  | space|  | bspc | enter| esc  | del  |  |   |
 *                 |      |      |      | shift| ctrl |  |      | ctrl | shift|      |      |
 *                 `----------------------------------'  '--------------------'------'------'
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,      _______,                                    _______, KC_HOME, KC_UP,   KC_END,   _______, _______,
      _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8,      _______,                                    _______, KC_LEFT, KC_DOWN, KC_RGHT,  _______, _______,
      _______,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     _______,                                    _______, KC_PGUP, KC_PGDN, _______,  _______, _______,
 */
    [RAISE] = LAYOUT(
      _______, _______, _______, _______, _______,   _______,                                       _______, _______, _______, _______, _______, _______,
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,     _______,                                       _______, _______, _______, _______, _______, _______,
      _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,     _______,                                       _______, _______, _______, _______, _______, _______,
      _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,    _______,                                       _______, _______, _______, _______, _______, _______,
                        _______, _______, _______,   _______, _______,                    _______,  _______, _______, _______, _______
    ),
};
