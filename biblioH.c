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
	int A = (int)((sqrt(5)-1)/2);
	return floor(m*(cle*A - floor(cle*A)));
}

void inserer(BiblioH* b, int num, char* titre, char* auteur){
	LivreH* new_livre = creer_livre(num, titre, auteur);
	int hash = fonctionHachage(new_livre->clef, b->m);
	if (hash < b->m){
		if (b->T != NULL) {
			new_livre->suivant = b->T[hash];
		}
		b->T[hash]=new_livre;
		b->nE++;
	}
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
			if (tmp->num == num){
				return tmp;
			}
			tmp = tmp->suivant;
		}
	}
}

LivreH* recherche_Livre_titre(BiblioH* b, char* titre){
	if ((b == NULL) || (b->T == NULL)) {return NULL;}
	for (int i=0; i< b->m ; i++){
		LivreH* temp = b->T[i];
		while (temp){
			if(strcmp(temp->titre, titre)){
				return temp;
			}
		temp=temp->suivant;
		}
	}
	return NULL;
}

BiblioH* recherche_Livre_auteur(BiblioH* b, char* auteur){
	if ((b == NULL) || (b->T == NULL)) {return NULL;}
	int hash=fonctionHachage(auteur);
	BiblioH* biblio_aut=creer_biblio();
	LivreH* temp = b->T[hash];
	while (temp){
		inserer(biblioa_aut, temp->num, temp->titre, temp->auteur);
		temp=temp->suivant; 
	}
	return biblio_aut;
}

void supprime_Livre(BiblioH* b, int num, char* auteur, char* titre){
	if ((b == NULL) || (b->T == NULL)){
		return;
	}
	int hash = fonctionHachage(auteur);
	
	LivreH* prec = NULL;
	LivreH* curr = b->T[hash];

	while(curr){
		if ((curr->num == num )&&(strcmp(curr->titre,titre))){
			if (prec==NULL){ //insetion en tete
				b->T[hash]= curr->suivant;
			}
			else{
				prec->suivant = curr->suivant;
			}
			liberer_livre(curr);
			break;
		}
		prec = curr;
		curr = curr->suivant;
	}
}


BiblioH* fusion(BiblioH* b1, BiblioH* b2){

	if (b2 == NULL){
		free(b2);
		return b1;
	}
	else{
		LivreH* tmp = NULL;
		for (int i = 0; i < b2->m; i++){
			tmp = b2->T[i];
			while (tmp != NULL){
				inserer(b1, tmp->num, tmp->titre, tmp->auteur);
				tmp = tmp->suivant;
			}
		}
	}
	liberer_biblio(b2);
	return b1;
}

LivreH* recherche_ouvrage(BiblioH* b){
	if (b == NULL || b->T == NULL){return NULL;}

	LivreH* res = NULL;

	for (int i = 0; i < b->m; i++){
		LivreH* curr = b->T[i];
		if (curr->suivant != NULL){
			LivreH* rech = curr->suivant;
			while(rech){
				if (strcmp(rech->titre, curr->titre) == 0){
					if (res == NULL){
						res = creer_livre(rech->num, rech->titre, rech->auteur);
					}else{
						LivreH* tmp = creer_livre(rech->num, rech->titre, rech->auteur);
						tmp->suivant = res;
						res = tmp;
					}
				}
				rech = rech->suivant;
			}
			rech = NULL;
		}
	}
	return res;
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
	// int test_h = fonctionHachage(3,5);
	// printf("le hash du livre est %d\n",test_h);

}
