#include<prototype.c>
extern unsigned char s1,s2,s3,s4,arr[4];//arr1[4],arr2[4],arr3[4],value_ldr1,value_ldr2,value_ldr3,value_ldr4,largest,s1,s2;
//----------------------------------------------------------------------------------
void Read_ADC_value()
{
	s1=0,s2=0,s3=0,s4=0;
	i2c_start();
	i2c_out_byte(0x90 | (dev_adr<<1));
	i2c_nack();
	i2c_out_byte(0x00);
	i2c_nack();
	i2c_out_byte(0x00);			//(0x00);	// start with A/D 0,auto increment on.
	i2c_nack();
	i2c_stop();									// read result
	i2c_start();
	i2c_out_byte(0x91 | (dev_adr<<1));
	i2c_nack();
	
	i2c_in_byte();  // throw the first away
	i2c_ack();
	//arr1[0]=i2c_in_byte();		///may change
	s1=i2c_in_byte();	
	//arr1[1]=i2c_in_byte();
	//arr1[2]=i2c_in_byte();
	//arr1[3]=i2c_in_byte();
	i2c_stop();	
	delay_ms(200);
	//Delay_1sec();
	//Delay_1sec();
  //--------------------------------------------------------
	i2c_start();
	i2c_out_byte(0x90 | (dev_adr<<1));
	i2c_nack();
	i2c_out_byte(0x01);//00
	i2c_nack();
	i2c_out_byte(0x01);			//(0x00);	// start with A/D 0,auto increment on.
	i2c_nack();
	i2c_stop();									// read result
	i2c_start();
	i2c_out_byte(0x91 | (dev_adr<<1));
	i2c_nack();
	
	i2c_in_byte();  // throw the first away
	i2c_ack();
	//arr1[1]=i2c_in_byte();		///may change
	s2=i2c_in_byte();	
	//arr1[1]=i2c_in_byte();
	//arr1[2]=i2c_in_byte();
	//arr1[3]=i2c_in_byte();
	i2c_stop();				
//--------------------------------------------------
					i2c_start();
	i2c_out_byte(0x90 | (dev_adr<<1));
	i2c_nack();
	i2c_out_byte(0x02);//00
	i2c_nack();
	i2c_out_byte(0x02);			//(0x00);	// start with A/D 0,auto increment on.
	i2c_nack();
	i2c_stop();									// read result
	i2c_start();
	i2c_out_byte(0x91 | (dev_adr<<1));
	i2c_nack();
	
	i2c_in_byte();  // throw the first away
	i2c_ack();
	//arr1[1]=i2c_in_byte();		///may change
	s3=i2c_in_byte();	
	//arr1[1]=i2c_in_byte();
	//arr1[2]=i2c_in_byte();
	//arr1[3]=i2c_in_byte();
	i2c_stop();			
	//----------------------------------
		i2c_start();
	i2c_out_byte(0x90 | (dev_adr<<1));
	i2c_nack();
	i2c_out_byte(0x03);//00
	i2c_nack();
	i2c_out_byte(0x03);			//(0x00);	// start with A/D 0,auto increment on.
	i2c_nack();
	i2c_stop();									// read result
	i2c_start();
	i2c_out_byte(0x91 | (dev_adr<<1));
	i2c_nack();
	
	i2c_in_byte();  // throw the first away
	i2c_ack();
	//arr1[1]=i2c_in_byte();		///may change
	s4=i2c_in_byte();	
	//arr1[1]=i2c_in_byte();
	//arr1[2]=i2c_in_byte();
	//arr1[3]=i2c_in_byte();
	i2c_stop();	
}

//------------------------------------------------------------------------------

unsigned char i2c_in_byte(void)
{
   unsigned char i_byte, n;
   i2c_high_sda();
   for (n=0; n<8; n++)
   {
      i2c_high_scl();

      if (SDA==1)
      {
         i_byte = (i_byte << 1) | 0x01; // msbit first
      }
      else
      {
         i_byte = i_byte << 1;
      }
      i2c_low_scl();
   }
   return(i_byte);
}
//-----------------------------------------------------------
void i2c_out_byte(unsigned char o_byte)
{
   unsigned char n;
   for(n=0; n<8; n++)
   {
      if(o_byte&0x80)
      {
         i2c_high_sda();
      }
      else
      {
         i2c_low_sda();
      }
      i2c_high_scl();
      i2c_low_scl();
      o_byte = o_byte << 1;
   }
   i2c_high_sda();
}
//-------------------------------------------------------------
void i2c_nack(void)
{
   i2c_high_sda();	// data at s1
   i2c_high_scl();	// clock pulse
   i2c_low_scl();
}
//---------------------------------------------------------
void i2c_ack(void)
{
   i2c_low_sda();	// bring data low and clock
   i2c_high_scl();
   i2c_low_scl();
   i2c_high_sda();
}

//-----------------------------------------------------------
void i2c_start(void)
{
   i2c_low_scl();
   i2c_high_sda();
   i2c_high_scl();	// bring SDA low while SCL is high
   i2c_low_sda();
   i2c_low_scl();
}

void i2c_stop(void)
{
   i2c_low_scl();
   i2c_low_sda();
   i2c_high_scl();
   i2c_high_sda();  // bring SDA high while SCL is high
   // idle is SDA high and SCL high
}

void i2c_high_sda(void)
{
   // bring SDA to high impedance
     SDA= 1;
   // delay_10us(5);
}

void i2c_low_sda(void)
{
    SDA=0;
   //SDA_DIR = 0;  // output a hard logic zero
   // delay_10us(5);
}

void i2c_high_scl(void)
{
   SCL= 1;   // high impedance
   // delay_10us(5);
}

void i2c_low_scl(void)
{
   SCL=0;
   //SCL_DIR = 0;
   // delay_10us(5);
}
