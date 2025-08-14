#ifndef DRIVER_MOTOR
#define DRIVER_MOTOR
#include "driver/gpio.h"
#include "driver/ledc.h"
#include <cstdint>

#define MOTOR_LEFT_PIN1 GPIO_NUM_18
#define MOTOR_LEFT_PIN2 GPIO_NUM_19
#define MOTOR_RIGHT_PIN1 GPIO_NUM_21
#define MOTOR_RIGHT_PIN2 GPIO_NUM_22

#define MOTOR_LEFT_CHANNEL_PIN1 LEDC_CHANNEL_0
#define MOTOR_LEFT_CHANNEL_PIN2 LEDC_CHANNEL_1
#define MOTOR_RIGHT_CHANNEL_PIN1 LEDC_CHANNEL_2
#define MOTOR_RIGHT_CHANNEL_PIN2 LEDC_CHANNEL_3

void motor_driver_init();

void motor_driver_forward(ledc_channel_t channel_pin1,
                          ledc_channel_t channel_pin2, uint_fast8_t duty);

void motor_driver_backward(ledc_channel_t channel_pin1,
                           ledc_channel_t channel_pin2, uint_fast8_t duty);

#endif // !DRIVER_MOTOR
