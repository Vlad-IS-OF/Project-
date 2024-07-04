#include <iostream>
#include <stdio.h>
#include <locale.h>
using namespace std;

void CreateArray(int* A, int N);
void OutArray(int* A, int N);
int OTR(int* A, int N);
int SUM(int* A, int N);

int main(void)
{
	setlocale(LC_ALL, "RUS");
	int N,vibor, a(0);
	cout << "������� ������ �������" << endl;
	cin >> N;
	int* A = new int[N];
	cout << "�������� ��� �����\n1)������\n2)������������� (������)\n3)�����" << endl;
	cin >> vibor;
	switch (vibor)
	{
	case 1:
		CreateArray(A, N);
		break;
	case 2:
		for (int i = 0; i < N; i++)
		{
			if (i % 2 == 0)
			{
				A[i] = rand() % 100;
			}
			else
			{
				A[i] = (rand() % 100) * (-1);
			}
		}
		break;
	case 3:
		return 1;
	default:
		return 10;
	}
	OutArray(A, N);
	int otr = OTR(A, N), sum = SUM(A, N);
	cout << "\n������������ ������������� = " << otr << "\n����� �������������, �� ������������� �������� = " << sum << endl;
	for (int i = 0; i < N / 2; i++) //��� ��������� �������
	{
		a = A[i];
		A[i] = A[N - i - 1];
		A[N - i - 1] = a;
	}
	OutArray(A, N);
	delete[] A;
	system("pause");
}
//1)������������ ������������� ��������� �������
//2)����� ������������� ��������� �������, ������������� �� ������������� ��������.
//�������� ������� ���������� ��������� � ������� �� ��������
int OTR(int* A, int N)
{
	int otr = 1;
	for (int i = 0; i < N; i++)
	{
		if (A[i] < 0)
			otr *= A[i];
	}
	return otr;
}

int SUM(int* A, int N)
{
	int SUM = 0, max = A[0], max_i = 0;
	for (int i = 1; i < N; i++)
	{
		if (max < A[i]) { max = A[i]; max_i = i; }
	}
	for (int i = 0; i < max_i; i++)
	{
		if (A[i] >= 0)
		{
			SUM += A[i];
		}
	}
	return SUM;
}

void OutArray(int* A,int N)
{
	for (int i = 0; i < N; i++)
		cout << A[i] << "; ";
}

void CreateArray(int* A,int N)
{
	int x;
	for (int i = 0; i < N; i++)
	{
		printf("A[%d] = ", i);
		cin >> x;
		A[i] = x;
	}
}