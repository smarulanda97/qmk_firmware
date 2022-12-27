/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------.                            ,-----------------------------------------------------------------------------.
    CTL_T(KC_ESC),        KC_Q,  LT(0,KC_W),        KC_E,        KC_R,        KC_T,                                     KC_Y,        KC_U,        KC_I,  LT(0,KC_O),        KC_P,     KC_BSPC,
  //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
     LT(3,KC_TAB),  LT(0,KC_A),  LT(0,KC_S),        KC_D,  LT(0,KC_F),  LT(0,KC_G),                                     KC_H,        KC_J,        KC_K,  LT(0,KC_L),     KC_SCLN,     KC_QUOT,
  //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
          KC_LSFT,  LT(0,KC_Z),  LT(0,KC_X),  LT(0,KC_C),  LT(0,KC_V),        KC_B,                               LT(0,KC_N),        KC_M,     KC_COMM,      KC_DOT,     KC_SLSH, RSFT_T(KC_SLSH),
  //|------------+------------+------------+------------+------------+------------+------------|  |------------+------------+------------+------------+------------+------------+------------|
                                                                MO(3),       MO(1),      KC_SPC,         KC_ENT,       MO(2),        MO(4)
                                                      //`---------------------------------------'  `-------------------------------------'
  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------.                            ,-----------------------------------------------------------------------------.
    CTL_T(KC_ESC),     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                                  XXXXXXX,  RCS(KC_UP),       KC_UP,     KC_PSCR,     XXXXXXX,     KC_BSPC,
  //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
     LT(3,KC_TAB),     XXXXXXX,     KC_LCTL,     KC_LALT,     KC_LALT,      KC_DEL,                             RCS(KC_LEFT),     KC_LEFT,     KC_DOWN,    KC_RIGHT,RCS(KC_RGHT),      KC_DEL,
  //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
          XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                                  XXXXXXX,     XXXXXXX,RCS(KC_DOWN),     XXXXXXX,     XXXXXXX,     XXXXXXX,
  //|------------+------------+------------+------------+------------+------------+------------|  |------------+------------+------------+------------+------------+------------+------------|
                                                              _______,     _______,      KC_SPC,         KC_ENT,       MO(5),      KC_RGUI
                                                      //`---------------------------------------'  `-------------------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_HASH,                      KC_EXLM, KC_AMPR, KC_PIPE, KC_PSLS, KC_BSLS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,   KC_AT,                       KC_DLR,  KC_EQL, KC_PMNS, KC_UNDS,  KC_GRV,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,                      KC_PLUS,KC_MINUS, KC_LABK, KC_RABK, KC_TILD, KC_QUES,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, _______,  KC_SPC,     KC_ENT, _______, KC_RGUI
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_ASTR,    KC_7,    KC_8,   KC_9,  KC_MINS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PSLS,    KC_4,    KC_5,   KC_6,  KC_PLUS,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PERC,    KC_1,    KC_2,    KC_3, KC_CIRC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, _______,  KC_SPC,     KC_ENT,    KC_0, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, XXXXXXX, XXXXXXX, KC_BRIU, KC_VOLU, XXXXXXX,                      XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, KC_BRID, KC_VOLD, XXXXXXX,                      XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX,                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     KC_ENT, KC_RALT, KC_RCTL
                                      //`--------------------------'  `--------------------------'
  ),

  [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, _______,  KC_SPC,     KC_ENT, _______, KC_RGUI
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_QWERTY 0
#define L_NAVIGATE 2
#define L_SYMBOLS 4
#define L_NUMPAD 8
#define L_FUNCS 16
#define L_ADJUST 32

void oled_render_layer_state(void) {
    oled_write_P(PSTR("@smarulanda97 - "), false);
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_QWERTY:
            oled_write_ln_P(PSTR("Qwerty\n"), false);
            break;
        case L_NAVIGATE:
            oled_write_ln_P(PSTR("Navigate\n"), false);
            break;
        case L_SYMBOLS:
            oled_write_ln_P(PSTR("Symbols\n"), false);
            break;
        case L_NUMPAD:
            oled_write_ln_P(PSTR("Numpad\n"), false);
            break;
        case L_FUNCS:
            oled_write_ln_P(PSTR("Functions\n"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_NAVIGATE:
        case L_ADJUST|L_SYMBOLS:
        case L_ADJUST|L_NUMPAD:
        case L_ADJUST|L_FUNCS:
        case L_ADJUST|L_NAVIGATE|L_SYMBOLS:
        case L_ADJUST|L_NAVIGATE|L_SYMBOLS|L_NUMPAD:
        case L_ADJUST|L_NAVIGATE|L_SYMBOLS|L_NUMPAD|L_FUNCS:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }

    switch (keycode) {
        case LT(0,KC_Z):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_Z)); // Ctrl-Z
                return false;
            }
            return true;
        case LT(0,KC_X):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_X)); // Ctrl-X
                return false;
            }
            return true;
        case LT(0,KC_C):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_C)); // Ctrl-C
                return false;
            }
            return true;
        case LT(0,KC_V):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_V)); // Ctrl-V
                return false;
            }
            return true;
        case LT(0,KC_A):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_A)); // Ctrl-A
                return false;
            }
            return true;
        case LT(0,KC_S):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_S)); // Ctrl-S
                return false;
            }
            return true;
        case LT(0,KC_F):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_F)); // Ctrl-F
                return false;
            }
            return true;
        case LT(0,KC_G):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_G)); // Ctrl-G
                return false;
            }
            return true;
        case LT(0,KC_W):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_W)); // Ctrl-W
                return false;
            }
            return true;
        case LT(0,KC_L):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_L)); // Ctrl-L
                return false;
            }
            return true;
        case LT(0,KC_O):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_O)); // Ctrl-W
                return false;
            }
            return true;
        case LT(0,KC_N):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_N)); // Ctrl-N
                return false;
            }
            return true;
    }

  return true;
}
#endif // OLED_ENABLE
