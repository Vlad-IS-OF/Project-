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
	//a)описать пустой вектор : vector <int> <название> (предварительно #include <vector>)
	//b)программно записать в вектор квадраты чисел от 1 до 10: push_back()
	//c)определить размер вектора : size()
	//d)удалить последний элемент : pop_back()
	//e)удалить все элементы : clear()
	*****************************************************************************/
	vector<int> A;
	int i = 1;
	A.reserve(10);
	for (; i <= A.capacity(); i++)
	{
		A.push_back(i * i);
	}
	cout << "Массив (vector): ";
	printArray_i(A);
	cout << endl;

	A.pop_back();
	cout << "Массив (vector) после удоления элемента: ";
	printArray_i(A);
	cout << endl;

	A.clear();
	cout << "Массив (vector) очишен;" << endl;
	cout << endl;
	/*****************************************************************************
	//f)поиск элемента и его номера : find(first, last, value), binary_search(first, last, value)
	//g)Поиск максимального и минимального элементов : max_element(), min_element()
	//h)Поиск последовательности в форме массива : search(first1, last1, first2, last2)
	//i)Подсчет количества нужных элементов : count()
	//j)Сортировка: sort()
	*****************************************************************************/
	int x;
	vector<int>::iterator it;
	A.shrink_to_fit();
	A.reserve(2);
	cout << "Введите числа (0 - конец ввода):\n";
	cin >> x;
	while (x != 0)
	{
		A.push_back(x);
		cin >> x;
	}
	cout << "Массив: ";
	printArray_i(A);
	cout << endl;

	cout << "Введите элемент который нужно найти: "; cin >> x;
	it = find(A.begin(), A.end(), x);
	if (it != A.end())
	{
		cout << "Элемент " << x << " находится на позиции: ";
		cout << (it - A.begin()) + 1 <<"; \nКоличество элементов: "<< count(A.begin(),A.end(),x) << "\n";
	}
	else cout << "Элемента " << x << "  нет" << endl;
	cout << endl;

	auto res_1 = max_element(A.begin(), A.end());
	auto res_2 = min_element(A.begin(), A.end());
	cout << "Max: " << *res_1 << "; Min: " << *res_2 << endl;
	cout << endl;

	vector <int> B;
	cout << "Введите поледовательность чисел для сравнения (0 - конец ввода):\n";
	cin >> x;
	while (x != 0)
	{		
		B.push_back(x);
		cin >> x;
	}
	cout << "Массив для сравнения:";
	printArray_i(B);
	cout << endl;
	if (search(A.begin(), A.end(), B.begin(), B.end()) != A.end())
		cout << "Есть совпадение"<< endl;
	else
		cout << "Нет совпадений" << endl;
	cout << endl;

	sort(A.begin(), A.end());
	cout << "После сортировки: ";
	printArray_i(A);
	/****************************************************************************
	19.	Дан одномерный массив (вектор), состоящий из N вещественных элементов.
		19.1.Ввести массив с клавиатуры.
		19.2.Найти минимальный положительный элемент.
		19.3.Вычислить произведение нечетных элементов массива.
		19.4.Вывести отрицательные элементы на экран.
	****************************************************************************/
	cout << "Индивидуальное задание" << endl;
	i = 0;
	float x_f;
	float proi = 1;
	float min_1, min_2;
	vector <float> K;
	cout << "Введите элементы вещественного массива (0 конец ввода):" << endl;
	cin >> x_f;
	while (x_f != 0)
	{
		K.push_back(x_f);
		cin >> x_f;
	}
	printArray_f(K);
	cout << endl;

	cout << "Отрицательные элементы: \n";
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
	cout << "\n\nМинимальный положительный элемент = " << min_2 << "\nПроизведение нечетных элементов массива = " << proi << ";" << endl;
}

void printArray_i(vector <int> X)
{
	int i;
	for (i = 0; i < X.size(); i++)
		cout << X[i] << " ";
	cout << "\nРазмер массива: " << X.size() << endl;
}

void printArray_f(vector <float> X)
{
	int i;
	for (i = 0; i < X.size(); i++)
		cout << X[i] << "; ";
	cout << "\nРазмер массива: " << X.size() << endl;
}