#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livre{
	int num;
	char* titre;
	char* auteur;
	struct livre* suiv;
} Livre;

typedef struct biblio{ 
	Livre* L;		/*premier element*/
} Biblio;


Livre* creer_livre(int num,char* titre,char* auteur);
void liberer_livre(Livre* l);
Biblio* creer_biblio();
void liberer_biblio(Biblio* b);
void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur);
void affiche_livre(Livre* l);
void afficher_biblio(Biblio* b);
Livre* recherche_Livre_num(Livre* li, int num);
Livre* recherche_Livre_titre(Livre* li, char titre);
Biblio* recherche_Livre_auteur(Biblio* b, char auteur);
void supprime_Livre(Biblio* b, int num, char* auteur, char* titre);
Biblio* fusion(Biblio* b1, Biblio* b2);
Livre* recherche_doublons(Biblio* b);