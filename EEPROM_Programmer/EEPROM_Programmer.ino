// EEPROM info
#define MAX_ADDRESS 2048
#define SHIFT_LEN 16 //number of bits to be shifted (16 = 2 74HC595 chips) + output enable

#define WRITE_DATA true
#define VALIDATE_DATA true
static const byte PROGMEM data_to_write [MAX_ADDRESS] = 
{0x00, 0x77, 0x99, 0x77, 0x22, 0x44, 0x77, 0x66, 0x33, 0x44, 0x88, 0x77, 0x11, 0x00, 0x88, 0x66, 0x22, 0x11, 0x66, 0x22, 0x55, 0x44, 0x77, 0x88, 0x00, 0x66, 0x77, 0x66, 0x44, 0x22, 0x99, 0x44, 0x33, 0x00, 0x66, 0x22, 0x99, 0x33, 0x99, 0x11, 0x00, 0x33, 0x99, 0x00, 0x66, 0x66, 0x66, 0x77, 0x77, 0x44, 0x44, 0x44, 0x44, 0x66, 0x88, 0x00, 0x22, 0x66, 0x00, 0x44, 0x66, 0x22, 0x55, 0x55, 
0x22, 0x55, 0x11, 0x00, 0x00, 0x00, 0x11, 0x88, 0x33, 0x55, 0x66, 0x44, 0x11, 0x22, 0x88, 0x33, 0x88, 0x11, 0x11, 0x33, 0x88, 0x88, 0x33, 0x11, 0x11, 0x22, 0x88, 0x77, 0x55, 0x44, 0x44, 0x44, 0x22, 0x11, 0x33, 0x88, 0x22, 0x55, 0x66, 0x22, 0x11, 0x33, 0x44, 0x33, 0x33, 0x00, 0x99, 0x66, 0x99, 0x55, 0x55, 0x99, 0x55, 0x66, 0x22, 0x77, 0x88, 0x88, 0x99, 0x33, 0x22, 0x22, 0x44, 0x99, 
0x77, 0x88, 0x77, 0x88, 0x22, 0x44, 0x55, 0x99, 0x33, 0x99, 0x22, 0x33, 0x44, 0x00, 0x22, 0x55, 0x88, 0x44, 0x00, 0x99, 0x88, 0x44, 0x88, 0x00, 0x00, 0x66, 0x33, 0x11, 0x66, 0x88, 0x22, 0x99, 0x55, 0x22, 0x00, 0x22, 0x44, 0x77, 0x66, 0x88, 0x11, 0x44, 0x00, 0x00, 0x44, 0x22, 0x77, 0x44, 0x00, 0x66, 0x22, 0x22, 0x22, 0x88, 0x44, 0x11, 0x77, 0x22, 0x22, 0x77, 0x88, 0x99, 0x77, 0x77, 
0x88, 0x44, 0x00, 0x88, 0x11, 0x00, 0x88, 0x33, 0x00, 0x11, 0x22, 0x99, 0x22, 0x99, 0x88, 0x44, 0x99, 0x22, 0x33, 0x22, 0x11, 0x44, 0x00, 0x66, 0x88, 0x77, 0x22, 0x00, 0x11, 0x22, 0x22, 0x99, 0x22, 0x44, 0x44, 0x88, 0x55, 0x99, 0x77, 0x99, 0x00, 0x88, 0x66, 0x99, 0x11, 0x11, 0x77, 0x88, 0x99, 0x11, 0x88, 0x66, 0x00, 0x11, 0x99, 0x11, 0x11, 0x22, 0x88, 0x44, 0x99, 0x22, 0x11, 0x99, 
0x44, 0x22, 0x88, 0x99, 0x66, 0x88, 0x11, 0x55, 0x55, 0x22, 0x66, 0x11, 0x44, 0x22, 0x77, 0x66, 0x44, 0x11, 0x22, 0x22, 0x22, 0x66, 0x55, 0x66, 0x55, 0x22, 0x00, 0x33, 0x11, 0x66, 0x77, 0x11, 0x00, 0x33, 0x22, 0x00, 0x11, 0x33, 0x33, 0x66, 0x88, 0x66, 0x99, 0x22, 0x44, 0x66, 0x44, 0x88, 0x00, 0x66, 0x88, 0x55, 0x88, 0x88, 0x44, 0x55, 0x00, 0x88, 0x99, 0x33, 0x00, 0x66, 0x66, 0x99, 
0x55, 0x77, 0x99, 0x88, 0x77, 0x44, 0x00, 0x44, 0x33, 0x55, 0x22, 0x11, 0x22, 0x33, 0x99, 0x33, 0x11, 0x66, 0x00, 0x11, 0x77, 0x99, 0x11, 0x11, 0x66, 0x55, 0x11, 0x55, 0x33, 0x44, 0x33, 0x55, 0x44, 0x33, 0x11, 0x55, 0x55, 0x44, 0x33, 0x33, 0x99, 0x11, 0x66, 0x11, 0x33, 0x22, 0x00, 0x22, 0x99, 0x44, 0x66, 0x55, 0x33, 0x99, 0x44, 0x44, 0x00, 0x99, 0x77, 0x22, 0x11, 0x44, 0x88, 0x22, 
0x33, 0x66, 0x00, 0x22, 0x99, 0x99, 0x00, 0x55, 0x88, 0x00, 0x44, 0x99, 0x22, 0x77, 0x00, 0x99, 0x88, 0x99, 0x00, 0x22, 0x66, 0x44, 0x66, 0x11, 0x11, 0x88, 0x88, 0x44, 0x00, 0x44, 0x11, 0x11, 0x77, 0x77, 0x33, 0x00, 0x88, 0x11, 0x33, 0x55, 0x88, 0x55, 0x00, 0x33, 0x33, 0x22, 0x55, 0x33, 0x88, 0x77, 0x88, 0x44, 0x99, 0x55, 0x11, 0x55, 0x33, 0x77, 0x77, 0x33, 0x44, 0x00, 0x55, 0x99, 
0x44, 0x33, 0x66, 0x44, 0x33, 0x77, 0x44, 0x11, 0x22, 0x55, 0x00, 0x99, 0x44, 0x77, 0x55, 0x88, 0x99, 0x66, 0x00, 0x66, 0x77, 0x99, 0x22, 0x11, 0x22, 0x11, 0x00, 0x11, 0x55, 0x55, 0x00, 0x00, 0x66, 0x55, 0x11, 0x33, 0x99, 0x22, 0x44, 0x00, 0x00, 0x44, 0x11, 0x33, 0x88, 0x99, 0x77, 0x88, 0x11, 0x44, 0x44, 0x55, 0x88, 0x22, 0x11, 0x33, 0x33, 0x44, 0x77, 0x88, 0x99, 0x77, 0x55, 0x66, 
0x77, 0x88, 0x66, 0x55, 0x55, 0x99, 0x88, 0x55, 0x55, 0x33, 0x22, 0x44, 0x66, 0x55, 0x66, 0x88, 0x99, 0x55, 0x22, 0x99, 0x33, 0x11, 0x22, 0x33, 0x66, 0x66, 0x77, 0x77, 0x11, 0x77, 0x11, 0x99, 0x22, 0x66, 0x99, 0x33, 0x00, 0x88, 0x88, 0x22, 0x88, 0x66, 0x22, 0x11, 0x99, 0x11, 0x55, 0x33, 0x88, 0x22, 0x66, 0x00, 0x22, 0x77, 0x55, 0x22, 0x44, 0x33, 0x55, 0x55, 0x33, 0x66, 0x77, 0x33, 
0x77, 0x22, 0x88, 0x66, 0x77, 0x33, 0x22, 0x77, 0x11, 0x33, 0x00, 0x22, 0x55, 0x55, 0x11, 0x88, 0x22, 0x11, 0x00, 0x77, 0x66, 0x33, 0x11, 0x99, 0x55, 0x55, 0x77, 0x99, 0x22, 0x88, 0x22, 0x77, 0x33, 0x77, 0x77, 0x88, 0x88, 0x44, 0x11, 0x88, 0x44, 0x88, 0x22, 0x77, 0x66, 0x00, 0x22, 0x22, 0x22, 0x99, 0x88, 0x44, 0x66, 0x44, 0x55, 0x77, 0x88, 0x22, 0x33, 0x77, 0x22, 0x55, 0x11, 0x77, 
0x00, 0x99, 0x77, 0x88, 0x44, 0x66, 0x77, 0x44, 0x77, 0x11, 0x66, 0x22, 0x66, 0x11, 0x00, 0x55, 0x11, 0x66, 0x66, 0x55, 0x77, 0x77, 0x55, 0x66, 0x88, 0x77, 0x88, 0x55, 0x66, 0x33, 0x44, 0x00, 0x11, 0x55, 0x33, 0x77, 0x88, 0x99, 0x77, 0x77, 0x11, 0x55, 0x55, 0x00, 0x44, 0x88, 0x55, 0x33, 0x22, 0x11, 0x22, 0x00, 0x55, 0x55, 0x99, 0x22, 0x55, 0x11, 0x00, 0x33, 0x33, 0x77, 0x99, 0x44, 
0x77, 0x88, 0x44, 0x33, 0x88, 0x11, 0x88, 0x88, 0x22, 0x77, 0x44, 0x88, 0x77, 0x33, 0x99, 0x77, 0x55, 0x22, 0x44, 0x88, 0x88, 0x66, 0x44, 0x66, 0x44, 0x33, 0x33, 0x44, 0x11, 0x11, 0x55, 0x00, 0x66, 0x44, 0x00, 0x66, 0x55, 0x99, 0x33, 0x33, 0x00, 0x44, 0x66, 0x99, 0x77, 0x99, 0x33, 0x66, 0x99, 0x44, 0x66, 0x88, 0x11, 0x55, 0x33, 0x33, 0x66, 0x55, 0x33, 0x55, 0x66, 0x22, 0x22, 0x55, 
0x88, 0x66, 0x66, 0x77, 0x66, 0x44, 0x33, 0x11, 0x33, 0x33, 0x11, 0x00, 0x88, 0x88, 0x77, 0x77, 0x66, 0x88, 0x11, 0x11, 0x55, 0x66, 0x44, 0x11, 0x11, 0x22, 0x33, 0x22, 0x55, 0x55, 0x77, 0x44, 0x55, 0x22, 0x00, 0x22, 0x88, 0x77, 0x77, 0x99, 0x55, 0x44, 0x88, 0x22, 0x88, 0x88, 0x22, 0x00, 0x88, 0x22, 0x88, 0x88, 0x66, 0x77, 0x55, 0x99, 0x99, 0x22, 0x77, 0x22, 0x44, 0x88, 0x00, 0x00, 
0x99, 0x33, 0x00, 0x99, 0x66, 0x99, 0x99, 0x66, 0x77, 0x22, 0x88, 0x22, 0x66, 0x88, 0x99, 0x77, 0x44, 0x99, 0x44, 0x99, 0x44, 0x00, 0x44, 0x66, 0x44, 0x66, 0x66, 0x77, 0x00, 0x66, 0x88, 0x00, 0x99, 0x11, 0x22, 0x55, 0x99, 0x44, 0x99, 0x99, 0x44, 0x00, 0x44, 0x33, 0x22, 0x00, 0x66, 0x11, 0x33, 0x88, 0x00, 0x22, 0x33, 0x88, 0x77, 0x66, 0x66, 0x33, 0x44, 0x88, 0x22, 0x44, 0x99, 0x44, 
0x11, 0x99, 0x66, 0x33, 0x66, 0x55, 0x44, 0x66, 0x44, 0x22, 0x55, 0x55, 0x44, 0x88, 0x33, 0x99, 0x99, 0x66, 0x22, 0x88, 0x44, 0x22, 0x99, 0x77, 0x66, 0x33, 0x33, 0x66, 0x55, 0x44, 0x44, 0x22, 0x66, 0x33, 0x00, 0x66, 0x55, 0x44, 0x11, 0x00, 0x66, 0x33, 0x88, 0x88, 0x55, 0x44, 0x22, 0x33, 0x44, 0x77, 0x55, 0x22, 0x11, 0x55, 0x00, 0x99, 0x44, 0x44, 0x00, 0x55, 0x44, 0x55, 0x33, 0x99, 
0x44, 0x22, 0x88, 0x66, 0x77, 0x66, 0x66, 0x77, 0x55, 0x00, 0x55, 0x33, 0x44, 0x88, 0x77, 0x55, 0x88, 0x11, 0x88, 0x88, 0x55, 0x77, 0x77, 0x22, 0x00, 0x33, 0x00, 0x11, 0x22, 0x00, 0x77, 0x44, 0x44, 0x99, 0x11, 0x88, 0x44, 0x33, 0x77, 0x55, 0x00, 0x66, 0x77, 0x55, 0x22, 0x00, 0x00, 0x33, 0x88, 0x33, 0x00, 0x44, 0x33, 0x99, 0x99, 0x33, 0x55, 0x44, 0x22, 0x44, 0x99, 0x44, 0x88, 0x55, 
0x88, 0x00, 0x66, 0x55, 0x11, 0x44, 0x44, 0x22, 0x66, 0x11, 0x66, 0x33, 0x22, 0x66, 0x00, 0x88, 0x00, 0x44, 0x77, 0x55, 0x44, 0x22, 0x77, 0x88, 0x44, 0x44, 0x22, 0x33, 0x33, 0x66, 0x88, 0x99, 0x33, 0x22, 0x55, 0x44, 0x88, 0x00, 0x55, 0x55, 0x99, 0x88, 0x22, 0x77, 0x66, 0x22, 0x33, 0x00, 0x44, 0x22, 0x33, 0x11, 0x33, 0x88, 0x22, 0x66, 0x66, 0x88, 0x99, 0x77, 0x77, 0x66, 0x11, 0x44, 
0x22, 0x99, 0x44, 0x66, 0x33, 0x22, 0x77, 0x11, 0x11, 0x77, 0x55, 0x55, 0x22, 0x00, 0x88, 0x55, 0x33, 0x77, 0x00, 0x22, 0x33, 0x66, 0x88, 0x22, 0x00, 0x99, 0x00, 0x66, 0x11, 0x00, 0x99, 0x11, 0x22, 0x88, 0x66, 0x66, 0x33, 0x00, 0x99, 0x22, 0x44, 0x44, 0x44, 0x77, 0x66, 0x55, 0x33, 0x88, 0x66, 0x99, 0x00, 0x44, 0x99, 0x44, 0x77, 0x66, 0x11, 0x00, 0x77, 0x44, 0x11, 0x77, 0x33, 0x44, 
0x44, 0x99, 0x44, 0x11, 0x22, 0x44, 0x33, 0x77, 0x99, 0x55, 0x55, 0x22, 0x55, 0x99, 0x77, 0x55, 0x44, 0x99, 0x11, 0x22, 0x00, 0x11, 0x33, 0x55, 0x44, 0x99, 0x55, 0x33, 0x33, 0x33, 0x55, 0x77, 0x11, 0x99, 0x22, 0x99, 0x55, 0x22, 0x22, 0x55, 0x00, 0x22, 0x77, 0x99, 0x55, 0x44, 0x00, 0x44, 0x77, 0x88, 0x77, 0x88, 0x33, 0x33, 0x55, 0x77, 0x77, 0x77, 0x77, 0x00, 0x77, 0x33, 0x99, 0x00, 
0x99, 0x11, 0x33, 0x66, 0x77, 0x33, 0x99, 0x33, 0x22, 0x33, 0x44, 0x22, 0x11, 0x22, 0x88, 0x77, 0x55, 0x33, 0x11, 0x22, 0x44, 0x33, 0x33, 0x88, 0x44, 0x22, 0x33, 0x99, 0x77, 0x88, 0x77, 0x88, 0x00, 0x22, 0x22, 0x00, 0x22, 0x33, 0x88, 0x55, 0x00, 0x11, 0x44, 0x00, 0x11, 0x33, 0x55, 0x00, 0x22, 0x44, 0x11, 0x99, 0x44, 0x55, 0x44, 0x00, 0x88, 0x11, 0x11, 0x11, 0x77, 0x33, 0x00, 0x99, 
0x00, 0x44, 0x00, 0x66, 0x77, 0x11, 0x00, 0x00, 0x55, 0x77, 0x22, 0x66, 0x55, 0x00, 0x66, 0x66, 0x88, 0x88, 0x88, 0x22, 0x44, 0x66, 0x66, 0x55, 0x88, 0x33, 0x11, 0x11, 0x55, 0x11, 0x77, 0x44, 0x77, 0x00, 0x77, 0x22, 0x00, 0x33, 0x33, 0x22, 0x88, 0x22, 0x00, 0x33, 0x99, 0x00, 0x22, 0x55, 0x55, 0x66, 0x55, 0x00, 0x11, 0x22, 0x77, 0x77, 0x00, 0x22, 0x77, 0x11, 0x99, 0x77, 0x22, 0x88, 
0x00, 0x88, 0x33, 0x77, 0x33, 0x22, 0x77, 0x22, 0x66, 0x55, 0x55, 0x22, 0x00, 0x11, 0x88, 0x55, 0x66, 0x55, 0x88, 0x66, 0x33, 0x11, 0x11, 0x11, 0x77, 0x66, 0x55, 0x11, 0x77, 0x11, 0x44, 0x00, 0x99, 0x88, 0x99, 0x11, 0x99, 0x99, 0x33, 0x00, 0x00, 0x11, 0x66, 0x11, 0x44, 0x44, 0x66, 0x11, 0x77, 0x66, 0x22, 0x00, 0x22, 0x22, 0x55, 0x77, 0x77, 0x99, 0x55, 0x00, 0x77, 0x99, 0x22, 0x22, 
0x88, 0x77, 0x00, 0x66, 0x99, 0x44, 0x88, 0x88, 0x11, 0x44, 0x11, 0x33, 0x33, 0x00, 0x44, 0x99, 0x77, 0x77, 0x77, 0x77, 0x55, 0x99, 0x99, 0x11, 0x77, 0x33, 0x99, 0x77, 0x77, 0x77, 0x00, 0x00, 0x77, 0x99, 0x11, 0x00, 0x00, 0x77, 0x22, 0x55, 0x77, 0x22, 0x22, 0x88, 0x11, 0x99, 0x44, 0x00, 0x66, 0x44, 0x77, 0x22, 0x77, 0x22, 0x88, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x11, 0x88, 0x77, 
0x66, 0x88, 0x00, 0x88, 0x88, 0x11, 0x22, 0x99, 0x22, 0x33, 0x11, 0x11, 0x11, 0x88, 0x11, 0x66, 0x11, 0x55, 0x55, 0x77, 0x66, 0x99, 0x66, 0x11, 0x55, 0x44, 0x44, 0x11, 0x33, 0x66, 0x77, 0x99, 0x99, 0x00, 0x66, 0x44, 0x44, 0x99, 0x22, 0x44, 0x33, 0x66, 0x77, 0x99, 0x33, 0x66, 0x22, 0x11, 0x44, 0x66, 0x55, 0x00, 0x11, 0x00, 0x11, 0x33, 0x88, 0x33, 0x44, 0x11, 0x88, 0x22, 0x22, 0x33, 
0x22, 0x11, 0x22, 0x77, 0x66, 0x99, 0x55, 0x99, 0x66, 0x33, 0x44, 0x11, 0x22, 0x11, 0x22, 0x99, 0x00, 0x88, 0x22, 0x88, 0x00, 0x22, 0x55, 0x66, 0x77, 0x66, 0x44, 0x11, 0x88, 0x33, 0x88, 0x66, 0x22, 0x11, 0x44, 0x77, 0x66, 0x66, 0x77, 0x77, 0x11, 0x00, 0x55, 0x22, 0x88, 0x00, 0x22, 0x11, 0x00, 0x00, 0x55, 0x00, 0x88, 0x33, 0x88, 0x99, 0x00, 0x00, 0x99, 0x66, 0x00, 0x11, 0x55, 0x22, 
0x00, 0x55, 0x11, 0x44, 0x99, 0x11, 0x44, 0x66, 0x00, 0x88, 0x66, 0x00, 0x66, 0x33, 0x55, 0x99, 0x22, 0x44, 0x55, 0x44, 0x33, 0x33, 0x66, 0x11, 0x44, 0x44, 0x88, 0x77, 0x66, 0x77, 0x88, 0x00, 0x99, 0x88, 0x33, 0x99, 0x00, 0x11, 0x66, 0x44, 0x77, 0x55, 0x11, 0x33, 0x88, 0x55, 0x11, 0x44, 0x22, 0x22, 0x22, 0x55, 0x00, 0x88, 0x66, 0x22, 0x44, 0x55, 0x66, 0x44, 0x55, 0x11, 0x33, 0x88, 
0x55, 0x66, 0x55, 0x33, 0x00, 0x66, 0x55, 0x33, 0x99, 0x55, 0x33, 0x77, 0x99, 0x44, 0x00, 0x00, 0x00, 0x88, 0x66, 0x66, 0x33, 0x77, 0x22, 0x66, 0x88, 0x66, 0x33, 0x22, 0x44, 0x33, 0x66, 0x44, 0x33, 0x22, 0x66, 0x11, 0x99, 0x22, 0x55, 0x22, 0x55, 0x88, 0x22, 0x11, 0x11, 0x66, 0x88, 0x88, 0x99, 0x99, 0x22, 0x22, 0x55, 0x66, 0x22, 0x44, 0x88, 0x00, 0x99, 0x00, 0x99, 0x22, 0x11, 0x55, 
0x00, 0x44, 0x99, 0x99, 0x22, 0x33, 0x00, 0x55, 0x55, 0x11, 0x22, 0x88, 0x00, 0x22, 0x88, 0x99, 0x99, 0x00, 0x33, 0x88, 0x77, 0x22, 0x00, 0x77, 0x33, 0x33, 0x88, 0x11, 0x11, 0x99, 0x44, 0x55, 0x00, 0x11, 0x99, 0x11, 0x22, 0x99, 0x22, 0x44, 0x11, 0x00, 0x99, 0x88, 0x66, 0x22, 0x44, 0x22, 0x88, 0x44, 0x55, 0x00, 0x44, 0x44, 0x99, 0x99, 0x22, 0x11, 0x99, 0x88, 0x44, 0x33, 0x88, 0x55, 
0x77, 0x77, 0x11, 0x44, 0x55, 0x66, 0x55, 0x22, 0x66, 0x44, 0x44, 0x22, 0x44, 0x55, 0x88, 0x00, 0x88, 0x77, 0x22, 0x88, 0x66, 0x22, 0x66, 0x55, 0x55, 0x77, 0x11, 0x22, 0x55, 0x11, 0x99, 0x66, 0x66, 0x00, 0x11, 0x55, 0x77, 0x77, 0x11, 0x11, 0x88, 0x11, 0x11, 0x11, 0x33, 0x22, 0x44, 0x44, 0x88, 0x88, 0x77, 0x22, 0x33, 0x99, 0x11, 0x00, 0x88, 0x77, 0x99, 0x99, 0x77, 0x11, 0x11, 0x22, 
0x11, 0x55, 0x66, 0x00, 0x00, 0x66, 0x99, 0x11, 0x11, 0x00, 0x11, 0x55, 0x22, 0x88, 0x11, 0x66, 0x11, 0x00, 0x77, 0x11, 0x33, 0x11, 0x66, 0x22, 0x55, 0x55, 0x33, 0x11, 0x11, 0x55, 0x77, 0x11, 0x66, 0x88, 0x99, 0x00, 0x66, 0x88, 0x44, 0x77, 0x33, 0x55, 0x99, 0x00, 0x99, 0x22, 0x33, 0x66, 0x22, 0x22, 0x55, 0x99, 0x66, 0x44, 0x22, 0x00, 0x00, 0x33, 0x22, 0x88, 0x88, 0x44, 0x33, 0x00, 
0x00, 0x44, 0x77, 0x00, 0x77, 0x77, 0x11, 0x00, 0x22, 0x55, 0x99, 0x66, 0x55, 0x66, 0x88, 0x44, 0x55, 0x33, 0x11, 0x55, 0x66, 0x88, 0x77, 0x55, 0x00, 0x99, 0x44, 0x88, 0x00, 0x55, 0x22, 0x44, 0x77, 0x44, 0x88, 0x44, 0x33, 0x99, 0x88, 0x22, 0x00, 0x55, 0x00, 0x00, 0x11, 0x22, 0x99, 0x33, 0x44, 0x55, 0x99, 0x22, 0x66, 0x22, 0x88, 0x44, 0x33, 0x66, 0x77, 0x55, 0x77, 0x44, 0x33, 0x22, 
0x77, 0x99, 0x77, 0x77, 0x11, 0x77, 0x22, 0x33, 0x99, 0x77, 0x99, 0x00, 0x00, 0x44, 0x00, 0x22, 0x55, 0x88, 0x99, 0x88, 0x77, 0x11, 0x99, 0x77, 0x22, 0x44, 0x66, 0x00, 0x66, 0x44, 0x66, 0x99, 0x11, 0x77, 0x66, 0x55, 0x11, 0x99, 0x11, 0x66, 0x88, 0x55, 0x88, 0x55, 0x88, 0x55, 0x00, 0x11, 0x55, 0x00, 0x88, 0x77, 0x44, 0x11, 0x66, 0x00, 0x55, 0x00, 0x66, 0x11, 0x00, 0x66, 0x11, 0x66, 
};

