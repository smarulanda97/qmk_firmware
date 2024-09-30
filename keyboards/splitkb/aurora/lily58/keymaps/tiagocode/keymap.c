#include QMK_KEYBOARD_H

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
     * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BackSP|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  Tab |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |LCTRL | NUMS | NAV  | /Space  /       \Enter \  |SYMBS |FUNCS | RAlt |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_QWERTY] = LAYOUT(
        XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
         KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_DEL,
         KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
          LCAPS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC, KC_RBRC,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   RCAPS,
                                   KC_LCTL,    NUMS,     NAV,  KC_SPC,  KC_ENT,   SYMBS,   FUNCS, KC_RALT
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
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |LCTRL | NUMS |      | /Space  /       \Enter \  | ADJ  |BackSP| RAlt |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_NAVIGATION] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, KC_PSCR, _______,
        _______, XXXXXXX, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX,                    KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______, XXXXXXX,  _______, _______,    ADJS,  KC_DEL, KC_BSPC
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
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |      |      |      |    ^ |    , |    . |-------|    |-------|      |    1 |    2 |    3 |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      | NAV  | /Space  /       \Enter \  |      |    0 |    . |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_NUMPAD] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, KC_MINS, KC_PLUS,  KC_EQL,                    XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, KC_ASTR, KC_PSLS, KC_PERC,                    XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, KC_CIRC, KC_COMM,  KC_DOT,  _______, _______, XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX,
                                   _______, XXXXXXX, _______,  _______, _______,    KC_0,  KC_DOT,  _______
    ),

    /* 
     * 4rd layer -> Symbols
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |BackSP|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |    ( |    ) |    # |                    |    ! |    & |    | |    \ |      | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |    { |    } |    @ |-------.    ,-------|    $ |    = |    - |    _ |   `  |      |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |      |      |      |    [ |    ] |      |-------|    |-------|    + |    - |    < |    > |    ~ |    ? |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /Space  /       \Enter \  |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_SYMBOLS] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_HASH,                    KC_EXLM, KC_AMPR, KC_PIPE, KC_PSLS, KC_BSLS, _______,
        _______, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,   KC_AT,                     KC_DLR,  KC_EQL, KC_PMNS, KC_UNDS,  KC_GRV, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,  _______, _______, KC_PLUS,KC_MINUS, KC_LABK, KC_RABK, KC_TILD, KC_QUES,
                                   _______, _______, _______,  _______, _______, _______, XXXXXXX, _______
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
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |   F1 |   F2 |   F3 |   F4 |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /Space  /       \Enter \  |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_FUNCTIONS] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,
        _______, XXXXXXX, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX,                    XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______,
                                   _______, _______, _______,  _______, _______, _______, XXXXXXX, _______
    ),

    /* 
     * 6th layer -> Adjust
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |LCTRL | NUMS | NAV  | /Space  /       \Enter \  |      |BackSP| RAlt |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_ADJUST] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, UG_TOGG, UG_HUEU, UG_SATU, UG_VALU,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______, XXXXXXX, XXXXXXX, UG_NEXT, UG_HUED, UG_SATD, UG_VALD,
                                   _______, _______, _______,  _______, _______, _______, XXXXXXX, _______
    ),
};


