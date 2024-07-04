#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif

#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

void OutArray1(int* A, int N);
void OutArray2(int A[50][50], int N, int M);
void Array2()
{
	int A[50][50] = { {00,01,02} ,{10,11,12} ,{20,21,22} };
	int chois, q = 0,N,M;
	printf("Введите размер массива:");
	scanf("%d%d", &N, &M);
	//a)ввод данных (вручную || рандом || заданные программно значения элементов массива);
	printf("Выберите способ ввода:\n1)Ручной\n2)Рандомно\n3)Автоматически\n");
	do
	{
		scanf("%d", &chois);
	} while (chois < 1 && chois>3);
	switch (chois)
	{
	case 1:
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				printf("A[%d][%d]=", i, j);
				scanf("%d", &q);
				A[i][j] = q;
			}
		break;
	case 2:
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				A[i][j] = rand() % 100;
			}
		break;
	case 3:
		break;
	}
	//b)вывод значений массива на экран (в форме прямоугольной матрицы);
	printf("=====================================================\n");
	OutArray2(A, N, M);
	//c)поиск максимального элемента с указанием его месторасположения;
	printf("=====================================================\n");
	int Max = A[0][0], Min = A[0][0], Max_i = 0, Max_j = 0, Min_i = 0, Min_j = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] > Max) { Max_i = i; Max_j = j; Max = A[i][j]; }
			if (A[i][j] < Min) { Min_i = i; Min_j = j; Min = A[i][j]; }
		}
	printf("Max = A[%d][%d] = %d;\nMin = A[%d][%d] = %d;\n", Max_i + 1, Max_j + 1, Max, Min_i + 1, Min_j + 1, Min);
	printf("=====================================================\n");
	//d)вывод сумм строк массива(переписывая в новый одномерный массив);
	int B[50];
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			sum += A[i][j];
		B[i] = sum;
		sum = 0;
	}
	OutArray1(B, N);
	printf("\n=====================================================\n");
	//e)	сортировку всех строк массива;
	int c, i, j;
	for (int y = 0; y < N; y++)
		for (i = 0; i < N; i++)
			for (j = 0; j < M - 1; j++)
				if (A[i][j] > A[i][j + 1])
				{
					c = A[i][j];
					A[i][j] = A[i][j + 1];
					A[i][j + 1] = c;
				}
	OutArray2(A, N, M);
	printf("=====================================================");
	//f)	поиск номера строки с наибольшим количеством нулевых элементов.
	int Null = 0, Null_1 = 0, Null_1_i = 0, Null_i = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++)
			if (A[i][j] == 0) { Null_1++; Null_1_i = i; }
		if (Null < Null_1) { Null = Null_1; Null_i = Null_1_i; }
		Null_1 = 0;
	}
	if (Null <= 0) printf("\nНет строки с нулевыми элементами\n");
	else printf("\nВ строке %d наибольшее количество нулевых элементов\n", Min_i + 1);
	//g)	индивидуальную задачу 
	/*дана целочисленная прямоугольная матрица.Определить:
1)Сумму элементов в тех строк которые не содержат отрицательных элементов;
2)минимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы. */
	printf("=====================================================");
	printf("\nИндивидуальное задание\n");
	int I,s1=0;
	printf("Введите порядок массива\n");
	scanf("%d", &I);
	int Q[50][50];
	printf("Выберите способ ввода:\n1)Ручной\n2)Рандомно\n");
	do
	{
		scanf("%d", &chois);
	} while (chois < 1 && chois>3);
	switch (chois)
	{
	case 1:
		for (int i = 0; i < I; i++)
			for (int j = 0; j < I; j++)
			{
				printf("A[%d][%d]=", i, j);
				scanf("%d", &q);
				Q[i][j] = q;
			}
		break;
	case 2:
		for (int i = 0; i < I; i++)
			for (int j = 0; j < I; j++)
			{
				Q[i][j] = rand() % 100;
			}
		break;
	}
	OutArray2(Q, I, I);
	//1)
	printf("=====================================================");
	for (int i = 0; i < I; i++)  //находим положительные элементы в строках и суммирукм их
	{
		sum = 0;
		for (int j = 0; j < I; j++)
		{
			s1 += Q[i][i];
			if (Q[i][j] >= 0) sum += Q[i][j];
			else
			{
				sum = 0;
				break;
			}
		}
		if (sum != 0) printf("\nСумма элементов строки № %d = %d", i + 1, sum);
	}
	printf("\n=====================================================\n");
	//2)
	int t1, t2;
	for (i = 1; i < I; i++) {
		t1 = 0; t2 = 0;
		for (j = 0; j < I - i; j++)
		{
			t1 += Q[i + j][j];
			t2 += Q[j][i + j];
		}
		if (t1 < s1) s1 = t1;
		if (t2 < s1) s1 = t2;
	}
	printf("Минимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы: %d", s1);
}

void OutArray1(int* A, int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d; ", A[i]);
	}
}
void OutArray2(int A[50][50], int N, int M)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%3d; ", A[i][j]);
		printf("\n");
	}
}