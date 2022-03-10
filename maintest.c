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
// PIC18F4550 Configuration Bit Settings

// 'C' source line config statements

// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <pic18f4550.h>
#include "pinout.h"
#include "fuses.h"
#include "config.h"
#include "utils.h"

//#define __USER__
#ifdef __USER__
#define DELAY(a) delay_MS(a);
#else
#define DELAY(a) __delay_ms(500);
#endif

void blink_RED(void);
void blink_YELLOW(void);
void blink_GREEN(void);
void blink_SEG_UNIDAD(void);
void blink_SEG_DECENA(void);
void digito(unsigned int, unsigned int);
void init(void);
void info_LED_AFORO(unsigned int);
void mostrar_CONTEO(unsigned int, unsigned int);
void mostrar_LED(unsigned int);
//#define LED_RED LATE2

unsigned int v_decena, v_unidad, v_cuenta = 0;
unsigned int v_detExterior = 1;
unsigned int v_detInterior = 1;
unsigned int v_detEntrada = 1;
unsigned int v_detSalida = 1;
unsigned int reset_entrada = 1;
unsigned int reset_salida = 1;

unsigned char v_estadoINF1 = 0;
unsigned char v_estadoINF2 = 0;
unsigned char tabla[10]={0x3f, 0x06, 0x5B, 0x4f, 0x66, 0x6D, 0x7D, 0x07, 0x7f, 0x6f};/*Matriz números del 0 al 9*/

void main()
{
    init();
    while(1){
        v_decena = v_cuenta / 10;
        v_unidad = v_cuenta % 10;
        mostrar_LED(v_cuenta);
        mostrar_CONTEO(v_decena, v_unidad);
        
        //*********************************************************************
        //Parte del código para detectar la entrada
        if(SENSOR_INF2 == 0 && SENSOR_INF1 == 1 && v_detInterior == 1){//Pasa por el primer sensor
            v_detExterior = 0; //Se detectó fuera del salón
        }
     if(SENSOR_PIR2 == 1 && v_detExterior == 0){
            MOTOR_IN1 = 1;           
        }else if(SENSOR_PIR2 == 0 ){
            MOTOR_IN1 = 0;
            if(SENSOR_PIR == 1 ){
            MOTOR_IN2 = 1;
            }
            if(SENSOR_PIR == 0)
            {
            MOTOR_IN2 = 0;
            }
            //v_detEntrada = 0;
        }
       
        if(SENSOR_INF2 == 1 && SENSOR_INF1 == 0 && v_detExterior == 0){//Pasa por el segundo sensor
            //Se verifica que entró
            //v_detExterior = 1;
            v_estadoINF1 = 1;
        }
        if(SENSOR_INF1 == 1 && v_estadoINF1 == 1){
            v_detExterior = 1;
            v_cuenta++;
            v_estadoINF1=0;
            
        }
        
        //Parte del código para detectar la salida
        if(SENSOR_INF2 == 1 && SENSOR_INF1 == 0 && v_detExterior == 1){//Pasa por el primer sensor
            v_detInterior = 0; //Se detectó dentro del salón    
        }
        /*if(SENSOR_PIR == 1 && v_detInterior == 0){
            MOTOR_IN1 = 1;     
        }else if(SENSOR_PIR==0 && v_detInterior == 0){
            MOTOR_IN1 = 0;
        }*//*else if(SENSOR_PIR==1 && v_detEntrada == 0){
            MOTOR_IN1 = 1;
        }else if(SENSOR_PIR==0 && v_detEntrada == 0){
            MOTOR_IN1 = 0;
            v_detEntrada = 1;
        }*/
        if(SENSOR_INF2 == 0 && SENSOR_INF1 == 1 && v_detInterior == 0){//Pasa por el segundo sensor
            //Se verifica que salió y hace el conteo restando 1
            //v_detInterior = 1;
            v_estadoINF2 = 1;     
        }
        if(SENSOR_INF2 == 1 && v_estadoINF2 == 1 && v_detInterior == 0){
            v_detInterior = 1;    
            v_cuenta--;
            v_estadoINF2 = 0;
        }
        //********************************************************************
        
        //------------------------------------------------
        /*
        if(SENSOR_INF1 == 0){
            v_estadoINF1 = 1;
        }
        if(SENSOR_INF1 == 1 && v_estadoINF1==1){
            v_cuenta++;
            v_estadoINF1=0;
        }*/
        
        ////
        //motor
        /*if(SENSOR_PIR2 == 1)
        {
        }
        else if (SENSOR_PIR == 1)*/
    }   
}

void blink_RED(void){
    //LED_RED = 0xff;     /*Turn ON LED for 500 ms */
    ALARMA_LED_RED = ON;
    __delay_ms(20);    /* Funcion de retardo de libreria */
    ALARMA_LED_RED = OFF;        /*Turn OFF LED for 2000 ms */
    __delay_ms(10);
}
    
void blink_YELLOW(void){
    ALARMA_LED_YELLOW = ON;
    __delay_ms(20);    /* Funcion de retardo de libreria */
    ALARMA_LED_YELLOW = OFF;        /*Turn OFF LED for 2000 ms */
    __delay_ms(10);
}

void blink_GREEN(void){
    ALARMA_LED_GREEN = ON;
    __delay_ms(20);    /* Funcion de retardo de libreria */
    ALARMA_LED_GREEN = OFF;        /*Turn OFF LED for 2000 ms */
    __delay_ms(10);
}

