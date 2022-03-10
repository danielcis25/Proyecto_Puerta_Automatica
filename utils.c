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
#include "utils.h"
#include "pinout.h"

/****************************************************************************
 * NAME: delay_MS
 * --------------------------------------------------------------------------
 * PARAMS:
 * val: delay in miliseconds
 * return: none
 * --------------------------------------------------------------------------
 * PURPOSE:
 * Set a delay in miliseconds
 * --------------------------------------------------------------------------
 * NOTE:
 * 
 ****************************************************************************/
void delay_MS(unsigned int val)
{
    unsigned int i,j;
    for(i=0;i<val;i++)
        for(j=0;j<165;j++); /*This count Provide delay of 1 ms for 8Mhz Frequency */
}
