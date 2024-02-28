/*
 * bluetooth.c
 *
 *  Created on: Feb 26, 2024
 *      Author: vanam
 */


#include "bluetooth.h"

void ReceivedFromBluetooth(uint8_t *rx_data,UART_HandleTypeDef huart2){
	if (*rx_data == 'L')
	{
		uint8_t buffer[2];// Check next two characters
		if (HAL_UART_Receive(&huart2, buffer, 2, HAL_MAX_DELAY) == HAL_OK)
		{
			if (buffer[0] == 'O' && buffer[1] == 'N')
			{
				HAL_GPIO_WritePin(Led_Out_GPIO_Port, Led_Out_Pin, GPIO_PIN_SET);
			}
		}
	}
	else if (*rx_data == 'L')
	{
		uint8_t buffer[3];// Check next two characters
		if (HAL_UART_Receive(&huart2, buffer,3, HAL_MAX_DELAY) == HAL_OK)
		{
			if (buffer[0] == 'O' && buffer[1] == 'F' && buffer[2] == 'F')
			{
				HAL_GPIO_WritePin(Led_Out_GPIO_Port, Led_Out_Pin, GPIO_PIN_RESET);
			}
		}
	}
	else if (*rx_data == 'F')
	{
		uint8_t buffer[2];// Check next two characters
		if (HAL_UART_Receive(&huart2, buffer, 2, HAL_MAX_DELAY) == HAL_OK)
		{
			if (buffer[0] == 'O' && buffer[1] == 'N')
			{
				HAL_GPIO_WritePin(Fan_Out_GPIO_Port, Fan_Out_Pin, GPIO_PIN_SET);
			}
		}
	}
	if (*rx_data == 'F')
	{
		uint8_t buffer[3];// Check next two characters
		if (HAL_UART_Receive(&huart2, buffer, 3, HAL_MAX_DELAY) == HAL_OK)
		{
			if (buffer[0] == 'O' && buffer[1] == 'F' && buffer[2] == 'F')
			{
				HAL_GPIO_WritePin(Fan_Out_GPIO_Port, Fan_Out_Pin, GPIO_PIN_RESET);
			}
		}
	}
}
void SendToBluetooth(int state, UART_HandleTypeDef huart2){
	if(state==1){
		char *tx_data = "person found";
		HAL_UART_Transmit(&huart2, (uint8_t *)tx_data , strlen(tx_data), HAL_MAX_DELAY);
	}
	else{
		char *tx_data = "person not found";
		HAL_UART_Transmit(&huart2, (uint8_t *)tx_data , strlen(tx_data), HAL_MAX_DELAY);
	}
}
