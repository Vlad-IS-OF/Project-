#include <iostream>
#include <locale.h>
using namespace std;

int main(void)
{
	setlocale(LC_ALL, "RUS");
	//средствами РОН реализовать операции сложение, 
	//вычитание, умножение и деление.
	//Результаты операций сохранить в переменные и вывести на экран
	int a,b,c,x,y,z,max;
	cout << "Введите 2 числа" << endl;
	cin >> a >> b;
	
	_asm
	{
		mov eax, a
		add eax, b
		mov c, eax
	}
	cout << a << " + " << b << " = " << c << endl;
	_asm
	{
		mov eax, a
		sub eax, b
		mov c, eax
	}
	cout << a << " - " << b << " = " << c << endl;
	_asm
	{
		mov eax, a
		imul eax, b
		mov c, eax
	}
	cout << a << " * " << b << " = " << c << endl;
	_asm
	{
		mov eax, a
		cdq
		div b
		mov c, eax
	}
	cout << a << " / " << b << " = " << c << endl;
	
	//Общая задача 2: найти максимальное значение из двух чисел(команда CMP)
	//Общая задача 3 : найти максимальное значение из трех чисел(команда CMP)
	cout << "Введите 3 числа для сравнения: ";
	cin >> x >> y >> z;
	_asm
	{
		mov eax,x
		cmp y, eax
		JL m1
		mov edx, y
		JMP m2
		m1: mov edx, eax
		m2: mov max, edx
	}
	cout << "Из чисел {" << x << "; " << y << "}. Наибольшее: " << max << endl;
	_asm
	{
		mov eax, x
		cmp y, eax
		JL m3
		mov edx, y
		JMP m4
		m3 : mov edx, eax
		m4: cmp z, edx
		JL m5
		mov edx, z
		m5: mov max, edx
	}
	cout << "Из чисел {" << x << "; " << y << "; " << z << "}. Наибольшее: " << max << endl;
	
	//Общая задача 4: вычислить сумму первых 5 натуральных чисел(используя команду условного перехода JLE)
	//Общая задача 5 : вычислить сумму первых 5 натуральных чисел(используя команду условного перехода JGE)
	//Общая задача 6 : вычислить сумму первых 5 натуральных чисел(используя команду условного перехода JNE)
	//Общая задача 7 : вычислить сумму первых 5 натуральных чисел(используя команду условного перехода JNZ)
	//Общая задача 8 : вычислить сумму первых 5 натуральных чисел(используя команду LOOP)
	int SUM, SUM_1, SUM_2, SUM_3, SUM_4, SUM_L;
	cout << "5 + 4 + 3 + 2 + 1" << endl;
	_asm
	{
		mov eax, 0
		mov ebx, 5
	s1: cmp ebx, 0
		jle s2
		add eax, ebx
		dec ebx
		jmp s1
	s2 : mov SUM, eax
	}
	cout << "JLE: " << SUM << endl;
	_asm
	{
		mov eax, 0
		mov ebx, 5
		mov ecx, 0
	s3: cmp ecx, ebx
		jge s4
		add eax, ebx
		dec ebx
		jmp s3
	s4 : mov SUM_1, eax
	}
	cout << "JGE: " << SUM_1 << endl;
	_asm
	{
		mov eax, 0
		mov ecx, 5
	s5: add eax, ecx
		dec ecx
		cmp ecx, 0
		jne s5
		mov SUM_2, eax
	}
	cout << "JNE: " << SUM_2 << endl;
	_asm
	{
		mov eax, 0
		mov ecx, 5
	s6: add eax, ecx
		dec ecx
		cmp ecx, 0
		jne s6
		mov SUM_3, eax
	}
	cout << "JNZ: " << SUM_3 << endl;
	_asm
	{
		mov eax,0
		mov ecx,5
	s7: add eax,ecx
		loop s7
		mov SUM_L, eax
	}
	cout << "Loop: " << SUM_L << endl;
	//Общая задача 9: вычислить выражение(используя команду LOOP) :
	//Общая задача 10: вычислить факториал заданного числа К(используя команду LOOP)
	int SUM_9,MUL;
	_asm 
	{
		mov ebx, 00
		mov ecx, 05
		sum:
		mov eax, 02
			mul ecx
			add ebx, eax
			loop sum
		mov SUM_9, ebx
	}
	cout << "SUM = " << SUM_9 << endl;
	int K;
	cout << "Введите К: "; cin >> K;
	_asm
	{
		mov eax,1
		mov ecx,K
		Q:	mul ecx
		loop Q
		mov MUL,eax
	}
	cout << K << "! = " << MUL;
}
