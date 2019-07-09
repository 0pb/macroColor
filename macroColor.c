//#define REMOVE_COLOR
//#define MSYS_COMP
#include "macroColor.h" 

int macroColor_colorAbove = 15 ; 
int setColor(int colorNumber) 
{
	//Window part
	if(mC_COLOR_WINDOW) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		setColorWindow(colorNumber, hConsole);
	}
	//Linux / AINSI part
	else setColorAinsi(colorNumber);
	return colorNumber ; 
}

int setColorWindow(int colorNumber, mC_COLOR_CPP)
//mC_COLOR_CPP is HANDLE *hConsole or HANDLE hConsole (c++ or c accordingly)
{
   	SetConsoleTextAttribute(hConsole, colorNumber);
   	return colorNumber; 
}

void setColorAinsi(int colorNumber) 
{
	if(colorNumber == 9)  printf("\e[0;34m") ; 
	if(colorNumber == 10) printf("\e[0;32m") ;
	if(colorNumber == 11) printf("\e[0;36m") ; 
	if(colorNumber == 12) printf("\e[0;31m") ; 
	if(colorNumber == 13) printf("\e[0;35m") ;
	if(colorNumber == 14) printf("\e[0;33m") ;
	if(colorNumber == 15) printf("\e[1;37m") ;
}