void blink_SEG_UNIDAD(void){
    //PORTBbits.RB3 = 1;
    SEG_UNIDAD = ON;
    __delay_ms(10);
    //PORTBbits.RB3 = 0;
    SEG_UNIDAD = OFF;
    __delay_ms(10);
}

void blink_SEG_DECENA(void){
    //PORTBbits.RB2 = 1;
    SEG_DECENA = ON;
    __delay_ms(10);
    //PORTBbits.RB2 = 0;
    SEG_DECENA = OFF;
    __delay_ms(10);
}

void init(void){
    OSCCON = 0x72;        /* Use internal oscilator of 8Mhz Frequency (01110010)*/
    TRISE = 0x00;         /* Set direction of PORTE as OUTPUT to which LED is connected */
    //TRISA = 0xFF;
    TRISD = 0x00;
    TRISB = 0x00;
    TRISC = 0x00;
    CFG_SENSOR_PIR = INPUT;       /* Pone el pin A0 de entrada*/
    CFG_SENSOR_INF1 = INPUT;       /* Pone el pin A1 de entrada*/
    CFG_SENSOR_INF2 = INPUT;       /* Pone el pin A2 de entrada*/
    
    CFG_ALARMA_LED_GREEN = OUTPUT;
    CFG_ALARMA_LED_YELLOW = OUTPUT;
    CFG_ALARMA_LED_RED = OUTPUT;
    CFG_MOTOR_IN1 = OUTPUT;
    CFG_MOTOR_IN2 = OUTPUT;
    
    ADCON1 = 0x0F;
}

void info_LED_AFORO(unsigned int v_cantidad){
    if(v_cantidad <= 10){
        blink_GREEN();
    }
    if(v_cantidad > 10 && v_cantidad <= 15){
        blink_YELLOW();
    }
    if(v_cantidad > 15 && v_cantidad <= 20){
        blink_RED();
    }
    if(v_cantidad > 20){
        v_cantidad = 0;
    }
}

void mostrar_CONTEO(unsigned int v_decena, unsigned int v_unidad){
    PORTD = (tabla[v_decena]);
    blink_SEG_DECENA();//blink de la decena del 7 seg
        
    PORTD = (tabla[v_unidad]);
    blink_SEG_UNIDAD();//blink de la unidad del 7 seg
}

void mostrar_LED(unsigned int v_cuenta){
    if(v_cuenta <= 10){
        //blink_GREEN();
        ALARMA_LED_YELLOW = OFF;
        ALARMA_LED_RED = OFF;
        ALARMA_LED_GREEN = ON;
    }
    else if(v_cuenta > 10 && v_cuenta <= 15){
        //blink_YELLOW();
        ALARMA_LED_GREEN = OFF;
        ALARMA_LED_RED = OFF;
        ALARMA_LED_YELLOW = ON;
    }
    else if(v_cuenta > 15 && v_cuenta <= 20){
        //blink_RED();
        ALARMA_LED_GREEN = OFF;
        ALARMA_LED_YELLOW = OFF;
        ALARMA_LED_RED = ON;
    }
    else if(v_cuenta > 20){
        v_cuenta = 0;
    }
}

void digito(unsigned int num, unsigned int orden){
    if(orden==2){
        blink_SEG_DECENA();
    }else if(orden == 1){
        
        blink_SEG_UNIDAD();
    }
    switch(num){
            case 1:
                SEG_A = OFF;
                SEG_B = ON;
                SEG_C = ON;
                SEG_D = OFF;
                SEG_E = OFF;
                SEG_F = OFF;
                SEG_G = OFF;
                break;
            case 2:
                SEG_A = ON;
                SEG_B = ON;
                SEG_C = OFF;
                SEG_D = ON;
                SEG_E = ON;
                SEG_F = OFF;
                SEG_G = ON;
                break;
            case 3:
                SEG_A = ON;
                SEG_B = ON;
                SEG_C = ON;
                SEG_D = ON;
                SEG_E = OFF;
                SEG_F = OFF;
                SEG_G = ON;
                break;
            case 4:
                SEG_A = OFF;
                SEG_B = ON;
                SEG_C = ON;
                SEG_D = OFF;
                SEG_E = OFF;
                SEG_F = ON;
                SEG_G = ON;
                break;
            case 5:
                SEG_A = ON;
                SEG_B = OFF;
                SEG_C = ON;
                SEG_D = ON;
                SEG_E = OFF;
                SEG_F = ON;
                SEG_G = ON;
                break;
            case 6:
                SEG_A = ON;
                SEG_B = OFF;
                SEG_C = ON;
                SEG_D = ON;
                SEG_E = ON;
                SEG_F = ON;
                SEG_G = ON;
                break;
            case 7:
                SEG_A = ON;
                SEG_B = ON;
                SEG_C = ON;
                SEG_D = OFF;
                SEG_E = OFF;
                SEG_F = OFF;
                SEG_G = OFF;
                break;
            case 8:
                SEG_A = ON;
                SEG_B = ON;
                SEG_C = ON;
                SEG_D = ON;
                SEG_E = ON;
                SEG_F = ON;
                SEG_G = ON;
                break;
            case 9:
                SEG_A = ON;
                SEG_B = ON;
                SEG_C = ON;
                SEG_D = ON;
                SEG_E = OFF;
                SEG_F = ON;
                SEG_G = ON;
                break;
            default:
                SEG_A = ON;
                SEG_B = ON;
                SEG_C = ON;
                SEG_D = ON;
                SEG_E = ON;
                SEG_F = ON;
                SEG_G = OFF;
                break;
        }
}
    
   