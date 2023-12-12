#include <stdint.h>
#include <stdbool.h>

typedef struct gpio_s * gpio_t;

/**
 * @brief Funcion que crea un GPIO
 *
 * @param puerto
 * @param bit
 * @return gpio_t
 */
gpio_t gpioCreate(uint8_t puerto, uint8_t bit);

/**
 * @brief Funcion que setea salida de un GPIO
 *
 * @param gpio
 * @param output
 * @return void
 */
void gpioSetOutput(gpio_t gpio, bool output);

/**
 * @brief Funcion que setea estado de un GPIO
 *
 * @param gpio
 * @param state
 * @return void
 */
void gpioSetState(gpio_t gpio, bool state);

/**
 * @brief Funcion que obtiene el estado de un GPIO
 *
 * @param gpio
 * @return bool
 */
bool gpioGetState(gpio_t gpio);
