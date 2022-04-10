/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _NUM
};


enum custom_keycodes {
    OS_SS = SAFE_RANGE,  //os screenshot
    OS_NW,  //os next word
    OS_PW,  //os prev word
    ID_NT,  //Idea Next Tab
    ID_PT,  //Idea Prev Tab
    ID_SR,  //Idea Split Right
    ID_SU,  //Idea Show Usage
    ID_STR, //Idea Structure
    ID_RN,  //Idea Rename
    ID_NAV, //Idea Navigation
    // TODO add column selection mode
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |TAB     |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |BS      |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |Esc   | Num  |  |Ent   |LShift|   N  |   M  | ,  < | . >  | /  ? |  Num   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | CTL  | Alt  | Gui  | Lower| Ent  |  | Spc  | Raise| Gui  | Alt  | Ctl  |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
        KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_BSPC, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_ESC,    TT(_NUM), /**/ KC_ENT, KC_LSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TT(_NUM),
                             KC_RCTL, KC_LALT, KC_LGUI, MO(_LOWER), KC_ENT  , /**/ KC_SPC, MO(_RAISE), KC_RGUI,  KC_RALT, KC_RCTL
    ),
/*
 * Lower Layer: Symbols, Navigation, Shorties
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Screen |  %   |  @   | UP   |  $   |  #   |                              |  ^   |  &   |  *   |P TAB |N TAB |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | LEFT | DOWN |RIGHT |  _   |                              |  =   |PG UP |HOME  |USAGE |STRUCT|RENAME  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |  `   |  ~   |  !   |  -   |      |      |  |      |      |   +  |PG DWN|END   |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | CTL  | Alt  | Gui  |      | Ent  |  | Spc  |      | Gui  | Alt  | Ctl  |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LOWER] = LAYOUT(
        OS_SS, KC_PERC, KC_AT,    KC_UP  , KC_DLR ,  KC_HASH,                                          KC_CIRC, KC_AMPR, KC_ASTR, ID_PT, ID_NT,  KC_BSLS,
      _______, _______, KC_LEFT,  KC_DOWN, KC_RIGHT, KC_UNDS,                                          KC_EQL,  KC_PGUP, KC_HOME, ID_SU, ID_STR, ID_RN,
      _______, _______, KC_GRAVE, KC_TILD, KC_EXLM,  KC_MINS, _______, _______, /**/ _______, _______, KC_PLUS, KC_PGDN, KC_END, _______,  _______, _______,
                                  KC_RCTL, KC_LALT,  KC_LGUI, _______, KC_ENT,  /**/ KC_SPC,  _______, KC_RGUI, KC_RALT, KC_RCTL
    ),
/*
 * Raise Layer: Number keys, Word Navigation, Function, Brackets
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      | Nav  |      |  [   |                              | ]    |F7    |F8    |F9    |F12   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |P Wrd | Down |N Wrd | (    |                              | )    |F4    |F5    |F6    |F11   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      | {    |      |      |  |      |      | }    |F1    |F2    |F3    |F10   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | CTL  | Alt  | Gui  |      | Ent  |  | Spc  |      | Gui  | Alt  | Ctl  |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT(
      _______, _______, _______, ID_NAV,  _______, KC_LBRC,                                          KC_RBRC, KC_F7, KC_F8, KC_F9, KC_F12,    _______,
      _______, _______, OS_PW,   KC_DOWN, OS_NW,   KC_LPRN,                                          KC_RPRN, KC_F4, KC_F5, KC_F6, KC_F11, _______,
      _______, _______, _______, _______, _______, KC_LCBR, _______, _______, /**/ _______, _______, KC_RCBR, KC_F1, KC_F2, KC_F3, KC_F10, _______,
                                KC_RCTL, KC_LALT,  KC_LGUI, _______, KC_ENT,  /**/ KC_SPC,  _______, KC_RGUI, KC_RALT, KC_RCTL
    ),
/*
 * Num Layer: Numbers
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Bsp    |      |      |      |      |      |                              | *    | 7    |  8   | 9    | -    |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              | /    | 4    | 5    | 6    | +    |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      | .    | 1    | 2    | 3    | 0    | Num    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | CTL  | Alt  | Gui  |      | Ent  |  | Spc  |      | Gui  | Alt  | Ctl  |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                           KC_ASTR, KC_7,   KC_8,   KC_9,   KC_MINS,  _______,
      KC_BSPC, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                           KC_SLSH, KC_4, KC_5, KC_6,  KC_PLUS,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______, _______, /**/ _______, _______, KC_DOT,  KC_1, KC_2, KC_3, KC_0, TG(_NUM),
                               KC_RCTL, KC_LALT,  KC_LGUI,   _______, KC_ENT,  /**/ KC_SPC,  _______, KC_RGUI, KC_RALT, KC_RCTL
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    //return update_tri_layer_state(state, _LOWER, _RAISE, _NUM);
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OS_SS:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                tap_code(KC_4);
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
            }
            break;
        case OS_NW:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_RGHT);
                unregister_code(KC_LALT);
            }
            break;
        case OS_PW:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_LEFT);
                unregister_code(KC_LALT);
            }
            break;
        case ID_NT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_RGHT);
                unregister_code(KC_LCTL);
            }
            break;
        case ID_PT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_LEFT);
                unregister_code(KC_LCTL);
            }
            break;
        case ID_SR:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LGUI);
                register_code(KC_LALT);
                tap_code(KC_F1);
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
                unregister_code(KC_LALT);
            }
            break;
        case ID_SU:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LALT);
                tap_code(KC_F7);
                unregister_code(KC_LALT);
                unregister_code(KC_LGUI);
            }
            break;
        case ID_STR:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_F12);
                unregister_code(KC_LGUI);
            }
            break;
        case ID_RN:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                tap_code(KC_F6);
                unregister_code(KC_LSFT);
            }
            break;
        case ID_NAV:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_UP);
                unregister_code(KC_LGUI);
            }
            break;
    }
    return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_dpx_logo(void){
    static const char PROGMEM dpx_logo[] = {
        // 'dpx', 128x46px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
        0xc0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0x78, 0xf0, 0xf0, 0xe0, 0xc0,
        0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8, 0xfe, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff,
        0x0f, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x83, 0x83, 0x91, 0x9e, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xfe, 0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x3e, 0x3e, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x12,
        0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x3f, 0x7f, 0xff, 0xff, 0xf7, 0xf7, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
        0x83, 0x01, 0x00, 0x00, 0x00, 0x0e, 0x7f, 0x00, 0x00, 0x80, 0x40, 0x00, 0x00, 0x80, 0xf0, 0xf0,
        0xf0, 0x70, 0xf0, 0xf0, 0xe0, 0x80, 0x00, 0x78, 0xf8, 0xf9, 0x19, 0x81, 0xf1, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1f, 0x3f, 0x7f,
        0xf7, 0xf6, 0xe0, 0xe0, 0xf0, 0xf8, 0xfe, 0xfc, 0xe1, 0xe3, 0xfc, 0xfc, 0xf9, 0xe3, 0xc7, 0xcf,
        0xdf, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf1, 0xc7, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff,
        0x7f, 0x3f, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
        0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(dpx_logo, sizeof(dpx_logo));
}


static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("alf rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_dpx_logo();
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
#endif
