#include "fonts.h"

using namespace dbuddy;

Fonts::Fonts() {
    lv_state_t STATES[8] = {LV_STATE_DEFAULT, LV_STATE_CHECKED, LV_STATE_FOCUSED, LV_STATE_EDITED, LV_STATE_HOVERED, LV_STATE_PRESSED, LV_STATE_DISABLED};

    for (unsigned char STATE : STATES) {
        init_font(&black_medium, STATE);
        lv_style_set_text_font(&black_medium[STATE], STATE, &roboto_black_24);
        lv_style_set_value_font(&black_medium[STATE], STATE, &roboto_black_24);

        init_font(&black_small, STATE);
        lv_style_set_text_font(&black_small[STATE], STATE, &roboto_black_16);
        lv_style_set_value_font(&black_small[STATE], STATE, &roboto_black_16);

        init_font(&black_xxlarge, STATE);
        lv_style_set_text_font(&black_xxlarge[STATE], STATE, &roboto_black_72);
        lv_style_set_value_font(&black_xxlarge[STATE], STATE, &roboto_black_72);

        init_font(&regular_xsmall, STATE);
        lv_style_set_text_font(&regular_xsmall[STATE], STATE, &roboto_regular_14);
        lv_style_set_value_font(&regular_xsmall[STATE], STATE, &roboto_regular_14);

        init_font(&regular_small, STATE);
        lv_style_set_text_font(&regular_small[STATE], STATE, &roboto_regular_16);
        lv_style_set_value_font(&regular_small[STATE], STATE, &roboto_regular_16);
    }
}

void Fonts::init_font(std::map<lv_state_t, lv_style_t> * map, lv_state_t state) {
    lv_style_t style;
    lv_style_init(&style);
    (*map)[state] = style;
}

lv_style_t * Fonts::get_black_medium(lv_state_t state) {
    return &black_medium.at(state);
}

lv_style_t * Fonts::get_black_small(lv_state_t state) {
    return &black_small.at(state);
}

lv_style_t * Fonts::get_black_xxlarge(lv_state_t state) {
    return &black_xxlarge.at(state);
}

lv_style_t * Fonts::get_regular_small(lv_state_t state) {
    return &regular_small.at(state);
}

lv_style_t * Fonts::get_regular_xsmall(lv_state_t state) {
    return &regular_xsmall.at(state);
}
