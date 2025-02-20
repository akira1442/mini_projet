#include "biblioH.h"

int fonctionClef(char* auteur){
	int sum = 0;	
	int i = 0;
	while (auteur[i] != '\0') {
        	sum+=auteur[i];
        	i++;
        }
    return sum;
}

LivreH* creer_livre(int num, char* titre, char* auteur){
	LivreH* new=(LivreH*)malloc(sizeof(LivreH));

	new -> clef = fonctionClef(auteur);
	new -> titre = strdup(titre);
	new -> auteur = strdup(auteur);
	new -> suivant = NULL;
	
	return new;
}

void liberer_livre(LivreH* l){
	free(l->titre);
	free(l->auteur);
	free(l);
}

BiblioH* creer_biblio(int m){
	BiblioH* new = (BiblioH*)malloc(sizeof(BiblioH));
	
	new -> nE = 0;
	new -> m = m;
	new -> T = NULL;
	
	return new;
}

void liberer_biblio(BiblioH* b){

	for (int i = 0; i < b->m; i++){
		LivreH* temp = b->T[i];
		while (temp){
			LivreH* temp2 = temp;
			temp = temp->suivant;
			liberer_livre(temp2);
		}
	}

	free(b->T);
	free(b);
}

int fonctionHachage(int cle, int m){
	float res = 0;
	float a=(sqrt(5)-1)/2 ;
	res = floor(m*(cle*a - floor(cle*a)));
	return (int)res;
}

void afficher_livreH(LivreH* l){
	printf("num : %d\n",l->clef);
	printf("titre : %s\n",l->titre);
	printf("auteur : %s\n",l->auteur);
}

void afficher_biblio(BiblioH* b){
	LivreH* l;
	for (int i = 0; i < b->m; i++){
		l = b->T[i];
		while(l != NULL){
			afficher_livreH(l);
			l = l->suivant;
		}
	}
}

LivreH* recherche_Livre_num(BiblioH* b, int num){

	LivreH* tmp = NULL;

	for (int i = 0; i < b->m; i++){
		tmp = b->T[i];
		while (tmp != NULL){
			if (tmp->clef == num){
				return tmp;
			}
			tmp = tmp->suivant;
		}
	}


}

void main(){
	LivreH* livre = creer_livre(1234,"SLMKF","MKSRF");
	printf("%s\n",livre->titre);
	printf("%s\n",livre->auteur);
	liberer_livre(livre);
	BiblioH* b = creer_biblio(5);
	printf("%d\n",b->nE);
	printf("%d\n",b->m);
	liberer_biblio(b);
	int test_h = fonctionHachage(3,5);
	printf("le hash du livre est %d\n",test_h);

	}
