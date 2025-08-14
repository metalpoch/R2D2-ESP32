#include "driver/gpio.h"
#include "driver/ledc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "motor_driver.h"
#include "portmacro.h"
#include "sensor_ir.h"
#include <cstdint>
#include <iostream>
#include <stdio.h>

#define IR_GPIO GPIO_NUM_14
#define DELAY 100

extern "C" void app_main(void) {
  sensor_ir_init(IR_GPIO);
  motor_driver_init();

  while (1) {
    // bool obstacle = sensor_ir_read(IR_GPIO);
    //
    // obstacle ? std::cout << "a obstacle" << std::endl
    //          : std::cout << "free" << std ::endl;
    //
    // vTaskDelay(DELAY / portTICK_PERIOD_MS);

    for (int i = 0; i < 256; i++) {
      std::cout << "motor forward - duty: " << i << std::endl;
      motor_driver_forward(MOTOR_LEFT_CHANNEL_PIN1, MOTOR_LEFT_CHANNEL_PIN2, i);
      vTaskDelay(500 / portTICK_PERIOD_MS);
    }

    for (int i = 0; i < 256; i++) {
      std::cout << "motor backward - duty: " << i << std::endl;
      motor_driver_backward(MOTOR_LEFT_CHANNEL_PIN1, MOTOR_LEFT_CHANNEL_PIN2,
                            i);
      vTaskDelay(500 / portTICK_PERIOD_MS);
    }
  }
}
