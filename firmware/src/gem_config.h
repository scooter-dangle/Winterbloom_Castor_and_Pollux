#pragma once
#include "sam.h"
#include "gem_adc.h"

#define PIN_STATUS_LED PIN_PA18
#define PIN_STATUS_LED_PORT 0
#define PIN_STATUS_LED_2 PIN_PA07
#define PIN_STATUS_LED_2_PORT 0

#define PIN_BUTTON PIN_PA15
#define PIN_BUTTON_PORT 0


/* Analog to Digital Converter Configuration */

/*
    GCLK1: 8MHz Clock / DIV8 = 1 kHz ADC clock
    GCLK0: 48Mhz Clokc / DIV32 = 1.5 kHz ADC clock
*/
#define GEM_ADC_GCLK GCLK_CLKCTRL_GEN_GCLK0
#define GEM_ADC_PRESCALER ADC_CTRLB_PRESCALER_DIV32
#define GEM_ADC_REF internal

/* Max impedance is 28kOhms */
#define GEM_ADC_SAMPLE_TIME 2

#define GEM_ADC_SAMPLE_NUM ADC_AVGCTRL_SAMPLENUM_256
#define GEM_ADC_SAMPLE_ADJRES ADC_AVGCTRL_ADJRES(4)

// #define GEM_ADC_USE_EXTERNAL_REF

extern const struct gem_adc_input gem_adc_inputs[];


/* Pulse out/TCC configuration. */

#define GEM_PULSEOUT_GCLK GCLK_CLKCTRL_GEN_GCLK1

#define GEM_TCC0_PIN_PORT 0
#define GEM_TCC0_PIN PIN_PA18
#define GEM_TCC0_PIN_FUNC PORT_PMUX_PMUXE_F
#define GEM_TCC0_WO 2

#define GEM_TCC1_PIN_PORT 0
#define GEM_TCC1_PIN PIN_PA07
#define GEM_TCC1_PIN_FUNC PORT_PMUX_PMUXO_E
#define GEM_TCC1_WO 1


/* Functions. */

void gem_config_init();

int __wrap_printf(const char * format, ...);