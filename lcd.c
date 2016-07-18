 #include <prototype.c>

void LCD_delay(unsigned char ms)
{
	unsigned char n;
	unsigned int i;
	for (n=0; n<ms; n++)
	{
		for (i=0; i<LCD_DELAY; i++); /* For 1 ms */
	}
    
}

void LCD_enable()
{
    LCD_en = 0; /* Clear bit P2.4 */
    LCD_delay(1);
    LCD_en = 1; /* Set bit P2.4 */
}

void LCD_command(unsigned char command)
{
    LCD_rs = 0; /* Clear bit P2.5 */

    P0 = (P0 & 0x0F)|(command & 0xF0);
    LCD_enable();
    P0 = (P0 & 0x0F)|(command<<4 & 0xF0);
    LCD_enable();
    LCD_delay(1);
}

void LCD_putc(unsigned char ascii)
{
    LCD_rs = 1; /* Set bit P2.5 */
    P0 = (P0 & 0x0f)|(ascii & 0xf0);
    LCD_enable();
    P0 = (P0 & 0x0F)|(ascii<<4 & 0xF0);
    LCD_enable();
    LCD_delay(1);
}

void LCD_puts(unsigned char *lcd_string)
{
	while (*lcd_string) 
	{
		LCD_putc(*lcd_string++);
	}
}

void LCD_init()
{
    LCD_en = 1; /* Set bit P2.4 */
    LCD_rs = 0; /* Clear bit P2.5 */   
    LCD_command(0x33);
    LCD_command(0x32);
    LCD_command(0x28);
    LCD_command(0x0C);
    LCD_command(0x06);
    LCD_command(0x01); /* Clear */
    LCD_delay(256);
}
void delay_ms(unsigned int x)
{
	unsigned char i=0,j=0;
	for(i=0;i<x;i++)
		for(j=0;j<113;j++);
}

void Delay_1sec()
{
	int i=0,j=0;
	for(i=0;i<1000;i++)
		for(j=0;j<113;j++);
}
