/*!
 \file config.h
 \date 2020-03-05
 \author Arnold Catamuscay <ascatamuscay@unicauca.edu.co>
         Daniel Cisneros <dcisneros@unicauca.edu.co>
         Cristian Nuñez <cnunez@unicauca.edu.co>
 \brief Proyecto para el manejo del aforo en un salon de clases mediante una
        puerta y un conteo de las personas que entran y salen del salon.
  
 \par Copyright
 Information contained herein is propietary to and constitues valuable
 confidential trade secrets of unicauca, and
 is subject to restrictions on use and disclosure.
  
 \par
 Copyright (c) unicauca 2022. All rights reserved.
 
 \par
 The copyright notices above do not evidence any actual or
 intended publication of this material.
 *************************
 */

#ifndef PINOUT_H
#define	PINOUT_H

#ifdef	__cplusplus
extern "C" {
#endif

#define ON 1
#define OFF 0
    
#define INPUT 1
#define OUTPUT 0

//LEDs - OUT
//#define LEDS LATE
//#define LED_GREEN PORTEbits.RE0 // Se activa si hay menos de 10 personas
//#define LED_YELLOW PORTEbits.RE1 // Se activa si hay 10 - 15 personas
//#define LED_RED PORTEbits.RE2 // Se activa si hay 15 - 20 personas
#define ALARMA_LED_GREEN LATE0
#define CFG_ALARMA_LED_GREEN TRISE0

#define ALARMA_LED_YELLOW LATE1
#define CFG_ALARMA_LED_YELLOW TRISE1

#define ALARMA_LED_RED LATE2
#define CFG_ALARMA_LED_RED TRISE2
    
//Sensores - IN
//#define DETECTED 1
#define SENSOR_PIR PORTAbits.RA0
#define CFG_SENSOR_PIR TRISA0
    
#define SENSOR_PIR2 PORTAbits.RA3
#define CFG_SENSOR_PIR2 TRISA3
    
#define SENSOR_INF1 PORTAbits.RA1//PORTA1
#define CFG_SENSOR_INF1 TRISA1
    
#define SENSOR_INF2 PORTAbits.RA2
#define CFG_SENSOR_INF2 TRISA2
    
//Motor
#define MOTOR_IN1 LATC0
#define CFG_MOTOR_IN1 TRISC0
#define MOTOR_IN2 LATC1
#define CFG_MOTOR_IN2 TRISC1
//#define MOTOR_EN1 RC2 

//RTC
#define RTC_SDA RB0
#define RTC_SCL RB1

//7-segmentos
#define SEG_A LATD0
#define SEG_B LATD1
#define SEG_C LATD2
#define SEG_D LATD3
#define SEG_E LATD4
#define SEG_F LATD5
#define SEG_G LATD6
#define SEG_UNIDAD LATB3//LATD7
#define SEG_DECENA LATB2 

#ifdef	__cplusplus
}
#endif

#endif	/* PINOUT_H */

