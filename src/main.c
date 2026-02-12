#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "I2C.h"
#include "ssd1306.h" 
bool isbuttonactive();
void init(){
	PORTK|=0xFF;
	
    
    DDRB &=~(1<<7);
    PORTB |=(1<<7); //internal pullup on digital pin 13


	DDRK &= ~(1<<0);
  PORTK|=(0xFF);
}
int counter = 0;
int main(void)
{  
	init();
  
  I2C_Init();  //initialize i2c interface to display

  InitializeDisplay(); //initialize  display


int num [3] ={0};
char numstring[4][8] = {0};

//itoa(PINK,counterstring,16);

  clear_display();  
  while (1)
  {
    //sendStrXY(calculationstring,0,0);
    if (isbuttonactive())
    {
        num[0] = PINK;
         itoa(num[0],numstring[0],16);
         
        //  _delay_ms(500);
        // while (!isbuttonactive());

         //strcat(calculationstring, "\n");
         sendStrXY(numstring[0],0,0);
        _delay_ms(500);
        while (!isbuttonactive());
        num[1] = PINK;
        itoa(num[1],numstring[1],16);
         
         sendStrXY(numstring[1],3,0);

         _delay_ms(500);
        while (!isbuttonactive());
        //num[2] = PINK;
        switch (PINK)
        {
        case 0xff:
            strcat(numstring[2], "&");
            num[2] = num[0] & num[1];
            itoa(num[2],numstring[3],16);
            break;
        case 0xfe:
            strcat(numstring[2], "|");
            num[2] = num[0] | num[1];
            itoa(num[2],numstring[3],16);
            break;
        case 0x7f:
            strcat(numstring[2], "&~");
            num[2] = num[0] &~ num[1];
            itoa(num[2],numstring[3],16);
            break;
        default:
            break;
        }
        sendStrXY(numstring[2],2,0);
        //_delay_ms(1000);
        sendStrXY(numstring[3],5,0);
         _delay_ms(500);
        while (!isbuttonactive());
        numstring[2][0] = '\0';
        clear_display();
        _delay_ms(500);

         
       //  sendStrXY(calculationstring,,0);
        // strcat(calculationstring, " = ");
        //strcat(calculationstring,"\n");
         //sendStrXY(calculationstring,0,0);
        //  numafterlogic = num1 + num2;
        //  itoa(numafterlogic,tmpstring,2);
        //  strcat(calculationstring, "hej");
        //  sendStrXY(calculationstring,0,0);
         

        
        
        
            
        
        
        
    }
    
    // itoa(counter,counterstring,10);
    // sendStrXY(counterstring,0,0);
    // counter++;
    // _delay_ms(1000);
  } 
}

 bool isbuttonactive()
 {
     if (!(PINB&(1<<7)))
     {
        _delay_ms(50);

        if (!(PINB&(1<<7)))
        {
            while(!(PINB&(1<<7)));
            _delay_ms(50);
            return true;
        }
        else return false;
        
     }
     else return false;
 }
