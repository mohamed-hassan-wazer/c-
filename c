// traffic lights
DDRD = 0xFF;
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRE = 0xFF;
	int ch[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
	PORTD=ch[0];
	PORTA=ch[0];
	while(1)
	{
		for(int i=0; i<=2; i++){ // لوب لعدد الليد
			PORTE = (1<<i);//شغلت الليد يمين
			PORTB = (1<<i);//شغلت الليد شمال
			if (i==1) // لو ساوي الاصفر لانه بيساوي الواحد من اللوب
			{
				for (int j=5; j>=0; j-- )
				{
					PORTD = ch[j]; // عد من فوق لتحت علي حسب الرقم في الشاشة اليمين
					PORTA = ch[j]; // في الشاشة الشمال
					_delay_ms(1000);
				}
				
				
				}else{
				for (int j=9; j>=0; j-- )
				{
					PORTD = ch[j]; // عد من فوق لتحت علي حسب الرقم في الشاشة اليمين

					PORTA = ch[j]; // في الشاشة اليمين
					_delay_ms(1000);
				}
			}
			
		}
		
		
	}



------------------------------------------------------
//interrupt 
#define  F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void int0_init(){
	DDRD &=~(1<<0);// الزار ك input
	PORTD = 0xFF;// فعلت pull up
	
	EIMSK |=(1<<INT0);  // علي حسب انت موصل علي int 0 , int1 .....
	
	EICRA |=(1<<ISC01); // pull up
  EICRA |=(1<<ISC01) | (1<<ISC00);  // pull down
	// الزيرو ا للي بعد ال سي بيتحدد علي حسب انت شغال int 0 , int1 .......
	sei();
	
	
}

ISR(INT0_vect){
//تحط الشرط اللي انت عاوزه اكنه كود عادي 

	PORTE ^=(1<<0);// هنا عملنا توجل 
	_delay_ms(5000);	
}

int main(void)
{
	DDRE =0xFF;
	// استدعيت الفانكشن
	int0_init();
	
	while(1){
// اللي هيحصل عادي 
		PORTE |=(1<<0);	
	}
