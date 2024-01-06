#include "LCD_Module.h"
#include "LCD_1in3.h"


UDOUBLE ImageSize = LCD_1IN3_HEIGHT*LCD_1IN3_WIDTH*2;
UWORD *BlackImage;

/* set address */
bool reserved_addr(uint8_t addr) {
return (addr & 0x78) == 0 || (addr & 0x78) == 0x78;
}

int LCD_Init(void)
{
    DEV_Delay_ms(100);
    if(DEV_Module_Init()!=0){
        return -1;
    }
    DEV_SET_PWM(50);
    LCD_1IN3_Init(VERTICAL);
    LCD_1IN3_Clear(WHITE);
    if((BlackImage = (UWORD *)malloc(ImageSize)) == NULL)
    {
        printf("Failed to apply for black memory...\r\n");
	exit(0);
    }
    //Fill screen
    Paint_NewImage((UBYTE *)BlackImage,LCD_1IN3.WIDTH,LCD_1IN3.HEIGHT, 0, WHITE);
    Paint_SetScale(65);
    Paint_Clear(WHITE);
    Paint_SetRotate(ROTATE_0);
    Paint_Clear(WHITE);
}

int LCD_Destroy(void)
{
    free(BlackImage);
    BlackImage = NULL;
    DEV_Module_Exit();
    return 0;
}

int LCD_Menu(void)
{
    Paint_DrawString_EN(10,40, "QRJCFT", &FontMilk24, WHITE, BLACK);
    Paint_DrawString_EN(10,70, "DPCOPLPEFR]", &FontMilk16, WHITE, BLACK);
    Paint_DrawString_EN(10,100, "ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_ab", &FontMilk24, BLACK, RED);
    LCD_1IN3_Display(BlackImage);
}

void LCD_Header(int Percent)
{
    char battery [5];
    snprintf(battery, sizeof battery, "%d%%", Percent); 
    Paint_DrawString_EN(160, 2, battery, &FontMilk16, BLACK, WHITE);
    LCD_1IN3_Display(BlackImage);
    DEV_Delay_ms(200000);
}
