#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

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
#define LCF4 LCTL_T(KC_F4)

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * 1st layer -> QWERTY
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |LCTRL |LCTRL | NUM  |Space | /Space  /       \Enter \  | SYMB |FUNCS | RAlt | RAlt |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_QWERTY] = LAYOUT(
    XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC, 
     KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_DEL, 
     KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, 
      LCAPS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX,    XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   RCAPS, 
                      KC_LCTL, KC_LCTL,    NUMS,     NAV,  KC_SPC,     KC_ENT,   SYMBS,   FUNCS, KC_RALT, KC_RALT
    ),

    /*
     * 2nd layer -> Navigation
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |BackSP|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |      |      |      |      |      |                    |      |      |  Up  |      |      | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |      |LCTRL | LAlt |LShift|      |-------.    ,-------| Home | Left | Down |Right | End  |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |LCTRL |LCTRL | NUM  |      | /Space  /       \Enter \  | ADJ  | Del  |BackSP| RAlt |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_NAVIGATION] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, KC_PSCR, _______,
    _______, XXXXXXX, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX,                      KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                      _______, _______, _______, _______, _______,    _______,    ADJS,  KC_DEL, KC_BSPC, _______
    ),
    
    /*
     * 3rd layer -> Numpad
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |BackSP|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |      |      |    - |    + |    = |                    |      |    7 |    8 |    9 |      | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |      |      |    * |    / |    % |-------.    ,-------|      |    4 |    5 |    6 |      |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |LShift|      |      |    ^ |    , |    . |-------|    |-------|      |    1 |    2 |    3 |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |LCTRL |LCTRL |      | NAV  | /Space  /       \Enter \  |      |    0 |    . | RAlt |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_NUMPAD] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, KC_MINS, KC_PLUS,  KC_EQL,                      XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, KC_ASTR, KC_PSLS, KC_PERC,                      KC_HOME,    KC_4,    KC_5,    KC_6, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, KC_CIRC, KC_COMM,  KC_DOT, _______,    _______, XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, _______,
                      _______, _______, XXXXXXX, _______, _______,    _______, _______,    KC_0,  KC_DOT, _______
    ),

    /*
     * 4rd layer -> Symbols
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |BackSP|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |      |      |    ( |    ) |    # |                    |    ! |    & |    | |    \ |      | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |      |      |    { |    } |    @ |-------.    ,-------|    $ |    = |    - |    _ |   `  |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |LShift|      |      |    [ |    ] |      |-------|    |-------|    + |    - |    < |    > |    ~ |    ? |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |LCTRL |      | NUM  | NAV  | /Space  /       \Enter \  |      |FUNCS | RAlt |      |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_SYMBOLS] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_HASH,                      KC_EXLM, KC_AMPR, KC_PIPE, KC_PSLS, KC_PSCR, _______,
    _______, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,   KC_AT,                       KC_DLR,  KC_EQL, KC_PMNS, KC_UNDS,  KC_END, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, _______,    _______, KC_PLUS,KC_MINUS, KC_LABK, KC_RABK, KC_TILD, KC_QUES,
                      _______, _______, _______, _______, _______,    _______, _______, XXXXXXX, KC_BSPC, _______
    ),

    /*
     * 5th layer -> Functions
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |BackSP|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |      |      |      |      |      |                    |      |   F9 |  F10 |  F11 |  F12 | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |      |LCTRL | LAlt |LShift|      |-------.    ,-------|      |   F5 |   F6 |   F7 |   F8 |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |-------|    |-------|      |   F1 |   F2 |   F3 |   F4 |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |      |      |      |      | /Space  /       \Enter \  |      |      |      |      |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_FUNCTIONS] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,
    _______, XXXXXXX, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX,                      XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /*
     * 6th layer -> Adjust
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |BackSP|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |      |      |      |      |      |-------.    ,-------|      |RGB ON| HUE+ | SAT+ | VAL+ |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |-------|    |-------|      | MODE | HUE- | SAT- | VAL- |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |      |      |      |      | /Space  /       \Enter \  |      |      |      |      |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_ADJUST] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, UG_TOGG, UG_HUEU, UG_SATU, UG_VALU,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______, XXXXXXX, XXXXXXX, UG_NEXT, UG_HUED, UG_SATD, UG_VALD,
                      _______, _______, _______, _______, _______,    _______, _______, XXXXXXX, XXXXXXX, _______
    ),
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { 
        // Left side encoder
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) {
        // Right side encoder
        if (clockwise) {
            tap_code16(C(KC_TAB));
        } else {
            tap_code16(C(KC_TAB));
        }
    }
    return false;
}
#endif