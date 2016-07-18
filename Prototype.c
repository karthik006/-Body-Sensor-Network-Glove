 #include <pins.h>

 #define LCD_DELAY 113 /* Delay for 1 ms */
 #define LCD_clear() LCD_command(0x1)	/* Clear display LCD */
 #define LCD_origin() LCD_command(0x2)	/* Set to origin LCD */
 #define LCD_row1() LCD_command(0x80)	/* Begin at Line 1 */
 #define LCD_row2() LCD_command(0xC0)   /* Begin at Line 2 */
 #define dev_adr 0
 
/***************************************************
 * Prototype(s)                                    *
 ***************************************************/
void LCD_delay(unsigned char ms);
void LCD_enable();
void LCD_command(unsigned char command);
void LCD_putc(unsigned char ascii);
void LCD_puts(unsigned char *lcd_string);
void LCD_init();

void delay_ms(unsigned int);
//void calculate_position();
////////////////void fwd_rotate();
////////////////void backwd_rotate();
////////////////void move_pannel();
//void Display();
void Delay_1sec();


//---------------------------------------
unsigned char i2c_in_byte(void);
void i2c_out_byte(unsigned char o_byte);
void i2c_nack(void);
void i2c_ack(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_high_sda(void);
void i2c_low_sda(void);
void i2c_high_scl(void);
void i2c_low_scl(void);
void Read_ADC_value();



//---------------------------------
void sensor_digital();
void original_function();
