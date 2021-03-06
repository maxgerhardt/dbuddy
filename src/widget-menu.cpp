#include "widget-menu.h"

using namespace dbuddy;

void Menu::init() {
    lv_obj_t * page = get_ui()->get_widget(WIDGET_PAGE)->get_self();
    set_self(lv_obj_create(page, nullptr));

    set_size(lv_obj_get_width(page), DEFAULT_MENU_HEIGHT + DEFAULT_PADDING);

    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_radius_none(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_background_overlay(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_padding_default(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_radius_none(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_background_transparent_full(LV_STATE_DEFAULT));
    add_style(LV_PAGE_PART_BG, get_ui()->get_styles()->get_border_color_white(LV_STATE_DEFAULT));
    add_style(LV_PAGE_PART_BG, get_ui()->get_styles()->get_border_color_white(LV_STATE_FOCUSED));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_border_sides_only_bottom(LV_STATE_DEFAULT));
}
