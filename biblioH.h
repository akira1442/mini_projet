#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct livreh {
	int num;
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
void inserer(BiblioH* b,int num,char* titre,char* auteur);
void afficher_livre(LivreH* livre);
void afficher_biblio(BiblioH* b);
LivreH* recherche_Livre_num(BiblioH* b, int num);
LivreH* recherche_Livre_titre(BiblioH* b, char* titre);
BiblioH* recherche_Livre_auteur(BiblioH* b, char* auteur);
void supprime_Livre(BiblioH* b, int num, char* titre, char* auteur);
BiblioH* fusion(BiblioH* b1, BiblioH* b2);
LivreH* recherche_ouvrage(BiblioH* b);