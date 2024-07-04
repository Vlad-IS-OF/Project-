#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void Cpp ()
{ 
	int n; 
	string F[100];
	string I[100];
	int D[100];
	int M[100];
	int G[100];
	cout << "Введите кол-во людей в списке: ";
	cin >> n;
	for (int i=0;i<n;i++)
	{
		cout << "Введите информацию о " << i+1 << "-ом человеке:" << endl;
		cout << "Фамилия: ";
		cin >> F[i];
		cout << "Имя: ";
		cin >> I[i];
		cout << "День рождения: ";
		cin >> D[i];
		cout << "Месяц рождения: ";
		cin >> M[i];
		cout << "Год рождения: ";
		cin >> G[i];
	}
	int max_G = G[0], max_M = M[0], max_D = D[0];
	for (int i = 2; i < n; i++)
		{   if (max_G < G[i])
			{
				max_G = G[i];max_M = M[i]; max_D = D[i];
			} else if (max_G == G[i] && max_M > M[i])
			{
				max_G = G[i];max_M = M[i]; max_D = D[i];
			} else if (max_G == G[i] && max_M == M[i] && max_D > D[i])
			{
				max_G = G[i];max_M = M[i]; max_D = D[i];
			}
		}
		int koll=0,adres;
		for (int i = 0;i<n;i++)
		{
			if (max_G == G[i] && max_M == M[i] && max_D == D[i])
				koll++;adres = i;
		}
		if (koll == 1) cout << "Самый старший: " << F[adres] << " " << I[adres] << endl;
		else cout << koll << endl;
	
}