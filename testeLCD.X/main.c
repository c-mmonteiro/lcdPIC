/*
 * File:   newmain.c
 * Author: Carlos
 *
 * Created on 20 de Setembro de 2021, 04:12
 */


#include <xc.h>
#include "lcd/lcd.h"

int main(void) {

    
    TRISEbits.TRISE7 = 1;   //Config Btn S1
    TRISEbits.TRISE8 = 1;   //Config Btn S2
    
    TRISEbits.TRISE5 = 0;   //Config LED 2
    TRISEbits.TRISE6 = 0;   //Config LED 1
    
    
    
    lcd_inicializa();
    lcd_escreveString("Ola Papa!");
    
    

    
    while (1)
    {
        if (PORTEbits.RE8 == 0){
            PORTEbits.RE5 = 1;
            lcd_inicializa();
            while (PORTEbits.RE8 == 0);
            PORTEbits.RE5 = 0;
        }
        if (PORTEbits.RE7 == 0){
            PORTEbits.RE6 = 1;
            lcd_clear();
            lcd_linha1();
            lcd_escreveString("Ola Mama!");
            lcd_linha2();
            lcd_escreveString("Ola Papa!");
            while (PORTEbits.RE7 == 0);
            PORTEbits.RE6 = 0;
        }   
    }
    
    
    return 0;
}
