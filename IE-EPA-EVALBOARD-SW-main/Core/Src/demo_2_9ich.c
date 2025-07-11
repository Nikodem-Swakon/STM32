
#include "SSD1680.h"
#include "stdlib.h"
#include "GUI_Paint.h"
#include "main.h"

#define WIDTH 128
#define HEIGHT 296

extern unsigned char gImage_logo248x46[1488]; //248x46

void demo_V1() { //Wyświetla testowe 3 prostokąty W B R
    static uint8_t BlackImage[128/8 * 296]; // NIE DO KOŃCA WIEM CO XD
    static uint8_t RedImage[128/8 * 296];

    int width_bytes = 128 / 8;

    EPD_Init(128, 296);  // INICJALIZACJA WYŚWIETLACZA
    HAL_Delay(300); // OPÓŹNIENIE

    // 1. Wyczyść oba bufory na biało (bit 1 = biały)
    memset(BlackImage, 0xFF, sizeof(BlackImage));
    memset(RedImage, 0x00, sizeof(RedImage)); // brak czerwieni
    // CZYŚCIMY BO NIE CHCEMY SYFILISA - PATRZ README.md

    // 2. Prostokąt 2: czarny (128x100) od wiersza 100 do 199
    for (int y = 100; y < 200; y++) {
        int offset = y * width_bytes;
        memset(&BlackImage[offset], 0x00, width_bytes); // czarne pixele
    }

    // 3. Prostokąt 3: czerwony (128x96) od wiersza 200 do 295
    for (int y = 200; y < 296; y++) {
        int offset = y * width_bytes;
        memset(&BlackImage[offset], 0x00, width_bytes);  // czarne tło
        memset(&RedImage[offset], 0xFF, width_bytes);    // czerwone pixele
    }

    // 5. Wyświetl
    EPD_Display(BlackImage, RedImage, 128, 296); // FUNKCJA WYŚWIETLAJĄCA
    HAL_Delay(3000);

    EPD_Sleep(); // USYPIAMY WYŚWIETLACZ BO NIE MUSI WIĘCEJ PRACOWAĆ
}

void demo_V2(){ //Wyświetla image  gImage_logo248x46

    static uint8_t BlackImage[128/8 * 296]; // NIE DO KOŃCA WIEM CO XD
    static uint8_t RedImage[128/8 * 296];


    EPD_Init(128, 296);  // INICJALIZACJA WYŚWIETLACZA
    HAL_Delay(300); // OPÓŹNIENIE

    // 1. Wyczyść oba bufory na biało (bit 1 = biały)
    memset(BlackImage, 0xFF, sizeof(BlackImage));
    memset(RedImage, 0x00, sizeof(RedImage)); // brak czerwieni
    // CZYŚCIMY BO NIE CHCEMY SYFILISA - PATRZ README.md


    Paint_NewImage(BlackImage, 128, 296, 0, WHITE);
    Paint_SelectImage(BlackImage);
    Paint_DrawBitMapXY(gImage_logo248x46,0,40,46,248);
    // 5. Wyświetl
    EPD_Display(BlackImage, RedImage, 128, 296); // FUNKCJA WYŚWIETLAJĄCA
    HAL_Delay(3000);

    EPD_Sleep(); // USYPIAMY WYŚWIETLACZ BO NIE MUSI WIĘCEJ PRACOWAĆ
}

void demo_V3(){ // Wyświetla string1 i string2
    const char first[] = "Pepsi MAX";  // PIERWSZY TEKST
    const char promotion[] = "DZIKIE KURWY, BAKLAZANY XDDD"; //DRUGI TEKST

    uint16_t x_first = 5; // POLOŻENIE PUNKTU STARTOWEGO DLA PIERWSZEGO TEKSTU X
    uint16_t y_first = 5; // -||- Y
    uint16_t x_promotion = 10;// POLOŻENIE PUNKTU STARTOWEGO DLA DRUGIEGO TEKSTU X
    uint16_t y_promotion = 200;// -||- Y

    static uint8_t BlackImage[128/8 * 296]; // NIE DO KOŃCA WIEM CO XD
    static uint8_t RedImage[128/8 * 296];

    int width_bytes = 128 / 8;

    EPD_Init(128, 296);  // INICJALIZACJA WYŚWIETLACZA
    HAL_Delay(300); // OPÓŹNIENIE

    // 1. Wyczyść oba bufory na biało (bit 1 = biały)
    memset(BlackImage, 0xFF, sizeof(BlackImage));
    memset(RedImage, 0x00, sizeof(RedImage)); // brak czerwieni
    // CZYŚCIMY BO NIE CHCEMY SYFILISA - PATRZ README.md

    // 4. Teraz wczytaj tekst do BlackImage i RedImage za pomocą Paint:
    Paint_NewImage(BlackImage, 128, 296, 0, WHITE); // TO CHYBA TEŻ DZIAŁA JAKO CZYSZCZENIE BUFORA
    Paint_SelectImage(BlackImage);
    Paint_DrawString_EN(x_first, y_first, first, &Font16, BLACK, WHITE); // TUTAJ MÓWIMY ŻEBY WYDRUKOWAŁO NAM W PUNKCIE DLA PIERWSZEGO STRINGA WŁAŚNIE TEGO STRINGA W TAKIM FONCIE
    // NO I MÓWIMY TEŻ ŻE MA TO BYĆ WARTOŚĆ MIĘDZY BLACK A WHITE - OBRAZ MONOCHROMATYCZNY DLA BUFORA CZARNEGO
    Paint_NewImage(RedImage, 128, 296, 0, WHITE);
    Paint_SelectImage(RedImage);
    Paint_DrawRectangle(x_promotion - 2, y_promotion - 2, x_promotion + 100, y_promotion + 50, RED, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    Paint_DrawString_EN(x_promotion, y_promotion, promotion, &Font16, BLACK, RED);

    // 5. Wyświetl
    EPD_Display(BlackImage, RedImage, 128, 296); // FUNKCJA WYŚWIETLAJĄCA
    HAL_Delay(3000);

    EPD_Sleep(); // USYPIAMY WYŚWIETLACZ BO NIE MUSI WIĘCEJ PRACOWAĆ
}
