#include <iostream>
#include <locale.h>
using namespace std;

int main(void)
{
	setlocale(LC_ALL, "RUS");
	//���������� ��� ����������� �������� ��������, 
	//���������, ��������� � �������.
	//���������� �������� ��������� � ���������� � ������� �� �����
	int a,b,c,x,y,z,max;
	cout << "������� 2 �����" << endl;
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
	
	//����� ������ 2: ����� ������������ �������� �� ���� �����(������� CMP)
	//����� ������ 3 : ����� ������������ �������� �� ���� �����(������� CMP)
	cout << "������� 3 ����� ��� ���������: ";
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
	cout << "�� ����� {" << x << "; " << y << "}. ����������: " << max << endl;
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
	cout << "�� ����� {" << x << "; " << y << "; " << z << "}. ����������: " << max << endl;
	
	//����� ������ 4: ��������� ����� ������ 5 ����������� �����(��������� ������� ��������� �������� JLE)
	//����� ������ 5 : ��������� ����� ������ 5 ����������� �����(��������� ������� ��������� �������� JGE)
	//����� ������ 6 : ��������� ����� ������ 5 ����������� �����(��������� ������� ��������� �������� JNE)
	//����� ������ 7 : ��������� ����� ������ 5 ����������� �����(��������� ������� ��������� �������� JNZ)
	//����� ������ 8 : ��������� ����� ������ 5 ����������� �����(��������� ������� LOOP)
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
	//����� ������ 9: ��������� ���������(��������� ������� LOOP) :
	//����� ������ 10: ��������� ��������� ��������� ����� �(��������� ������� LOOP)
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
	cout << "������� �: "; cin >> K;
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