// inputs to 74HC595 shift register
#define SHIFT_DATA_PIN 2
#define SHIFT_CLOCK_PIN 4
#define SHIFT_LATCH_PIN 3

// IO Pins
#define EEPROM_D0 5
#define EEPROM_D7 12

// Control pins
#define WRITE_ENABLE 13

// Shifts <SHIFT_LEN> bits into a 74HC595 chip
void shiftData(bool data[SHIFT_LEN]) {
  for (int i = 0; i < SHIFT_LEN; i++) {
    digitalWrite(SHIFT_DATA_PIN, data[i]);
    digitalWrite(SHIFT_CLOCK_PIN, true);
    digitalWrite(SHIFT_CLOCK_PIN, false);
  }
  digitalWrite(SHIFT_LATCH_PIN, true);
  digitalWrite(SHIFT_LATCH_PIN, false);
  
}

// Sets current address that EEPROM is reading
void setAddress(long unsigned int address, bool outputEnable) { //address from 0 to 32767
  bool bits [SHIFT_LEN]; //used for holding data to be shifted
  for (int i = SHIFT_LEN - 1; i >= 0; i--) {
    bits[i] = address%2 == 1;
    address = address/2;
  }
  bits[0] = !outputEnable;
  shiftData(bits);
}

// Reads byte from EEPROM address
byte readAddress(long unsigned int address) {
  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin++) {
    pinMode(pin, INPUT);
  }

  setAddress(address, true); //enable EEPROM output
  delayMicroseconds(1);
  byte data = 0;
  for (int pin = EEPROM_D7; pin >= EEPROM_D0; pin--) {
    data = (data << 1) + digitalRead(pin);
  }
  return data;
}

