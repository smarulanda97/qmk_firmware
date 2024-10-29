/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2023 Santiago Marulanda <@smarulanda97>

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

enum layers {
    _QWERTY,
    _NAVIGATION,
    _NUMPAD,
    _SYMBOLS,
    _FUNCTIONS,
    _ADJUST,
};

// Aliases for changing layers
#define NAV MO(_NAVIGATION)
#define NUMS MO(_NUMPAD)
#define SYMBS MO(_SYMBOLS)
#define FUNCS MO(_FUNCTIONS)
#define ADJS MO(_ADJUST)

// Aliases for modifiers
#define LCAPS SFT_T(KC_CAPS)
#define RCAPS RSFT_T(KC_CAPS)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * 1st layer -> QWERTY
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/      /      \      \-----------------------------------------'
     *                          |Space |      | /Space /        \Enter \  |Enter | SYMB |
     *                          |      |      |/      /          \      \ |      |      |
     *                          `--------------------'            '------''-------------'
     */
    [_QWERTY] = LAYOUT_split_3x6_3(
         KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
         KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
          LCAPS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   RCAPS,
                                               NUMS,     NAV,  KC_SPC,    KC_ENT,   SYMBS,   FUNCS
    ),

    /*
     * 2nd layer -> Navigation
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |      |      |      |      |      |                    |      |      |      |      |      | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |      |LCTRL | LAlt |LShift|      |                    | Home | Left | Down |Right | End  | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |-------|    |-------|      |      |      |      |      |RShift|
     * `-----------------------------------------/      /      \      \-----------------------------------------'
     *                          | NUMS | NAV  | /Space /        \Enter \  | ADJS |FUNCS |
     *                          |      |      |/      /          \      \ |      |      |
     *                          `--------------------'            '------''-------------'
     */
    [_NAVIGATION] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX,                     KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,  KC_DEL,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, _______,   _______,    ADJS, XXXXXXX
    ),

    /*
     * 3rd layer -> Numpad
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |      |      |    - |    + |    = |                    |      |    7 |    8 |    9 |      | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |      |      |    * |    / |    % |                    |      |    4 |    5 |    6 |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|      |      |    ^ |    , |    . |-------|    |-------|      |    1 |    2 |    3 |      |RShift|
     * `-----------------------------------------/      /      \      \-----------------------------------------'
     *                          | NUMS | NAV  | /Space /        \Enter \  |    0 |    . |
     *                          |      |      |/      /          \      \ |      |      |
     *                          `--------------------'            '------''-------------'
     */
    [_NUMPAD] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, KC_MINS, KC_PLUS,  KC_EQL,                     XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, KC_ASTR, KC_PSLS, KC_PERC,                     XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, KC_CIRC, KC_COMM,  KC_DOT,                     XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, _______,
                                            XXXXXXX, XXXXXXX, _______,   _______,    KC_0,  KC_DOT
    ),

    /*
     * 4rd layer -> Symbols
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |      |      |    ( |    ) |    # |                    |    ! |    & |    | |    \ |      | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |      |      |    { |    } |    @ |                    |    $ |    = |    - |    _ |   `  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|      |      |    [ |    ] |      |-------|    |-------|    + |    - |    < |    > |    ~ |    ? |
     * `-----------------------------------------/      /      \      \-----------------------------------------'
     *                          | NUMS | NAV  | /Space /        \Enter \  |SYMBS |FUNCS |
     *                          |      |      |/      /          \      \ |      |      |
     *                          `--------------------'            '------''-------------'
     */
    [_SYMBOLS] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_HASH,                     KC_EXLM, KC_AMPR, KC_PIPE, KC_PSLS, KC_BSLS, _______,
        _______, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,   KC_AT,                      KC_DLR,  KC_EQL, KC_PMNS, KC_UNDS,  KC_GRV, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,                     KC_PLUS,KC_MINUS, KC_LABK, KC_RABK, KC_TILD, KC_QUES,
                                            XXXXXXX, XXXXXXX, _______,   _______, XXXXXXX, XXXXXXX
    ),

    /*
     * 5th layer -> Functions
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |      |      |      |      |      |                    |      |   F9 |  F10 |  F11 |  F12 |BackSP|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |      |LCTRL | LAlt |LShift|      |                    |      |   F5 |   F6 |   F7 |   F8 |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |-------|    |-------|      |   F1 |   F2 |   F3 |   F4 |      |
     * `-----------------------------------------/      /      \      \-----------------------------------------'
     *                          | NUMS | NAV  | /Space /        \Enter \  |SYMBS |      |
     *                          |      |      |/      /          \      \ |      |      |
     *                          `--------------------'            '------''-------------'
     */
    [_FUNCTIONS] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,
        _______, XXXXXXX, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX,                     XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______,
                                            XXXXXXX, XXXXXXX, _______,   _______, XXXXXXX, XXXXXXX
    ),

    /*
     * 6th layer -> Adjust
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |      |      |      |      |      |                    |      |      |      |      |      | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |      |      |      |      |      |                    |      |      |RGB ON| HUE+ | SAT+ | VAL+ |3
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
     * `-----------------------------------------/      /      \      \-----------------------------------------'
     *                          |      |      | /Space /        \Enter \  |      |      |
     *                          |      |      |/      /          \      \ |      |      |
     *                          `--------------------'            '------''-------------'
     */
    [_ADJUST] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, UG_TOGG, UG_HUEU, UG_SATU, UG_VALU,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, UG_NEXT, UG_HUED, UG_SATD, UG_VALD,
                                            XXXXXXX, XXXXXXX, _______,   _______, XXXXXXX, XXXXXXX
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
    oled_write_P(PSTR("Huber - "), false);
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

    return true;
}
#endif // OLED_ENABLE
