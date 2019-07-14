// ======================================================================
// macroColor.h - simple header for colored output in c++
// Made by 0pb - https://github.com/0pb/macroColor
//
// Distributed under the GNU GENERAL PUBLIC LICENSE
// See accompanying file LICENSE.txt or copy at
// https://github.com/0pb/macroColor/blob/master/LICENSE
// ======================================================================
#ifndef MACROCOLOR_H
#define MACROCOLOR_H
	/******************************************************************/
	#include <stdio.h>
    #include <unistd.h>
    #include <curses.h>
    #include <term.h>
	#if !defined(MSYS_COMP) && defined(_WIN32)
		#include <windows.h>
		#define mC_COLOR_WINDOW 1			
		//work for cplusplus
		#ifdef __cplusplus 
			#define mC_COLOR_CPP HANDLE hConsole
		//work for c
		#else  			
			#define mC_COLOR_CPP HANDLE *hConsole
		#endif	
		int setColorWindow(int colorNumber, mC_COLOR_CPP);	
	#endif
	//Add compatibility to msys
	//use #define MSYS_COMP before #include "macroColor.h" if you want to use the color in msys
	#if defined(MSYS_COMP) || defined(unix)
		#if defined(MACROCOLOR_TERMCAP) 
			#define MC_SETCOLOR_TERMCAP 1 		
		#else
			#define MC_SETCOLOR_TERMCAP 0
		#endif
			void setColorAinsi(int colorNumber);
			void setColorTcap(int colorNumber);
	#endif
	/******************************************************************/	
	//if you want to remove the color
	#ifdef REMOVE_COLOR 
		#define BLU(stuff) 		stuff	
		#define GREEN(stuff)	stuff	
		#define CYAN(stuff)		stuff
		#define RED(stuff)		stuff
		#define MAGENTA(stuff)	stuff
		#define YELLOW(stuff)	stuff
		#define WHITE(stuff)	stuff
	#else
		/******************************************************************/
		int setColor(int colorNumber);
		//extern needed or nested color won't work
		extern int macroColor_colorAbove;	
		/******************************************************************/
		#define BLU(stuff) 											\
			do {													\
				int macroColor_Tempo = macroColor_colorAbove ;		\
				macroColor_colorAbove = setColor(9);				\
				stuff												\
				setColor(macroColor_Tempo);							\
			} while(0)												
		#define GREEN(stuff) 										\
			do {													\
				int macroColor_Tempo = macroColor_colorAbove ;		\
				macroColor_colorAbove = setColor(10);				\
				stuff												\
				setColor(macroColor_Tempo);							\
			} while(0)												
		#define CYAN(stuff) 										\
			do {													\
				int macroColor_Tempo = macroColor_colorAbove ;		\
				macroColor_colorAbove = setColor(11) ;				\
				stuff												\
				setColor(macroColor_Tempo);							\
			} while(0)												
		#define RED(stuff) 											\
			do {													\
				int macroColor_Tempo = macroColor_colorAbove ;		\
				macroColor_colorAbove = setColor(12) ;				\
				stuff												\
				setColor(macroColor_Tempo);							\
			} while(0)												
		#define MAGENTA(stuff) 										\
			do {													\
				int macroColor_Tempo = macroColor_colorAbove ;		\
				macroColor_colorAbove = setColor(13);				\
				stuff												\
				setColor(macroColor_Tempo);							\
			} while(0)												
		#define YELLOW(stuff) 										\
			do {													\
				int macroColor_Tempo = macroColor_colorAbove ;		\
				macroColor_colorAbove = setColor(14);				\
				stuff												\
				setColor(macroColor_Tempo);							\
			} while(0)												
		#define WHITE(stuff) 										\
			do {													\
				int macroColor_Tempo = macroColor_colorAbove ;		\
				macroColor_colorAbove = setColor(15) ;				\
				stuff												\
				setColor(macroColor_Tempo);							\
			} while(0)												
	#endif
#endif
#undef MACROCOLOR_TERMCAP
#undef MSYS_COMP
#undef REMOVE_COLOR