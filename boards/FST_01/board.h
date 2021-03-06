/*
    ChibiOS/RT - Copyright (C) 2006,2007,2008,2009,2010 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.

                                      ---

    A special exception to the GPL can be applied should you wish to distribute
    a combined work that includes ChibiOS/RT, without being obliged to provide
    the source code for any proprietary components. See the file exception.txt
    for full details of how and when the exception can be applied.
*/

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for the FST-01 board.
 */
#define	SET_USB_CONDITION(en) en	/* To connect USB, call palSetPad */
#define	SET_LED_CONDITION(on) on	/* To emit light, call palSetPad */
#define GPIO_USB	GPIOA_USB_ENABLE
#define IOPORT_USB	GPIOA
#define GPIO_LED	GPIOB_LED
#define IOPORT_LED	GPIOB

/*
 * Board identifier.
 */
#define BOARD_FST_01
#define BOARD_NAME "FST-01"

/*
 * Board frequencies.
 */
#define STM32_LSECLK            32768
#define STM32_HSECLK            12000000

/*
 * MCU type, this macro is used by both the ST library and the ChibiOS/RT
 * native STM32 HAL.
 */
#define STM32F10X_MD
#define CPU_WITH_NO_GPIOE	1

/*
 * IO pins assignments.
 */
#define GPIOB_LED		0
#define GPIOA_USB_ENABLE	10
#define GPIOA_SPI1NSS		4

/*
 * Timer assignment for CIR
 */
#define TIMx	TIM2

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 *
 * The digits have the following meaning:
 *   0 - Analog input.
 *   1 - Push Pull output 10MHz.
 *   2 - Push Pull output 2MHz.
 *   3 - Push Pull output 50MHz.
 *   4 - Digital input.
 *   5 - Open Drain output 10MHz.
 *   6 - Open Drain output 2MHz.
 *   7 - Open Drain output 50MHz.
 *   8 - Digital input with PullUp or PullDown resistor depending on ODR.
 *   9 - Alternate Push Pull output 10MHz.
 *   A - Alternate Push Pull output 2MHz.
 *   B - Alternate Push Pull output 50MHz.
 *   C - Reserved.
 *   D - Alternate Open Drain output 10MHz.
 *   E - Alternate Open Drain output 2MHz.
 *   F - Alternate Open Drain output 50MHz.
 * Please refer to the STM32 Reference Manual for details.
 */

/*
 * Port A setup.
 * PA0  - input with pull-up (TIM2_CH1)
 * PA1  - input with pull-down (TIM2_CH2)
 * PA2  - input with pull-up (TIM2_CH3)
 * PA4  - Push pull output   (SPI1_NSS)
 * PA5  - Alternate Push pull output (SPI1_SCK)
 * PA6  - Alternate Push pull output (SPI1_MISO)
 * PA7  - Alternate Push pull output (SPI1_MOSI)
 * PA10 - Push pull output   (USB 1:ON 0:OFF)
 * PA11 - input with pull-up (USBDM)
 * PA12 - input with pull-up (USBDP)
 */
#define VAL_GPIOACRL            0xBBB38888      /*  PA7...PA0 */
#define VAL_GPIOACRH            0x88888388      /* PA15...PA8 */
#define VAL_GPIOAODR            0xFFFFFFFD

/*
 * Port B setup.
 * Everything input with pull-up except:
 * PB0  - Push pull output   (LED 1:ON 0:OFF)
 */
#define VAL_GPIOBCRL            0x88888883      /*  PB7...PB0 */
#define VAL_GPIOBCRH            0x88888888      /* PB15...PB8 */
#define VAL_GPIOBODR            0xFFFFFFFF

/*
 * Port C setup.
 * Everything input with pull-up except:
 */
#define VAL_GPIOCCRL            0x88888888      /*  PC7...PC0 */
#define VAL_GPIOCCRH            0x88888888      /* PC15...PC8 */
#define VAL_GPIOCODR            0xFFFFFFFF

/*
 * Port D setup.
 * Everything input with pull-up except:
 * PD0  - Normal input (XTAL).
 * PD1  - Normal input (XTAL).
 */
#define VAL_GPIODCRL            0x88888844      /*  PD7...PD0 */
#define VAL_GPIODCRH            0x88888888      /* PD15...PD8 */
#define VAL_GPIODODR            0xFFFFFFFF

/*
 * Port E setup.
 * Everything input with pull-up except:
 */
#define VAL_GPIOECRL            0x88888888      /*  PE7...PE0 */
#define VAL_GPIOECRH            0x88888888      /* PE15...PE8 */
#define VAL_GPIOEODR            0xFFFFFFFF

#endif /* _BOARD_H_ */
