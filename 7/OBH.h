#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif

#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

void FIO()
{
	string S,name1,name2;
	int n;
	cout<<"Введите Имя, Отчество и Фамилею:\n";
	getline(cin,S);
	name1 = S.substr(0,1)+'.';
	n=S.find(' ');
	S=S.substr(n+1);
	n=S.find(' ');
	name2 = S.substr(0,1)+'.';
	S=S.substr(n+1);
	S = S + ' '+name1+name2;
	cout << S << endl;
}
void month()
{
	int p;
	cout<<"Введите дату в определённом формате(12 April 1999):\n";
	string s,day,year,out,month;
	getline(cin,s);
	p=s.find(' ');
	day = s.substr(0,p);
	s=s.substr(p+1);
	p=s.find(' ');
	year = s.substr(p+1);
	s=s.substr(0,p);
	cout << month<< endl;
	if (s =="January") out = year + "-1-" + day;
	if (s =="February") out = year + "-2-" + day;
	if (s =="March") out = year + "-3-" + day;
	if (s =="April") out = year + "-4-" + day;
	if (s =="May") out = year + "-5-" + day;
	if (s =="June") out = year + "-6-" + day;
	if (s =="July") out = year + "-7-" + day;
	if (s =="August") out = year + "-8-" + day;
	if (s =="September") out = year + "-9-" + day;
	if (s =="October") out = year + "-10-" + day;
	if (s =="November") out = year + "-11-" + day;
	if (s =="December") out = year + "-12-" + day;
	cout << out;   
}