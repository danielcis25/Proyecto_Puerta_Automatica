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

#ifndef UTILS_H
#define	UTILS_H

#ifdef	__cplusplus
extern "C" {
#endif

/*
 *unsigned char = 8 bits (0-255)
 *char = 8 btis (-127 +127)
 *int = 16 bits (0-65535)
 *long = 32 btis
 *short = 16 bits
 *double = 32 bits
 *float = 32 bits (3.1416)
 * 
 *uint_8
 *uint_16
 */    

    
void delay_MS(unsigned int);

#ifdef	__cplusplus
}
#endif

#endif	/* UTILS_H */

