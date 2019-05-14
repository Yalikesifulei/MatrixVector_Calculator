#include"interface.h"
#include<tchar.h>
#include<conio.h>

int main(){
	SetConsoleTitle(_T("Vector and matrix calculator"));
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, CYAN_BG+WHITE); system("cls");

	HorizontalMenu(h);	
	system("pause");
}