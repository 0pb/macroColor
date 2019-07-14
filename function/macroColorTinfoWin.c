//#define REMOVE_COLOR
//#define MSYS_COMP
#include "macroColor.h" 

int macroColor_colorAbove = 15 ; 
int setColor(int colorNumber) 
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	setColorWindow(colorNumber, hConsole);
	return colorNumber ; 
}

int setColorWindow(int colorNumber, mC_COLOR_CPP)
//mC_COLOR_CPP is HANDLE *hConsole or HANDLE hConsole (c++ or c accordingly)
{
   	SetConsoleTextAttribute(hConsole, colorNumber);
   	return colorNumber; 
}