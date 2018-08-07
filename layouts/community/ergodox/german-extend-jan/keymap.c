//german keymap derived from german-kinergo with german special keys on a separate layer

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "keymap_german.h"

#define BASE 0 //default layer
#define SYMB 1 //symbol layer
#define NAV 2 //navigation layer
#define GER 3 //german layer

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * X'es mark the spots where this is different from the "german" layout which it is based on.
 *
 * ,--------------------------------------------------.           ,-------------------------------------------------------.
 * |X =    X|   1  |   2  |   3  |   4  |   5  |XLEFTX|           |XRIGHT|   6  |   7  |   8  |   9  |   0  |   -    	  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+-------------|
 * |X Del  X|   Q  |   W  |   E  |   R  |   T  | Ctrl |           | Alt  |   Y  |   U  |   I  |   O  |   P  |   \         |
 * |--------+------+------+------+------+------| space|           | Tab  |------+------+------+------+------+-------------|
 * |  TT2   | A/L1 |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  ' cmd/win  |
 * |--------+------+------+------+------+------|X HYPX|           |X MEHX|------+------+------+------+------+-------------|
 * | LShift |Y/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift      |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+-------------'
 *   |XCtrlX|X CMDX|  ALT | [    |  ]   |                                       |XLeftX|X Up X|XDownX|XRight|   MO(3)     |
 *   `----------------------------------'                                       `-----------------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |XLALTX|XCTRLX|       | Alt  |Ctrl/Esc|
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |XXX   |XXX   | Home |       | PgUp |XXX     |XXX   |
 *                                 | Bkspc|Space |------|       |------|  Tab   | Enter|
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
  [BASE] = KEYMAP(
  	//left hand
  	KC_EQUAL,	KC_1,		KC_2,		KC_3,				KC_4,		KC_5,		KC_LEFT,
  	KC_DELETE,	KC_Q,		KC_W,		KC_E,				KC_R,		KC_T,		LCTL(KC_SPACE),
  	TT(2),		LT(1,KC_A),	KC_S,		KC_D,				KC_F,		KC_G,		
  	KC_LSHIFT, 	CTL_T(KC_Z),KC_X,		KC_C,				KC_V,		KC_B,		ALL_T(KC_NO),
  	KC_LCTL,	KC_LGUI,    KC_LALT,	KC_LBRACKET,		KC_RBRACKET,
  																							ALT_T(KC_APPLICATION),	KC_LGUI,
  																													KC_HOME,
  																				KC_BSPACE,	KC_SPACE,				KC_END,

  	//right hand
  	KC_RIGHT,	KC_6,		KC_7,		KC_8,				KC_9,		KC_0,		KC_MINUS,
  	LALT(KC_TAB),KC_Y,		KC_U,		KC_I,				KC_O,		KC_P,		KC_BSLASH,
  				KC_H,		KC_J,		KC_K,				KC_L,		KC_SCOLON,	GUI_T(KC_QUOTE),
  	MEH_T(KC_NO),KC_N,		KC_M,		KC_COMMA,			KC_DOT,		RCTL_T(KC_SLASH),KC_RSHIFT,
  							KC_LEFT,	KC_UP,				KC_DOWN,	KC_RIGHT,	MO(3),

	KC_LALT,CTL_T(KC_ESCAPE),
	KC_PGUP,
	KC_PGDOWN,KC_TAB,KC_ENTER),

 /* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | TOT  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [SYMB] = KEYMAP(
  	//left hand
  	KC_ESCAPE,	KC_F1,		KC_F2,		KC_F3,				KC_F4,		KC_F5,		KC_TRNS,
  	KC_TRNS,	KC_EXLM,	KC_AT,		KC_LCBR,			KC_RCBR,	KC_PIPE,	KC_TRNS,
  	KC_TRNS,	KC_TRNS,	KC_DLR,		KC_LPRN,			KC_RPRN,	KC_GRAVE,	
  	KC_TRNS,	KC_PERC,	KC_CIRC,	KC_LBRACKET,		KC_RBRACKET,KC_TILD,	KC_TRNS,
  	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,			KC_TRNS,
  																							KC_TRNS,				KC_TRNS,
  																													KC_TRNS,
  																				KC_TRNS,	KC_TRNS,				KC_TRNS,

  	//right hand																			
  	KC_TRNS,	KC_F6,		KC_F7,		KC_F8,				KC_F9,		KC_F10,		KC_F11,
  	KC_TRNS,	KC_UP,		KC_7,		KC_8,				KC_9,		KC_ASTR,	KC_F12,
  				KC_DOWN,	KC_4,		KC_5,				KC_6,		KC_PLUS,	KC_TRNS,
  	KC_TRNS,	KC_AMPR,	KC_1,		KC_2,				KC_3,		KC_BSLASH,	KC_TRNS,
  							KC_TRNS,	KC_DOT,				KC_0,		KC_EQUAL,	KC_TRNS,

  	KC_TRNS,KC_TRNS,
  	KC_TRNS,
  	KC_TRNS,KC_TRNS,KC_TRNS),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | Shift| LCtrl| MsUp | Mclk |      |      |           |  PG  |WHL UP| Home | Up   | End  | Del  |   ESC  |
 * |--------+------+------+------+------+------|      |           |  UP  |------+------+------+------+------+--------|
 * |        | ESC  |MsLeft|MsDown|MsRght|      |------|           |------|WHL DN| Left | Down | Right|BKSPC |   INS  |
 * |--------+------+------+------+------+------|      |           |  PG  |------+------+------+------+------+--------|
 * |        | Undo | Cut  | Copy | Paste|Ctrl+W|      |           | DOWN |      |      | Prev | Next |      |  PLAY  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |Lclk  | Rclk |                                       |VOL DN|VOL UP| MUTE |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Lclk | Rclk |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [NAV] = KEYMAP(
  	//left hand
  	KC_TRNS,	KC_F1,		KC_F2,		KC_F3,				KC_F4,		KC_F5,		KC_TRNS,
  	KC_TRNS,	SFT_T(KC_NO),	CTL_T(KC_NO),	KC_MS_UP,	KC_MS_BTN3,	KC_TRNS,	KC_MS_WH_UP,
  	KC_TRNS,	KC_ESCAPE,		KC_MS_LEFT,		KC_MS_DOWN,	KC_MS_RIGHT,KC_TRNS,	
  	KC_TRNS,	LCTL(KC_Z),		LCTL(KC_X),		LCTL(KC_C),	LCTL(KC_V),	LCTL(KC_W),	KC_MS_WH_DOWN,
  	KC_TRNS,	KC_TRNS,		KC_TRNS,		KC_MS_BTN1,	KC_MS_BTN2,

  																							KC_TRNS,				KC_TRNS,
  																													KC_TRNS,
  																				KC_MS_BTN1,KC_MS_BTN2,				KC_TRNS,

  	//right hand
  	KC_TRNS,	KC_F6,		KC_F7,		KC_F8,				KC_F9,		KC_F10,		KC_F11,
  	KC_PGUP,	KC_MS_WH_UP,KC_HOME,	KC_UP,				KC_END,		KC_DELETE,	KC_ESCAPE,
  				KC_MS_WH_DOWN,KC_LEFT,	KC_DOWN,			KC_RIGHT,	KC_BSPACE,	KC_INSERT,
  	KC_PGDOWN,	KC_TRNS,	KC_TRNS,	KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRNS,KC_MEDIA_PLAY_PAUSE,
  							KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,KC_TRNS,KC_TRNS,

  	KC_TRNS,KC_TRNS,
  	KC_TRNS,
  	KC_TRNS,KC_TRNS,KC_TRNS),

  /* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [GER] = KEYMAP(
  	//left hand
  	KC_TRNS,	KC_TRNS,		DE_EURO,		KC_TRNS,	KC_TRNS,    KC_TRNS,	KC_TRNS,
  	KC_TRNS,	KC_TRNS,		KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
  	KC_TRNS,	DE_AE,			DE_SS,			KC_TRNS,	KC_TRNS,	KC_TRNS,	
  	KC_TRNS,	KC_TRNS,		KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
  	KC_TRNS,	KC_TRNS,		KC_TRNS,		KC_TRNS,	KC_TRNS,

  																							KC_TRNS,				KC_TRNS,
  																													KC_TRNS,
  																					KC_TRNS,KC_TRNS,				KC_TRNS,

  	//right hand
  	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,				KC_TRNS,		KC_TRNS,	KC_TRNS,
  	KC_TRNS,	KC_TRNS,	DE_UE,		KC_TRNS,				DE_OE,		KC_TRNS,	KC_TRNS,
  				KC_TRNS,	KC_TRNS,	KC_TRNS,				KC_TRNS,		KC_TRNS,	KC_TRNS,
  	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,				KC_TRNS,		KC_TRNS,	KC_TRNS,
  							KC_TRNS,	KC_TRNS,				KC_TRNS,		KC_TRNS,	KC_TRNS,

  	KC_TRNS,KC_TRNS,
  	KC_TRNS,
  	KC_TRNS,KC_TRNS,KC_TRNS),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

void matrix_scan_user(void) {
};

