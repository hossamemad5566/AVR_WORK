/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : STD
 * @about :
****************************************/

#ifndef STD_H_
#define STD_H_

#define STD_OK      0
#define STD_NOK     1

typedef unsigned char            u8;
typedef   signed char            s8;
typedef unsigned short int       u16;
typedef   signed short int       s16;
typedef unsigned long  int       u32;
typedef   signed long  int       s32;
typedef float                    f32;
typedef double                   f64;

#define NULL ((void*)0)

typedef union 
{
    struct 
    {
        u8 bit0 :1;
        u8 bit1 :1;
        u8 bit2 :1;
        u8 bit3 :1;
        u8 bit4 :1;
        u8 bit5 :1;
        u8 bit6 :1;
        u8 bit7 :1;
    };
    u8 AllReg;
}Reg_;


#define HIGH 1
#define LOW  0

#endif /* STD_H_ */