//writes byte to EEPROM address
void writeAddress(long unsigned int address, byte data) {
  setAddress(address, false); //disable EEPROM output

  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin++) {
    pinMode(pin, OUTPUT);
  }

  byte origdata = data;

  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin++) {
    digitalWrite(pin, data & 1);
    data = data >> 1;
  }

  digitalWrite(WRITE_ENABLE, false);
  delayMicroseconds(1);
  digitalWrite(WRITE_ENABLE, true);
  delay(1);
  
  pinMode(EEPROM_D7, INPUT);

  int count = 0;
  
  while (readAddress(address) != origdata) {
    delay(1);
  }
}


bool readEEPROM(bool verify = false) { // Reads entire EEPROM in 16 byte blocks
  bool retval = true;

  for (int base = 0; base < MAX_ADDRESS; base += 16) {
    byte data [16];
    for (int offset = 0; offset < 16; offset++) {
      byte nbyte = readAddress(base + offset);

      if (verify) {
        byte cbyte;
        memcpy_P(&cbyte, &data_to_write[base + offset], sizeof cbyte);
        if (nbyte != cbyte) {
          char buffer[80];
          sprintf(buffer, "VERIFICATION ERROR, Byte at: %03X should have been %02X but was %02X", base + offset, cbyte, nbyte);
          Serial.println(buffer);
          retval = false;
        }
        data[offset] = nbyte;
      }
    }

    char buf[80];
    sprintf(buf, "%03X: %02X %02X %02X %02X %02X %02X %02X %02X   %02X %02X %02X %02X %02X %02X %02X %02X",
            base, data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7],
            data[8], data[9], data[10], data[11], data[12], data[13], data[14], data[15]);

    Serial.println(buf);
  }

  return retval;
}

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  pinMode(SHIFT_DATA_PIN, OUTPUT);
  pinMode(SHIFT_CLOCK_PIN, OUTPUT);
  pinMode(SHIFT_LATCH_PIN, OUTPUT);

  digitalWrite(WRITE_ENABLE, true); //inverted pin
  pinMode(WRITE_ENABLE, OUTPUT);

  int lastpercent = 0;

  if (WRITE_DATA) {
    Serial.println("Writing to eeprom:");
    for (long unsigned int address = 0; address < MAX_ADDRESS; address ++) {
      if (address * 100 / MAX_ADDRESS >= lastpercent + 5) {
        lastpercent = address * 100 / MAX_ADDRESS;
        Serial.print(address * 100 / MAX_ADDRESS);
        Serial.println("% complete...");
      }

      byte nextbyte;
      memcpy_P(&nextbyte, &data_to_write[address], sizeof nextbyte);
      writeAddress(address, nextbyte);
    }
    Serial.println("Write complete.");
  }
  Serial.println("Reading eeprom:");
  if (!readEEPROM(VALIDATE_DATA)) {
    Serial.println("At least one verification error occured!");
  }
  Serial.println("Read complete.");
}

void loop() {
  
}
