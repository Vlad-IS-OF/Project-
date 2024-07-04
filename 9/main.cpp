#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
//� ����� input.txt �������� ����� (� �������), ������� �� � ����������. �������� � ���� output.txt �� �����.
int C(void)
{
   FILE* f;
    int n, x, S = 0;
    f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("���� �� ������.");
        return 0;
    }
    while (1) {
        n = fscanf(f, "%d", &x);
        if (n != 1) break;
        S += x;
    }
    fclose(f);
    f = fopen("output_1.txt", "w");
    fprintf(f, "S = %d", S);
    printf("OK\n");
    fclose(f); 
}
//����������� ���������� ������� ����� �� �����. ������������� ������ �������� � ����� ����.
int Cpp(void)
{
    const int MAX = 100;
    int A[MAX];
    int i, j, c, N;
    ifstream Fin;
    ofstream Fout;

    Fin.open("input.txt");
    if (Fin) {
        N = 0;
        while (N < MAX && Fin >> A[N])
            N++;
        Fin.close();
        for (i = 0; i < N - 1; i++)
            for (j = N - 2; j >= i; j--)
                if (A[j] > A[j + 1]) {
                    c = A[j]; A[j] = A[j + 1]; A[j + 1] = c;
                }
        Fout.open("output.txt");
        for (i = 0; i < N; i++)
            Fout << A[i] << endl;
        Fout.close();
        cout << "������ ��������� � ����� 'output_3.txt'.";
    }
    else
        cout << "�� ������� ������� ���� 'input_3.txt'.";
    return 0;
}
//19)��� �������� ������������������ ��������������� ����� ����� ���������� ����� ����������� ����� ���� � ���������,
//������ ������� ����������� �� ����� ��� �� 4. �������� ������� �������� ������������������ �� ��������� 1000.
//���������� ��������� ������������������ �� ��������� 10000.
int CCpp(void)
{
    const int d = 4, max = 10000;
    int A[d];
    int N, mn, m, i;
    ifstream Fin;
    ofstream Fout;
    Fin.open("input.txt");
    if (Fin) {
        N = 0;
        while (N < max && Fin >> A[N])
            if (A[N]<1000)
                N++;
        Fin.close();
        mn = 1001;
        m = 2001;
        for (i = d + 1; i < N; i++)
        {
            if (A[i - d] < mn)
                mn = A[i - d];
            if (A[i] + mn < m)
                m = A[i] + mn;
        }
        Fout.open("output_2.txt");
        Fout << m << endl;
        Fout.close();
        cout << "������ ��������� � ����� 'output_2.txt'.";
    }
    else
        cout << "�� ������� ������� ���� 'input.txt'.";
    return 0;
}

int main(void)
{
    setlocale(LC_ALL, "RUS");
    C();
    Cpp();
    CCpp();
    getch();
}
