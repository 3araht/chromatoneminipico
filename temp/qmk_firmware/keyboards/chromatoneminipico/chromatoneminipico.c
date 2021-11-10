/* Copyright 2021 3araht
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

#include "chromatoneminipico.h"

#ifdef RGB_MATRIX_ENABLE
#    define NO_LED 255

led_config_t g_led_config = {
    {
        { NO_LED,    115, 114, 113, 112, 111, 110, 109, 108, 107 },
        { 0,      NO_LED,  79,  80,  81,  82,  83,  84,  85,  86 },
        { 1,          78,  77,  76,  75,  74,  73,  72,  71,  70 },
        { 3,      NO_LED,  42,  43,  44,  45,  46,  47,  48,  49 },
        { 2,          41,  40,  39,  38,  37,  36,  35,  34,  33 },
        { 4,      NO_LED,   5,   6,   7,   8,   9,  10,  11,  12 },
        { 97,         98,  99, 100, 101, 102, 103, 104, 105, 106 },
        { 96,         95,  94,  93,  92,  91,  90,  89,  88,  87 },
        { 60,         61,  62,  63,  64,  65,  66,  67,  68,  69 },
        { 59,         58,  57,  56,  55,  54,  53,  52,  51,  50 },
        { 23,         24,  25,  26,  27,  28,  29,  30,  31,  32 },
        { 22,         21,  20,  19,  18,  17,  16,  15,  14,  13 }
    },  {
        { 14,  12 },
        { 14,  36 },
        { 19,  48 }, { 9, 48 },
        { 14,  60 },
        { 39,  60 }, { 49,  60 }, {  59, 60 }, {  69, 60 }, {  79, 60 }, {  89, 60 }, {  99, 60 }, { 109, 60 }, { 119, 60 }, { 129, 60 }, { 139, 60 }, { 149, 60 }, { 159, 60 }, { 169, 60 }, { 179, 60 }, { 189, 60 }, { 199, 60 }, { 209, 60 },
        { 214, 48 }, { 204, 48 }, { 194, 48 }, { 184, 48 }, { 174, 48 }, { 164, 48 }, { 154, 48 }, { 144, 48 }, { 134, 48 }, { 124, 48 }, { 114, 48 }, { 104, 48 }, {  94, 48 }, {  84, 48 }, {  74, 48 }, {  64, 48 }, {  54, 48 }, {  44, 48 }, { 34, 48 },
        { 39,  36 }, { 49,  36 }, {  59, 36 }, {  69, 36 }, {  79, 36 }, {  89, 36 }, {  99, 36 }, { 109, 36 }, { 119, 36 }, { 129, 36 }, { 139, 36 }, { 149, 36 }, { 159, 36 }, { 169, 36 }, { 179, 36 }, { 189, 36 }, { 199, 36 }, { 209, 36 },
        { 214, 24 }, { 204, 24 }, { 194, 24 }, { 184, 24 }, { 174, 24 }, { 164, 24 }, { 154, 24 }, { 144, 24 }, { 134, 24 }, { 124, 24 }, { 114, 24 }, { 104, 24 }, {  94, 24 }, {  84, 24 }, {  74, 24 }, {  64, 24 }, {  54, 24 }, {  44, 24 }, { 34, 24 },
        { 39,  12 }, { 49,  12 }, {  59, 12 }, {  69, 12 }, {  79, 12 }, {  89, 12 }, {  99, 12 }, { 109, 12 }, { 119, 12 }, { 129, 12 }, { 139, 12 }, { 149, 12 }, { 159, 12 }, { 169, 12 }, { 179, 12 }, { 189, 12 }, { 199, 12 }, { 209, 12 },
        { 214,  0 }, { 204,  0 }, { 194,  0 }, { 184,  0 }, { 174,  0 }, { 164,  0 }, { 154,  0 }, { 144,  0 }, { 134,  0 }, { 124,  0 }, { 114,  0 }, { 104,  0 }, {  94,  0 }, {  84,  0 }, {  74,  0 }, {  64,  0} , {  54,  0 }, {  44,  0 }, { 34,  0 }
    },  {
        1,
        4,
        4, 4,
        4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
    }
};

// indicator
const uint8_t led_scale_indicator[12][12] = {
  {23, 29, 35, 41, 60, 66,  72,  78,  97, 103,    109,    115},     //  C
  { 5, 11, 17, 42, 48, 54,  79,  85,  91, NO_LED, NO_LED, NO_LED},  //  C#
  {28, 34, 40, 65, 71, 77, 102, 108, 114, NO_LED, NO_LED, NO_LED},  //  D
  { 6, 12, 18, 43, 49, 55,  80,  86,  92, NO_LED, NO_LED, NO_LED},  //  D#
  {27, 33, 39, 64, 70, 76, 101, 107, 113, NO_LED, NO_LED, NO_LED},  //  E
  { 7, 13, 19, 44, 50, 56,  81,  87,  93, NO_LED, NO_LED, NO_LED},  //  F
  {26, 32, 38, 63, 69, 75, 100, 106, 112, NO_LED, NO_LED, NO_LED},  //  F#
  { 8, 14, 20, 45, 51, 57,  82,  88,  94, NO_LED, NO_LED, NO_LED},  //  G
  {25, 31, 37, 62, 68, 74,  99, 105, 111, NO_LED, NO_LED, NO_LED},  //  G#
  { 9, 15, 21, 46, 52, 58,  83,  89,  95, NO_LED, NO_LED, NO_LED},  //  A
  {24, 30, 36, 61, 67, 73,  98, 104, 110, NO_LED, NO_LED, NO_LED},  //  A#
  {10, 16, 22, 47, 53, 59,  84,  90,  96, NO_LED, NO_LED, NO_LED}   //  B
};

const uint8_t led_single_col_indicator[37][3] = {
  {41, 78, 115},  //  K01  = C1
  { 5, 42,  79},  //  K02  = C#1
  {40, 77, 114},  //  K03  = D1
  { 6, 43,  80},  //  K04  = D#1
  {39, 76, 113},  //  K05  = E1
  { 7, 44,  81},  //  K06  = F1
  {38, 75, 112},  //  K07  = F#1
  { 8, 45,  82},  //  K08  = G1
  {37, 74, 111},  //  K09  = G#1
  { 9, 46,  83},  //  K10  = A1
  {36, 73, 110},  //  K11  = A#1
  {10, 47,  84},  //  K12  = B1
  {35, 72, 109},  //  K13  = C2
  {11, 48,  85},  //  K14  = C#2
  {34, 71, 108},  //  K15  = D2
  {12, 49,  86},  //  K16  = D#2
  {33, 70, 107},  //  K17  = E2
  {13, 50,  87},  //  K18  = F2
  {32, 69, 106},  //  K19  = F#2
  {14, 51,  88},  //  K20  = G2
  {31, 68, 105},  //  K21  = G#2
  {15, 52,  89},  //  K22  = A2
  {30, 67, 104},  //  K23  = A#2
  {16, 53,  90},  //  K24  = B2
  {29, 66, 103},  //  K25  = C3
  {17, 54,  91},  //  K26  = C#3
  {28, 65, 102},  //  K27  = D3
  {18, 55,  92},  //  K28  = D#3
  {27, 64, 101},  //  K29  = E3
  {19, 56,  93},  //  K30  = F3
  {26, 63, 100},  //  K31  = F#3
  {20, 57,  94},  //  K32  = G3
  {25, 62,  99},  //  K33  = G#3
  {21, 58,  95},  //  K34  = A3
  {24, 61,  98},  //  K35  = A#3
  {22, 59,  96},  //  K36  = B3
  {23, 60,  97}   //  K37  = C4
};

// C indicator
const uint8_t led_c_indicator[2][12][10] = {
    {  //  for C-System
        {   7,  11,  15, 19,  63,  67,  71,  75, NO_LED, NO_LED },
        {  38,  34,  30, 26,  94,  90,  86,  82, NO_LED, NO_LED },
        {  45,  49,  53, 57,  99, 103, 107, 111,    115, NO_LED },
        {  74,  70,  66, 62,  20,  16,  12,   8,     78, NO_LED },
        {  83,  87,  91, 95,  25,  29,  33,  37,     41,     79 },
        { 110, 106, 102, 98,  58,  54,  50,  46,     42,    114 },
        {   5,   9,  13, 17,  21,  61,  65,  69,     73,     77 },
        {  40,  36,  32, 28,  24,  96,  92,  88,     84,     80 },
        {  43,  47,  51, 55,  59,  97, 101, 105,    109,    113 },
        {   6,  10,  14, 18,  22,  60,  64,  68,     72,     76 },
        {  39,  35,  31, 27,  23,  93,  89,  85,     81, NO_LED },
        {  44,  48,  52, 56, 100, 104, 108, 112, NO_LED, NO_LED }
    },
    {  //  for B-System
        {  42,  46,  50, 54,  58,  99, 103, 107,    111,    115 },
        {  40,  36,  32, 28,  24,  95,  91,  87,     83,     79 },
        {   6,  10,  14, 18,  22,  61,  65,  69,     73,     77 },
        {  43,  47,  51, 55,  59,  98, 102, 106,    110,    114 },
        {  39,  35,  31, 27,  23,  96,  92,  88,     84,     80 },
        {   7,  11,  15, 19,  60,  64,  68,  72,     76, NO_LED },
        {  44,  48,  52, 56,  97, 101, 105, 109,    113, NO_LED },
        {  38,  34,  30, 26,  93,  89,  85,  81, NO_LED, NO_LED },
        {   8,  12,  16, 20,  63,  67,  71,  75, NO_LED, NO_LED },
        {  45,  49,  53, 57, 100, 104, 108, 112, NO_LED, NO_LED },
        {  41,  37,  33, 29,  25,  94,  90,  86,     82, NO_LED },
        {   5,   9,  13, 17,  21,  62,  66,  70,     74,     78 }
    }
};

#endif  //  RGB_MATRIX_ENABLE

uint8_t shift_led_indicator_left(uint8_t scale_indicator_col){
    if (scale_indicator_col > 0) {
        scale_indicator_col--;
    } else {
        scale_indicator_col = 11;
    }
    return scale_indicator_col;
}

uint8_t shift_led_indicator_right(uint8_t scale_indicator_col){
    if (scale_indicator_col < 11) {
        scale_indicator_col++;
    } else {
        scale_indicator_col = 0;
    }
    return scale_indicator_col;
}

#ifdef ENCODER_ENABLE
const uint16_t rt_matrix[2][2] = {
    {1, 1}, {3, 1}
};

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        keypos_t key;
        int cw = 0;
        cw = clockwise ? 1 : 0;
        key.row = rt_matrix[cw][0];
        key.col = rt_matrix[cw][1];
        uint8_t layer = layer_switch_get_layer(key);
        uint16_t keycode = keymap_key_to_keycode(layer, key);
        keyrecord_t record;
        record.event.key = key;

        if (keycode < MI_ON){
            tap_code16(keycode);
        } else {
            record.event.pressed = true;
            process_midi(keycode, &record);
            wait_ms(TAP_CODE_DELAY);
            record.event.pressed = false;
            process_midi(keycode, &record);
        }

    }
    return true;
}
#endif  // ENCODER_ENABLE
