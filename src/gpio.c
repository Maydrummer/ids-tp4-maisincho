#include "gpio.h"
#include <stddef.h>

#ifndef GPIO_MAX_INSTANCES
#define GPIO_MAX_INSTANCES 10
#endif
//! Estructura con los atributos de un puerto digital
struct gpio_h {
    uint8_t port; //!< Numero de puerto GPIO
    uint8_t pin;  //!< Pin del puerto GPIO
    bool state;   //!< Estado actual del puerto digital
    bool output;  //!< El puerto es configurado como salida
#ifdef USE_STATIC_MEM
    bool used; //!< El descriptor del puerto está ocupado
#endif
};

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

static gpio_t GpioAllocate(void);

/* === Private function implementation ========================================================= */

#ifdef USE_STATIC_MEM
static gpio_t GpioAllocate(void) {
    static struct gpio_h Instances[MAX_GPIO_INSTANCES] = {0};

    gpio_t self = NULL;
    for (int Index = 0; Index < MAX_GPIO_INSTANCES; Index++) {
        if (!Instances[Index].used) {
            self = &Instances[Index];
            self->used = true;
            break;
        }
    }
    return self;
}
#endif

/* === Public function implementation ========================================================== */

gpio_t GpioCreate(uint8_t port, uint8_t bit) {
    gpio_t self;
#ifdef USE_STATIC_MEM
    self = GpioAllocate();
#else
    self = malloc(sizeof(struct gpio_h));
#endif
    if (self) {
        self->port = port;
        self->pin = bit;
        self->output = false;
        self->state = false;
    }

    return self;
}

void GpioSetDirection(gpio_t self, bool output) {
    self->output = output;
}

bool GpioGetDirection(gpio_t self) {
    return self->output;
}

void GpioSetState(gpio_t self, bool state) {
    if (self->output) {
        self->state = state;
    }
}

bool GpioGetState(gpio_t self) {
    return self->state;
}

/* === End of documentation ==================================================================== */
