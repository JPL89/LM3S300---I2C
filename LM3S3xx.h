/*
*	@File        LM3S3xx.H	 		
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

#ifndef LM3SXXX_H
#define LM3SXXX_H

#define  __at(address) (*((volatile unsigned long *)(address))) 

/* GPIOA REGISTERS MAP  */
#define GPIOADATA				__at(0x400043FCU)
#define GPIOADIR				__at(0x40004400U)
#define GPIOAFSEL				__at(0x40004420U)
#define GPIOAODR				__at(0x4000450CU)
#define GPIOAPUR				__at(0x40004510U)
#define GPIOAODR				__at(0x4000450CU)
#define GPIOAPDR				__at(0x40004514U)
#define GPIOADEN				__at(0x4000451CU)
#define GPIOADR8R				__at(0x40004508U)

/* GPIOB REGISTERS MAP  */
#define GPIOBDATA				__at(0x400053FCU)
#define GPIOBDIR				__at(0x40005400U)
#define GPIOBFSEL				__at(0x40005420U)
#define GPIOBODR				__at(0x4000550CU)
#define GPIOBPUR				__at(0x40005510U)
#define GPIOBODR				__at(0x4000550CU)
#define GPIOBPDR				__at(0x40005514U)
#define GPIOBDEN				__at(0x4000551CU)
#define GPIOBDR8R				__at(0x40005508U)

/* GPIOC REGISTERS MAP  */
#define GPIOCDATA				__at(0x400063FCU)
#define GPIOCDIR				__at(0x40006400U)
#define GPIOCFSEL				__at(0x40006420U)
#define GPIOCODR				__at(0x4000650CU)
#define GPIOCPUR				__at(0x40006510U)
#define GPIOCODR				__at(0x4000650CU)
#define GPIOCPDR				__at(0x40006514U)
#define GPIOCDEN				__at(0x4000651CU)
#define GPIOCDR8R				__at(0x40006508U)

/* GPIOD REGISTERS MAP  */
#define GPIODDATA				__at(0x400073FCU)
#define GPIODDIR				__at(0x40007400U)
#define GPIODFSEL				__at(0x40007420U)
#define GPIODODR				__at(0x4000750CU)
#define GPIODPUR				__at(0x40007510U)
#define GPIODODR				__at(0x4000750CU)
#define GPIODPDR				__at(0x40007514U)
#define GPIODDEN				__at(0x4000751CU)
#define GPIODDR8R				__at(0x40007508U)

/* GPIOE REGISTERS MAP  */
#define GPIOEDATA				__at(0x400241FCU)
#define GPIOEDIR				__at(0x40024400U)
#define GPIOEFSEL				__at(0x40024420U)
#define GPIOEODR				__at(0x4002450CU)
#define GPIOEPUR				__at(0x40024510U)
#define GPIOEODR				__at(0x4002450CU)
#define GPIOEPDR				__at(0x40024514U)
#define GPIOEDEN				__at(0x4002451CU)
#define GPIOEDR8R				__at(0x40024508U)

/* System Control Register Map */
#define DID0					__at(0x400FE000U)
#define DID1					__at(0x400FE004U)
#define DC0						__at(0x400FE008U)
#define DC1						__at(0x400FE010U)
#define DC2						__at(0x400FE014U)
#define DC3						__at(0x400FE018U)
#define DC4						__at(0x400FE01CU)
#define PBORCTL					__at(0x400FE030U)
#define LDOPCTL					__at(0x400FE034U)
#define SRCR0					__at(0x400FE040U)
#define SRCR1					__at(0x400FE044U)
#define SRCR2					__at(0x400FE048U)
#define RIS						__at(0x400FE050U)
#define IMC						__at(0x400FE054U)
#define MISC					__at(0x400FE058U)
#define RESC					__at(0x400FE05CU)
#define RCC						__at(0x400FE060U)
#define PLLCFG					__at(0x400FE064U)
#define RCGC0					__at(0x400FE100U)
#define RCGC1					__at(0x400FE104U)
#define RCGC2					__at(0x400FE108U)
#define SCGC0					__at(0x400FE110U)
#define SCGC1					__at(0x400FE114U)
#define SCGC2					__at(0x400FE118U)
#define DCGC0					__at(0x400FE120U)
#define DCGC1					__at(0x400FE124U)
#define DCGC2					__at(0x400FE128U)
#define DSLPCLKCFG				__at(0x400FE144U)
#define CLKVCLR					__at(0x400FE150U)
#define LDOARST					__at(0x400FE160U)

/* I2C REGISTERS MAP  */
#define I2CMSA					__at(0x40020000U)
#define I2CMCS					__at(0x40020004U)
#define I2CMDR					__at(0x40020008U)
#define I2CMTPR					__at(0x4002000CU)
#define I2CMIMR					__at(0x40020010U)
#define I2CMRIS					__at(0x40020014U)
#define I2CMMIS					__at(0x40020018U)
#define I2CMICR					__at(0x4002001CU)
#define I2CMCR					__at(0x40020020U)
#define I2CSOAR					__at(0x40020800U)
#define I2CSCSR					__at(0x40020804U)
#define I2CSDR					__at(0x40020808U)
#define I2CSIMR					__at(0x4002080CU)
#define I2CSRIS					__at(0x40020810U)
#define I2CSMIS					__at(0x40020814U)
#define I2CSICR					__at(0x40020818U)

/* SPI REGISTERS MAP  */
#define SSICR0					__at(0x40008000U)
#define SSICR1					__at(0x40008004U)
#define SSIDR						__at(0x40008008U)
#define SSISR						__at(0x4000800CU)
#define SSICPSR					__at(0x40008010U)
#define SSIIM						__at(0x40008014U)
#define SSIRIS					__at(0x40008018U)
#define SSIMIS					__at(0x4000801CU)
#define SSIICR						__at(0x40008020U)
#define SSIPeriphID4			__at(0x40008FD0U)
#define SSIPeriphID5			__at(0x40008FD4U)
#define SSIPeriphID6			__at(0x40008FD8U)
#define SSIPeriphID7			__at(0x40008FDCU)
#define SSIPeriphID0			__at(0x40008FE0U)
#define SSIPeriphID1			__at(0x40008FE4U)
#define SSIPeriphID2			__at(0x40008FE8U)
#define SSIPeriphID3			__at(0x40008FECU)
#define SSIPCellID0				__at(0x40008FF0U)
#define SSIPCellID1				__at(0x40008FF4U)
#define SSIPCellID2				__at(0x40008FF8U)
#define SSIPCellID3				__at(0x40008FFCU)

/* UART1 */
#define UARTIBRD					__at(0x4000D024U)
#define UARTLCRH					__at(0x4000D02CU)
#define UARTFBRD					__at(0x4000D028U)
#define UARTCTL						__at(0x4000D030U)
#define UARTDR						__at(0x4000D000U)
#define UARTRSR						__at(0x4000D004U)
#define UARTFR						__at(0x4000D018U)

#endif /* LM3S3XX_H */
