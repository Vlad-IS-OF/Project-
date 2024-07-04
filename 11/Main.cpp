#include <iostream>
#include <vector>
#include <locale.h>
#include <algorithm>
using namespace std;

void printArray_i(vector <int> X);
void printArray_f(vector <float> X);

int main(void)
{
	setlocale(LC_ALL, "RUS");

	/*****************************************************************************
	//a)������� ������ ������ : vector <int> <��������> (�������������� #include <vector>)
	//b)���������� �������� � ������ �������� ����� �� 1 �� 10: push_back()
	//c)���������� ������ ������� : size()
	//d)������� ��������� ������� : pop_back()
	//e)������� ��� �������� : clear()
	*****************************************************************************/
	vector<int> A;
	int i = 1;
	A.reserve(10);
	for (; i <= A.capacity(); i++)
	{
		A.push_back(i * i);
	}
	cout << "������ (vector): ";
	printArray_i(A);
	cout << endl;

	A.pop_back();
	cout << "������ (vector) ����� �������� ��������: ";
	printArray_i(A);
	cout << endl;

	A.clear();
	cout << "������ (vector) ������;" << endl;
	cout << endl;
	/*****************************************************************************
	//f)����� �������� � ��� ������ : find(first, last, value), binary_search(first, last, value)
	//g)����� ������������� � ������������ ��������� : max_element(), min_element()
	//h)����� ������������������ � ����� ������� : search(first1, last1, first2, last2)
	//i)������� ���������� ������ ��������� : count()
	//j)����������: sort()
	*****************************************************************************/
	int x;
	vector<int>::iterator it;
	A.shrink_to_fit();
	A.reserve(2);
	cout << "������� ����� (0 - ����� �����):\n";
	cin >> x;
	while (x != 0)
	{
		A.push_back(x);
		cin >> x;
	}
	cout << "������: ";
	printArray_i(A);
	cout << endl;

	cout << "������� ������� ������� ����� �����: "; cin >> x;
	it = find(A.begin(), A.end(), x);
	if (it != A.end())
	{
		cout << "������� " << x << " ��������� �� �������: ";
		cout << (it - A.begin()) + 1 <<"; \n���������� ���������: "<< count(A.begin(),A.end(),x) << "\n";
	}
	else cout << "�������� " << x << "  ���" << endl;
	cout << endl;

	auto res_1 = max_element(A.begin(), A.end());
	auto res_2 = min_element(A.begin(), A.end());
	cout << "Max: " << *res_1 << "; Min: " << *res_2 << endl;
	cout << endl;

	vector <int> B;
	cout << "������� ����������������� ����� ��� ��������� (0 - ����� �����):\n";
	cin >> x;
	while (x != 0)
	{		
		B.push_back(x);
		cin >> x;
	}
	cout << "������ ��� ���������:";
	printArray_i(B);
	cout << endl;
	if (search(A.begin(), A.end(), B.begin(), B.end()) != A.end())
		cout << "���� ����������"<< endl;
	else
		cout << "��� ����������" << endl;
	cout << endl;

	sort(A.begin(), A.end());
	cout << "����� ����������: ";
	printArray_i(A);
	/****************************************************************************
	19.	��� ���������� ������ (������), ��������� �� N ������������ ���������.
		19.1.������ ������ � ����������.
		19.2.����� ����������� ������������� �������.
		19.3.��������� ������������ �������� ��������� �������.
		19.4.������� ������������� �������� �� �����.
	****************************************************************************/
	cout << "�������������� �������" << endl;
	i = 0;
	float x_f;
	float proi = 1;
	float min_1, min_2;
	vector <float> K;
	cout << "������� �������� ������������� ������� (0 ����� �����):" << endl;
	cin >> x_f;
	while (x_f != 0)
	{
		K.push_back(x_f);
		cin >> x_f;
	}
	printArray_f(K);
	cout << endl;

	cout << "������������� ��������: \n";
	min_2 = K[0];
	for (; i < K.size(); i++)
	{
		min_1 = K[i];
		if (min_1 < min_2 && min_1>0)
			min_2 = min_1;
		if (i % 2 != 0)
			proi *= K[i];
		if (K[i] < 0)
			cout << K[i] << " ";
	}
	cout << "\n\n����������� ������������� ������� = " << min_2 << "\n������������ �������� ��������� ������� = " << proi << ";" << endl;
}

void printArray_i(vector <int> X)
{
	int i;
	for (i = 0; i < X.size(); i++)
		cout << X[i] << " ";
	cout << "\n������ �������: " << X.size() << endl;
}

void printArray_f(vector <float> X)
{
	int i;
	for (i = 0; i < X.size(); i++)
		cout << X[i] << "; ";
	cout << "\n������ �������: " << X.size() << endl;
}