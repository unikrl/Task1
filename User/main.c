#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"

int main(void)
{
	int offset, i, col;
	char hello[] = "Hello,  ";
	char num[] = "205";
	char tmp[2] = {0, 0};
	
	OLED_Init();
	
	while (1)
	{	
		OLED_Clear();
		OLED_ShowString(1, 1, "ID: 632407030327"); 
		OLED_ShowCN(2, 1, 0, 1); 
		OLED_ShowCN(2, 2, 1, 1); 
		Delay_ms(2000); 
		
		for (offset = 16; offset >= -44; offset -= 2) 
		{
			OLED_Clear();
			
			for (i = 0; i < 8; i++) 
			{
				col = offset + i;
				if (col >= 1 && col <= 16) 
				{
					tmp[0] = hello[i];
					OLED_ShowString(2, col, tmp);
				}
			}
			
			for (i = 0; i < 16; i++) 
			{
				col = (offset + 8) / 2 + i;
				if (col >= 1 && col <= 8) 
				{
					OLED_ShowCN(2, col, i + 2, 1);
				}
			}
			
			for (i = 0; i < 3; i++) 
			{
				col = offset + 40 + i;
				if (col >= 1 && col <= 16) 
				{
					tmp[0] = num[i];
					OLED_ShowString(2, col, tmp);
				}
			}
			
			Delay_ms(150); 
		}
		Delay_ms(1000); 
	}
}