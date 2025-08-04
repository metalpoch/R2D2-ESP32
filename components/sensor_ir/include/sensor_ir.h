#ifndef SENSOR_IR
#define SENSOR_IR

#include "driver/gpio.h"

void sensor_ir_init(gpio_num_t pin);
bool sensor_ir_read(gpio_num_t pin);

#endif // !SENSOR_IR
