//
// Created by zhouzhi on 2025/10/2.
//

#include "main.h"
#include "gpio.h"
#include "usart.h"

extern uint8_t rx_byte;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->Instance == &huart4) {
        ring_buffer_push(&rx_buf, rx_byte)
        HAL_UART_Receive_IT(&huart4, &rx_byte, 1);
    }
}
