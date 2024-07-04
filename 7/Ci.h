#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <Windows.h>

//Дана стрoка символов. Слова в строке отделяются друг от друга пробелом. Удолить из строки самое короткое слово.
void ci()
{
	int i = 0, dlina_tek = 0, dlina_min = 255, polozhenie, polozhenie_min = 0;
	char q[999];
	
	gets(q);
	//puts(q);
	while(q[i] != '\0')
	{
		if(q[i] == ' ')
			i++;
		else
		{
			if(q[i-1] == ' ')
			{
				polozhenie = i;
			}
			while(q[i]!= ' ')
			{
				dlina_tek++;
				i++;
				if(q[i] == '\0')
					break;
			}
			if(dlina_tek < dlina_min)
			{
				polozhenie_min = polozhenie;
				dlina_min = dlina_tek;
			}
			dlina_tek = 0;
		}
	}
	printf("%d Длина минимального слова\n", dlina_min);
	printf("%d положение минимального слова\n", polozhenie_min+1);
	for(int j = 0; j<=dlina_min;j++)
	{
		for(i = polozhenie_min; q[i] != '\0'; i++)
		{
			q[i] = q[i+1];
				//printf("%c", q[i]);
		}
	}
	puts(q);
}