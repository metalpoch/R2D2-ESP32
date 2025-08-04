#include "sensor_ir.h"
#include "driver/gpio.h"
#include "hal/gpio_types.h"

void sensor_ir_init(gpio_num_t pin) {
  gpio_config_t io_conf;
  io_conf.mode = GPIO_MODE_INPUT;
  io_conf.pin_bit_mask = (1ULL << pin);
  io_conf.intr_type = GPIO_INTR_DISABLE;
  io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
  io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
  gpio_config(&io_conf);
}

bool sensor_ir_read(gpio_num_t pin) { return gpio_get_level(pin) == 0; }
