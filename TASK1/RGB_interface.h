/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : RGB
 * @about :
****************************************/
#ifndef HAL_RGB_INTERFACE_H_
#define HAL_RGB_INTERFACE_H_

#define BLU_PIN     PC0_PIN
#define GRN_PIN     PC1_PIN
#define RED_PIN     PC2_PIN

void RGB_init(void);

void RGB_color_on(char led);


#endif
