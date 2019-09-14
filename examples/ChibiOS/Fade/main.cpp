/*
  Uses PWM to fade LED 1 (PA0) on and off.
*/

#include "ch.hpp"
#include "hal.h"

#define SPEED 5
#define PWM_INC 50
#define MAX_PWM 10000

// PWM Config
static PWMConfig pwmcfg = {
  1000000, // 1MHz PWM clock frequency.
  10000,   // 1 second PWM period
  NULL,
  {
   {PWM_OUTPUT_ACTIVE_HIGH, NULL},
   {PWM_OUTPUT_DISABLED, NULL},
   {PWM_OUTPUT_DISABLED, NULL},
   {PWM_OUTPUT_DISABLED, NULL}
  },
  0,
  0
};

/*
 * Application entry point.
 */
int main(void) {
  // System initializations.
  halInit();
  chSysInit();
  pwmStart(&PWMD2, &pwmcfg);

  int pwmVal = 0;
  int direction = 1;
  while (1) {
    pwmEnableChannel(&PWMD2, 0, PWM_PERCENTAGE_TO_WIDTH(&PWMD2, pwmVal));

    // Increment PWM & change direction if we've reached the min/max
    pwmVal += (PWM_INC * direction);
    if (pwmVal >= MAX_PWM) {
      direction = -1;
      pwmVal = MAX_PWM;
    } else if (pwmVal <= 0) {
      direction = 1;
      pwmVal = 0;
    }

    chThdSleepMilliseconds(SPEED);
  }
}
