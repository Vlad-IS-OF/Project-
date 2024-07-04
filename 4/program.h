#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif

#include <stdio.h>
#include <locale.h>
#include <math.h>
#pragma once

float RingS(float R1, float R2);
void Max(int a, int b);
int Min(int a, int b);
void Binar(int a);
int Sum_all(int a);
int rev(int a);
int NOD(int a, int b);
int NOK(int a, int b);

void Start()
{
	int a, b, c, B, Nod, Nok, r;
	float R1, R2;
	setlocale(LC_ALL, "RUS");
	printf("Введите 2 чила: ");
	scanf("%d%d", &a, &b);
	Max(a, b);
	c = Min(a, b);
	do
	{
		printf("Введите чилo: ");
		scanf("%d", &B);
	} while (!(B >= 0 && B <= 255));
	Binar(B);
	printf("Сумма всех чисел = %d\n", Sum_all(B));
	printf("Введите чилo: ");
	scanf("%d", &B);
	r = rev(B);
	printf("Введите 2 чила: ");
	scanf("%d%d", &a, &b);
	Nod = NOD(a, b);
	Nok = NOK(a, b);
	printf("НОД = %d;\nНОК = %d\n", Nod, Nok);
	do
	{
		printf("Введите 2 радиуса: ");
		scanf("%f %f", &R1, &R2);
	} while (R1 <= R2);
	printf("Площадь кольца = %0.2f", RingS(R1, R2));
}

float RingS(float R1, float R2)
{
	float S_1, S_2;
	S_1 = 3.14 * (R1 * R1);
	S_2 = 3.14 * (R2 * R2);
	return S_1 - S_2;
}

void Max(int a, int b)
{
	int Max = 0;
	if (a > b)
		printf("Максимальное значение: %d\n", a);
	else
		printf("Максимальное значение: %d\n", b);
}

int Min(int a, int b)
{
	int min = 0;
	if (a > b)
	{
		min = b;
		printf("Минимальное значение: %d\n", min);
		return min;
	}
	else
	{
		min = a;
		printf("Минимальное значение: %d\n", min);
		return min;
	}
}

void Binar(int a)
{
	int k = 128;
	while (k > 0)
	{
		printf("%d", a / k);
		a = a % k;
		k = k / 2;
	}
	printf("\n");
}

int Sum_all(int a)
{
	int s = 0;
	while (a > 0)
	{
		s += a % 10;
		a /= 10;
	}
	return s;
}

int rev(int a)
{
	int i, s = 0;
	for (i = 0; a > 0; a /= 10)
	{
		i = a % 10;
		s *= 10;
		s += i;
		printf("%d", i);
	}
	printf("\n");
	return s;
}

int NOD(int a, int b) {
	while (a != b) {
		if (a > b) {
			a -= b;
		}
		else {
			b -= a;
		}
	}
	return a;
}

int NOK(int a, int b) {
	return abs(a * b) / NOD(a, b);
}
