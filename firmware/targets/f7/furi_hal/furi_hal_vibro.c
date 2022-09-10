#include <furi_hal_vibro.h>
#include <furi_hal_gpio.h>

#define TAG "FuriHalVibro"

void furi_hal_vibro_init() {
    furi_hal_gpio_init(&vibro_gpio, GpioModeOutputPushPull, GpioPullNo, GpioSpeedLow);
    furi_hal_gpio_write(&vibro_gpio, false);
    FURI_LOG_I(TAG, "Init OK");
}

void furi_hal_vibro_on(bool value) {
    furi_hal_gpio_write(&vibro_gpio, value);
}
