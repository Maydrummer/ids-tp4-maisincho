#ifndef GPIO_H
#define GPIO_H

/** @file main.h
 ** @brief Definición de la función principal del programa
 **/

/* === Headers files inclusions ================================================================ */
#include <stdint.h>
#include <stdbool.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

typedef struct gpio_h * gpio_t;

/* === Public data type declarations =========================================================== */

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Función para crear un puerto digital
 *
 * @param port Numero de puerto GPIO correspondiente
 * @param bit Numero de bit asignado al puerto
 * @return gpio_t Puntero al objeto creado
 */
gpio_t GpioCreate(uint8_t port, uint8_t bit);

/**
 * @brief Función para configurar la direccion del puerto digital como salida o como entrada
 *
 * @param gpio puntero al objeto obtenido al llamar a la función GpioCreate
 * @param output configuración de salida del puerto digital: true => Salida, False => Entrada
 * @return Void No devuelve valor de retorno
 */
void GpioSetDirection(gpio_t gpio, bool output);

/**
 * @brief Función para consultar la direccion del puerto digital, si es salida o entrada
 *
 * @param gpio puntero al objeto obtenido al llamar a la función GpioCreate
 * @return true El puerto digital esta configurado como Salida
 * @return false El puerto digital esta configurado como Entrada
 */
bool GpioGetDirection(gpio_t gpio);

/**
 * @brief Función para configurar el estado del puerto digital: On / Off
 *
 * @param gpio puntero al objeto obtenido al llamar a la función GpioCreate
 * @param state El estado del puerto digital: true => Encender (On), false => Apagar (Off)
 * @return Void No devuelve valor de retorno
 */
void GpioSetState(gpio_t gpio, bool state);

/**
 * @brief Función para consultar el estado de un puerto digital
 *
 * @param gpio puntero al objeto obtenido al llamar a la función GpioCreate
 * @return true El puerto digital está encendido
 * @return false El puerto digital está apagado
 */
bool GpioGetState(gpio_t gpio);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */
