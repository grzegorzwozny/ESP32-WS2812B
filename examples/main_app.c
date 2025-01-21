#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
#include "main_app.h"
#include "WS2812B.h"


// ***********************************************************************
//  GLOBAL BARIABLES
// ***********************************************************************


// ***********************************************************************
//  APP MAIN FUNCTION
// ***********************************************************************

void app_main(void) {
    // Create Task 1
    xTaskCreate(
        task1_function,      // Function for Task 1
        "Task_1",           // Name of Task 1
        8192,               // Stack size for Task 1 (in words)
        NULL,               // Parameter passed to Task 1
        1,                  // Priority of Task 1
        NULL                // Task handle for Task 1 (optional)
    );

    // Create Task 2
    xTaskCreate(
        task2_function,      // Function for Task 2
        "Task_2",           // Name of Task 2
        2048,               // Stack size for Task 2 (in words)
        NULL,               // Parameter passed to Task 2
        1,                  // Priority of Task 2
        NULL                // Task handle for Task 2 (optional)
    );

    // Create Task 3
    xTaskCreate(
        task3_function,      // Function for Task 3
        "Task_3",           // Name of Task 3
        2048,               // Stack size for Task 3 (in words)
        NULL,               // Parameter passed to Task 3
        1,                  // Priority of Task 3
        NULL                // Task handle for Task 3 (optional)
    );

    // Initialize LEDs
    ws2812b_init();
}

// ***********************************************************************
//  TASKS
// ***********************************************************************

// Function for Task 1
void task1_function(void *pvParameter) {

    while (1) {

        // Set LED colors
        for (size_t i = 0; i < 9; ++i) {
            ws2812b_set_pixel_color(i, ws2812b_color(25, 0, 0)); // Green
        }
        ws2812b_show();

        vTaskDelay(pdMS_TO_TICKS(1000)); // Wait 1 second

        // Change colors to red
        for (size_t i = 0; i < 9; ++i) {
            ws2812b_set_pixel_color(i, ws2812b_color(0, 125, 0)); // Red
        }
        ws2812b_show();

        vTaskDelay(pdMS_TO_TICKS(1000)); // Wait 1 second

        // Change colors to blue
        for (size_t i = 0; i < 9; ++i) {
            ws2812b_set_pixel_color(i, ws2812b_color(0, 0, 255)); // Red
        }
        ws2812b_show();
        vTaskDelay(pdMS_TO_TICKS(1000)); // Wait 1 second

        // Turn off all LEDs
        ws2812b_clear();
        ws2812b_show();
        vTaskDelay(pdMS_TO_TICKS(3000)); // Wait 1 second
    }
}

// Function for Task 2
void task2_function(void *pvParameter) {
    while (1) {
        // printf("Hello from Task 2\n"); // Print message from Task 2
        vTaskDelay(pdMS_TO_TICKS(4000));
    }
}

// Function for Task 3
void task3_function(void *pvParameter) {
    while (1) {
        // printf("Hello from Task 3\n"); // Print message from Task 3
        vTaskDelay(pdMS_TO_TICKS(6000));
    }
}