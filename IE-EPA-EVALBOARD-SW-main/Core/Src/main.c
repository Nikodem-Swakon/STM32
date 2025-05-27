/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "demo.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();




//////////////////////// FUNKCJA TESTOWA/////////////////////////////////
  //EPD_Init(128, 296);
  //HAL_Delay(300);

 /* static uint8_t pattern[128/8 * 296];
  static uint8_t red[128/8 * 296];

  // Wyczyść oba bufory
  memset(pattern, 0xFF, sizeof(pattern)); // całość biała (bo bit 1 = biały)
  memset(red, 0x00, sizeof(red));         // brak czerwieni

  int width_bytes = 128 / 8;

  // 1. Prostokąt 1: biały (128x100)
  // To już jest cały ekran ustawiony na biały w pattern (0xFF),
  // więc nic nie trzeba zmieniać w pierwszych 100 liniach.

  // 2. Prostokąt 2: czarny (128x100) od wiersza 100 do 199
  // czarny = bit 0, czyli ustawiamy bity pattern na 0 w tych liniach
  for (int y = 100; y < 200; y++) {
      int offset = y * width_bytes;
      memset(&pattern[offset], 0x00, width_bytes); // czarne pixele
  }

  // 3. Prostokąt 3: czerwony (128x96) od wiersza 200 do 295
  // czerwony = ustawiamy red = 0xFF, pattern może być 0x00 lub 0xFF
  // żeby mieć wyraźny czerwony, ustawimy pattern na 0 (czarny) i red na 1
  for (int y = 200; y < 296; y++) {
      int offset = y * width_bytes;
      memset(&pattern[offset], 0x00, width_bytes);  // czarne tło
      memset(&red[offset], 0xFF, width_bytes);      // czerwone pixele
  }

  EPD_Display(pattern, red, 128, 296);
  HAL_Delay(3000);

*/
  //////////////////////// FUNKCJA TESTOWA/////////////////////////////////


  //demo_2_13ich();
  //demo_2_66ich();
  //demo_2_9ich();
  //demo_4_2ich();

  //demo_2_13ichV2();
  //demo_2_66ichV2();
  demo_2_9ichV2();
  //demo_4_2ichV2();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
// Załóżmy: uint8_t pattern[128/8 * 296];

void fill_stripes(uint8_t *buf, uint16_t width, uint16_t height)
{
    uint16_t bytes_per_line = width / 8;
    for(uint16_t y=0; y<height; y++)
    {
        uint8_t color = (y % 2) ? 0x00 : 0xFF; // co druga linia: czarna lub biała
        for(uint16_t x=0; x<bytes_per_line; x++)
        {
            buf[y * bytes_per_line + x] = color;
        }
    }
}

void fill_checkerboard(uint8_t *buf, uint16_t width, uint16_t height)
{
    uint16_t bytes_per_line = width / 8;
    for(uint16_t y=0; y<height; y++)
    {
        for(uint16_t x=0; x<bytes_per_line; x++)
        {
            // Szachownica: bajt na zmianę 0xAA (10101010) / 0x55 (01010101) -- wzór zależny od y
            buf[y * bytes_per_line + x] = ((y % 2) == 0) ? 0xAA : 0x55;
        }
    }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
