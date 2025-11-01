/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 * Copyright (c) 2025 Bernd Porr
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

// GPIO pin
const int n = 15;

// Blinking rate
const int LED_delay_ms = 1000;

// Perform initialisation
void pico_led_init(void) {
    gpio_init(n);
    gpio_set_dir(n, GPIO_OUT);
}

// Turn the led on or off
void pico_set_led(bool led_on) {
    gpio_put(n, led_on);
}

// global state of the LED but should be done via the
// user data of the repeating timer.
bool led_state = false;

bool repeating_timer_callback(struct repeating_timer *t) {
    led_state = !led_state;
    pico_set_led(led_state);
    return true;
}

int main() {
    pico_led_init();
    struct repeating_timer timer;
    add_repeating_timer_ms(-500, repeating_timer_callback, NULL, &timer);
    while (true) {
	sleep_ms(0xffffffff);
    }
}
