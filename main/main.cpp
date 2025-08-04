#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "portmacro.h"
#include "sensor_ir.h"
#include <iostream>
#include <stdio.h>

#define IR_GPIO GPIO_NUM_14
#define DELAY 100

extern "C" void app_main(void) {
  sensor_ir_init(IR_GPIO);

  while (1) {
    bool obstacle = sensor_ir_read(IR_GPIO);

    obstacle ? std::cout << "a obstacle" << std::endl
             : std::cout << "free" << std ::endl;

    vTaskDelay(DELAY / portTICK_PERIOD_MS);
  }
}
