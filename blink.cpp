/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 * Copyright (c) 2025 Bernd Porr
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

// Blinking rate
const int LED_delay_ms = 500;

class LED {
public:
    LED(int gpio = 15) : n(gpio) {}
    
    // Perform initialisation
    void init() {
	gpio_init(n);
	gpio_set_dir(n, GPIO_OUT);
	gpio_put(n, s);
    }
    
    // Turn the led on or off
    void toggle() {
	s = !s;
	gpio_put(n, s);
    }
    
private:
    // LED state
    bool s = true;
    
    // GPIO pin
    const int n;
};


bool repeating_timer_callback(struct repeating_timer *t) {
    ((LED*)(t->user_data))->toggle();
    return true;
}

int main() {
    LED led;
    led.init();
    struct repeating_timer timer;
    add_repeating_timer_ms(-LED_delay_ms,
			   repeating_timer_callback,
			   &led,
			   &timer);
    // sleep forever. All done by the timer.
    while (true) {
	sleep_ms(0xffffffff);
    }
}
