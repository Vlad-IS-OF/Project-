#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif

#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <conio.h>

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "RUS");
	int a,b,c;
	printf("Введите 3 целых числа: ");
	scanf("%d%d%d", &a, &b, &c);
	if (a > b)
	{
		if (a > c)
		{
			printf("MAX: %d", a);
		}
	}
	else if (b > c)
	{
		printf("MAX: %d", b);
	}
	else printf("MAX: %d", c);
	/*а) Написать программу, которая проверяет – является ли сумма последних цифр трех заданных чисел нечетным числом.
	б) Написать программу, которая определяет – какая из двух точек, заданных на плоскости своими координатами, находится ближе к оси OX, и какая к оси OY.*/
	int sum = a + b + c;
	if (sum % 2 != 0)
		printf("\nСумма чисел не чётная.");
	else printf("\nСумма чисел чётная.");
	int x1, x2, y1, y2;
	printf("\nВведите координаты 1-й точки (х и у) и координаты 2-й точки (х и у): ");
	scanf("%d%d%d%d", &x1, &y1,  &x2, &y2);
	x1 = fabs(x1);
	x2 = fabs(x2);
	y1 = fabs(y1);
	y2 = fabs(y2);
	if (y1 < y2)
		printf("К оси ОХ ближе 1-я точка.\n");
	else printf("К оси ОХ ближе 2-я точка.\n");
	if (x1 < x2)
		printf("К оси ОY ближе 1-я точка.\n");
	else printf("К оси ОY ближе 2-я точка.\n");
}