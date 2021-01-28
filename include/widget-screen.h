#ifndef DBUDDY_SCREEN_H
#define DBUDDY_SCREEN_H

#include "widget.h"
#include "fonts.h"
#include "styles.h"

namespace dbuddy {
    class Screen : public Widget {
    public:
        Screen(lv_obj_t *, lv_obj_t *);

        void init(Fonts *, Styles *) final;
    };
}

#endif //DBUDDY_SCREEN_H