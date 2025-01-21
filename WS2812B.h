#ifndef WS2812B_H
#define WS2812B_H

#include  <string.h>
#include "driver/rmt_tx.h"
#include "esp_err.h"

// Configuration
#define RMT_LED_STRIP_RESOLUTION_HZ 10000000 // 10MHz resolution, 1 tick = 0.1us (led strip needs a high resolution)
#define RMT_LED_STRIP_GPIO_NUM      38
#define LED_NUMBERS_MAX             9
#define FRAME_DURATION_MS           10

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} ws2812b_color_t;

void ws2812b_init(void);
uint32_t ws2812b_color(uint8_t red, uint8_t green, uint8_t blue);
void ws2812b_set_pixel_color(uint8_t index, uint32_t color);
void ws2812b_clear(void);
void ws2812b_show(void);

#endif // WS2812B_H
