#include QMK_KEYBOARD_H

#define _QWERTY 0

#define _FUN1 1
#define _FUN2 2

enum my_emojis {
  M_SHRUGS = SAFE_RANGE,
  M_FLIP_TABLE,
  M_GLORIOUS_CAT,
  M_ANGRY,
  M_ANGRY_2,
  M_WHY,
  M_BOW,
  M_SORRY,
  M_BEAR,
  M_LENNY,
  M_PRAISE_THE_SUN,
  M_SALUTE,
};

#define M_PTS M_PRAISE_THE_SUN
#define M_FLIP M_FLIP_TABLE
#define M_GLORY M_GLORIOUS_CAT


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
    case M_SHRUGS:
      SEND_STRING("¯\\_(ツ)_/¯");
      break;
    case M_FLIP_TABLE:
      SEND_STRING("(ノಠ益ಠ)ノ彡┻━┻");
      break;
    case M_GLORIOUS_CAT:
      SEND_STRING("(=ↀωↀ=)✧");
      break;
    case M_ANGRY:
      SEND_STRING("(╬⓪益⓪)");
      break;
    case M_ANGRY_2:
      SEND_STRING("ヾ( ˃̶⺫˂̶｡)ノ");
      break;
    case M_WHY:
      SEND_STRING("щ(ಠ益ಠщ)");
      break;
    case M_BOW:
      SEND_STRING("＿|￣|●");
      break;
    case M_SORRY:
      SEND_STRING("๑•́ㅿ•̀๑) ᔆᵒʳʳᵞ");
      break;
    case M_BEAR:
      SEND_STRING("˞͛ʕ̡̢̡,,Ծ‸Ծ,, ʔ̢̡̢˞͛");
      break;
    case M_LENNY:
      SEND_STRING("( ͡° ͜ʖ ͡°)");
      break;
    case M_PRAISE_THE_SUN:
      SEND_STRING("( ﾉ ﾟｰﾟ)ﾉ☀️");
      break;
    case M_SALUTE:
      SEND_STRING("(￣^￣)ゞ");
      break;
    }
  }
  return true;
};

  /* Template
   * ,------------------------------------------------------------------------------------------.
   * |     |     |     |     |     |     |     |     |     |     |     |     |     |            |
   * |------------------------------------------------------------------------------------------+
   * |        |     |     |     |     |     |     |     |     |     |     |     |     |         |
   * |------------------------------------------------------------------------------------------+
   * |          |     |     |     |     |     |     |     |     |     |     |     |             |
   * |------------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     |     |            |
   * |------------------------------------------------------------------------------------------+
   * |      |       |       |                                    |        |      |       |      |
   * `------------------------------------------------------------------------------------------'

  [LAYER_NAME] = LAYOUT
  (
   _______       , _______ , _______  , _______, _______, _______ , _______  , _______  , _______  , _______  , _______  , _______ , _______ , _______ , ______,
   _______       , _______ , _______  , _______, _______, _______ , _______  , _______  , _______  , _______  , _______  , _______ , _______ , _______ ,
   _______       , _______ , _______  , _______, _______, _______ , _______  , _______  , _______  , _______  , _______  , _______ , _______ ,
   _______       , _______ , _______  , _______, _______, _______ , _______  , _______  , _______  , _______  , _______  , _______ , _______ , _______ ,
   _______       , _______ , _______  , _______, _______, _______ , _______  , _______  , _______  , _______  , _______

   )
   */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty Layer
   * ,------------------------------------------------------------------------------------------.
   * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc    |
   * |------------------------------------------------------------------------------------------+
   * |   Tab  |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \    |
   * |------------------------------------------------------------------------------------------+
   * | CtrL/Esc |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |------------------------------------------------------------------------------------------+
   * |   Shift   |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |  Up  |   Shift   |
   * |------------------------------------------------------------------------------------------+
   * | Fun2 |  Alt  |  Cmd  |               Space                |  Fun1  | Left | Down | Right |
   * `------------------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT
  (
   KC_ESC         , KC_1    , KC_2     , KC_3   , KC_4   , KC_5    , KC_6       , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS , KC_EQL  , XXXXXXX , KC_BSPC,
   KC_TAB         , KC_Q    , KC_W     , KC_E   , KC_R   , KC_T    , KC_Y       , KC_U     , KC_I     , KC_O     , KC_P     , KC_LBRC , KC_RBRC , KC_BSLS ,
   LCTL_T(KC_ESC) , KC_A    , KC_S     , KC_D   , KC_F   , KC_G    , KC_H       , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOT , KC_ENT  ,
   KC_LSFT        , XXXXXXX , KC_Z     , KC_X   , KC_C   , KC_V    , KC_B       , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH , KC_RSFT , XXXXXXX ,
   MO(_FUN2)      , KC_LALT , KC_LGUI  , KC_SPC , KC_SPC , KC_SPC  , MO(_FUN1)  , KC_LEFT  , XXXXXXX  , KC_DOWN  , KC_RGHT
   ),

  /* Function 1
   * ,------------------------------------------------------------------------------------------.
   * | ~ ` | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |   Delete   |
   * |------------------------------------------------------------------------------------------+
   * |        |     |     | End |     |     |     |     |     |     | Pscr|     |     |  Reset  |
   * |------------------------------------------------------------------------------------------+
   * |          | Home|     |     |     |     | Left| Down| Up  |Right|     |     |             |
   * |------------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     |     |            |
   * |------------------------------------------------------------------------------------------+
   * |      |       |       |                                    |        |      |       |      |
   * `------------------------------------------------------------------------------------------'
   */
  [_FUN1] = LAYOUT
  (
   KC_GRV         , KC_F1   , KC_F2    , KC_F3  , KC_F4  , KC_F5   , KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11  , KC_F12  , _______ , KC_DEL,
   _______        , _______ , _______  , KC_END , _______, _______ , _______  , _______  , _______  , _______  , KC_PSCR  , _______ , _______ , RESET   ,
   _______        , KC_HOME , _______  , _______, _______, _______ , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  , _______ , _______ ,
   _______        , _______ , _______  , _______, _______, _______ , _______  , _______  , _______  , _______  , _______  , _______ , _______ , _______ ,
   _______        , _______ , _______  , _______, _______, _______ , _______  , _______  , _______  , _______  , _______
   ),

  /* Function 2
   * ,------------------------------------------------------------------------------------------.
   * |     |     |     |     |     |     |     |     |     |     |     |     |     |            |
   * |------------------------------------------------------------------------------------------+
   * |        |Angr2| Why |     |     |     |     |     |     |     | PTS |     |     |         |
   * |------------------------------------------------------------------------------------------+
   * |          |Angry|Shrug|     | Flip|Glori|Salut|     |     |Lenny|     |     |             |
   * |------------------------------------------------------------------------------------------+
   * |           |Sorry|Bear |     |     | Bow |     |     |     |     |     |     |            |
   * |------------------------------------------------------------------------------------------+
   * |      |       |       |                                    |        |      |       |      |
   * `------------------------------------------------------------------------------------------'
   */
  [_FUN2] = LAYOUT
  (
   _______        , _______   , _______  , _______, _______, _______ , _______  , _______  , _______  , _______  , _______  , _______ , _______ , _______ , _______,
   _______        , M_ANGRY_2 , M_WHY    , _______, _______, _______ , _______  , _______  , _______  , _______  , M_PTS    , _______ , _______ , _______ ,
   _______        , M_ANGRY   , M_SHRUGS , _______, M_FLIP , M_GLORY , M_SALUTE , _______  , _______  , M_LENNY  , _______  , _______ , _______ ,
   _______        , _______   , M_SORRY  , M_BEAR , _______, _______ , _______  , M_BOW    , _______  , _______  , _______  , _______ , _______ , _______ ,
   _______        , _______   , _______  , _______, _______, _______ , _______  , _______  , _______  , _______  , _______

   )
};
