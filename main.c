/*--------------------------------------------------------------------------------------------
	Project 	: solar pannel
	Date		: 06/02/09
	Files used; main.c,lcd.c,ADC.c,Functions2.c, prototype.c,pins.h

---------------------------------------------------------------------------------------------*/
#include <prototype.c>


unsigned char s1=0,s2=0,s3=0,s4=0,arr[4];//arr1[4],arr2[4],arr3[4],arr[4],EAST,WEST;
unsigned int m,p,adval;


void main()
{
	LCD_delay(30);
	LCD_init();
	LCD_clear();
//	P2=0X00;
	LCD_row1();
	LCD_puts("ASSISTIVE BODY");
	Delay_1sec();
	Delay_1sec();
	Delay_1sec();
	Delay_1sec();
	//ADC_init();


	while(1)
	{
		Read_ADC_value();
		sensor_digital();
		original_function();

		 Delay_1sec();


//		LCD_row2();
//		LCD_puts("                ");
//		LCD_command(0xc0);



//		adval=s1;
//		Display();
//		LCD_putc(' ');
//		adval=s2;
////		Display();
//
//		LCD_putc(' ');
//		adval=s3;
////		Display();
//
//		LCD_putc(' ');
//		adval=s4;
////		Display();


		//LCD_command(0xc4);
		//adval=arr1[1];
		//Display();
		//EAST=arr1[0];
		//WEST=arr1[1];
		/*LCD_command(0xc8);
		adval=arr1[2];
		Display();
		LCD_command(0xcc);
		adval=arr1[3];
		Display();*/
		delay_ms(100);

	//	move_pannel();
		//Delay_1sec();
		//Delay_1sec();
		delay_ms(200);
		//delay_ms(200);
	}
}

//void Display()
//{
//		p=adval;
//		m=0;
//		if(p==0)
//		{
//		//LCD_command(0xc4);
//		LCD_putc('0');
//		}
//		while(p>0)
//		{
//		arr[m]=p%10;
//		p=p/10;
//		m++;
//		}
//		while(m>0)
//		{
//		m--;
//		LCD_putc(0x30+arr[m]);
//		}
//}
