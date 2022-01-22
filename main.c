#include "msp.h"
#include "LCD.h"
#include "keypad.h"
#include "delay.h"
/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
    LCD_init();
	keypad_init();
	unsigned char key= keypad_getkey();

	while(key == 13){key = keypad_getkey();} //wait for button to be pressed
	LCD_write(key + 0x30); //changes char to ascii character for number
    while(key!=13){// wait for button to be released
	    delay_ms(1);
	    key=keypad_getkey();
	}

    while(key == 13){key = keypad_getkey();}//button press 2
    LCD_write(key + 0x30); //writes second letter
    while(key!=13){// wait for button to be released
         delay_ms(1);
         key=keypad_getkey();
     }

    while(key == 13){key = keypad_getkey();}//button press 3
    LCD_write(key + 0x30); //writes third letter
    while(key!=13){// wait for button to be released
         delay_ms(1);
         key=keypad_getkey();
     }

    while(key == 13){key = keypad_getkey();}//button press 4
    LCD_write(key + 0x30);//writes 4th letter
    while(key!=13){// wait for button to be released
         delay_ms(1);
         key=keypad_getkey();
     }

    LCD_write_word(" BOOM");
    LCD_command(SET_CURSOR | 0x40); // Move cursor to 2nd line
    LCD_write_word("Assignment 4"); // when using string/char * use "" instead of ''

    while(1);//infinite while loop
}
