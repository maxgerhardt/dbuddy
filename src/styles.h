#ifndef DBUDDY_STYLES_H
#define DBUDDY_STYLES_H

#include "lvgl/lvgl.h"

#define DEFAULT_PADDING 16
#define DEFAULT_BORDER 5

extern lv_style_t style_default_background_color_black;
extern lv_style_t style_default_background_color_blue;
extern lv_style_t style_default_background_overlay_color_black;
extern lv_style_t style_default_background_transparent_full;
extern lv_style_t style_default_background_transparent_10;
extern lv_style_t style_default_background_transparent_20;
extern lv_style_t style_default_background_transparent_30;
extern lv_style_t style_default_background_transparent_40;
extern lv_style_t style_default_background_transparent_half;
extern lv_style_t style_default_background_transparent_60;
extern lv_style_t style_default_background_transparent_70;
extern lv_style_t style_default_background_transparent_80;
extern lv_style_t style_default_background_transparent_90;
extern lv_style_t style_default_background_transparent_cover;
extern lv_style_t style_default_border_color_white;
extern lv_style_t style_default_border_none;
extern lv_style_t style_default_border_sides_right_none;
extern lv_style_t style_default_font_black_large;
extern lv_style_t style_default_font_black_large_48;
extern lv_style_t style_default_font_black_large_72;
extern lv_style_t style_default_font_black_medium;
extern lv_style_t style_default_font_black_small;
extern lv_style_t style_default_padding_default;
extern lv_style_t style_default_padding_left_none;
extern lv_style_t style_default_padding_none;
extern lv_style_t style_default_radius_none;
extern lv_style_t style_default_text_color_black;

extern lv_style_t style_focused_background_blend_mode_additive;
extern lv_style_t style_focused_background_color_purple;
extern lv_style_t style_focused_text_color_black;

void styles_init(void);

#endif //DBUDDY_STYLES_H
