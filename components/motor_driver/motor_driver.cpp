#include "motor_driver.h"
#include "driver/ledc.h"
#include "hal/ledc_types.h"
#include "soc/clk_tree_defs.h"

void motor_driver_init() {
  ledc_timer_config_t ledc_timer = {
      .speed_mode = LEDC_LOW_SPEED_MODE,
      .duty_resolution = LEDC_TIMER_8_BIT,
      .timer_num = LEDC_TIMER_0,
      .freq_hz = 5000,
      .clk_cfg = LEDC_AUTO_CLK,
      .deconfigure = false,
  };

  ledc_timer_config(&ledc_timer);

  ledc_channel_config_t ledc_channel = {
      .speed_mode = LEDC_LOW_SPEED_MODE,
      .timer_sel = LEDC_TIMER_0,
      .duty = 0,
      .hpoint = 0,
  };

  // Left motor
  ledc_channel.channel = MOTOR_LEFT_CHANNEL_PIN1;
  ledc_channel.gpio_num = MOTOR_LEFT_PIN1;
  ledc_channel_config(&ledc_channel);

  ledc_channel.channel = MOTOR_LEFT_CHANNEL_PIN2;
  ledc_channel.gpio_num = MOTOR_LEFT_PIN2;
  ledc_channel_config(&ledc_channel);

  // Right motor
  ledc_channel.channel = MOTOR_RIGHT_CHANNEL_PIN1;
  ledc_channel.gpio_num = MOTOR_RIGHT_PIN1;
  ledc_channel_config(&ledc_channel);

  ledc_channel.channel = MOTOR_RIGHT_CHANNEL_PIN2;
  ledc_channel.gpio_num = MOTOR_RIGHT_PIN2;
  ledc_channel_config(&ledc_channel);
}

void motor_driver_forward(ledc_channel_t channel_pin1,
                          ledc_channel_t channel_pin2, uint_fast8_t duty) {
  ledc_set_duty(LEDC_LOW_SPEED_MODE, channel_pin1, duty);
  ledc_update_duty(LEDC_LOW_SPEED_MODE, channel_pin1);

  ledc_set_duty(LEDC_LOW_SPEED_MODE, channel_pin2, 0);
  ledc_update_duty(LEDC_LOW_SPEED_MODE, channel_pin2);
}

void motor_driver_backward(ledc_channel_t channel_pin1,
                           ledc_channel_t channel_pin2, uint_fast8_t duty) {
  ledc_set_duty(LEDC_LOW_SPEED_MODE, channel_pin1, 0);
  ledc_update_duty(LEDC_LOW_SPEED_MODE, channel_pin1);

  ledc_set_duty(LEDC_LOW_SPEED_MODE, channel_pin2, duty);
  ledc_update_duty(LEDC_LOW_SPEED_MODE, channel_pin2);
}
