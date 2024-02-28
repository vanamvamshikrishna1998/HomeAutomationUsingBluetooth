/*
 * sensor_dht.h
 *
 *  Created on: Feb 26, 2024
 *      Author: vanam
 */

#ifndef INC_SENSOR_DHT_H_
#define INC_SENSOR_DHT_H_

#include "main.h"
#include "stm32f4xx_hal.h"

#define OUTPUT 1
#define INPUT 0

/**
 * @brief DHT11 struct
 */
typedef struct{
	float temperature; ///Temperature value
	float humidity; ///humidity value
}DHT_Data;


void microDelay(uint16_t delay,TIM_HandleTypeDef *htim4);
void Read_DHTSensor(DHT_Data *dht_data,TIM_HandleTypeDef *htim4,GPIO_InitTypeDef *GPIO_InitStruct);
uint8_t DHT11_Start(TIM_HandleTypeDef *htim4,GPIO_InitTypeDef *GPIO_InitStruct);
uint8_t DHT11_Read(TIM_HandleTypeDef *htim4);


#endif /* INC_SENSOR_DHT_H_ */
