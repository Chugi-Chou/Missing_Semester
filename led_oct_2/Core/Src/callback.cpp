//
// Created by zhouzhi on 2025/10/2.
//

#include "main.h"
#include "gpio.h"
#include "tim.h"

uint32_t count;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim == &htim1) count ++;
}
