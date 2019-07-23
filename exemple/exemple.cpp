
//#define REMOVE_COLOR
//#define MSYS_COMP
#include "macroColor.h" 
#include <stdio.h> 
#include <iostream> 
#include <string> 

int main( int argc, char* args[] )
{
	//Test of all 6 colors
	GREEN
	(
		std::cout << "\n[green]\n" ; 
	);

	BLU
	(
		std::cout << "[blu]\n" ; 
	);

	//test if else statement
	int g = 1 ; 
	if(g > 0) 
	{
		CYAN
		(
			std::cout << "[cyan]\n" ; 
			int i = 0 ; 
			std::cout << "i + 1 = " << i + 1 << "\n" ; 
		); 
	}
	else
	{
		RED
		(
			std::cout << "[red]\n" ; 
		);
	}

	YELLOW
	(
		std::cout << "[yellow]\n" ; 
	);		

	WHITE
	(
		std::cout << "[white]\n" ; 
	);	

	//Test nested color
	YELLOW
	(
		std::cout << "[yellow" ; 
		RED
		(
			std::cout << "[red" ;
			BLU
			(
				std::cout << "[blu]" ;
			);
			std::cout << "]" ;
		);
		std::cout << "]\n"; 
	);

	//use directly the color macro, remember it doesn't automatically back to white, so you have to put C_WHITE or it stay in yellow
	C_YELLOW
	std::cout << "Yellow without white afterward\n" ; 
	int abc = 0 ; 
	std::cout << abc << "\n" ; 
	std::cout << "Still yellow\n" ; 
	C_WHITE

	return 0;
}