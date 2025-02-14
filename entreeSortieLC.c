#include "entreeSortieLC.h" 

Biblio* charger_n_entrees(char* nomfic, int n){
	
	FILE* f = fopen("GdeBiblio.txt", "r");
	
	if (f == NULL){
        	printf("Le fichier n'a pas pu être ouvert\n");
        	return NULL;
    }

	Biblio* b = creer_biblio();
	int num, i = 0;
	char auteur[30];
	char titre[30];

    while (i < n && fscanf(f,"%d %s %s",&num,titre,auteur) == 3) {
        inserer_en_tete(b,num,titre,auteur);
        i++;
    }

	fclose(f);
	return b;
}

void enregistrer_biblio(Biblio *b, char* nomfic){
	
	// Déclaration de nomfic si non déclarer
	if ((nomfic == NULL) || (nomfic[0] == '\0')){
		nomfic = ("Richard.txt");
	}

	FILE* f = fopen(nomfic, "w");

	Livre* liste = b->L;
	
	while (liste != NULL){
		fprintf(f, "%d %s %s\n", liste->num, liste->titre, liste->auteur);
		liste = liste->suiv;
	}

	fclose(f);
}
