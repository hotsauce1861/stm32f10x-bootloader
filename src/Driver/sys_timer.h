#ifndef SYS_TIMER_H
#define SYS_TIMER_H
#include <stdint.h>

//Timebase 1ms
#define SYSTICK_FREQ	1000

void gw_hal_set_time_cnt(uint32_t val);
uint32_t gw_hal_get_time_cnt(void);
void gw_hal_delay(volatile uint32_t ntime);
void gw_hal_dec(void);
void hal_system_timer_config(void);

#endif
