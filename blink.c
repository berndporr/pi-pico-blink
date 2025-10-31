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

int main() {
    bool b = true;
    pico_led_init();
    while (true) {
        pico_set_led(b);
	b = !b;
        sleep_ms(LED_delay_ms);
    }
}
