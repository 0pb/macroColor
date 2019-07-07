#include "macroColor.h" 
#include <stdio.h> 
#include <iostream> 
#include <string> 

int main( int argc, char* args[] )
{

	std::string message = "TEST" ; 

	//Test of all 6 colors
	L_GREEN
	(
		std::cout << "[" << message << "]\n" ; 
	)

	L_BLU
	(
		std::cout << "[" << message << "]\n" ; 
	)

	L_CYAN
	(
		std::cout << "[" << message << "]\n" ; 
		int i = 0 ; 
		//whatever you want to write
		std::cout << "i + 1 = " << i + 1 << "\n" ; 
	)	
	
	L_RED
	(
		std::cout << "[" << message << "]\n" ; 
	)	

	L_YELLOW
	(
		std::cout << "[" << message << "]\n" ; 
	)		

	L_WHITE
	(
		std::cout << "[" << message << "]\n" ; 
	)	

	//Test nested color
	L_YELLOW
	(
		std::cout << "[" ; 
		L_RED
		(
			std::cout << "[" ;
			std::cout << message ;
			L_BLU
			(
				std::cout << "[" ;
				std::cout << message ; 
				std::cout << "]" ;
			)
			std::cout << "]" ;
		)
		std::cout << "]\n"; 
	)

	return 0;
}