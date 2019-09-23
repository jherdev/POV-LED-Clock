#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/debug.h"
#include "driverlib/pwm.h"
#include "driverlib/pin_map.h"
#include "inc/hw_gpio.h"
#include "driverlib/rom.h"

void delay_ms(uint32_t ui32Ms);

#define PWM_FREQUENCY 50 // Frequency in Hertz (Hz)

int main(void)
{
    int Load = 0;
    int PWMClock = 0;
    int PWMRate = 0;

    PWMRate = 920;  // (PWMRATE / 10 = duty cycle)

    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);   // 40 MHz
    SysCtlPWMClockSet(SYSCTL_PWMDIV_64);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);     // Enable PWM1 -
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);    // GPIO Pin Group D Enable
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);    // GPIO Pin Group A Enable

    GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_5);  // switch signal input

    GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_0);    // Convert D0 to PWM Output
    GPIOPinConfigure(GPIO_PD0_M1PWM0);              // Connect D0 to PWM1

    PWMClock = SysCtlClockGet() / 64;
    Load = (PWMClock / PWM_FREQUENCY) - 1;          // minus 1, count down to 0
    PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, Load);

    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, PWMRate * Load / 1000);
    PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT, true);
    PWMGenEnable(PWM1_BASE, PWM_GEN_0);

    while(1)
    {
        if(GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_5) == 32){
            PWMRate = 1000;
            PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, PWMRate * Load / 1000);
            do{
                delay_ms(500);
            }while(GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_5) == 32);
        }

        if(GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_5) == 0){
            PWMRate = 920;
            PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, PWMRate * Load / 1000);
            do{
                delay_ms(500);
            }while(GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_5) == 0);
        }
    }
}

void delay_ms(uint32_t ui32Ms) {
    SysCtlDelay(ui32Ms * (SysCtlClockGet() / 3 / 1000));
}

