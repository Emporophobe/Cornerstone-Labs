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
#include <sound.h>
#include <math.h>

double distanceThreshold = 11;
int turnTime = 800;
int forwardTime = 200;

double voltage;
double distance;

double convertFrontReading(double voltage)
{
  //y = 26.803*e^(-0.004636x)
  double coef = 26.803;
  double expo = -0.004636;
  
  return coef * exp(expo * voltage);
}

int main(void)
{
  
    lcd_init();  //Initialize the LCD
    adc_init();  //Initialize analog input
    servo_init(); //Initialize servo motor control
    
    while(1==1)            //Execute the following code repeatedly
    {
      
        voltage = adc_read(5);
        distance = convertFrontReading(voltage);
        lcd_decimal(FIRST_LINE, distance, 4); //Display x on LCD
        lcd_instruction(GOTO_LINE1);
        
        if (pin_value(PORT_B0) == HIGH && pin_value(PORT_D7) == HIGH)
        {
            //lcd_text(FIRST_LINE, "Left Sensor");
            //lcd_text(SECOND_LINE, "Right Sensor");
            servo_robot(REVERSE, 100);
            delay_ms(turnTime);
            servo_robot(SPIN_RIGHT, 100);
            delay_ms(turnTime);
            //lcd_clear();
        }
        else if(pin_value(PORT_B0) == HIGH)   //If left sensor detects boundary edge
        { 
            servo_robot(REVERSE, 100);
            delay_ms(turnTime);
            servo_robot(SPIN_RIGHT, 100);
            delay_ms(turnTime);
        }
        else if(pin_value(PORT_D7) == HIGH)  //If right sensor detects table edge
        {   
            servo_robot(REVERSE, 100);
            delay_ms(turnTime);
            servo_robot(SPIN_LEFT, 100);
            delay_ms(turnTime);
        }
        else
        {
            if(distance < distanceThreshold)
            {
             servo_robot(FORWARD, 100);
             delay_ms(forwardTime);
            }
            
            else
            {
              servo_robot(SPIN_RIGHT, 100);
              delay_ms(forwardTime/2);
            }
            
        }
    }           
}
