#include "a62hnah.h"
#define ______ KC_TRNS

//Layers
// enum
// {
//   _QWERTY = 0,
//   _MACRO = 1,
//   _NUMPAD = 2,
//   _COLEMAK = 3,
//   _FUNC = 4,
//   _LED = 5,
//   _MOUSE = 6,
//   _CH_LAYER = 7
// };

#define _QWERTY 0
#define _MACRO 1
#define _NUMPAD 2
#define _COLEMAK 3
#define _FUNC 4
#define _LED 5
#define _MOUSE 6
#define _CH_LAYER 7

// Macro
enum pt_keycodes {
  PT_M_CMD,
  PT_M_REMOTE,
  PT_M_SERVICES,
  PT_M_REG,
  PT_M_GP,
  PT_M_SQL_QUERY,
  PT_M_COPY,
  PT_M_COPY_PATH,
  PT_M_SAVE,
  PT_M_000,
  PT_M_X,
};

// Func Led
enum function_id {
  RGBLED_RED,
	RGBLED_ORANGE,
	RGBLED_YELLOW,
	RGBLED_GREEN,
	RGBLED_CYAN,
	RGBLED_BLUE,
	RGBLED_PURPLE
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// QWERTY
  // Default layer
  // ,-----------------------------------------.                ,-----------------------------------------.
  // | Esc  |   1  |   2  |   3  |   4  |   5  |                |   6  |   7  |   8  |   9  |   0  | Bksp |
  // |------+------+------+------+------+------|                |------+------+------+------+------+------|
  // | Tab  |   Q  |   W  |   E  |   R  |   T  |                |   Y  |   U  |   I  |   O  |   P  |  \   |
  // |------+------+------+------+------+------|                |------+------+------+------+------+------|
  // | Cap  |   A  |   S  |   D  |   F  |   G  |,------.,------.|   H  |   J  |   K  |   L  |   ;  |Enter |
  // |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
  // |Shift |   Z  |   X  |   C  |   V  |   B  || Macro||   '  ||   N  |   M  |   ,  |   .  |   /  |Shift |
  // |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
  // | Ctrl | Win  | Alt  | LT(4)| MO(2)| Space|`------'`------'|  Del |   =  |   -  | Alt  | MO(4)| Ctrl |
  // `-----------------------------------------'                `-----------------------------------------'

