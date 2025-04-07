/*
 * I2C-Generator: 0.3.0
 * Yaml Version: 0.1.0
 * Template Version: 0.7.0-62-g3d691f9
 */
/*
 * Copyright (c) 2021, Sensirion AG
 *
 * For licensing please refer to the LICENSE file of the repository.
 */

#include <inttypes.h>
#include <stdio.h>  // printf

#include "sensirion_common.h"
#include "sensirion_i2c_hal.h"
#include "sgp40_i2c.h"

/*
 * TO USE CONSOLE OUTPUT (PRINTF) YOU MAY NEED TO ADAPT THE INCLUDE ABOVE OR
 * DEFINE IT ACCORDING TO YOUR PLATFORM:
 * #define printf(...)
 */

int main(void) {
    int16_t error = 0;

    // Parameters for deactivated humidity compensation:
    uint16_t default_rh = 0x8000;
    uint16_t default_t = 0x6666;

    sensirion_i2c_hal_init();

    uint16_t serial_number[3];
    uint8_t serial_number_size = 3;
    error = sgp40_get_serial_number(serial_number, serial_number_size);

    if (error) {
        printf("Error executing sgp40_get_serial_number(): %i\n", error);
    } else {
        printf("Serial number: %" PRIu64 "\n",
               (((uint64_t)serial_number[0]) << 32) |
                   (((uint64_t)serial_number[1]) << 16) |
                   ((uint64_t)serial_number[2]));
    }

    // Start Measurement
    for (int i = 0; i < 60; i++) {
        uint16_t sraw_voc = 0;

        sensirion_i2c_hal_sleep_usec(1000000);

        error = sgp40_measure_raw_signal(default_rh, default_t, &sraw_voc);
        if (error) {
            printf("Error executing sgp40_measure_raw_signal(): "
                   "%i\n",
                   error);
        } else {
            printf("SRAW VOC: %u\n", sraw_voc);
        }
    }

    return 0;
}
