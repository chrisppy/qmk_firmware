#include QMK_KEYBOARD_H

#define LFT_SPC LT(_NUM, KC_SPC)
#define LFT_GUI LGUI_T(KC_A)
#define LFT_ALT LALT_T(KC_R)
#define LFT_CTL LCTL_T(KC_S)
#define LFT_SFT LSFT_T(KC_T)
#define LFT_SG LSG_T(KC_G)
#define RHT_SG RSG_T(KC_M)
#define RHT_SFT RSFT_T(KC_N)
#define RHT_CTL RCTL_T(KC_E)
#define RHT_ALT RALT_T(KC_I)
#define RHT_GUI RGUI_T(KC_O)
#define RHT_ENT LT(_FUN, KC_ENT)
#define LFT_ESC LT(_SYM, KC_ESC)

enum layers {
    _BASE,
    _NUM,
    _SYM,
    _FUN
};

enum custom_keycodes {
    PRN = SAFE_RANGE,
    BRK
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    uint8_t mods = get_mods();
    bool shifted = mods & MOD_MASK_SHIFT;

    switch (keycode) {
    case KC_1 ... KC_0:
        tap_code(keycode);
        return false;
    case KC_BSPC:
        if (shifted) {
            del_mods(MOD_MASK_SHIFT);
            tap_code(KC_DEL);
            set_mods(mods);
        } else {
            tap_code(KC_BSPC);
        }
        return false;
    case KC_COMM:
        if (shifted) {
            del_mods(MOD_MASK_SHIFT);
            tap_code(KC_SCLN);
            set_mods(mods);
        } else {
            tap_code(KC_COMM);
        }
        return false;
    case KC_DOT:
        if (shifted) {
            del_mods(MOD_MASK_SHIFT);
            tap_code16(KC_COLN);
            set_mods(mods);
        } else {
            tap_code(KC_DOT);
        }
        return false;
    case KC_END:
        if (shifted) {
            del_mods(MOD_MASK_SHIFT);
            tap_code(KC_HOME);
            set_mods(mods);
        } else {
            tap_code(KC_END);
        }
        return false;
    case KC_PGDN:
        if (shifted) {
            del_mods(MOD_MASK_SHIFT);
            tap_code(KC_PGUP);
            set_mods(mods);
        } else {
            tap_code(KC_PGDN);
        }
        return false;
    case KC_SLSH:
        if (shifted) {
            del_mods(MOD_MASK_SHIFT);
            tap_code(KC_BSLS);
            set_mods(mods);
        } else {
            tap_code(KC_SLSH);
        }
        return false;
    case KC_SPC:
        if (shifted) {
            del_mods(MOD_MASK_SHIFT);
            tap_code(KC_TAB);
            set_mods(mods);
        } else {
            tap_code(KC_SPC);
        }
        return false;
    case BRK:
        if (shifted) {
            del_mods(MOD_MASK_SHIFT);
            tap_code16(KC_LCBR);
            tap_code16(KC_RCBR);
            tap_code(KC_LEFT);
            set_mods(mods);
        } else {
            tap_code(KC_LBRC);
            tap_code(KC_RBRC);
            tap_code(KC_LEFT);
        }

        return false;
    case PRN:
        if (shifted) {
            del_mods(MOD_MASK_SHIFT);
            tap_code16(KC_LT);
            tap_code16(KC_GT);
            tap_code(KC_LEFT);
            set_mods(mods);
        } else {
            tap_code16(KC_LPRN);
            tap_code16(KC_RPRN);
            tap_code(KC_LEFT);
        }

        return false;
    }

    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
       KC_GRV,     KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y, KC_MINS,  KC_EQL,
      KC_PGDN,  LFT_GUI, LFT_ALT, LFT_CTL, LFT_SFT,  LFT_SG,  RHT_SG, RHT_SFT, RHT_CTL, RHT_ALT, RHT_GUI, KC_SLSH,
       KC_END,     KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_QUOT,  KC_INS,
                        LFT_ESC, LFT_SPC,     PRN,                       BRK, RHT_ENT, KC_BSPC
    ),

    [_NUM] = LAYOUT_split_3x6_3(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX,
                        XXXXXXX, _______, XXXXXXX,                   XXXXXXX,    KC_0, XXXXXXX
    ),

    [_SYM] = LAYOUT_split_3x6_3(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_AMPR, KC_ASTR, KC_QUES, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,  KC_DLR, KC_PERC, KC_CIRC, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EXLM,   KC_AT, KC_HASH, XXXXXXX, XXXXXXX,
                        _______, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_PIPE, XXXXXXX
    ),

    [_FUN] = LAYOUT_split_3x6_3(
      XXXXXXX,  KC_F12,   KC_F7,   KC_F8,   KC_F9, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX,  KC_F11,   KC_F4,   KC_F5,   KC_F6, XXXXXXX, XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
      XXXXXXX,  KC_F10,   KC_F1,   KC_F2,   KC_F3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, _______, XXXXXXX
    ),
};
