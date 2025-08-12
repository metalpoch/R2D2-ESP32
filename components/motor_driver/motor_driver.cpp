#include "motor_driver.h"
#include "driver/gpio.h"
#include "hal/gpio_types.h"

void motor_driver_init(gpio_num_t pin1, gpio_num_t pin2) {
  gpio_config_t io_conf_1;
  io_conf_1.mode = GPIO_MODE_OUTPUT;
  io_conf_1.pin_bit_mask = (1ULL << pin1);
  io_conf_1.intr_type = GPIO_INTR_DISABLE;
  io_conf_1.pull_up_en = GPIO_PULLUP_DISABLE;
  io_conf_1.pull_down_en = GPIO_PULLDOWN_DISABLE;

  gpio_config_t io_conf_2;
  io_conf_2.mode = GPIO_MODE_OUTPUT;
  io_conf_2.pin_bit_mask = (1ULL << pin2);
  io_conf_2.intr_type = GPIO_INTR_DISABLE;
  io_conf_1.pull_up_en = GPIO_PULLUP_DISABLE;
  io_conf_1.pull_down_en = GPIO_PULLDOWN_DISABLE;

  gpio_config(&io_conf_1);
  gpio_config(&io_conf_2);
}

void motor_driver_forward(gpio_num_t pin1, gpio_num_t pin2) {
  gpio_set_level(pin1, 1);
  gpio_set_level(pin2, 0);
}

void motor_driver_backward(gpio_num_t pin1, gpio_num_t pin2) {
  gpio_set_level(pin1, 0);
  gpio_set_level(pin2, 1);
}

void motor_driver_neutral(gpio_num_t pin1, gpio_num_t pin2) {
  gpio_set_level(pin1, 0);
  gpio_set_level(pin2, 0);
}
