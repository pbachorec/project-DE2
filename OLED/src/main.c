// https://github.com/Sylaina/oled-display

#include <avr/io.h>
#include <oled.h>
#include <timer.h>
#include <avr/interrupt.h> 

volatile uint8_t display_mode = 0;  // 0 = Amplituda, 1 = Otáčky

int main(void)
{
//inicializace
oled_init(OLED_DISP_ON); 
oled_clrscr();
TIM1_ovf_4sec();
TIM1_ovf_enable();

sei();

while (1)
{
    if(display_mode == 1)
    {
      //Current
      oled_gotoxy(0,0);
      oled_charMode(DOUBLESIZE);
      oled_puts("0.05 A");

      //Wattage
      oled_gotoxy(0,2);
      oled_charMode(DOUBLESIZE);
      oled_puts("0.05 W/m2");
      oled_gotoxy(0,4);

      //
      oled_charMode(DOUBLESIZE);
      oled_puts("0.05 Wh/m2");
      oled_display();
    }
    else
    {
      //Current
      oled_gotoxy(0,0);
      oled_charMode(DOUBLESIZE);
      oled_puts("Otacky");

      //Wattage
      oled_gotoxy(0,2);
      oled_charMode(DOUBLESIZE);
      oled_puts("....");
      oled_gotoxy(0,4);

      //
      oled_charMode(DOUBLESIZE);
      oled_puts("....");
      oled_display();      
    }
}
  return 0;
}

ISR(TIMER1_OVF_vect)
{   
    display_mode = !display_mode;

}