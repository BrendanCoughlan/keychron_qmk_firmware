/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

// clang-format off
enum layers{
  US_BASE,  //US keyboard layout, configured as German in OS
  US_SHIFT, //simulated shift from US_BASE
  DE, //German layout, also what the OS thinks the KB is
  MOUSE_MOVE, //Base layer for mouse movement
  MOUSE_SCROLL, //Mouse srcolling, simulated shift from MOUSE_MOVE
  FN //Configuration layer superimposed on everything
};

#define FN_SFT MO(FN)
#define US_SFT MO(US_SHIFT)
#define MS_SFT MO(MOUSE_SCROLL)
#define MS_LK DF(MOUSE_SCROLL)
#define MS_ULK DF(MOUSE_MOVE)
#define SW_DE DF(DE)
#define SW_US DF(US_BASE)
#define SW_MS DF(MOUSE_MOVE)
#define CT_ESC MT(MOD_LCTL, KC_ESC)
#define PARAG LSFT(KC_3)
#define SZETT KC_MINS
#define AUML KC_QUOT
#define OUML KC_SCLN
#define UUML KC_LBRC
#define EURO RALT(KC_E)
#define CPRT RALT(KC_C)
#define DEGREE LSFT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[US_BASE] = LAYOUT_iso_109(
    KC_ESC,                  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,         KC_F10,        KC_F11,        KC_F12,        KC_PSCR,  KC_SCRL,  KC_PAUS, KC_F13,  KC_F14,  KC_F15,  KC_F16,
    LSFT(KC_EQL),  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,          KC_SLSH,       LSFT(KC_0),    KC_BSPC,       KC_INS,   KC_HOME,  KC_PGUP, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
    KC_TAB,        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Z,     KC_U,     KC_I,     KC_O,     KC_P,          RALT(KC_8),    RALT(KC_9),    KC_ENT,        KC_DEL,   KC_END,   KC_PGDN, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
    CT_ESC,        KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     LSFT(KC_COMM), LSFT(KC_NUHS), RALT(KC_MINS),                                KC_P4,   KC_P5,   KC_P6,
    US_SFT,        KC_EQL,   KC_Y,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,        LSFT(KC_7),                   US_SFT,                  KC_UP,             KC_P1,   KC_P2,   KC_P3,   KC_PENT,
    KC_LCTL,       KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_LALT,       KC_RGUI,       FN_SFT,        KC_RCTL,       KC_LEFT,  KC_DOWN,  KC_RGHT, KC_P0,            KC_PDOT),

[US_SHIFT] = LAYOUT_iso_109(
    _______,                      _______,    _______,     _______,    _______,    _______,    _______,    _______,       _______,    _______,        _______,       _______,       _______,       _______,  _______,  _______, _______, _______, _______, _______,
    RALT(KC_RBRC),  LSFT(KC_1),   RALT(KC_Q), KC_NUHS,     LSFT(KC_4), LSFT(KC_5), KC_GRV,     LSFT(KC_6), LSFT(KC_RBRC), LSFT(KC_8), LSFT(KC_9),     LSFT(KC_SLSH), KC_RBRC,       _______,       _______,  _______,  _______, _______, _______, _______, _______,
    _______,        LSFT(KC_Q),   LSFT(KC_W), LSFT(KC_E),  LSFT(KC_R), LSFT(KC_T), LSFT(KC_Z), LSFT(KC_U), LSFT(KC_I),    LSFT(KC_O), LSFT(KC_P),     RALT(KC_7),    RALT(KC_0),    _______,       _______,  _______,  _______, _______, _______, _______, _______,
    _______,        LSFT(KC_A),   LSFT(KC_S), LSFT(KC_D),  LSFT(KC_F), LSFT(KC_G), LSFT(KC_H), LSFT(KC_J), LSFT(KC_K),    LSFT(KC_L), LSFT(KC_DOT),   LSFT(KC_2),                   RALT(KC_NUBS),                              _______, _______, _______,
    _______,        LSFT(KC_EQL), LSFT(KC_Y), LSFT(KC_X),  LSFT(KC_C), LSFT(KC_V), LSFT(KC_B), LSFT(KC_N), LSFT(KC_M),    KC_NUBS,    LSFT(KC_NUBS),  LSFT(KC_MINS),                _______,                 _______,           _______, _______, _______, _______,
    _______,        _______,      _______,                                         _______,                                           _______,        _______,       _______,       _______,       _______,  _______,  _______, _______,          _______),

[DE] = LAYOUT_iso_109(
    KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_PSCR,  KC_SCRL,  KC_PAUS, KC_F13,  KC_F14,  KC_F15,  KC_F16,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, KC_INS,   KC_HOME,  KC_PGUP, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_ENT,  KC_DEL,   KC_END,   KC_PGDN, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
    CT_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_NUHS,                              KC_P4,   KC_P5,   KC_P6,
    KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,           KC_UP,             KC_P1,   KC_P2,   KC_P3,   KC_PENT,
    KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI,  FN_SFT,   KC_RCTL, KC_LEFT,  KC_DOWN,  KC_RGHT, KC_P0,            KC_PDOT),

[MOUSE_MOVE] = LAYOUT_iso_109(
    KC_ESC,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,  KC_BTN1,  KC_BTN2,  KC_BTN3,  KC_BTN4,  KC_BTN5,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSPC, KC_INS,   MS_LK,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_TAB,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BTN1,  KC_BTN3,  KC_BTN2,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BTN3, KC_BTN1,  KC_BTN3,  KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    MS_LK,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  XXXXXXX,  XXXXXXX,            XXXXXXX,                              KC_BTN4, KC_BTN5, KC_P6,
    MS_SFT,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  MS_LK,    XXXXXXX,  XXXXXXX,  XXXXXXX,            MS_SFT,            KC_MS_U,           KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN2,
    KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_BTN1,                                KC_LALT,  KC_RGUI,  FN_SFT,   KC_RCTL, KC_MS_L,  KC_MS_D,  KC_MS_R, XXXXXXX,          XXXXXXX),

[MOUSE_SCROLL] = LAYOUT_iso_109(
    KC_ESC,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSPC, KC_INS,   MS_ULK,   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
    KC_TAB,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
    MS_ULK,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  XXXXXXX,  XXXXXXX,            XXXXXXX,                              XXXXXXX, XXXXXXX,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  MS_ULK,   XXXXXXX,  XXXXXXX,  XXXXXXX,            _______,           KC_WH_U,           XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
    KC_LCTL,  KC_LGUI,  KC_LALT,                                XXXXXXX,                                KC_LALT,  KC_RGUI,  FN_SFT,   KC_RCTL, KC_WH_L,  KC_WH_D,  KC_WH_R, XXXXXXX,           XXXXXXX),

[FN] = LAYOUT_iso_109(
    _______,            KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU, KC_SNAP,  KC_SIRI,  RGB_MOD,  KC_F13,  KC_F14,   KC_F15,  KC_F16,
    DEGREE,   XXXXXXX,  XXXXXXX,  PARAG,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  SZETT,    XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  EURO,     XXXXXXX,  XXXXXXX,  XXXXXXX,  SW_US,    XXXXXXX,  XXXXXXX,  XXXXXXX,  UUML,     XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  SW_DE,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  OUML,     AUML,               XXXXXXX,                               XXXXXXX, XXXXXXX,  XXXXXXX,
    KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  CPRT,     XXXXXXX,  XXXXXXX,  XXXXXXX,  SW_MS,    XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_RSFT,           KC_UP,              XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
    _______,  _______,  _______,                                XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,           XXXXXXX),
};
