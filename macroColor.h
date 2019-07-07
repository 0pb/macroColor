
// ======================================================================
// macroColor.h - simple header for colored output in c++
// Made by 0pb - https://github.com/0pb/macroColor
//
// Distributed under the GNU GENERAL PUBLIC LICENSE
// See accompanying file LICENSE.txt or copy at
// https://github.com/0pb/macroColor/blob/master/LICENSE
// ======================================================================

#ifndef macroColor_h

#ifdef _WIN32
	#include <windows.h>
	int colorAbove = 15 ;
	int tempoColor = 15 ;  

	#define BLU 	SetConsoleTextAttribute(hConsole, 9) ; 	colorAbove = 9 ;
	#define GREEN 	SetConsoleTextAttribute(hConsole, 10); 	colorAbove = 10;
	#define CYAN 	SetConsoleTextAttribute(hConsole, 11); 	colorAbove = 11;
	#define RED 	SetConsoleTextAttribute(hConsole, 12); 	colorAbove = 12;
	#define YELLOW 	SetConsoleTextAttribute(hConsole, 14); 	colorAbove = 14;
	#define WHITE 	SetConsoleTextAttribute(hConsole, 15); 	colorAbove = 15;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif

/*TODO LINUX VERSION
#ifdef unix

    #define BLU	        stream << "\e[0;34m" ;
    #define GREEN       stream << "\e[0;32m" ;
    #define CYAN        stream << "\e[0;36m" ;
    #define RED         stream << "\e[0;31m" ;
    #define YELLOW      stream << "\e[0;33m" ;
    #define WHITE		stream << "\e[1;37m" ;

#endif
*/

#define COLOR_ABOVE							\
	do {									\
		if(tempo == 9)  BLU  				\
		if(tempo == 10) GREEN  				\
		if(tempo == 11) CYAN  				\
		if(tempo == 12) RED  				\
		if(tempo == 14) YELLOW  			\
		if(tempo == 15) WHITE  				\
	} while(0) ; 							


#define L_BLU(stuff)						\
	do {									\
		int tempo = colorAbove;				\
		BLU 								\
		stuff								\
		COLOR_ABOVE							\
	} while(0) ;

#define L_GREEN(stuff)						\
	do {									\
		int tempo = colorAbove;				\
		GREEN								\
		stuff								\
		COLOR_ABOVE							\
	} while(0) ;

#define L_CYAN(stuff)						\
	do {									\
		int tempo = colorAbove;				\
		CYAN								\
		stuff								\
		COLOR_ABOVE							\
	} while(0) ;

#define L_RED(stuff)						\
	do {									\
		int tempo = colorAbove;				\
		RED									\
		stuff								\
		COLOR_ABOVE							\
	} while(0) ;

#define L_YELLOW(stuff)						\
	do {									\
		int tempo = colorAbove;				\
		YELLOW								\
		stuff								\
		COLOR_ABOVE							\
	} while(0) ;

#define L_WHITE(stuff)						\
	do {									\
		int tempo = colorAbove;				\
		WHITE								\
		stuff								\
		COLOR_ABOVE							\
	} while(0) ;

#endif