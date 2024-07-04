#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif
#include "Ci.h"
#include "Cpp.h"
#include "OBH.h"

void main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FIO();
	month();
	cout << "\nВведите строку символов" << endl;
	ci();
	Cpp();
	getch();
	
}