#include <18f4620.h>
#use        delay  (clock=20000000)

#use RS232(baud=9600, xmit=PIN_D6, rcv = PIN_D7, stream=RF_ID)
#use        rs232  (baud = 9600, xmit=PIN_A0, rcv=PIN_A1, STREAM = GSM) 

#include <lcd.c>
#include "keypad.c"

char ch;

unsigned int data[20];

int i =0;

byte pnum2[] = {"9108887477"};
byte num1[15]={"1900430D5C0"}; 
byte num2[15]={"1A00218BFF4"};  
byte num3[15]={"14004AC777E"}; 

void start()
{
    lcd_putc('\f');      //Clear LCD Display   
    lcd_gotoxy(1,1);
    printf(lcd_putc," RFID GSM based");
    lcd_gotoxy(1,2);
    printf(lcd_putc,"Ration Distribtion");     
}

void beep(unsigned long duration)
{
   output_high(PIN_D2);
   delay_ms(duration);
   output_low(PIN_D2);
}

void main()
{ 
   
   kbd_init();
   lcd_init();
   
   start();
         
   output_high(PIN_D2);   
   output_high(PIN_D3);   
   delay_ms(700);   
   output_low(PIN_D2);   
   output_low(PIN_D3);   
   delay_ms(700);   
   output_high(PIN_D2);   
   output_high(PIN_D3);   
   delay_ms(700);   
   output_low(PIN_D2);   
   output_low(PIN_D3);   
   init_phone();
   
   while(1)
   {
      
      lcd_putc('\f');
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Show the TAG");  
         
      read_rfid_data();    //read the rfid tag number from RFID Reader (live data)

      lcd_putc('\f');
      lcd_gotoxy(1,1);
      printf(lcd_putc,"RFID Tag Number");      
      lcd_gotoxy(1,2);
      printf(lcd_putc,"%s",data);
      delay_ms(1600); 
      
      if(!strcmp(num1,data))
      {    
         if(tag2 == 0)
         {
            if(flag2 < 3)
            {
                  lcd_putc('\f');
                  lcd_gotoxy(1,1);
                  printf(lcd_putc,"Sending Message");
                  lcd_gotoxy(1,2);
                  printf(lcd_putc,"Citizen : 2");
                  delay_ms(2000);
                  
                  gen_otp();
                  
                  fprintf(GSM,"AT+CMGS=\"+919901260520\"\r\n");
                  delay_ms(1000);
                  fprintf(GSM,"OTP for Accessing "); 
                  delay_ms(1000);
                  fprintf(GSM," : %Lu \r\n",a);          
                  delay_ms(2000);
                  fputc(0x1A,GSM);
                  fgetc(GSM);
                  delay_ms(2500);
                   
                  while(1)
                  {
                        lcd_putc('\f');      //Clear LCD Display
                        lcd_gotoxy(1,1);      
                        printf(lcd_putc," ENTER OTP  "); 
                        
                        read_password();
                        
                        delay_ms(2000);
                        
                        psd = atoi32(pwd);
                                    
                        if(psd == a)
                        {                  
                           printf(lcd_putc,"\f");
                           lcd_gotoxy(1,1);
                           printf(lcd_putc,"ACCESS GRANTED");                     
                           delay_ms(2000);
                           
                           if(flag2 == 0)
                           {
                                 lcd_putc('\f');      //Clear LCD Display
                                 lcd_gotoxy(1,1);      
                                 printf(lcd_putc," ENTER Oil Qty:  "); 
                                 
                                 read_data();
                                 
                                 delay_ms(2000);
                                 
                                 qty = atoi32(pwd);
                                 
                                 lcd_putc('\f');      //Clear LCD Display
                                 lcd_gotoxy(1,1);      
                                 printf(lcd_putc,"Pls Collect Oil "); 
                                 delay_ms(2000);
                                 
                                 output_high(PIN_C4);
                                 qty = qty*2000;
                                 delay_ms(qty);
                                 output_low(PIN_C4);
                                 
                                              
                                 fprintf(GSM,"AT+CMGS=\"+919901260520\"\r\n");
                                 delay_ms(1000);
                                 fprintf(GSM,"Your Ration-Oil Delivered \r\n "); 
                                 delay_ms(1000);
                                 flag2 = flag2+1;
                                 break;
                                 
                                 
                           }
                           
                           else if(flag2 == 1)
                           {
                                 lcd_putc('\f');      //Clear LCD Display
                                 lcd_gotoxy(1,1);      
                                 printf(lcd_putc," ENTER Sugar Qty:  "); 
                                 
                                 read_data();
                                 
                                 delay_ms(2000);
                                 
                                 qty = atoi32(pwd);
                                 
                                 lcd_putc('\f');      //Clear LCD Display
                                 lcd_gotoxy(1,1);      
                                 printf(lcd_putc,"Pls Collect Sugar "); 
                                 delay_ms(2000);
                                 
                                 output_high(PIN_C5);
                                 qty = qty*2000;
                                 delay_ms(qty);
                                 output_low(PIN_C5);
                                 
                                              
                                 fprintf(GSM,"AT+CMGS=\"+919901260520\"\r\n");
                                 delay_ms(1000);
                                 fprintf(GSM,"Your Ration-Sugar Delivered \r\n "); 
                                 delay_ms(1000);
                                 flag2 = flag2+1;
                                 break;
                                 
                                 
                           }
                           
                           else if(flag2 == 2)
                           {
                                 lcd_putc('\f');      //Clear LCD Display
                                 lcd_gotoxy(1,1);      
                                 printf(lcd_putc," ENTER Rice Qty:  "); 
                                 
                                 read_data();
                                 
                                 delay_ms(2000);
                                 
                                 qty = atoi32(pwd);
                                 
                                 lcd_putc('\f');      //Clear LCD Display
                                 lcd_gotoxy(1,1);      
                                 printf(lcd_putc,"Pls Collect Rice "); 
                                 delay_ms(2000);
                                 
                                 output_high(PIN_C6);
                                 qty = qty*2000;
                                 delay_ms(qty);
                                 output_low(PIN_C6);
                                 
                                                
                                 fprintf(GSM,"AT+CMGS=\"+919901260520\"\r\n");
                                 delay_ms(1000);
                                 fprintf(GSM,"Your Ration-Rice Delivered \r\n "); 
                                 delay_ms(1000);
                                 flag2 = flag2+1;
                                 break;
                           }
                           
                        }
                                       
                        else
                        {
                           printf(lcd_putc,"\f");
                           lcd_gotoxy(1,1);
                           printf(lcd_putc,"You have Entered");
                           lcd_gotoxy(1,2);
                           printf(lcd_putc,"Wrong OTP");
                           beep(2500);
                           wrong++;
                        }
                        if(wrong > 2)
                        {
                           tag2 = 1;
                           
                           printf(lcd_putc,"\f");
                           lcd_gotoxy(1,1);
                           printf(lcd_putc,"Your Card Blocked");
                           beep(2500);
                           
                           fprintf(GSM,"AT+CMGS=\"+919901260520\"\r\n");
                           delay_ms(1000);
                           fprintf(GSM,"Your Card Blocked \r\n "); 
                           delay_ms(1000);
                           delay_ms(2500);
                           break;      
                           
                        }
                  }
               }
               else
               {
                   tag2 = 1;
                     
                     printf(lcd_putc,"\f");
                     lcd_gotoxy(1,1);
                     printf(lcd_putc,"Your Quota Over");
                     lcd_gotoxy(1,2);
                     printf(lcd_putc,"Card Blocked");
                     beep(2500);
                     
                     fprintf(GSM,"AT+CMGS=\"+919901260520\"\r\n");
                     delay_ms(1000);
                     fprintf(GSM,"Your Card Blocked \r\n "); 
                     delay_ms(1000); 
                     break;
               }
         }
         else
         {
            printf(lcd_putc,"\f");
            lcd_gotoxy(1,1);
            printf(lcd_putc,"Your Card Blocked");
            beep(2500);
            
         }
      }
      
      if(!strcmp(num2,data))
      {    
         if(tag1 == 0)
         {
            if(flag1 < 3)
            {
                  lcd_putc('\f');
                  lcd_gotoxy(1,1);
                  printf(lcd_putc,"Sending Message");
                  lcd_gotoxy(1,2);
                  printf(lcd_putc,"Citizen : 1");
                  delay_ms(2000);
                  
                  gen_otp();
                  
                  fprintf(GSM,"AT+CMGS=\"%s\"\r\n",pnum2);
                  delay_ms(1000);
                  fprintf(GSM,"OTP for Accessing "); 
                  delay_ms(1000);
                  fprintf(GSM," : %Lu \r\n",a);          
                  delay_ms(2000);
                  delay_ms(2500);
                   
                  while(1)
                  {
                        lcd_putc('\f');      //Clear LCD Display
                        lcd_gotoxy(1,1);      
                        printf(lcd_putc," ENTER OTP  "); 
                        
                        read_password();
                        
                        delay_ms(2000);
                        
                        psd = atoi32(pwd);
                                    
                        if(psd == a)
                        {                  
                           printf(lcd_putc,"\f");
                           lcd_gotoxy(1,1);
                           printf(lcd_putc,"ACCESS GRANTED");                     
                           delay_ms(2000);
                           
                           if(flag1 == 0)
                           {
                                 lcd_putc('\f');      //Clear LCD Display
                                 lcd_gotoxy(1,1);      
                                 printf(lcd_putc," ENTER Oil Qty:  "); 
                                 
                                 read_data();
                                 
                                 delay_ms(2000);
                                 
                                 qty = atoi32(pwd);
                                 
                                 lcd_putc('\f');      //Clear LCD Display
                                 lcd_gotoxy(1,1);      
                                 printf(lcd_putc,"Pls Collect Oil "); 
                                 delay_ms(2000);
                                 
                                 output_high(PIN_C4);
                                 qty = qty*2000;
                                 delay_ms(qty);
                                 output_low(PIN_C4);
                                 
                                              
                                 fprintf(GSM,"AT+CMGS=\"%s\"\r\n",pnum2);
                                 delay_ms(1000);
                                 fprintf(GSM,"Your Ration-Oil Delivered \r\n "); 
                                 delay_ms(1000);
                                 flag1 = flag1+1;
                                 break;
                                 
                                 
                           }
                           
                           else if(flag1 == 1)
                           {
                                 lcd_putc('\f');      //Clear LCD Display
                                 lcd_gotoxy(1,1);      
                                 printf(lcd_putc," ENTER Sugar Qty:  "); 
                                 
                                 read_data();
                                 
                                 delay_ms(2000);
                                 
                                 qty = atoi32(pwd);
                                 
                                 lcd_putc('\f');      //Clear LCD Display
                                 lcd_gotoxy(1,1);      
                                 printf(lcd_putc,"Pls Collect Sugar "); 
                                 delay_ms(2000);
                                 
                                 output_high(PIN_C5);
                                 qty = qty*2000;
                                 delay_ms(qty);
                                 output_low(PIN_C5);
                                 
                                              
                                 fprintf(GSM,"AT+CMGS=\"%s\"\r\n",pnum2);
                                 delay_ms(1000);
                                 fprintf(GSM,"Your Ration-Sugar Delivered \r\n "); 
                                 delay_ms(1000);
                                 delay_ms(2500);
                                 flag1 = flag1+1;
                                 break;
                                 
                                 
                           }
                           
                           else if(flag1 == 2)
                           {
                                 lcd_putc('\f');      //Clear LCD Display
                                 lcd_gotoxy(1,1);      
                                 printf(lcd_putc," ENTER Rice Qty:  "); 
                                 
                                 read_data();
                                 
                                 delay_ms(2000);
                                 
                                 qty = atoi32(pwd);
                                 
                                 lcd_putc('\f');      //Clear LCD Display
                                 lcd_gotoxy(1,1);      
                                 printf(lcd_putc,"Pls Collect Rice "); 
                                 delay_ms(2000);
                                 
                                 output_high(PIN_C6);
                                 qty = qty*2000;
                                 delay_ms(qty);
                                 output_low(PIN_C6);
                                 
                                                
                                 fprintf(GSM,"AT+CMGS=\"%s\"\r\n",pnum2);
                                 delay_ms(1000);
                                 fprintf(GSM,"Your Ration-Rice Delivered \r\n "); 
                                 delay_ms(1000);
                                 flag1 = flag1+1;
                                 break;
                           }
                           
                        
                        }
                                       
                        else
                        {
                           printf(lcd_putc,"\f");
                           lcd_gotoxy(1,1);
                           printf(lcd_putc,"You have Entered");
                           lcd_gotoxy(1,2);
                           printf(lcd_putc,"Wrong OTP");
                           beep(2500);
                           wrong1++;
                        }
                        if(wrong1 > 2)
                        {
                           tag1 = 1;
                           
                           printf(lcd_putc,"\f");
                           lcd_gotoxy(1,1);
                           printf(lcd_putc,"Your Card Blocked");
                           beep(2500);
                           
                           fprintf(GSM,"AT+CMGS=\"%s\"\r\n",pnum2);
                           delay_ms(1000);
                           fprintf(GSM,"Your Card Blocked \r\n "); 
                           delay_ms(1000);
                           delay_ms(2500);
                           break;
                                 
                           
                        }
                  }
               }
               else
               {
                   tag1 = 1;
                     
                     printf(lcd_putc,"\f");
                     lcd_gotoxy(1,1);
                     printf(lcd_putc,"Your Quota Over");
                     lcd_gotoxy(1,2);
                     printf(lcd_putc,"Card Blocked");
                     beep(2500);
                     
                     fprintf(GSM,"AT+CMGS=\"%s\"\r\n",pnum2);
                     delay_ms(1000);
                     fprintf(GSM,"Your Card Blocked \r\n "); 
                     delay_ms(1000);
                     delay_ms(2500);
               }
         }
         else
         {
            printf(lcd_putc,"\f");
            lcd_gotoxy(1,1);
            printf(lcd_putc,"Your Card Blocked");
            beep(2500);
            
         }
      }
      
   }
}


