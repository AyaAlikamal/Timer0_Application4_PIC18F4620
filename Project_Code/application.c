/* 
 * File:   application.c
 * Author: AyaAli
 * Created on September 22, 2023, 10:24 AM
 */
#include "application.h"
void Timer0_Defualt_Hundeler(void);
volatile uint_8 square_25hz_waveform = ZERO_INIT;

timer0_config_t Timer1_obj={
.TMR0_Interrupt_Hundeler = Timer0_Defualt_Hundeler,
.timer0_mode = TIMER0_TIMER_MODE_CFG,
.timer0_conter_edge = TIMER0_RAISING_EDG_COFG,
.timer0_register_size = TIMER0_16BIT_MODE_CFG,
.timer0_prescaler_enable = TIMER0_PRESCALLER_DISABLE_COUNTER_CFG,
.timer0_preload_value = 55536
};

led_t led1={
.Port_Name = PORTC_INDEX,
.pin = PIN0,
.led_statues = LED_OFF
};
led_t led2={
.Port_Name = PORTC_INDEX,
.pin = PIN1,
.led_statues = LED_OFF
};
int main() {
   
Std_ReturnType ret = E_NOT_OK;
application_initialize();
ret = Timer0_Init(&Timer1_obj);
ret = led_initialize(&led1);
ret = led_initialize(&led2);

while(1){
    
}
 return (EXIT_SUCCESS);
}
void application_initialize(void){
   Std_ReturnType ret = E_NOT_OK;
//   ECU_Layer_initialize();

}

void Timer0_Defualt_Hundeler(void){
    square_25hz_waveform++;
    led_toggle(&led1);
    if(square_25hz_waveform == 2){
      square_25hz_waveform = 0;
      led_toggle(&led2);
    }
    else{}
}