//
// Created by zhouzhi on 2025/10/2.
//

#include "main.h"
#include "usart.h"

extern uint8_t rx_msg[10];


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart == &huart1) {
        if (rx_msg[0] == 'R') {
            HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
        } else if (rx_msg[0] == 'M') {
            HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
        }
    HAL_UART_Receive_IT(&huart1, rx_msg, 1);
    }
}