#include "LCD_Module.h"
#include "Pico_UPS.h"

static int ups_percent;

void event_handler (void);
void LCD_handler (void);

int
main (void)
{
  INA219_init ();
  LCD_Init();

  while (1)
    event_handler ();
  
  return 0;
}

void
event_handler (void)
{
  ups_percent = UPS_percent (); /* Update batary status */
  LCD_handler ();		/* Update LCD image */
}

void
LCD_handler (void)
{
  LCD_Menu (); 			/* Show menu */
  LCD_Header (ups_percent); 	/* Show batary status */
}
