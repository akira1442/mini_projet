#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct livreh {
	int clef;
	char* titre;
	char* auteur;
	struct LivreH * suivant ;
} LivreH ;

typedef struct table {
	int nE ; /*nombre d’elements contenus dans la table de hachage */
	int m ; /*taille de la table de hachage */
	LivreH ** T ; /*table de hachage avec resolution des collisions par chainage */
} BiblioH ;


int fonctionClef(char* auteur);
LivreH* creer_livre(int num, char* titre, char* auteur);
void liberer_livre(LivreH* l);
BiblioH* creer_biblio(int m);
void liberer_biblio(BiblioH* b);
int fonctionHachage(int cle, int m);