	[_QWERTY] = KEYMAP(
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_N, KC_DEL,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_M, KC_EQL,
		LT(4, KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_COMM, KC_MINS,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, MO(1), KC_RALT,
		KC_LCTL, KC_LGUI, KC_LALT, MO(4), MO(2), KC_SPC, KC_QUOT, MO(4),
		KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_DOT, KC_RCTL,
		KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, MT(MOD_LSFT, KC_SLSH),
		KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, KC_RSFT),

// Macro
  // ,-----------------------------------------.                ,-----------------------------------------.
  // | TO(0)| M(1) | M(2) | M(3) | M(4) | M(5) |                |      |      |      |      |      |      |
  // |------+------+------+------+------+------|                |------+------+------+------+------+------|
  // |      |      |      |      |      |      |                |      |      |      |      | M(8) |      |
  // |------+------+------+------+------+------|                |------+------+------+------+------+------|
  // |      | M(6) | M(7) |      |      |      |,------.,------.|      |      |      |      |      |      |
  // |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
  // |      | M(10)|      |      |      |      ||      ||      ||      |      |      |      |      |      |
  // |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
  // |      |      |      |      |      |      |`------'`------'|      |      |      |      |      |      |
  // `-----------------------------------------'                `-----------------------------------------'
  // Macro List:
  // 1. CMD
  // 2. Remode Desktop
  // 3. Services
  // 4. Group Policy
  // 5. Registry Editor
  // 6. Select All + Copy
  // 7. SQL Query: SELECT * FROM
  // 8. Copy Folder Path -> Run -> Enter
  // 9. 000 (3 number zero)
  // 10. X

	[_MACRO] = KEYMAP(
		TO(0), M(PT_M_CMD), M(PT_M_REMOTE), M(PT_M_SERVICES), M(PT_M_GP), M(PT_M_REG), ______, ______,
		______, ______, ______, ______, ______, ______, ______, ______,
		______, M(PT_M_COPY), M(PT_M_SQL_QUERY), ______, ______, ______, ______, ______,
		______, ______, M(PT_M_X), ______, ______, ______, ______, ______,
		______, ______, ______, ______, ______, ______, ______, ______,
		______, ______, ______, ______, ______, ______, ______, ______,
		______, ______, ______, ______, M(PT_M_COPY_PATH), ______, ______,
		______, ______, ______, ______, ______, ______, ______),

// Numpad
  // ,-----------------------------------------.                ,-----------------------------------------.
  // | TO(0)| Cap  | SLCK |  CAL |  F4  | PGUP |                |   ^  | NLCK |   /  |   *  |   -  | Bksp |
  // |------+------+------+------+------+------|                |------+------+------+------+------+------|
  // | Tab  | M(S) |  NO  |  UP  |  INS | PGDN |                |   %  |   7  |   8  |   9  |   +  | Pause|
  // |------+------+------+------+------+------|                |------+------+------+------+------+------|
  // | Esc  |   A  | LEFT | DOWN | RIGHT| HOME |,------.,------.|   &  |   4  |   5  |   6  |   +  | Enter|
  // |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
  // | Shift| CtrS |  NO  |   =  | PSCR | END  || Bksp ||Enter ||   |  |   1  |   2  |   3  | Enter| CtrS |
  // |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
  // | Ctrl | Win  | Alt  |   =  |  APP | Space|`------'`------'|  DEL |   0  |   0  |   .  | Enter| Ctrl |
  // `-----------------------------------------'                `-----------------------------------------'
  // M(S): Ctrl + S
  // CtrS: Ctrl + Shift

	[_NUMPAD] = KEYMAP(
		TO(0), KC_CAPS, KC_SLCK, KC_CALC, KC_F4, KC_PGUP, KC_PIPE, KC_DEL,
		KC_TAB, M(PT_M_SAVE), KC_NO, KC_UP, KC_INS, KC_PGDN, KC_P1, KC_P0,
		KC_ESC, KC_A, KC_LEFT, KC_DOWN, KC_RGHT, KC_HOME, KC_P2, M(PT_M_000),
		KC_LSFT, CTL_T(KC_LSFT), KC_NO, KC_EQL, KC_PSCR, KC_END, KC_BSPC, KC_PDOT,
		KC_LCTL, KC_LGUI, KC_LALT, KC_EQL, KC_APP, KC_SPC, KC_ENT, KC_PENT,
		KC_CIRC, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_BSPC, KC_P3, KC_RCTL,
		KC_PERC, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_PAUS, KC_PENT,
		KC_AMPR, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PENT, CTL_T(KC_RSFT)),

	// Colemak
  // ,-----------------------------------------.                ,-----------------------------------------.
  // | Esc  |   1  |   2  |   3  |   4  |   5  |                |   6  |   7  |   8  |   9  |   0  | Bksp |
  // |------+------+------+------+------+------|                |------+------+------+------+------+------|
  // | Tab  |   Q  |   W  |   F  |   P  |   G  |                |   J  |   L  |   U  |   I  |   ;  |  \   |
  // |------+------+------+------+------+------|                |------+------+------+------+------+------|
  // | Cap  |   A  |   R  |   S  |   T  |   D  |,------.,------.|   H  |   N  |   E  |   I  |   O  |Enter |
  // |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
  // |Shift |   Z  |   X  |   C  |   V  |   B  || Bksp ||   '  ||   K  |   M  |   ,  |   .  |   /  |Shift |
  // |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
  // | Ctrl | Win  | Alt  | LT(4)| MO(2)| Space|`------'`------'|  Del | MO(6)| To(2)| Alt  | Win  | Ctrl |
  // `-----------------------------------------'                `-----------------------------------------'

  [_COLEMAK] = KEYMAP(
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_K, KC_DEL,
		KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_M, TO(0),
		KC_BSPC, KC_A, KC_R, KC_S, KC_T, KC_D, KC_COMM, TO(2),
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_SPC, KC_RALT,
		KC_LCTL, KC_LGUI, KC_LALT, KC_CAPS, MO(4), KC_SPC, KC_QUOT, KC_RGUI,
		KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_DOT, KC_RCTL,
		KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS, MT(MOD_LSFT, KC_SLSH),
		KC_H, KC_N, KC_E, KC_I, KC_O, KC_ENT, KC_RSFT),

	// Function
  // ,-----------------------------------------.                ,-----------------------------------------.
  // |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |                |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
  // |------+------+------+------+------+------|                |------+------+------+------+------+------|
  // | Tab  | BRIU | WAKE | VOLU | PLAY | PGUP |                |   <  | ACDEL|  UP  |   {  |   }  | F12  |
  // |------+------+------+------+------+------|                |------+------+------+------+------+------|
  // |      | ACDEL| SLEEP| VOLD | STOP | PGDN |,------.,------.|   >  | LEFT | DOWN | RIGHT| PSCR | Enter|
  // |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
  // | Shift| BRID | POWER| MUTE | PREV | HOME ||Space ||Reset ||   %  |   =  |  [   |   ]  |   /  | TO(0)|
  // |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
  // | Ctrl | Win  | Alt  |      | NEXT |  END |`------'`------'|  DEL | MO(7)| TO(2)|   *  |      | Ctrl |
  // `-----------------------------------------'                `-----------------------------------------'
  // ACDEL = ALT + CTRL + DEL
  // BRIU: Brightness Up - Tăng độ sáng màn hình
  // BRID: Brightness Down - Giảm độ sáng màn hình

  [_FUNC] = KEYMAP(
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_PERC, KC_DEL,
		KC_TAB, KC_BRIU, KC_WAKE, KC_VOLU, KC_MPLY, KC_PGUP, KC_EQL, MO(7),
		______, LCTL(LALT(KC_DEL)), KC_SLEP, KC_VOLD, KC_MSTP, KC_PGDN, KC_LBRC, TO(2),
		KC_LSFT, KC_BRID, KC_PWR, KC_MUTE, KC_MPRV, KC_HOME, KC_SPC, KC_ASTR,
		KC_LCTL, KC_LGUI, KC_LALT, ______, KC_MNXT, KC_END, RESET, ______,
		KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_RBRC, KC_BSLS,
		KC_LABK, LCTL(LALT(KC_DEL)), KC_UP, KC_LCBR, KC_RCBR, KC_F12, KC_SLSH,
		KC_RABK, KC_LEFT, KC_DOWN, KC_RGHT, KC_PSCR, KC_ENT, TO(0)),


	// LED
  // ,-----------------------------------------.                ,-----------------------------------------.
  // |      | BL_O | BL_S | BL_D | BL_I |      |                |      |      |      |      |      |      |
  // |------+------+------+------+------+------|                |------+------+------+------+------+------|
  // |      | R_T  | R_M  | R_F0 | R_F1 | R_F2 |                |      | R_MP | R_MB | R_MR |      |      |
  // |------+------+------+------+------+------|                |------+------+------+------+------+------|
  // |      | R_HI | R_SI | R_VI | R_F3 | R_F4 |,------.,------.|      | R_MSW| R_MSN| R_MK |      |      |
  // |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
  // |      | R_HD | R_SD | R_VD | R_F5 | R_F6 ||Delete||Enter ||      | R_MX | R_MG | R_MT |      |      |
  // |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
  // |      |      |      |      |      |      |`------'`------'|      |      |      |      |      |      |
  // `-----------------------------------------'                `-----------------------------------------'
  // BL: Led nền
  // R: Led gầm RGB

  [_LED] = KEYMAP(
		TO(0), BL_TOGG, BL_STEP, BL_DEC, BL_INC, ______, ______, ______,
		______, RGB_TOG, RGB_MOD, F(0), F(1), F(2), RGB_M_X, ______,
		______, RGB_HUI, RGB_SAI, RGB_VAI, F(3), F(4), RGB_M_G, ______,
		______, RGB_HUD, RGB_SAD, RGB_VAD, F(5), F(6), ______, ______,
		______, ______, ______, ______, ______, ______, ______, ______,
		______, ______, ______, ______, ______, ______, RGB_M_T, ______,
		______, RGB_M_P, RGB_M_B, RGB_M_R, ______, ______, ______,
		______, RGB_M_SW, RGB_M_SN, RGB_M_K, ______, ______, ______),

	// MOUSE
  // ,-----------------------------------------.                ,-----------------------------------------.
  // |      |      |      |      |      |      |                |      |      | M_C3 |      |      |      |
  // |------+------+------+------+------+------|                |------+------+------+------+------+------|
  // |      |      |      | W_FWD|      |      |                |      | M_C1 | M_U  | M_C2 |      |      |
  // |------+------+------+------+------+------|                |------+------+------+------+------+------|
  // |      |      |      | W_BAK|      |      |,------.,------.|      | M_L  | M_D  | M_R  |      |      |
  // |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
  // |      |      |      |      |      |      ||Delete||Enter ||      | MW_L | MW_U | MW_R |      |      |
  // |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
  // |      |      |      |      |      |      |`------'`------'|      |      | MW_D |      |      |      |
  // `-----------------------------------------'                `-----------------------------------------'
  // W_FWD: Browser Forward (Windows)
  // W_BAK: Browser Back (Windows)
  [_MOUSE] = KEYMAP(
		TO(0), ______, ______, ______, ______, ______, ______, ______,
		______, ______, ______, KC_WFWD, ______, ______, KC_WH_L, ______,
		______, ______, ______, KC_WBAK, ______, ______, KC_WH_U, KC_WH_D,
		______, ______, ______, ______, ______, ______, ______, ______,
		______, ______, ______, ______, ______, ______, ______, ______,
		______, ______, KC_BTN3, ______, ______, ______, KC_WH_R, ______,
		______, KC_BTN1, KC_MS_U, KC_BTN2, ______, ______, ______,
		______, KC_MS_L, KC_MS_D, KC_MS_R, ______, ______, ______),

	// Change Layour
  [_CH_LAYER] = KEYMAP(
		TO(0), TO(1), TO(2), TO(3), TO(4), TO(5), ______, ______,
		______, TO(6), ______, ______, ______, ______, ______, ______,
		______, ______, ______, ______, ______, ______, ______, ______,
		______, ______, ______, ______, ______, ______, ______, ______,
		______, ______, ______, ______, ______, ______, ______, ______,
		______, ______, ______, ______, ______, ______, ______, ______,
		______, ______, ______, ______, ______, ______, ______,
		______, ______, ______, ______, ______, ______, ______)

};

// Macro Definitions
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    // for basic strings
    case PT_M_CMD: {
        if (record->event.pressed) {
          SEND_STRING(SS_LGUI("r"));
          _delay_ms(200);
          SEND_STRING("cmd" SS_TAP(X_ENTER));
          return false;
        }
    }
    case PT_M_REMOTE: {
        if (record->event.pressed) {
          SEND_STRING(SS_LGUI("r"));
          _delay_ms(200);
          SEND_STRING("mstsc" SS_TAP(X_ENTER));
          return false;
        }
    }
    case PT_M_SERVICES: {
        if (record->event.pressed) {
          SEND_STRING(SS_LGUI("r"));
          _delay_ms(200);
          SEND_STRING("services.msc" SS_TAP(X_ENTER));
          return false;
        }
    }
    case PT_M_REG: {
        if (record->event.pressed) {
          SEND_STRING(SS_LGUI("r"));
          _delay_ms(200);
          SEND_STRING("regedit" SS_TAP(X_ENTER));
          return false;
        }
    }
    case PT_M_GP: {
        if (record->event.pressed) {
          SEND_STRING(SS_LGUI("r"));
          _delay_ms(200);
          SEND_STRING("gpedit.msc" SS_TAP(X_ENTER));
          return false;
        }
    }
    case PT_M_SQL_QUERY: {
        if (record->event.pressed) {
          SEND_STRING("SELECT * FROM");
          return false;
        }
    }
    case PT_M_COPY: {
        if (record->event.pressed) {
          SEND_STRING(SS_LCTRL("ac"));
          return false;
        }
    }
    case PT_M_COPY_PATH: {
        if (record->event.pressed) {
          SEND_STRING(SS_LCTRL("c") SS_LGUI("r"));
          _delay_ms(200);
          SEND_STRING(SS_LCTRL("v") SS_TAP(X_ENTER));
          return false;
        }
    }
    case PT_M_SAVE:{
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL("s"));
            return false;
          }
    }
    case PT_M_000:{
        if (record->event.pressed) {
            SEND_STRING("000");
            return false;
          }
    }
    case PT_M_X: {
        if (record->event.pressed) {
          SEND_STRING("Hnah Joker" SS_TAP(X_ENTER));
          return false;
        }
    }
  }
  return MACRO_NONE;
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(RGBLED_RED),
  [1]  = ACTION_FUNCTION(RGBLED_ORANGE),
  [2]  = ACTION_FUNCTION(RGBLED_YELLOW),
  [3]  = ACTION_FUNCTION(RGBLED_GREEN),
  [4]  = ACTION_FUNCTION(RGBLED_CYAN),
  [5]  = ACTION_FUNCTION(RGBLED_BLUE),
  [6]  = ACTION_FUNCTION(RGBLED_PURPLE),

};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case  RGBLED_RED:
      if (record->event.pressed) {
        rgblight_enable();
        rgblight_mode(1);
        rgblight_setrgb(255, 0, 0);
      }
      break;
    case  RGBLED_ORANGE:
      if (record->event.pressed) {
        rgblight_enable();
        rgblight_mode(1);
        rgblight_setrgb(255, 97, 0);
      }
      break;
	case  RGBLED_YELLOW:
      if (record->event.pressed) {
        rgblight_enable();
        rgblight_mode(1);
        rgblight_setrgb(255, 255, 0);
      }
      break;
	case  RGBLED_GREEN:
      if (record->event.pressed) {
        rgblight_enable();
        rgblight_mode(1);
        rgblight_setrgb(0, 255, 0);
      }
	  break;
	case  RGBLED_CYAN:
      if (record->event.pressed) {
        rgblight_enable();
        rgblight_mode(1);
        rgblight_setrgb(0, 255, 255);
      }
    break;
	case  RGBLED_BLUE:
      if (record->event.pressed) {
        rgblight_enable();
        rgblight_mode(1);
        rgblight_setrgb(0, 0, 255);
      }
    break;
	case  RGBLED_PURPLE:
      if (record->event.pressed) {
        rgblight_enable();
        rgblight_mode(1);
        rgblight_setrgb(255, 0, 240);
      }
    break;
  }
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_KANA)) {

	} else {

	}

}
