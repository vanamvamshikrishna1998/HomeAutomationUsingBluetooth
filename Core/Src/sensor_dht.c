/*
 * sensor_dht.c
 *
 *  Created on: Feb 26, 2024
 *      Author: vanam
 */
#include "sensor_dht.h"

uint8_t Rh_int, Rh_dec, Temp_int, Temp_dec, Checksum;

// Function to generate microsecond delay using timer
void microDelay(uint16_t delay,TIM_HandleTypeDef *htim4)
{
  __HAL_TIM_SET_COUNTER(htim4, 0);
  while (__HAL_TIM_GET_COUNTER(htim4) < delay);
}

void Read_DHTSensor(DHT_Data *dht_data,TIM_HandleTypeDef *htim4,GPIO_InitTypeDef *GPIO_InitStruct){
	HAL_TIM_Base_Start(htim4);
	  // Send the start signal and check the response
	  if (DHT11_Start(htim4,GPIO_InitStruct))
	  {
	    // Read the data bytes
	    Rh_int = DHT11_Read(htim4);
	    Rh_dec = DHT11_Read(htim4);
	    Temp_int = DHT11_Read(htim4);
	    Temp_dec = DHT11_Read(htim4);
	    Checksum = DHT11_Read(htim4);

	    // Verify the checksum
	    if (Checksum == (Rh_int + Rh_dec + Temp_int + Temp_dec))
	    {
	      // Convert the data to float values
	      dht_data->humidity = (float)(Rh_int + Rh_dec / 100.0);
	      dht_data->temperature = (float)(Temp_int + Temp_dec / 100.0);
	    }
	    else
	    {
	      // Invalid data, set the values to zero
	      dht_data->humidity = 0;
	      dht_data->temperature = 0;
	    }
	  }
	  else
	  {
	    // No response from the sensor, set the values to zero
	      dht_data->humidity = 0;
	      dht_data->temperature = 0;
	  }
}


// Function to send start signal to DHT11
uint8_t DHT11_Start(TIM_HandleTypeDef *htim4,GPIO_InitTypeDef *GPIO_InitStruct)
{
  uint8_t Response = 0;
  // Set the pin as output
  GPIO_InitStruct->Pin = Sensor_Dht_In_Pin;
  GPIO_InitStruct->Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct->Pull = GPIO_NOPULL;
  GPIO_InitStruct->Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(Sensor_Dht_In_GPIO_Port, GPIO_InitStruct);

  // Pull the pin low for 18 ms
  HAL_GPIO_WritePin(Sensor_Dht_In_GPIO_Port, Sensor_Dht_In_Pin, GPIO_PIN_RESET);
  HAL_Delay(18);

  // Pull the pin high for 20-40 us
  HAL_GPIO_WritePin(Sensor_Dht_In_GPIO_Port, Sensor_Dht_In_Pin, GPIO_PIN_SET);
  HAL_Delay(40);

  // Set the pin as input
  GPIO_InitStruct->Pin = Sensor_Dht_In_Pin;
  GPIO_InitStruct->Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct->Pull = GPIO_NOPULL;
  HAL_GPIO_Init(Sensor_Dht_In_GPIO_Port, GPIO_InitStruct);

  // Wait for 80 us and check if the pin is low
  HAL_Delay(80);
  if (!(HAL_GPIO_ReadPin(Sensor_Dht_In_GPIO_Port, Sensor_Dht_In_Pin)))
  {
    // Wait for another 80 us and check if the pin is high
	  HAL_Delay(80);
    if ((HAL_GPIO_ReadPin(Sensor_Dht_In_GPIO_Port, Sensor_Dht_In_Pin)))
    {
      // The sensor has responded with low-high signal
      Response = 1;
    }
  }

  // Return the response
  return Response;
}

// Function to read one byte of data from DHT11
uint8_t DHT11_Read(TIM_HandleTypeDef *htim4)
{
  uint8_t i, value = 0;

  // Read 8 bits of data
  for (i = 0; i < 8; i++)
  {
    // Wait for the pin to go high
    while (!(HAL_GPIO_ReadPin(Sensor_Dht_In_GPIO_Port, Sensor_Dht_In_Pin)));

    // Wait for 40 us
    HAL_Delay(40);

    // Check the state of the pin
    if (!(HAL_GPIO_ReadPin(Sensor_Dht_In_GPIO_Port, Sensor_Dht_In_Pin)))
    {
      // The bit is 0
      value = value << 1;
    }
    else
    {
      // The bit is 1
      value = (value << 1) | 1;

      // Wait for the pin to go low
      while ((HAL_GPIO_ReadPin(Sensor_Dht_In_GPIO_Port, Sensor_Dht_In_Pin)));
    }
  }

  // Return the value
  return value;
}

