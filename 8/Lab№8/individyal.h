#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct PRICE
{
	string tovar;
	string magazin;
	int Rub;
};
struct TTime 
{
	int s; 
	int m; 
	int h;
};
struct Sot 
{
	int num_p;
	string FIO;
	string otdel;
	int zarplata;
};
void sec_plus(TTime &t)
{

	t.s++;
	if (t.s > 59) { t.m++; t.s = 0; }
	if (t.m > 59) { t.h++; t.m = 0; }
	if (t.h > 24) { t.h = 0; }
}
void tovar()
{
	const int N = 10;
	PRICE c;
	int i, j;
	PRICE S[N] = {
	{"Конфета","Candy",150},
	{"Машинка","Candy",200},
	{"Кукла","Candy",120},
	{"Конфета","Fivti",100},
	{"Мотоцыкл","Portal",350},
	{"Платье","Shop",500},
	{"Конфета","Falle",125},
	{"Машина","Falle",210},
	{"Радио","24-RU",654},
	{"Телефон","24-RU",7813}
	};
	string s, t;
	bool q = false;
	for (i = 0; i < N; i++) //Сортировка
		for (j = N - 2; j >= i; j--)
			if (S[j].magazin > S[j + 1].magazin)
			{
				c = S[j];
				S[j] = S[j + 1];
				S[j + 1] = c;
			}
	for (i = 0; i < N; i++)
	{
		s = S[i].tovar + ' ' + S[i].magazin + ' ' + to_string(S[i].Rub);
		cout << s << endl;
	} // Ввывод товаров
	cout << "\nТовар:";
	cin >> t;
	for (i = 0; i < N; i++)
	{
		if (t == S[i].tovar)
		{
			q = true;
			s = S[i].tovar + ' ' + S[i].magazin + ' ' + to_string(S[i].Rub);
			cout << s << endl;
		}
	}
	if (q == false)
	{
		cout << "Такого товара нет!!!" << endl;
	}
}
void tame()
{
	cout << "\nВведите время: ";
	TTime time;
	cin >> time.h >> time.m >> time.s;
	cout << time.h << " ч. " << time.m << " мин. " << time.s << " сек.";
	sec_plus(time);
	cout << " + 1 сек. = ";
	cout << time.h << " ч. " << time.m << " мин. " << time.s << " сек.";
}
void sotr()
{
	const int N = 3;
	string FIO;
	int i, j;
	Sot c;
	Sot S[N] = { {13,"Самойлов В.Ф.","Кадры",13000}, {1,"Кропоткина Н.Т","Секретарь",15000}, {15,"Сивков В.С","Программист",20000} };
	for (i = 0; i < N; i++) //Сортировка
		for (j = N - 2; j >= i; j--)
			if (S[j].FIO > S[j + 1].FIO)
			{
				c = S[j];
				S[j] = S[j + 1];
				S[j + 1] = c;
			}
	for (i = 0; i < N; i++)
	{
		//cout << S[i].num_p << ' ' << S[i].FIO << ' ' << S[i].otdel << ' ' << S[i].zarplata << endl;
		if (S[i].zarplata > S[i + 1].zarplata)
			FIO = S[i].FIO;
	}

	cout << FIO << endl;
}