#include <stdio.h>
#include "pico/stdlib.h"   // stdlib 
#include "hardware/irq.h"  // interrupts
#include "hardware/pwm.h"  // pwm 
#include "hardware/sync.h" // wait for interrupt 

#include "audio.h"

int main(void) {
    /* Overclocking for fun but then also so the system clock is a 
     * multiple of typical audio sampling rates.
     */
    stdio_init_all();
    set_sys_clock_khz(176000, true);
    bool toggle = true;
    Audio audio;
    while(true)
    {
        audio.PlayAudio("switch_off.dat");
        sleep_ms(5000);
        audio.PlayAudio("switch_on.dat");
        sleep_ms(5000);
    }
    while(1) {
        __wfi(); // Wait for Interrupt
    }
}
