#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NUM 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  OS_SS,  //os screenshot
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

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    MO(_NUM),         KC_ESC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LCTL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, LOWER,   KC_ENT,                    KC_SPC,  RAISE,   KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1,   KC_F2,   KC_F3,   KC_4,    KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     OS_SS,   KC_PERC, KC_AT,   KC_UP,   KC_DLR,  KC_HASH,                            KC_CIRC, KC_AMPR, KC_ASTR, ID_PT,   ID_NT,   ID_SR,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT,KC_UNDS,                            KC_EQL , KC_PGUP, KC_HOME, ID_SU,   ID_STR,  ID_RN,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  _______,KC_GRAVE,KC_TILD, KC_EXLM, KC_MINS, _______,          _______, KC_PLUS, KC_PGDN, KC_END,  _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_LALT,                    KC_LGUI,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, ID_NAV,  _______, KC_LBRC,                            KC_RBRC, KC_F7,   KC_F8,   KC_F9,   KC_F12,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, OS_PW,   KC_DOWN, OS_NW,   KC_LPRN,                            KC_RPRN, KC_F4,    KC_F5,   KC_F6,   KC_F11,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, KC_LCBR, _______,          _______, KC_RCBR, KC_F1,   KC_F2,   KC_F3,    KC_F10,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_LALT,                   KC_LGUI, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_ASTR, KC_7,    KC_8,    KC_9,    KC_MINS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                             KC_SLSH, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, KC_DOT , KC_1,    KC_2,    KC_3,    KC_0,    KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_ENT ,                   KC_SPC , _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _NUM);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _NUM);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _NUM);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _NUM);
            }
            return false;
            break;
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

///LAYER LIGHTNING

void keyboard_post_init_user(void){
    rgblight_enable_noeeprom(); // enable the RGBs
    rgblight_sethsv_noeeprom(23, 235, 110); // set to red
    //rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // set to breathing
}

uint32_t layer_state_set_user(uint32_t state){
    switch(biton32(state)) {
        case _LOWER:
            rgblight_sethsv_noeeprom(65, 235, 110);
            break;
        case _RAISE:
            rgblight_sethsv_noeeprom(8, 235, 110);
            break;
        case _NUM:
            rgblight_sethsv_noeeprom(150, 235, 80);
            break;
        default:
            rgblight_sethsv_noeeprom(23, 235, 110);
            //rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 3);
            break;

    }
    return state;
}