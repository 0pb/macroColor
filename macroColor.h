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
	#if !defined(MSYS_COMP) && defined(_WIN32)
		#include <windows.h>
		#define MC_COLOR_WINDOW 1			
		//work for cplusplus
		#ifdef __cplusplus 
			#define MC_COLOR_CPP HANDLE hConsole
		//work for c
		#else  			
			#define MC_COLOR_CPP HANDLE *hConsole
		#endif	
	#endif
	//Add compatibility to msys
	//use #define MSYS_COMP before #include "macroColor.h" if you want to use the color in msys
	#if defined(MSYS_COMP) || defined(unix)
	#endif
		int setColorWindow(int colorNumber, MC_COLOR_CPP);	
		void setColorAinsi(int colorNumber);
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