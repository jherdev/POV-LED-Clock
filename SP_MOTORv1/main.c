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

#define PWM_FREQUENCY 50 // Frequency in Hertz (Hz)

int main(void)
{
    int Load = 0;
    int PWMClock = 0;
    int PWMRate = 0;

    PWMRate = 930;  // (PWMRATE / 10 = duty cycle)

    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);   // 40 MHz
    SysCtlPWMClockSet(SYSCTL_PWMDIV_64);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);     // Enable PWM1 -
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);    // GPIO Pin Group D Enable

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

    }
}



