# WS2812B Library for ESP32-S3

This library provides functions to control WS2812B addressable LEDs using the ESP32-S3 microcontroller. It is tested with ESP-IDF v5.4.0.

## Features

- Control WS2812B LEDs with precise timing
- Simple API for setting colors and updating the LED strip
- Efficient use of RMT (Remote Control) peripheral for data transmission

## Requirements

- ESP32-S3
- ESP-IDF v5.4.0

## Installation

1. Clone this repository into your ESP-IDF project directory:
    ```sh
    git clone https://github.com/yourusername/ws2812b-esp32-s3.git
    ```

2. Include the library in your project by adding the following line to your `CMakeLists.txt`:
    ```cmake
    add_subdirectory(ws2812b-esp32-s3)
    ```

3. Link the library to your application:
    ```cmake
    target_link_libraries(${PROJECT_NAME} PRIVATE ws2812b-esp32-s3)
    ```

## Usage

### Initialization

Initialize the WS2812B library and configure the RMT channel:

```c
#include "WS2812B.h"

void app_main(void)
{
    ws2812b_init();
}
```

### Setting Pixel Colors

Set the color of individual LEDs using the `ws2812b_set_pixel_color` function:

```
ws2812b_set_pixel_color(0, ws2812b_color(255, 0, 0)); // Set first LED to red
ws2812b_set_pixel_color(1, ws2812b_color(0, 255, 0)); // Set second LED to green
ws2812b_set_pixel_color(2, ws2812b_color(0, 0, 255)); // Set third LED to blue

```

### Updating the LED Strip

After setting the colors, update the LED strip to reflect the changes:

```
ws2812b_show();

```

### Clearing the LED Strip

Clear all LEDs:

```
ws2812b_clear();
ws2812b_show();

```

Example
-------

Here is a complete example that initializes the library, sets some colors, and updates the LED strip:

```
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "WS2812B.h"

void app_main(void)
{
    ws2812b_init();

    ws2812b_set_pixel_color(0, ws2812b_color(255, 0, 0)); // Red
    ws2812b_set_pixel_color(1, ws2812b_color(0, 255, 0)); // Green
    ws2812b_set_pixel_color(2, ws2812b_color(0, 0, 255)); // Blue

    ws2812b_show();

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

```

License
-------

This project is licensed under the MIT License - see the LICENSE file for details.

Contributing
------------

Contributions are welcome! Please open an issue or submit a pull request.

Acknowledgments
---------------

-   ESP-IDF - Espressif IoT Development Framework
-   WS2812B - WS2812B LED datasheet
