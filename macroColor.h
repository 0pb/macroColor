
// ======================================================================
// macroColor.h - simple header for colored output in c++
// Made by 0pb - https://github.com/0pb/macroColor
//
// Distributed under the GNU GENERAL PUBLIC LICENSE
// See accompanying file LICENSE.txt or copy at
// https://github.com/0pb/macroColor/blob/master/LICENSE
// ======================================================================

#ifndef macroColor_h

	//Add compatibility to msys
	//use #define MSYS_COMP before #include "macroColor.h" if you want to use the color in msys
	#if defined(MSYS_COMP)
		#include <stdio.h> 
		#include <iostream> 
		int macroColor_colorAbove = 15 ;
		int tempoColor = 15 ;  
	
	    #define C_BLU	    std::cout << "\e[0;34m" ; 	macroColor_colorAbove = 9 ;
	    #define C_GREEN     std::cout << "\e[0;32m" ; 	macroColor_colorAbove = 10;
	    #define C_CYAN      std::cout << "\e[0;36m" ; 	macroColor_colorAbove = 11;
	    #define C_RED       std::cout << "\e[0;31m" ; 	macroColor_colorAbove = 12;
	    #define C_YELLOW    std::cout << "\e[0;33m" ; 	macroColor_colorAbove = 14;
	    #define C_WHITE		std::cout << "\e[1;37m" ; 	macroColor_colorAbove = 15;
	#endif
	
	#if !defined(MSYS_COMP) && defined(_WIN32) 
		#include <windows.h>
		int macroColor_colorAbove = 15 ;
		int tempoColor = 15 ; 
		#define C_BLU 		SetConsoleTextAttribute(hConsole, 9) ; 	macroColor_colorAbove = 9 ;
		#define C_GREEN 	SetConsoleTextAttribute(hConsole, 10); 	macroColor_colorAbove = 10;
		#define C_CYAN 		SetConsoleTextAttribute(hConsole, 11); 	macroColor_colorAbove = 11;
		#define C_RED 		SetConsoleTextAttribute(hConsole, 12); 	macroColor_colorAbove = 12;
		#define C_YELLOW 	SetConsoleTextAttribute(hConsole, 14); 	macroColor_colorAbove = 14;
		#define C_WHITE 	SetConsoleTextAttribute(hConsole, 15); 	macroColor_colorAbove = 15;
	
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	#endif
	
	#ifdef unix
		#include <stdio.h> 
		#include <iostream>  
		int macroColor_colorAbove = 15 ;
		int tempoColor = 15 ;  
	    #define C_BLU	    std::cout << "\e[0;34m" ; 	macroColor_colorAbove = 9 ;
	    #define C_GREEN     std::cout << "\e[0;32m" ; 	macroColor_colorAbove = 10;
	    #define C_CYAN      std::cout << "\e[0;36m" ; 	macroColor_colorAbove = 11;
	    #define C_RED       std::cout << "\e[0;31m" ; 	macroColor_colorAbove = 12;
	    #define C_YELLOW    std::cout << "\e[0;33m" ; 	macroColor_colorAbove = 14;
	    #define C_WHITE		std::cout << "\e[1;37m" ; 	macroColor_colorAbove = 15;
	
	#endif
	
	#ifndef REMOVE_COLOR
		#define COLOR_ABOVE							\
			do {									\
				if(macroColor_tempo == 9)  C_BLU  	\
				if(macroColor_tempo == 10) C_GREEN  \
				if(macroColor_tempo == 11) C_CYAN  	\
				if(macroColor_tempo == 12) C_RED  	\
				if(macroColor_tempo == 14) C_YELLOW \
				if(macroColor_tempo == 15) C_WHITE  \
			} while(0) ; 							
		
		
		#define BLU(stuff)										\
			do {												\
				int macroColor_tempo = macroColor_colorAbove;	\
				C_BLU 											\
				stuff											\
				COLOR_ABOVE										\
			} while(0) ;
		
		#define GREEN(stuff)									\
			do {												\
				int macroColor_tempo = macroColor_colorAbove;	\
				C_GREEN											\
				stuff											\
				COLOR_ABOVE										\
			} while(0) ;
		
		#define CYAN(stuff)										\
			do {												\
				int macroColor_tempo = macroColor_colorAbove;	\
				C_CYAN											\
				stuff											\
				COLOR_ABOVE										\
			} while(0) ;
		
		#define RED(stuff)										\
			do {												\
				int macroColor_tempo = macroColor_colorAbove;	\
				C_RED											\
				stuff											\
				COLOR_ABOVE										\
			} while(0) ;
		
		#define YELLOW(stuff)									\
			do {												\
				int macroColor_tempo = macroColor_colorAbove;	\
				C_YELLOW										\
				stuff											\
				COLOR_ABOVE										\
			} while(0) ;
		
		#define WHITE(stuff)									\
			do {												\
				int macroColor_tempo = macroColor_colorAbove;	\
				C_WHITE											\
				stuff											\
				COLOR_ABOVE										\
			} while(0) ;
	#endif

	#ifdef REMOVE_COLOR 
		#define BLU(stuff) 		stuff	
		#define GREEN(stuff)	stuff	
		#define CYAN(stuff)		stuff
		#define RED(stuff)		stuff
		#define YELLOW(stuff)	stuff
		#define WHITE(stuff)	stuff
	#endif

#endif
#undef MSYS_COMP
#undef REMOVE_COLOR