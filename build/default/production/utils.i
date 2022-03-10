# 1 "utils.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18Fxxxx_DFP/1.3.36/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "utils.c" 2
# 1 "./utils.h" 1
# 44 "./utils.h"
void delay_MS(unsigned int);
# 1 "utils.c" 2

# 1 "./pinout.h" 1
# 2 "utils.c" 2
# 17 "utils.c"
void delay_MS(unsigned int val)
{
    unsigned int i,j;
    for(i=0;i<val;i++)
        for(j=0;j<165;j++);
}
