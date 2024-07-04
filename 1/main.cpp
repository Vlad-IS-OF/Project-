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
	int a, b, x, y;
	printf("Введите два целых числа: ");
	scanf("%d%d", &a, &b);
	printf("\n%d + %d = %d", a, b, a + b);
	printf("\n%d - %d = %d", a, b, a - b);
	printf("\n%d * %d = %d", a, b, a * b);
	printf("\n%d / %d = %d", a, b, a / b);
	printf("\nВведите x и y: ");
	scanf("%d%d", &x, &y);
	//double P = (((3.11 * x) / (sqrt(fabs(7 * x - pow(3, x)))) + tan(x - 2 * y)));
	printf("%f", (((3.11 * x) / (sqrt(fabs(7 * x - pow(3, x)))) + tan(x - 2 * y))));
}