#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif

#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <math.h>
#include <conio.h>

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "RUS");
	//Вывести на консоль модель таблицы с курсами валют: «РУБЛЬ» - «ДОЛЛАР» - «ЕВРО» от 1 до 100 (руб.)
	float K_D = 74.01, K_E = 80.46;
	float D, E;
	printf("Таблица курса валют: «РУБЛЬ» - «ДОЛЛАР» - «ЕВРО»\n");
	for (int i = 1; i <= 100; i++)
	{
		D = i * K_D;
		E = i * K_E;
		printf("%3d  %4.2f  %4.2f\n", i, D, E);
	}
	const float e = 0.00001;
	int n;
	float x, next, s;
	printf("Введите х: ");
	do {
		cin >> x;
	} while (x > 1);
	n = 0;
	s = 1; 
	next = -x / 5;
	do{
		s += next;
		n++;
		next = -next * (1 / 5 - n) / (n + 1) * x;
	} while (fabs(next) > e);
	printf("Ответ цикла: %0.4f\n", s);
	printf("Ответ формулы: %0.4f", pow(1 - x, 1 / 5));
}