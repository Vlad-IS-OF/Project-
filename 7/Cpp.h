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
	cout << "������� ���-�� ����� � ������: ";
	cin >> n;
	for (int i=0;i<n;i++)
	{
		cout << "������� ���������� � " << i+1 << "-�� ��������:" << endl;
		cout << "�������: ";
		cin >> F[i];
		cout << "���: ";
		cin >> I[i];
		cout << "���� ��������: ";
		cin >> D[i];
		cout << "����� ��������: ";
		cin >> M[i];
		cout << "��� ��������: ";
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
		if (koll == 1) cout << "����� �������: " << F[adres] << " " << I[adres] << endl;
		else cout << koll << endl;
	
}