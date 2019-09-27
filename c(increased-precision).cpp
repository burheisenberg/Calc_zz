//#include <iostream>
#include <bits/stdc++.h>
//#include <stdio.h>
using namespace std;
#define PI     3.141592653589//7932384626
#define Euler  2.718281828459//0452353602
char *x;
string line;
int a,b;
bool t=0;
long double parseCh();
long double parseNum();
long double parseSum();
long double parseFactor();
long double parseProduct();

long double parseCh(){if(*x<='9'&&*x>='0'){return *x++-'0';}
				else if(*x=='p'){++x;return PI;}
				else if(*x=='e'){++x;return Euler;}
				else {cout<<"There is something wrong"<<endl;}return 0;}
long double parseNum(){long double num1=parseCh();
	while(*x>='0'&&*x<='9'||*x=='p'||*x=='e'){long double num2=parseCh();num1*=10;num1+=num2;}
	while(*x=='.'){++x;a=0;
	while(*x>='0'&&*x<='9'){++a;long double num2=parseCh();num1*=10;num1+=num2;}num1*=pow(10,-a);}
	while(*x==34){++x;long double num2=parseFactor();num1=pow(num1,num2);}
	return num1;}
long double parseSum(){
	long double pro1=parseProduct();while(*x=='+'||*x=='-'){
	while(*x=='+'){++x;long double pro2=parseProduct();pro1+=pro2;}
	while(*x=='-'){++x;long double pro2=parseProduct();pro1-=pro2;}}
	return pro1;}
long double parseFactor(){
	if(*x<='9'&&*x>='0'||*x=='p'||*x=='e'){return parseNum();}//return *x++ - '0';}
	else if(*x=='('){++x;long double sum=parseSum();++x;return sum;}
//	else if(*x=='^'){++x;}  üslü hesaplamalar için destek eklenecek
	//else if(*x=='p'){++x;return PI;}
	//else if(*x=='e'){++x;return Euler;}
	else{printf("expected digit but found %c\n",*x);}return 0;}
long double parseProduct(){long double fac1=parseFactor();
	while(/**x>='0'&&*x<='9'||*/*x=='*'||*x=='/'/*||*x==34||*x=='.'*/){/*
	while(*x=='.'){++x;a=0;
	while(*x>='0'&&*x<='9'){++a;long double fac2=parseFactor();fac1*=10;fac1+=fac2;}fac1*=pow(10,-a);}
	while(*x>='0'&&*x<='9'){long double fac2=parseFactor();fac1*=10;fac1+=fac2;}//}*/
	//while(*x==34){++x;long double parseNum();} //34 " tekabül ediyor*/
	while(*x=='*'){++x;long double fac2=parseFactor();fac1*=fac2;}
	while(*x=='/'){++x;long double fac2=parseFactor();fac1/=fac2;}}
	return fac1;}

int main(){
	//x="444+5*5/4-25";
	cout<<"-Instrutions-"<<endl;
	cout<<"plus\t\t:+\nreduce\t\t:-\nmultiply\t:*\ndivide\t\t:/\n";
	cout<<"parenthesis\t:()\nexponent\t:\"\nNumber Pi\t:p\nNumber E\t:e\n";
	/*INSTRUCTIONS:
	plus            :+
	reduce          :-
	multiply        :*
	divide          :/
	parenthesis     :()
	exponent        :"
	Number Pi       :p
	Number E        :e      */
	start://
	//x="";
	cout << "what you want to do: ";
	cin>>line;
	if(line=="exit"){return 0;}
    int n = line.length();  
    char char_array[n+1];
    strcpy(char_array, line.c_str());
    x=char_array;//
	long double result=parseSum();
	cout<<"result: "<<setprecision(16)<<result<<endl;
	goto start;
	return 0;
}
