#ifndef DRIVER_MOTOR
#define DRIVER_MOTOR
#include "driver/gpio.h"

void motor_driver_init(gpio_num_t pin1, gpio_num_t pin2);
void motor_driver_forward(gpio_num_t pin1, gpio_num_t pin2);
void motor_driver_backward(gpio_num_t pin1, gpio_num_t pin2);
void motor_driver_neutral(gpio_num_t pin1, gpio_num_t pin2);

#endif // !DRIVER_MOTOR
