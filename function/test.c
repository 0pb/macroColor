#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stdio.h> 

#define TAILLE_CASE 3 
#define TAILLE_GRILLE 3

int minmax(int valeur1, int valeur2, int numeroJoueur) 
{
	if(numeroJoueur == 1) return (valeur1>=valeur2) ? valeur1 : valeur2 ;
	return (valeur1<=valeur2) ? valeur1 : valeur2 ;
}

const bool regle(int numeroLigne, int numeroColonne) 
{
	/*!
	* @function regle
	* @abstract verifie que les regles soient bien respectes
	* @param numeroLigne	numero de la ligne
	* @param numeroColonne 	numero de la colonne
	* @return 				vrai si les regles sont respectes, faux sinon
	*/
	//if(grille[numeroLigne][numeroColonne] != 0)			return false; 
	if(numeroLigne>TAILLE_GRILLE || numeroLigne<0) 		return false; 
	if(numeroColonne>TAILLE_GRILLE || numeroColonne<0) 	return false;
	return true; 
}

const int joueur1 = 1;
const int joueur2 = -1;

TEST_CASE("Regle") {
    CHECK(regle(0,2,joueur1) == 2);
    CHECK(regle(2,0,joueur1) == 2);
    CHECK(regle(2,1,joueur1) == 2);
}

TEST_CASE("Maximum") {
    CHECK(minmax(0,2,joueur1) == 2);
    CHECK(minmax(2,0,joueur1) == 2);
    CHECK(minmax(2,1,joueur1) == 2);
}

TEST_CASE("Minimum") {
	CHECK(minmax(2,1,joueur2) == 1);
	CHECK(minmax(1,2,joueur2) == 1);
	CHECK(minmax(2,2,joueur2) == 2);
	CHECK(minmax(-1,1,joueur2) == -1);
}

//REQUIRE();
//WARN(); 

