

#include <stdio.h>
//#define REMOVE_COLOR
//#define MSYS_COMP
#include "macroColor.h" 

int main( int argc, char* args[] )
{
	GREEN
	(
		printf("[green]\n");
	);
	
	BLU
	(
		printf("[blu]\n");
	);

	//test if else statement
	if(1) 
	{
		CYAN
		(
			printf("[cyan]\n");
			int i = 0 ; 
			printf("i + 1 = %i\n", i + 1);
		);	 
	}
	else
	{
		RED
		(
			printf("[red]\n"); 
		);	
	}

	YELLOW
	(
		printf("[yellow]\n"); 
	);		

	WHITE
	(
		printf("[white]\n");
	);	

	//Test nested color
	YELLOW
	(
		printf("[yellow");
		RED
		(
			printf("[red"); 
			BLU
			(
				printf("[blu]");
			);
			printf("]");
		);
		printf("]\n"); 
	);

	/*
	//use directly the color macro, remember it doesn't automatically back to white, so you have to put C_WHITE or it stay in yellow
	C_YELLOW 
	printf("Yellow without white afterward\n");
	int abc = 0 ; 
	printf("%i\n", abc);
	printf("Yellow without white afterward\n") ; 
	C_WHITE
	*/
	return 0 ; 
}