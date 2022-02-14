#include "fsl_gpio.h"
#include "fsl_clock.h"
#include "fsl_iomuxc.h"
#include "fsl_rtwdog.h"

#define BOARD_NAME                                         "MIMXRT1060-EVK"
#define LED_GPIO                                           GPIO1
#define LED_GPIO_PIN                                       (9U)
#define LED_GPIO_PIN_MASK                                  (1U << 9U)   /*!< GPIO pin mask */
//#define CPU_MIMXRT1062DVL6A                                // Needed for including device header from fsl_device_registers.h
