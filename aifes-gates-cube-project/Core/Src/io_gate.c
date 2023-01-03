/**
 ******************************************************************************
 * @file            : io_gate.c
 * @brief           : Map a gate to gpio ports.
 * @author			: paspf
 * @date			: 2022-01-02
 * @copyright		: paspf, GNU General Public License v3.0
 ******************************************************************************
 */

#include <stdio.h>
#include "io_gate.h"
#include "stm32l4xx_hal.h"
#include "test_gates.h"

/* Include models */
extern void aifes_e_and_gate_f32_fnn_inference(float* input_data, float* output_data);

/* Private variables */
static float input_data[2];
static float output_data[1];

/* Private function prototypes */
static void _gpio_init();
static void _gpio_read();
static void _nn_predict();
static void _gpio_write();

/**
 * @fn void io_gates()
 * @brief IO gates initialization and main loop.
 *
 */
void io_gates() {
	_gpio_init();
	while(1) {
		_gpio_read();
		_nn_predict();
		_gpio_write();
		HAL_Delay(50);
	}
}

/**
 * @fn void _gpio_init()
 * @brief Initialize GPIO pins.
 *
 */
static void _gpio_init() {
	/* Buttons */
	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_Buttons = {0};
	GPIO_Buttons.Mode = GPIO_MODE_INPUT;
	GPIO_Buttons.Pull = GPIO_PULLDOWN;
	GPIO_Buttons.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_Buttons.Pin = GPIO_PIN_8 | GPIO_PIN_9;

	HAL_GPIO_Init(GPIOB, &GPIO_Buttons);

	/* LEDS */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_Leds;
	GPIO_Leds.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Leds.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_Leds.Pin = GPIO_PIN_5;
	HAL_GPIO_Init(GPIOC, &GPIO_Leds);
}

/**
 * @fn void _gpio_read()
 * @brief Read out GPIO pins and wirte level into input_data.
 *
 */
static void _gpio_read() {
	int pin8 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);
	int pin9 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9);
	// Write GPIO level to ai_input buffer.
	input_data[0] = (float) pin8;
	input_data[1] = (float) pin9;
}

/**
 * @fn void __nn_predict()
 * @brief Run prediction on the current values in input_data.
 *
 */
static void _nn_predict() {
	aifes_e_and_gate_f32_fnn_inference(input_data, output_data);
}

/**
 * @fn void _gpio_write()
 * @brief Write Hi or Lo to a GPIO bin based on the current value in output_data.
 *
 */
static void _gpio_write() {
	// Read output (predicted y) of neural network.
	int y_pred = float_prediction_to_binary_int(output_data[0]);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, y_pred);
}

