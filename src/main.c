#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "I2C.h"  //include library for i2c driver
#include "ssd1306.h"

int main()
{
  sendStrXY("fucking navi lort",5,0);
  return 0;  
}