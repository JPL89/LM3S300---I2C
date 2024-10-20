/*
*	@File        MAIN.C	 		
*	@Author		JOSIMAR PEREIRA LEITE
*	@country	Brazil
*	@Date		20/10/2024
*
*	Copyright (C) 2024  JOSIMAR PEREIRA LEITE
*
*	This program is free software: you can redistribute it and/or modify
*	it under the terms of the GNU General Public License as published by
*	the Free Software Foundation, either version 3 of the License, or
*	(at your option) any later version.
*/

#include "LM3S3xx.h"

void I2C_init(void);
unsigned char I2C_write(unsigned char reg, unsigned char data);
void I2C_write2(unsigned char d0, unsigned char d1, unsigned char d2, unsigned char d3);
void I2C_write1(unsigned char data);

static int i;

static void delay(long n)
{
	while(n--);
}

/*************************************** I2C ********************************************/

void I2C_init(void)
{	
	RCGC1 |=(1UL << 12UL); /* Enable the I2C clock */
		
	RCGC2 |=(1UL << 1UL); /* GPIOB CLOCK */
	
	GPIOBODR 	|= (1UL << 2UL) | (1UL << 3UL);	
	GPIOBFSEL |= (1UL << 2UL) | (1UL << 3UL);	
				
	I2CMCR = (1UL << 4UL); /* MASTER */
	I2CMTPR = 0x00000003; /* (8000000 / ( 2 * (6 + 4) * 100000)) - 1 = 3 */
}

void I2C_write1(unsigned char data)
{	
	I2CMSA = 0x70;	
	I2CMDR = data;
	I2CMCS = 0x00000007;	
	while((I2CMCS & (1UL << 0UL)) == 1);
}

/*
		0x00: SUCCESS
		0x01: ERROR
*/
unsigned char I2C_write(unsigned char reg, unsigned char data)
{	
	I2CMSA = 0x70;	
	I2CMDR = reg;
	while((I2CMCS & 0x40) == 1);
	
	I2CMCS = 0x00000003;	
	while((I2CMCS & 0x01) == 1);
	
	if(I2CMCS & 0x02) {
		I2CMCS = 0x00000004;
		return 0x01;
	}
	
	I2CMDR = data;	
	I2CMCS = 0x00000005;
	while((I2CMCS & 0x01) == 1);	
	
	if(I2CMCS & 0x02) {
		I2CMCS = 0x00000004;
		return 0x01;
	}
	
	return (0x00);
}

void I2C_write2(unsigned char d0, unsigned char d1, unsigned char d2, unsigned char d3)
{	
	I2CMSA = 0x70;
	
	I2CMDR = 0x00;
	I2CMCS = 0x00000003;
	while((I2CMCS & 0x01) == 1);
	
	I2CMDR = 0xE4;
	I2CMCS = 0x00000001;
	while((I2CMCS & 0x01) == 1);
	
	I2CMDR = d0;
	I2CMCS = 0x00000001;
	while((I2CMCS & 0x01) == 1);
	
	I2CMDR = d1;
	I2CMCS = 0x00000001;
	while((I2CMCS & 0x01) == 1);
	
	I2CMDR = d2;
	I2CMCS = 0x00000001;
	while((I2CMCS & 0x01) == 1);
	
	I2CMDR = d3;
	I2CMCS = 0x00000005;
	while((I2CMCS & 0x01) == 1);
}

static const unsigned char font[] = 
{
    0xFC,  
    0x60,  
    0xDA,  
    0xF2,  
    0x66,  
    0xB6,  
    0xBE,  
    0xE0,  
    0xFE,  
    0xF6, 	
    0xEE,  
    0x3E,  
    0x9C,  
    0x7A, 
    0x9E,  
    0x8E
};   

int main (void)
{				
	/* CLEAR CRYSTAL BITS AND SET 8MHZ CRYSTAL */
	RCC &=~((1UL << 6)|(1 << 7UL)|(1UL << 8UL)|(1UL << 9UL));	
	RCC |= ((1UL << 6UL)|(1UL << 8UL)|(1UL << 9UL)); 
	
	/* CLEAR OSCILATION SOURCE AND SET MAIN OSCILATION */
	RCC &=~((1UL << 4UL)|(1UL << 5UL));	
	
	/* ENABLE GPIO */
	RCGC2 = 0x1F;
	
	I2C_init();	
	
	I2C_write(0x00, 0xE4);

	/****************************/
	
	i = 0;
	
	while (1)
	{		
		I2C_write2(font[i/1000%10], font[i/100%10], font[i/10%10], font[i%10]);
		
		i++;
		
		delay(100000);		
	}
}
