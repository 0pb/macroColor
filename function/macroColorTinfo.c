//#define REMOVE_COLOR
//#define MSYS_COMP		
//need to add -ltinfo in compilator arg

#define MACROCOLOR_TERMCAP
#include "macroColor.h" 

int macroColor_colorAbove = 15 ; 
void setColorTcap(int colorNumber) 
{
	    setupterm(NULL, STDOUT_FILENO, NULL);
        char* color_cap = tigetstr("setaf");
        if(colorNumber == 9)  tputs(tiparm(color_cap, COLOR_BLUE), 1, putchar);
		if(colorNumber == 10) tputs(tiparm(color_cap, COLOR_GREEN), 1, putchar);
		if(colorNumber == 11) tputs(tiparm(color_cap, COLOR_CYAN), 1, putchar);
		if(colorNumber == 12) tputs(tiparm(color_cap, COLOR_RED), 1, putchar);
		if(colorNumber == 13) tputs(tiparm(color_cap, COLOR_MAGENTA), 1, putchar);
		if(colorNumber == 14) tputs(tiparm(color_cap, COLOR_YELLOW), 1, putchar);
		if(colorNumber == 15) tputs(tiparm(color_cap, COLOR_WHITE), 1, putchar);
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

int setColor(int colorNumber) 
{
	if(MC_SETCOLOR_TERMCAP) 
	{
		setColorTcap(colorNumber);
	}
	else 
	{
		setColorAinsi(colorNumber);
	}
	return colorNumber ; 
}
