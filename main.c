//Include library files
#include "main.h"

// Systick Delay Counter
//volatile uint32_t g_systickCounter;
bool pinState = false;


// Possible Implementation of Systick Delay
/*
void SysTick_Handler(void)
{
    if (g_systickCounter != 0U)
    {
        g_systickCounter--;
    }
}

void SysTick_DelayTicks(uint32_t n)
{
    g_systickCounter = n;
    while (g_systickCounter != 0U)
    {
    }
}
*/

/*
Delay Function as SysTick Delay will not be used here
*/
void myDelay (uint32_t delay)
{
  for (uint32_t i = 0; i<delay; i++)
  {
    uint32_t useless = 0;
    useless = i;
  }
}

int main()
{
  
  // ----- Enable Clocks -----
  /*kCLOCK-Iomuxc = CCGR4_CG1 (fsl_clock.h)*/
  CLOCK_EnableClock(kCLOCK_Iomuxc);

  // ----- Disable RTWDOG -----
  
  //RTWDOG->CS &= ~RTWDOG_CS_EN_MASK;
  //RTWDOG->TOVAL = 0xFFFF;

  RTWDOG_Disable(RTWDOG);
  RTWDOG_SetTimeoutValue(RTWDOG,0xFFFF);  // Without this, the Watchdog will somehow still be enabled
  
  // ----- Configure IOMUX and GPIO -----
  /* GPIO configuration of USER_LED on GPIO_AD_B0_09 (pin F14) */
  gpio_pin_config_t USER_LED_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  GPIO_PinInit(LED_GPIO, LED_GPIO_PIN, &USER_LED_config);

  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_09_GPIO1_IO09, 0U); 

  IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_09_GPIO1_IO09, 0x10B0U); //??
  // Clock Config
  
  while(1)
  {
    
    // ----- Delay -----
    myDelay(0x5FFFF);
    // ----- Toggle LEDs -----
    /*API Reference mismatch --> 3 Parameters and missing function GPIO_TogglePinOutput
    https://mcuxpresso.nxp.com/api_doc/dev/329/group__lpc__gpio.html#ga63087014b80c48f9556d67aeede5f854*/
    GPIO_PortToggle(LED_GPIO, LED_GPIO_PIN_MASK);
    /*
    if(pinState == true)
    {
       GPIO_PinWrite(LED_GPIO, LED_GPIO_PIN, 0u);
       pinState = false;
    }
    else
    {
       GPIO_PinWrite(LED_GPIO, LED_GPIO_PIN, 1u);
       pinState = true;
     
    }
    */
  }
  
  
  return 0;
}
