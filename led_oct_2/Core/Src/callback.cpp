//
// Created by zhouzhi on 2025/10/2.
//

#include "main.h"
#include "gpio.h"
#include "usart.h"

extern uint8_t rx_msg[4];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart == &huart4) {
        if (rxmsg[0] == 'R') {
            HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
        }
        else if (rxmsg[0] == 'M') {
            HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_SET);
        }
        HAL_UART_Receive_IT(&huart4, rx_msg, 1);
    }
}
