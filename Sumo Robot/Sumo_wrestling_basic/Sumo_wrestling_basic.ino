/* Robot lookdown sensor (side sensor) test code. 

Note: This code works with a black course background and a white boundary.  For a white background with a black
  boundary, search for condition where pin_value(PORT_##) == HIGH
  Use this code to calibrate the sensors to just detect the boundary at the edge of the Sumo competition area.

*/
#include <mxapi.h>
#include <lcd.h>
#include <adc.h>
#include <ms_delay.h>
#include <servo.h>

int main(void)
{
    int time = 250;
  
    lcd_init();  //Initialize the LCD
    adc_init();  //Initialize analog input
    servo_init(); //Initialize servo motor control
    
    while(1==1)            //Execute the following code repeatedly
    {
        if (pin_value(PORT_B0) == HIGH && pin_value(PORT_D7) == HIGH)
        {
            lcd_text(FIRST_LINE, "Left Sensor");
            lcd_text(SECOND_LINE, "Right Sensor");
            servo_robot(REVERSE, 100);
            delay_ms(time);
            servo_robot(SPIN_RIGHT, 100);
            delay_ms(time);
            lcd_clear();
        }
        else if(pin_value(PORT_B0) == HIGH)   //If left sensor detects boundary edge
        { 
            lcd_text(FIRST_LINE, "Left Sensor");
            servo_robot(REVERSE, 50);
            delay_ms(time);
            servo_robot(SPIN_RIGHT, 50);
            delay_ms(time);
            lcd_clear();
        }
        else if(pin_value(PORT_D7) == HIGH)  //If right sensor detects table edge
        {   
            lcd_text(SECOND_LINE, "Right Sensor");
            servo_robot(REVERSE, 50);
            delay_ms(time);
            servo_robot(SPIN_LEFT, 50);
            delay_ms(time);
            lcd_clear();
        }
        else
        {
            servo_robot(FORWARD, 100);
        }
    }           
}
