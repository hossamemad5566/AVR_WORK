/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : SPI
 * @about :
****************************************/

#ifndef MCAL_SPI_PRIVATE_H_
#define MCAL_SPI_PRIVATE_H_

typedef union 
{
    struct 
    {
        u8 SPR0 :1;
        u8 SPR1 :1;
        u8 CPHA :1;
        u8 CPOL :1;
        u8 MSTR :1;
        u8 DORD :1;
        u8 SPE :1;
        u8 SPIE :1;
    };
    u8 AllReg;
}SPCR_;

#define SPDR_REG     (*(volatile Reg_ *)0x2F)
#define SPSR_REG     (*(volatile Reg_ *)0x2E)
#define SPCR_REG     (*(volatile SPCR_ *)0x2D)



#endif 
