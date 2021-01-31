#include <stdexcept>

#include "dbuddy.h"
#include "fonts.h"
#include "styles.h"
#include "ui.h"

#ifdef USE_MONITOR
#include "simulator.h"
#else
#define RA8875_INT      13
#define RA8875_CS       5
#define RA8875_RESET    12

#include "nodemcu32s.h"
#endif

#define USE_DOUBLE_BUFFER (false)

using namespace dbuddy;

#if LV_MEM_CUSTOM == 0
static void memory_monitor(lv_task_t *param);
#endif

void setup() {
#ifndef USE_MONITOR
    Serial.begin(115200);
#endif

    lv_init();

    DBuddy::setup(
#ifdef USE_MONITOR
        new Simulator(),
#else
        new NodeMCU32s(new Adafruit_RA8875(RA8875_CS, RA8875_RESET), RA8875_INT),
#endif
        new Ui(new Fonts, new Styles),
        USE_DOUBLE_BUFFER
    );

#if LV_MEM_CUSTOM == 0
    lv_task_create(memory_monitor, 5000, LV_TASK_PRIO_MID, nullptr);
#endif
}

void loop() {
    DBuddy::loop();
}

#if LV_MEM_CUSTOM == 0
/**
 * Print the memory usage periodically
 * @param param
 */
static void memory_monitor(lv_task_t *param) {
  (void)param; /*Unused*/

  lv_mem_monitor_t mon;
  lv_mem_monitor(&mon);

#ifndef USE_MONITOR
  Serial.printf("used: %6d (%3d %%), frag: %3d %%, biggest free: %6d\n",
         (int)mon.total_size - mon.free_size, mon.used_pct, mon.frag_pct,
         (int)mon.free_biggest_size);
#else
  printf("used: %6d (%3d %%), frag: %3d %%, biggest free: %6d\n",
         (int)mon.total_size - mon.free_size, mon.used_pct, mon.frag_pct,
         (int)mon.free_biggest_size);
#endif
}
#endif

/* Assume desktop environment */
#if !defined (ARDUINO) 

/* define OS-specific sleep functions */
#ifdef __WIN32__
#include <synchapi.h> /* for Sleep() */
#define SLEEP_FUNC(ms) Sleep(ms)
#else 
/* Linux (and mac probably too) */ 
#include <unistd.h> /* for usleep() */
#define SLEEP_FUNC(ms) usleep(1000U * (ms))
#endif

int main() {
    setup();
    while(true) {
        loop();
        /* put thread to sleep to not lock up CPU */
        SLEEP_FUNC(3); 
    }
}
#endif 