/*
 * demo_2_9ich.c
 *
 *  Created on: Feb 13, 2025
 *      Author: Mateusz
 */

#include "SSD1680.h"
#include "stdlib.h"
#include "GUI_Paint.h"
#include "main.h"

#define WIDTH 128
#define HEIGHT 296

extern unsigned char gImage_logo248x46[1488]; //248x46

void demo_2_9ichV2() {
    const char first[] = "Pepsi MAX";
    const char promotion[] = "DZIKIE KURWY, BAKLAZANY XDDD";

    uint16_t x_first = 5;
    uint16_t y_first = 5;
    uint16_t x_promotion = 10;
    uint16_t y_promotion = 200;

    static uint8_t BlackImage[128/8 * 296];
    static uint8_t RedImage[128/8 * 296];

    int width_bytes = 128 / 8;

    EPD_Init(128, 296);
    HAL_Delay(300);

    // 1. Wyczyść oba bufory na biało (bit 1 = biały)
    memset(BlackImage, 0xFF, sizeof(BlackImage));
    memset(RedImage, 0x00, sizeof(RedImage)); // brak czerwieni


    // 4. Teraz wczytaj tekst do BlackImage i RedImage za pomocą Paint:
    Paint_NewImage(BlackImage, 128, 296, 0, WHITE);
    Paint_SelectImage(BlackImage);
    Paint_DrawString_EN(x_first, y_first, first, &Font16, BLACK, WHITE);

    Paint_NewImage(RedImage, 128, 296, 0, WHITE);
    Paint_SelectImage(RedImage);
    Paint_DrawRectangle(x_promotion - 2, y_promotion - 2, x_promotion + 100, y_promotion + 50, RED, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    Paint_DrawString_EN(x_promotion, y_promotion, promotion, &Font16, BLACK, RED);

    // 5. Wyświetl
    EPD_Display(BlackImage, RedImage, 128, 296);
    HAL_Delay(3000);

    EPD_Sleep();
}
